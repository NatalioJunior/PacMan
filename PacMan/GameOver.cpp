
#include "Engine.h"
#include "GameOver.h"
#include "Home.h"

// ------------------------------------------------------------------------------

void GameOver::Init()
{

    setGameState(GAMEOVER);                                   // indica em qual tela está
    backg = new Sprite("");                                   // Sprite a definir
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

    // passa ao primeiro nível com ENTER
    if (window->KeyDown(VK_RETURN))
        Engine::Next<Home>();
}

// ------------------------------------------------------------------------------

void GameOver::Draw()
{
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}

// ------------------------------------------------------------------------------