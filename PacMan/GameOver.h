// ---------------------------------------------------------------------------------
//CARLOS CAVEIRINHA
// TELA DE GAMEOVER
// ---------------------------------------------------------------------------------

#ifndef CAVEIRINHA_GAMEOVER_H_
#define CAVEIRINHA_GAMEOVER_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class GameOver : public Game
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