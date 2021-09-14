// ---------------------------------------------------------------------------------
//CARLOS CAVEIRINHA
// PONTUAÇÃO DO NIVEL, SE COMER TODAS PASSA DE NIVEL
// ---------------------------------------------------------------------------------


#include "Food.h"

// ---------------------------------------------------------------------------------

Food::Food(Image* img)
{	//definindo imgem da comida e sua bb
	sprite = new Sprite(img);

	bbox = new Rect((float)-sprite->Width() / 2, (float)-sprite->Height() / 2, (float) sprite->Width() / 2, (float) sprite->Height() / 2);
	//tipo para verificar na colisao
	type = FOOD;
}

// ---------------------------------------------------------------------------------

Food::~Food()
{
	delete sprite;
	delete bbox;
}

// ---------------------------------------------------------------------------------

void Food::Update()
{

}

// ---------------------------------------------------------------------------------
