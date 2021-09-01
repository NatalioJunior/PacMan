#include "Engine.h"
#include "Home.h"
#include "LvlBase.h"
#include "Player.h"
#include "Pivot.h"
#include <string>
#include <fstream>
using std::ifstream;
using std::string;


void LvlBase::Init() {
	scene = new Scene();


	bg = new Sprite("Resources/lvl1noPivot.png");


	Player* p = new Player();
	scene->Add(p, MOVING);

	Pivot* pivot;
	bool left, right, top, down;
	float posX, posY;

	ifstream fin;

    fin.open("lvlBasePivots.txt");
    fin >> left;
    while (!fin.eof())
    {
        if (fin.good())
        {
            // lê linha de informações do pivô
            fin >> right; fin >> top; fin >> down; fin >> posX; fin >> posY;
            pivot = new Pivot(left, right, top, down);
            pivot->MoveTo(posX, posY);
            scene->Add(pivot, STATIC);
        }
        else
        {
            // ignora comentários
            fin.clear();
            char temp[80];
            fin.getline(temp, 80);
        }
        fin >> left;
    }
    fin.close();

}
void LvlBase::Finalize() {
    delete bg;
    delete scene;
}
void LvlBase::Update() {
    // habilita/desabilita bounding box
    if (ctrlKeyB && window->KeyDown('B'))
    {
        viewBBox = !viewBBox;
        ctrlKeyB = false;
    }
    else if (window->KeyUp('B'))
    {
        ctrlKeyB = true;
    }

    if (window->KeyDown(VK_ESCAPE))
    {
        // volta para a tela de abertura
        Engine::Next<Home>();
    }
    else
    {
        // atualiza cena
        scene->Update();
        scene->CollisionDetection();
    }
}
void LvlBase::Draw() {
    bg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
    scene->Draw();

    if (viewBBox)
        scene->DrawBBox();
}