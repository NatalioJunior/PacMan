// ---------------------------------------------------------------------------------
//CARLOS CAVEIRINHA
// TELA INICIAL DO JOGOS
// ---------------------------------------------------------------------------------


#ifndef CAVEIRINHA_HOME_H_
#define CAVEIRINHA_HOME_H_

// ------------------------------------------------------------------------------
// Inclus�es

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

    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// -----------------------------------------------------------------------------

#endif