/**********************************************************************************
// Food (C�digo Fonte)
//
// Cria��o:     03 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Comida do PacMan
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
