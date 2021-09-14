// ---------------------------------------------------------------------------------
//CARLOS CAVEIRINHA
// TELA DE GAME OVER APOS SER MORTO POR UM FANTASMA
// ---------------------------------------------------------------------------------

#include "Engine.h"
#include "GameOver.h"
#include "Home.h"

// ------------------------------------------------------------------------------

void GameOver::Init()
{

    setGameState(GAMEOVER);                                   // indica em qual tela est�
    backg = new Sprite("Resources/GameOver.jpg");             // Sprite
}

// ------------------------------------------------------------------------------

void GameOver::Finalize()
{
    delete backg;
}

// ------------------------------------------------------------------------------

void GameOver::Update()
{
    // sai do jogo com a tecla ESC
    if (ctrlKeyESC && window->KeyDown(VK_ESCAPE))
    {
        ctrlKeyESC = false;
        window->Close();
    }
    else if (window->KeyUp(VK_ESCAPE))
    {
        ctrlKeyESC = true;
    }

    // passa ao primeiro n�vel com ENTER
    if (window->KeyDown(VK_RETURN))
        Engine::Next<Home>();
}

// ------------------------------------------------------------------------------

void GameOver::Draw()
{
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}

// ------------------------------------------------------------------------------