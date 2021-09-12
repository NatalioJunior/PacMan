
#include "Engine.h"
#include "Win.h"
#include "Home.h"

// ------------------------------------------------------------------------------

void Win::Init()
{

    setGameState(WIN);                                   // indica em qual tela está
    backg = new Sprite("");                              // Sprite a definir
}

// ------------------------------------------------------------------------------

void Win::Finalize()
{
    delete backg;
}

// ------------------------------------------------------------------------------

void Win::Update()
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

void Win::Draw()
{
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}

// ------------------------------------------------------------------------------