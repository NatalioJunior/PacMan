
// ---------------------------------------------------------------------------------
//CARLOS CAVEIRINHA
//OBJETOS RESPONSAVEIS POR ATRAPALHAR A VIDA DO PLAYER
// ---------------------------------------------------------------------------------


#include "Obstacle.h"

// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------

Obstacle::Obstacle()
{
	//CRIA SPRITE E BB
	sprite = new Sprite("Resources/SpiderWeb.png");

	bbox = new Rect((float)-sprite->Width() / 2, (float)-sprite->Height() / 2, (float)sprite->Width() / 2, (float)sprite->Height() / 2);
	type = OBSTACLE;
}

// ---------------------------------------------------------------------------------

Obstacle::~Obstacle()
{
	delete sprite;
	delete bbox;
}

// ---------------------------------------------------------------------------------

void Obstacle::Update()
{

}

// ---------------------------------------------------------------------------------
