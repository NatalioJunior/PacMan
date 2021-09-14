// ---------------------------------------------------------------------------------
//CARLOS CAVEIRINHA
// ---------------------------------------------------------------------------------


#include "CarlosCaveirinha.h"
#include "Player.h"
#include "Pivot.h"
#include "Food.h"
#include "Special.h"
#include "Ghost.h"

// ---------------------------------------------------------------------------------

Scene* Player::scene = nullptr;
Player::Player()
{
	// Sprites do player
	spriteL = new Sprite("Resources/SkullL.png");
	spriteR = new Sprite("Resources/SkullR.png");
	spriteU = new Sprite("Resources/SkullU.png");
	spriteD = new Sprite("Resources/SkullD.png");

	//definindo a bb
	bbox = new Rect(-20, -20, 20, 20);
	type = PLAYER;

	stateTime = 5;
}
Player::Player(Scene* sc)
{
	scene = sc;
	// Sprites do player:
	spriteL = new Sprite("Resources/SkullL.png");
	spriteR = new Sprite("Resources/SkullR.png");
	spriteU = new Sprite("Resources/SkullU.png");
	spriteD = new Sprite("Resources/SkullD.png");

	//definindo bb
	bbox = new Rect(-20, -20, 20, 20);
	MoveTo(480.0f, 445.0f);
	type = PLAYER;

	stateTime = 5;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
	delete spriteL;
	delete spriteR;
	delete spriteU;
	delete spriteD;
	delete bbox;
}

// ---------------------------------------------------------------------------------

void Player::Stop()
{
	velX = 0;
	velY = 0;
	ctrlWeb = true;
}

// ---------------------------------------------------------------------------------

void Player::Up()
{
	velX = 0;
	velY = -190.0f;
	ctrlWeb = true;
}

// ---------------------------------------------------------------------------------

void Player::Down()
{
	velX = 0;
	velY = 190.0f;
	ctrlWeb = true;
}

// ---------------------------------------------------------------------------------

void Player::Left()
{
	velX = -190.0f;
	velY = 0;
	ctrlWeb = true;
}

// ---------------------------------------------------------------------------------

void Player::Right()
{
	velX = 190.0f;
	velY = 0;
	ctrlWeb = true;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object* obj)
{
	//Testando quais objetos estao colidindo
	if (obj->Type() == PIVOT)
		PivotCollision(obj);
	if (obj->Type() == FOOD)
		foodCollision(obj);
	if (obj->Type() == SPECIAL)
		specialCollision(obj);
	if (obj->Type() == GHOST)
		ghostCollision(obj);
	if (obj->Type() == OBSTACLE)
		ObstacleCollision(obj);

}

// ---------------------------------------------------------------------------------
//COLISOES personalizadas 
void Player::foodCollision(Object* obj) {
	Food* fd = (Food*)obj;
	setScore(getScore() + 10);
	scene->Delete(fd, STATIC);
	scene->comidasTotais -= 1;
}
void Player::ghostCollision(Object* obj) {
	Ghost* g = (Ghost*)obj;
	if (state == FLEE) {
		//MoveTo(480.0f, 445.0f);
		game->setGameState(GAMEOVER);
	}
	else {
		g->stateTime = 10;
		g->gameStart = false;
		g->currentMove = g->nextMove = STOPED;
		g->Stop();
		g->MoveTo(479.0f, 335.0f);
	}
}

void Player::ObstacleCollision(Object* obj)
{
	if (ctrlWeb) {
		velX = velX * 0.55f;
		velY = velY * 0.5f;
		ctrlWeb = false;
	}
}

void Player::specialCollision(Object* obj) {
	Special* sp = (Special*)obj;
	setScore(getScore() + 10);
	scene->Delete(sp, STATIC);
	state = PURSUE;
}
// ---------------------------------------------------------------------------------

void Player::PivotCollision(Object* obj)
{
	Pivot* p = (Pivot*)obj;

	switch (currState)
	{
	case STOPED:
		// -----------------------
		// CurrentState == STOPED
		// -----------------------

		switch (nextState)
		{
		case LEFT:
			if (p->left)
			{
				currState = LEFT;
				Left();
			}
			break;
		case RIGHT:
			if (p->right)
			{
				currState = RIGHT;
				Right();
			}

			break;
		case UP:
			if (p->up)
			{
				currState = UP;
				Up();
			}
			break;
		case DOWN:
			if (p->down)
			{
				currState = DOWN;
				Down();
			}
			break;
		}
		break;

	case LEFT:
		// -----------------------
		// CurrentState == LEFT
		// -----------------------

		if (x < p->X())
		{
			if (!p->left)
			{
				MoveTo(p->X(), Y());
				currState = STOPED;
				Stop();
			}
		}

		switch (nextState)
		{
		case LEFT:
			if (x < p->X())
			{
				if (!p->left)
				{
					MoveTo(p->X(), Y());
					currState = STOPED;
					Stop();
				}
			}
			break;
		case RIGHT:
			currState = RIGHT;
			Right();

			break;
		case UP:
			if (x < p->X())
			{
				if (p->up)
				{
					MoveTo(p->X(), Y());
					currState = UP;
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
					currState = DOWN;
					Down();
				}
			}
			break;
		}
		break;

	case RIGHT:
		// -----------------------
		// CurrentState == RIGHT
		// -----------------------

		if (x > p->X())
		{
			if (!p->right)
			{
				MoveTo(p->X(), Y());
				currState = STOPED;
				Stop();
			}
		}

		switch (nextState)
		{
		case LEFT:
			currState = LEFT;
			Left();
			break;
		case RIGHT:
			if (x > p->X())
			{
				if (!p->right)
				{
					MoveTo(p->X(), Y());
					currState = STOPED;
					Stop();
				}
			}

			break;
		case UP:
			if (x > p->X())
			{
				if (p->up)
				{
					MoveTo(p->X(), Y());
					currState = UP;
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
					currState = DOWN;
					Down();
				}
			}
			break;
		}
		break;

	case UP:
		// -----------------------
		// CurrentState == UP
		// -----------------------

		if (y < p->Y())
		{
			if (!p->up)
			{
				MoveTo(x, p->Y());
				currState = STOPED;
				Stop();
			}
		}

		switch (nextState)
		{
		case LEFT:
			if (y < p->Y())
			{
				if (p->left)
				{
					MoveTo(x, p->Y());
					currState = LEFT;
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
					currState = RIGHT;
					Right();
				}
			}
			break;
		case UP:
			if (y < p->Y())
			{
				if (!p->up)
				{
					MoveTo(x, p->Y());
					currState = STOPED;
					Stop();
				}
			}
			break;
		case DOWN:
			currState = DOWN;
			Down();
			break;
		}
		break;

	case DOWN:
		// -----------------------
		// CurrentState == DOWN
		// -----------------------

		if (y > p->Y())
		{
			if (!p->down)
			{
				MoveTo(x, p->Y());
				currState = STOPED;
				Stop();
			}
		}

		switch (nextState)
		{
		case LEFT:
			if (y > p->Y())
			{
				if (p->left)
				{
					MoveTo(x, p->Y());
					currState = LEFT;
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
					currState = RIGHT;
					Right();
				}
			}
			break;
		case UP:
			currState = UP;
			Up();
			break;
		case DOWN:
			if (y > p->Y())
			{
				if (!p->down)
				{
					MoveTo(x, p->Y());
					currState = STOPED;
					Stop();
				}
			}
			break;
		}
		break;
	}
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
	//Controles
	if (window->KeyDown(VK_LEFT))
	{
		nextState = LEFT;

		if (currState == RIGHT || currState == STOPED)
		{
			currState = LEFT;
			Left();
		}
	}

	if (window->KeyDown(VK_RIGHT))
	{
		nextState = RIGHT;

		if (currState == LEFT || currState == STOPED)
		{
			currState = RIGHT;
			Right();
		}
	}

	if (window->KeyDown(VK_UP))
	{
		nextState = UP;

		if (currState == DOWN || currState == STOPED)
		{
			currState = UP;
			Up();
		}
	}

	if (window->KeyDown(VK_DOWN))
	{
		nextState = DOWN;

		if (currState == UP || currState == STOPED)
		{
			currState = DOWN;
			Down();
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
	if (stateTime <= 0) {
		state = FLEE;
		stateTime = 5;
	}

}

// ---------------------------------------------------------------------------------

void Player::Draw()
{
	switch (currState)
	{
	case LEFT:  spriteL->Draw(x, y, Layer::MIDDLE); break;
	case RIGHT: spriteR->Draw(x, y, Layer::MIDDLE); break;
	case UP:    spriteU->Draw(x, y, Layer::MIDDLE); break;
	case DOWN:  spriteD->Draw(x, y, Layer::MIDDLE); break;
	default:
		switch (nextState)
		{
		case LEFT:  spriteL->Draw(x, y, Layer::MIDDLE); break;
		case RIGHT: spriteR->Draw(x, y, Layer::MIDDLE); break;
		case UP:    spriteU->Draw(x, y, Layer::MIDDLE); break;
		case DOWN:  spriteD->Draw(x, y, Layer::MIDDLE); break;
		default:    spriteL->Draw(x, y, Layer::MIDDLE);
		}
	}
}

// ---------------------------------------------------------------------------------
void Player::setScene(Scene* sc) {
	scene = sc;
}
// ---------------------------------------------------------------------------------