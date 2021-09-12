/**********************************************************************************
// Ghost (Código Fonte)
// 
// Criação:     01 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Fantasmas do PacMan
//
**********************************************************************************/

#include "PacMan.h"
#include "Player.h"
#include "Ghost.h"
#include "Pivot.h"

// ---------------------------------------------------------------------------------

Ghost::Ghost(Player * p, float X, float Y, float time, uint enemy)
{
    // Inimigo deve movimentar-se em relação a tal player
    player = p;

    // Sprites a definir
    switch (enemy) {
    case BLACK: {
        spriteL = new Sprite("Resources/BlackGhostL.png");
        spriteR = new Sprite("Resources/BlackGhostR.png");
        spriteU = new Sprite("Resources/BlackGhostU.png");
        spriteD = new Sprite("Resources/BlackGhostD.png");
		fleeL = new Sprite("Resources/BlueGhostL.png");
		fleeR = new Sprite("Resources/BlueGhostR.png");
		fleeU = new Sprite("Resources/BlueGhostU.png");
		fleeD = new Sprite("Resources/BlueGhostD.png");
        break;
        }
    case PUMPKIN: {
        spriteL = new Sprite("Resources/PumpkinL.png");
        spriteR = new Sprite("Resources/PumpkinR.png");
        spriteU = new Sprite("Resources/PumpkinU.png");
        spriteD = new Sprite("Resources/PumpkinD.png");
		fleeL = new Sprite("Resources/BluePumpkinL.png");
		fleeR = new Sprite("Resources/BluePumpkinR.png");
		fleeU = new Sprite("Resources/BluePumpkinU.png");
		fleeD = new Sprite("Resources/BluePumpkinD.png");
        break;
        }
    default: {
        spriteL = new Sprite("Resources/WhiteGhostL.png");
        spriteR = new Sprite("Resources/WhiteGhostR.png");
        spriteU = new Sprite("Resources/WhiteGhostU.png");
        spriteD = new Sprite("Resources/WhiteGhostD.png");
		fleeL = new Sprite("Resources/BlueGhostL.png");
		fleeR = new Sprite("Resources/BlueGhostR.png");
		fleeU = new Sprite("Resources/BlueGhostU.png");
		fleeD = new Sprite("Resources/BlueGhostD.png");
        }
    }

    // imagem do player é 48 por 48 (com borda transparente de W pixels)
    bbox = new Rect(-20, -20, 20, 20);
    MoveTo(X, Y);
    type = GHOST;

	stateTime = time;
}

// ---------------------------------------------------------------------------------

Ghost::~Ghost()
{
	delete fleeL;
	delete fleeR;
	delete fleeU;
	delete fleeD;

    delete spriteL;
    delete spriteR;
    delete spriteU;
    delete spriteD;
    delete bbox;
}

// ---------------------------------------------------------------------------------

void Ghost::Stop() {
    velX = 0;
    velY = 0;
}

void Ghost::Up()
{
	if (state == PURSUE) {
		velX = 0;
		velY = -180.0f;
	}
	if (state == FLEE) {
		velX = 0;
		velY = -175.0f;
	}
    
}
void Ghost::Down()
{
	if (state == PURSUE) {
		velX = 0;
		velY = 180.0f;
	}
	if (state == FLEE) {
		velX = 0;
		velY = 175.0f;
	}
}

void Ghost::Left()
{
	if (state == PURSUE) {
		velX = -180.0f;
		velY = 0;
	}
	if (state == FLEE) {
		velX = -175.0f;
		velY = 0;
	}
}

void Ghost::Right()
{
	if (state == PURSUE) {
		velX = 180.0f;
		velY = 0;
	}
	if (state == FLEE) {
		velX = 175.0f;
		velY = 0;
	}
}

// ---------------------------------------------------------------------------------

void Ghost::OnCollision(Object* obj)
{
	if (obj->Type() == PIVOT)
		PivotCollision(obj);
}

void Ghost::PivotCollision(Object* obj)
{
	Pivot* p = (Pivot*)obj;
	distX = player->X() - x;
	distY = player->Y() - y;

	if (state == PURSUE) {
		if (distX > 25.0f || distX < -25.0f) {
			if (distX < 0)
			{
				nextMove = LEFT;

				if (currentMove == RIGHT || currentMove == STOPED)
				{
					currentMove = LEFT;
					Left();
				}
			}
			else {
				if (distX > 0)
				{
					nextMove = RIGHT;

					if (currentMove == LEFT || currentMove == STOPED)
					{
						currentMove = RIGHT;
						Right();
					}
				}
			}
		}
		else {
			if (distY < 0)
			{
				nextMove = UP;

				if (currentMove == DOWN || currentMove == STOPED)
				{
					currentMove = UP;
					Up();
				}
			}
			else {
				if (distY > 0)
				{
					nextMove = DOWN;

					if (currentMove == UP || currentMove == STOPED)
					{
						currentMove = DOWN;
						Down();
					}
				}
			}
		}
	}

	switch (currentMove)
	{
	case STOPED:
		// -----------------------
		// CurrentMove == STOPED
		// -----------------------

		switch (nextMove)
		{
		case LEFT:
			if (p->left)
			{
				currentMove = LEFT;
				Left();
			}
			break;
		case RIGHT:
			if (p->right)
			{
				currentMove = RIGHT;
				Right();
			}

			break;
		case UP:
			if (p->up)
			{
				currentMove = UP;
				Up();
			}
			break;
		case DOWN:
			if (p->down)
			{
				currentMove = DOWN;
				Down();
			}
			break;
		}
		break;

	case LEFT:
		// -----------------------
		// CurrentMove == LEFT
		// -----------------------

		if (x < p->X())
		{
			if (!p->left)
			{
				MoveTo(p->X(), Y());
				currentMove = STOPED;
				Stop();
				if (p->down) {
					currentMove = DOWN;
					Down();
				}
				else if (p->up){
					currentMove = UP;
					Up();
				}
				else {
					currentMove = RIGHT;
					Right();
				}
			}
		}

		switch (nextMove)
		{
		case LEFT:
			if (x < p->X())
			{
				if (!p->left)
				{
					MoveTo(p->X(), Y());
					currentMove = STOPED;
					Stop();
					if (p->down) {
						currentMove = DOWN;
						Down();
					}
					else if (p->up){
						currentMove = UP;
						Up();
					}
					else {
						currentMove = RIGHT;
						Right();
					}
				}
			}
			break;
		case RIGHT:
			currentMove = RIGHT;
			Right();

			break;
		case UP:
			if (x < p->X())
			{
				if (p->up)
				{
					MoveTo(p->X(), Y());
					currentMove = UP;
					Up();
				}
			}
			break;
		case DOWN:
			if (x < p->X())
			{
				if (p->down)
				{
					MoveTo(p->X(), Y());
					currentMove = DOWN;
					Down();
				}
			}
			break;
		}
		break;

	case RIGHT:
		// -----------------------
		// CurrentMove == RIGHT
		// -----------------------

		if (x > p->X())
		{
			if (!p->right)
			{
				MoveTo(p->X(), Y());
				currentMove = STOPED;
				Stop();
				if (p->down) {
					currentMove = DOWN;
					Down();
				}
				else if(p->up){
					currentMove = UP;
					Up();
				}
				else {
					currentMove = LEFT;
					Left();
				}
			}
		}

		switch (nextMove)
		{
		case LEFT:
			currentMove = LEFT;
			Left();
			break;
		case RIGHT:
			if (x > p->X())
			{
				if (!p->right)
				{
					MoveTo(p->X(), Y());
					currentMove = STOPED;
					Stop();
					if (p->down) {
						currentMove = DOWN;
						Down();
					}
					else if (p->up){
						currentMove = UP;
						Up();
					}
					else {
						currentMove = LEFT;
						Left();
					}
				}
			}

			break;
		case UP:
			if (x > p->X())
			{
				if (p->up)
				{
					MoveTo(p->X(), Y());
					currentMove = UP;
					Up();
				}
			}
			break;
		case DOWN:
			if (x > p->X())
			{
				if (p->down)
				{
					MoveTo(p->X(), Y());
					currentMove = DOWN;
					Down();
				}
			}
			break;
		}
		break;

	case UP:
		// -----------------------
		// CurrentMove == UP
		// -----------------------

		if (y < p->Y())
		{
			if (!p->up)
			{
				MoveTo(p->X(), Y());
				currentMove = STOPED;
				Stop();
				if (p->right) {
					currentMove = RIGHT;
					Right();
				}
				else if (p->left){
					currentMove = LEFT;
					Left();
				}
				else {
					currentMove = DOWN;
					Down();
				}
			}
		}

		switch (nextMove)
		{
		case LEFT:
			if (y < p->Y())
			{
				if (p->left)
				{
					MoveTo(x, p->Y());
					currentMove = LEFT;
					Left();
				}
			}
			break;
		case RIGHT:
			if (y < p->Y())
			{
				if (p->right)
				{
					MoveTo(x, p->Y());
					currentMove = RIGHT;
					Right();
				}
			}
			break;
		case UP:
			if (y < p->Y())
			{
				if (!p->up)
				{
					MoveTo(p->X(), Y());
					currentMove = STOPED;
					Stop();
					if (p->right) {
						currentMove = RIGHT;
						Right();
					}
					else if (p->left){
						currentMove = LEFT;
						Left();
					}
					else {
						currentMove = DOWN;
						Down();
					}
				}
			}
			break;
		case DOWN:
			currentMove = DOWN;
			Down();
			break;
		}
		break;

	case DOWN:
		// -----------------------
		// CurrentMove == DOWN
		// -----------------------

		if (y > p->Y())
		{
			if (!p->down)
			{
				MoveTo(p->X(), Y());
				currentMove = STOPED;
				Stop();
				if (p->right) {
					currentMove = RIGHT;
					Right();
				}
				else if (p->left){
					currentMove = LEFT;
					Left();
				}
				else {
					currentMove = UP;
					Up();
				}
			}
		}

		switch (nextMove)
		{
		case LEFT:
			if (y > p->Y())
			{
				if (p->left)
				{
					MoveTo(x, p->Y());
					currentMove = LEFT;
					Left();
				}
			}
			break;
		case RIGHT:
			if (y > p->Y())
			{
				if (p->right)
				{
					MoveTo(x, p->Y());
					currentMove = RIGHT;
					Right();
				}
			}
			break;
		case UP:
			currentMove = UP;
			Up();
			break;
		case DOWN:
			if (y > p->Y())
			{
				if (!p->down)
				{
					MoveTo(p->X(), Y());
					currentMove = STOPED;
					Stop();
					if (p->right) {
						currentMove = RIGHT;
						Right();
					}
					else if (p->left){
						currentMove = LEFT;
						Left();
					}
					else {
						currentMove = UP;
						Up();
					}
				}
			}
			break;
		}
		break;
	}

}

// ---------------------------------------------------------------------------------

void Ghost::Update()
{
	state = !player->state;

	if (state == FLEE) {
		if (distX > distY || player->Y() == y) {
			if (distX < 0)
			{
				nextMove = RIGHT;

				if (currentMove == LEFT || currentMove == STOPED)
				{
					currentMove = RIGHT;
					Right();
				}
			}
			else {
				if (distX > 0)
				{
					nextMove = LEFT;

					if (currentMove == RIGHT || currentMove == STOPED)
					{
						currentMove = LEFT;
						Left();
					}
				}
			}
		}
		else {
			if (distY < 0)
			{
				nextMove = DOWN;

				if (currentMove == UP || currentMove == STOPED)
				{
					currentMove = DOWN;
					Down();
				}
			}
			else {
				if (distY > 0)
				{
					nextMove = UP;

					if (currentMove == DOWN || currentMove == STOPED)
					{
						currentMove = UP;
						Up();
					}
				}
			}
		}
   }

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);

    // mantém player dentro da tela
    if (x + 20 < 0)
        MoveTo(window->Width() + 20.f, Y());

    if (x - 20 > window->Width())
        MoveTo(-20.0f, Y());

    if (Y() + 20 < 0)
        MoveTo(x, window->Height() + 20.0f);

    if (Y() - 20 > window->Height())
        MoveTo(x, -20.0f);

	if (state == PURSUE) {
		stateTime -= gameTime;
	}
	if (stateTime <= 0 && !gameStart) {
		MoveTo(479.0f, 360.0f);
		gameStart = !gameStart;

	}
}

// ---------------------------------------------------------------------------------

void Ghost::Draw()
{
	if (state == PURSUE)
		switch (currentMove)
		{
		case STOPED: spriteD->Draw(x, y, Layer::UPPER); break;
		case LEFT:  spriteL->Draw(x, y, Layer::UPPER); break;
		case RIGHT: spriteR->Draw(x, y, Layer::UPPER); break;
		case UP:    spriteU->Draw(x, y, Layer::UPPER); break;
		case DOWN:  spriteD->Draw(x, y, Layer::UPPER); break;
		default:
			switch (nextMove)
			{
			case LEFT:  spriteL->Draw(x, y, Layer::UPPER); break;
			case RIGHT: spriteR->Draw(x, y, Layer::UPPER); break;
			case UP:    spriteU->Draw(x, y, Layer::UPPER); break;
			case DOWN:  spriteD->Draw(x, y, Layer::UPPER); break;
			default:    spriteL->Draw(x, y, Layer::UPPER);
			}
		}
	if (state == FLEE)
		switch (currentMove)
		{
		case STOPED: fleeD->Draw(x, y, Layer::UPPER); break;
		case LEFT:  fleeL->Draw(x, y, Layer::UPPER); break;
		case RIGHT: fleeR->Draw(x, y, Layer::UPPER); break;
		case UP:    fleeU->Draw(x, y, Layer::UPPER); break;
		case DOWN:  fleeD->Draw(x, y, Layer::UPPER); break;
		default:
			switch (nextMove)
			{
			case LEFT:  fleeL->Draw(x, y, Layer::UPPER); break;
			case RIGHT: fleeR->Draw(x, y, Layer::UPPER); break;
			case UP:    fleeU->Draw(x, y, Layer::UPPER); break;
			case DOWN:  fleeD->Draw(x, y, Layer::UPPER); break;
			default:    fleeL->Draw(x, y, Layer::UPPER);
			}
		}
    
}