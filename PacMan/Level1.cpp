/**********************************************************************************
// Level1 (Código Fonte)
//
// Criação:     18 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nível 1 do jogo PacMan
//
**********************************************************************************/
#include <string>
#include <fstream>

#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "Player.h"
#include "Ghost.h"
#include "Pivot.h"
#include "Food.h"
#include "Special.h"
#include "Obstacle.h"
#include "GameOver.h"
using std::ifstream;
using std::string;

Scene* Level1::scene = nullptr;
// ------------------------------------------------------------------------------

void Level1::Init()
{
	// indica em qual tela está
	setGameState(LVL1);

	// cria gerenciador de cena
	scene = new Scene();

	backg = new Sprite("Resources/Level1Dark.png");

	// cria jogador
	player = new Player();
	scene->Add(player, MOVING);
	player->MoveTo(480.0f, 445.0f);
	player->setScene(scene);

	// cria inimigos no centro ( eixo Y = 365.0f )
	Ghost* ghost = new Ghost(player, 460.0f, 280.0f);
	scene->Add(ghost, MOVING);
	ghost = new Ghost(player, 435.0f, 370.0f, 10.0f, BLACK);
	scene->Add(ghost, MOVING);

	// cria pontos de mudança de direção
	Pivot* pivot;
	bool left, right, up, down;
	float posX, posY;

	// cria pivôs a partir do arquivo
	ifstream fin;
	fin.open("PivotsL1.txt");
	fin >> left;
	while (!fin.eof())
	{
		if (fin.good())
		{
			// lê linha de informações do pivô
			fin >> right; fin >> up; fin >> down; fin >> posX; fin >> posY;
			pivot = new Pivot(left, right, up, down);
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

	// cria comidas no mapa
	foodSprite = new Image("Resources/Food.png");
	specialSprite = new Image("Resources/Special.png");
	Food* food;
	Special* special = new Special(specialSprite);
	special->MoveTo(60.0f, 84.0f);
	scene->Add(special, STATIC);
	special = new Special(specialSprite);
	special->MoveTo(900.0f, 630.0f);
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
			scene->comidasTotais += 1;
		}
		else {
			fin.clear();
			char temp[80];
			fin.getline(temp, 80);
		}
		fin >> foodPosX;
	}

	fin.close();

	Obstacle* spiderweb = new Obstacle();
	spiderweb->MoveTo(155.0f, 356.0f);
	scene->Add(spiderweb, STATIC);
	spiderweb = new Obstacle();
	spiderweb->MoveTo(805.0F, 356.0f);
	scene->Add(spiderweb, STATIC);

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
		// passa manualmente para o próximo nível
		Engine::Next<Level2>();
	}
	else if (window->KeyDown('G'))
	{
		// passa manualmente para a tela de GameOver
		Engine::Next<GameOver>();
	}
	else
	{		
		// atualiza cena
		scene->Update();
		scene->CollisionDetection();
	}

	// COMANDOS DO PLAYER
	if (getGameState() == GAMEOVER) {
		Engine::Next<GameOver>();
	}

	if (scene->comidasTotais == 0) {
		// passa naturalmente para o próximo nível
		Engine::Next<Level2>();
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