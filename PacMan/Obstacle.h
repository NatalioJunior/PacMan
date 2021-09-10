/**********************************************************************************
// Food (Arquivo de Cabeçalho)
//
// Criação:     03 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Comida do PacMan
//
**********************************************************************************/

#ifndef _PACMAN_OBSTACLE_H_
#define _PACMAN_OBSTACLE_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "PacMan.h"


// ---------------------------------------------------------------------------------

class Obstacle : public Object
{
private:
	Sprite* sprite = nullptr;			// sprite da comida

public:
	Obstacle();                   // construtor
	~Obstacle();                            // destrutor


	void Update();                      // atualização do objeto
	void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Obstacle::Draw()
{
	sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------


#endif