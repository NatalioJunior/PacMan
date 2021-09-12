/**********************************************************************************
// Home (Código Fonte) 
// 
// Criação:     18 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de abertura do jogo PacMan
//
**********************************************************************************/

#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"

// ------------------------------------------------------------------------------

void Home::Init()
{

    setGameState(HOME);                                   // indica em qual tela está
    backg = new Sprite("Resources/Home.png");             //    Sprite a definir
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete backg;
}

// ------------------------------------------------------------------------------

void Home::Update()
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

    // passa ao primeiro nível 1 com ENTER
    if (ctrlKeyENTER && window->KeyDown(VK_RETURN))
    {
        ctrlKeyENTER = false;
        Engine::Next<Level1>();
    }
    else if (window->KeyUp(VK_RETURN))
    {
        ctrlKeyENTER = true;
    }

    // passa ao primeiro nível 2 com NUMPAD 1
    if (window->KeyDown(VK_NUMPAD1))
        Engine::Next<Level2>();
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}

// ------------------------------------------------------------------------------