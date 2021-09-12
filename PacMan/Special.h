// ---------------------------------------------------------------------------------
//CARLOS CAVEIRINHA
// COMIDAS ESPECIAIS RESPONSAVEIS POR MUDAR O COMPORTAMENTO DOS FANTASMAS
// ---------------------------------------------------------------------------------

#ifndef CAVEIRINHA_SPECIAL_H_
#define CAVEIRINHA_SPECIAL_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "CarlosCaveirinha.h"


// ---------------------------------------------------------------------------------

class Special : public Object
{
private:
	Sprite* sprite = nullptr;			// sprite da comida

public:
	Special(Image* img);                // construtor
	~Special();                         // destrutor


	void Update();                      // atualização do objeto
	void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Special::Draw()
{
	sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------


#endif
