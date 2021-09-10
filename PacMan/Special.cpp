
#include "Special.h"

// ---------------------------------------------------------------------------------

Special::Special(Image* img)
{
	sprite = new Sprite(img);

	bbox = new Rect((float)-sprite->Width() / 2, (float)-sprite->Height() / 2, (float)sprite->Width() / 2, (float)sprite->Height() / 2);
	type = SPECIAL;
}

// ---------------------------------------------------------------------------------

Special::~Special()
{
	delete sprite;
	delete bbox;
}

// ---------------------------------------------------------------------------------

void Special::Update()
{

}

// ---------------------------------------------------------------------------------
