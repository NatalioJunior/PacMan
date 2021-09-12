// ---------------------------------------------------------------------------------
//CARLOS CAVEIRINHA
// TELA INICIAL DO JOGOS
// ---------------------------------------------------------------------------------


#ifndef CAVEIRINHA_HOME_H_
#define CAVEIRINHA_HOME_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
    Sprite * backg = nullptr;       // pano de fundo
    bool ctrlKeyESC = false;        // controle do ESC
    bool ctrlKeyENTER = false;      // controle do ENTER

public:

    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// -----------------------------------------------------------------------------

#endif