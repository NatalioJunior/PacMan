/**********************************************************************************
// Food (Código Fonte)
//
// Criação:     03 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Comida do PacMan
//
**********************************************************************************/

#include "Obstacle.h"

// ---------------------------------------------------------------------------------

Obstacle::Obstacle()
{
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
