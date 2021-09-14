// ---------------------------------------------------------------------------------
//CARLOS CAVEIRINHA
// TELA  DE WIN
// ---------------------------------------------------------------------------------

#ifndef CAVEIRINHA_WIN_H_
#define CAVEIRINHA_WIN_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Win : public Game
{
private:
    Sprite* backg = nullptr;        // pano de fundo
    bool ctrlKeyESC = false;        // controle do ESC

public:

    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// -----------------------------------------------------------------------------

#endif