#ifndef _PACMAN_LVLBASE_H_
#define _PACMAN_LVLBASE_H_


#include "Game.h"
#include "Sprite.h"
#include "Scene.h"


//Definindo Classe

class LvlBase : public Game
{

private:
    Sprite* bg = nullptr;       // background
    Scene* scene = nullptr;       // gerenciado de cena

    bool viewBBox = false;          // habilita visualização da bounding box
    bool ctrlKeyB = false;

public:

    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();


};



#endif

