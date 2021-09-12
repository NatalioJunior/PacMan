
#ifndef _PACMAN_WIN_H_
#define _PACMAN_WIN_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Win : public Game
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
