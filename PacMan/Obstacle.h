// ---------------------------------------------------------------------------------
//CARLOS CAVEIRINHA
// OBJETOS QUE ATRAPA�HAM O PLAYER
// ---------------------------------------------------------------------------------


#ifndef CAVEIRINHA_OBSTACLE_H_
#define CAVEIRINHA_OBSTACLE_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "CarlosCaveirinha.h"


// ---------------------------------------------------------------------------------

class Obstacle : public Object
{
private:
	Sprite* sprite = nullptr;			// sprite da comida

public:
	Obstacle();                   // construtor
	~Obstacle();                            // destrutor


	void Update();                      // atualiza��o do objeto
	void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Obstacle::Draw()
{
	sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------


#endif