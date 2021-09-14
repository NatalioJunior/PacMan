// ---------------------------------------------------------------------------------
//CARLOS CAVEIRINHA
// TELA DE GAMEOVER
// ---------------------------------------------------------------------------------

#ifndef CAVEIRINHA_GAMEOVER_H_
#define CAVEIRINHA_GAMEOVER_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class GameOver : public Game
{
private:
    Sprite* backg = nullptr;        // pano de fundo
    bool ctrlKeyESC = false;        // controle do ESC

public:

    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// -----------------------------------------------------------------------------

#endif