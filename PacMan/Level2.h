/**********************************************************************************
// Level2 (Arquivo de Cabeçalho)
// 
// Criação:     18 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nível 2 do jogo PacMan
//
**********************************************************************************/

#ifndef _PACMAN_LEVEl2_H_
#define _PACMAN_LEVEL2_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"

// ------------------------------------------------------------------------------

class Level2 : public Game
{
private:
    Sprite* backg = nullptr;       // background
    Image* foodSprite = nullptr;   // comidas
    Image* specialSprite = nullptr; // comidas especiais

    Player* player = nullptr;

    bool viewBBox = false;          // habilita visualização da bounding box
    bool ctrlKeyB = false;          // controle da tecla B

public:
    static Scene* scene;          // gerenciador de cena
    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
    void nextLvl();
    void restartLvl();
    void home();

};

// -----------------------------------------------------------------------------

#endif