/**********************************************************************************
// Level1 (C�digo Fonte)
//
// Cria��o:     18 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   N�vel 1 do jogo PacMan
//
**********************************************************************************/

#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "Player.h"
#include "Ghost.h"
#include "Pivot.h"
#include <string>
#include <fstream>
#include "Food.h"
#include "Special.h"
using std::ifstream;
using std::string;

Scene* Level1::scene = nullptr;
// ------------------------------------------------------------------------------

void Level1::Init()
{
	// cria gerenciador de cena
	scene = new Scene();

	// cria background
	backg = new Sprite("Resources/Level1.jpg");

	// cria jogador
	Player* player = new Player();
	scene->Add(player, MOVING);
	player->setScene(scene);

	// cria inimigos no centro ( eixo Y = 365.0f )
	Ghost* ghost = new Ghost(player, 460.0f, 365.0f);
	scene->Add(ghost, MOVING);
	ghost = new Ghost(player, 484.0f, 365.0f, BLACK);
	scene->Add(ghost, MOVING);
	ghost = new Ghost(player, 508.0f, 365.0f, PUMPKIN);
	scene->Add(ghost, MOVING);

	// cria pontos de mudan�a de dire��o
	Pivot* pivot;
	bool left, right, up, down;
	float posX, posY;

	// cria piv�s a partir do arquivo
	ifstream fin;
	fin.open("PivotsL1.txt");
	fin >> left;
	while (!fin.eof())
	{
		if (fin.good())
		{
			// l� linha de informa��es do piv�
			fin >> right; fin >> up; fin >> down; fin >> posX; fin >> posY;
			pivot = new Pivot(left, right, up, down);
			pivot->MoveTo(posX, posY);
			scene->Add(pivot, STATIC);
		}
		else
		{
			// ignora coment�rios
			fin.clear();
			char temp[80];
			fin.getline(temp, 80);
		}
		fin >> left;
	}
	fin.close();

	// cria comidas no mapa
	foodSprite = new Image("Resources/Food.png");
	specialSprite = new Image("Resources/Special.png");
	Food* food;
	Special* special = new Special(specialSprite);
	special->MoveTo(540, 271);
	scene->Add(special, STATIC);

	float foodPosX, foodPosY;
	fin.open("FoodL1.txt");
	fin >> foodPosX;
	while (!fin.eof()) {
		if (fin.good()) {
			fin >> foodPosY;
			food = new Food(foodSprite);

			food->MoveTo(foodPosX, foodPosY);
			scene->Add(food, STATIC);
		}
		else {
			fin.clear();
			char temp[80];
			fin.getline(temp, 80);
		}
		fin >> foodPosX;
	}

	fin.close();


	//160.0f e 449.0f
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
	delete backg;
	delete scene;
	delete foodSprite;
	delete specialSprite;
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
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
	else if (window->KeyDown('N'))
	{
		// passa manualmente para o pr�ximo n�vel
		//Engine::Next<Level2>();
	}
	else
	{
		// atualiza cena
		scene->Update();
		scene->CollisionDetection();
	}
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
	// desenha cena
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();

	// desenha bounding box dos objetos
	if (viewBBox)
		scene->DrawBBox();
}

// ------------------------------------------------------------------------------