// ---------------------------------------------------------------------------------
//CARLOS CAVEIRINHA
// SEGUNDO LEVEL JOGAVEL E UM POUCO MAIS DIFICIL
// ---------------------------------------------------------------------------------

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
#include "Win.h"
using std::ifstream;
using std::string;

Scene* Level2::scene = nullptr;
// ------------------------------------------------------------------------------

void Level2::Init()
{
	// indica em qual tela está
	setGameState(LVL2);

	// cria gerenciador de cena
	scene = new Scene();

	backg = new Sprite("Resources/Level2Blue.png");

	// cria jogador
	player = new Player();
	scene->Add(player, MOVING);
	player->MoveTo(479.0f, 420.0f);
	player->setScene(scene);

	// cria inimigos no centro ( eixo Y = 365.0f )
	Ghost* ghost = new Ghost(player, 460.0f, 280.0f);
	scene->Add(ghost, MOVING);
	ghost = new Ghost(player, 434.0f, 360.0f, 10.0f, BLACK);
	scene->Add(ghost, MOVING);

	// cria pontos de mudança de direção
	Pivot* pivot;
	bool left, right, up, down;
	float posX, posY;

	// cria pivôs a partir do arquivo
	ifstream fin;
	fin.open("PivotsL2.txt");
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
	special->MoveTo(156.0f, 320.0f);
	scene->Add(special, STATIC);
	special = new Special(specialSprite);
	special->MoveTo(804.0f, 390.f);
	scene->Add(special, STATIC);

	float foodPosX, foodPosY;
	fin.open("FoodL2.txt");
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
	spiderweb->MoveTo(240.0f, 355.0f);
	scene->Add(spiderweb, STATIC);
	spiderweb = new Obstacle();
	spiderweb->MoveTo(720.0f, 355.0f);
	scene->Add(spiderweb, STATIC);

}

// ------------------------------------------------------------------------------

void Level2::Finalize()
{
	delete backg;
	delete scene;
	delete foodSprite;
	delete specialSprite;
}

// ------------------------------------------------------------------------------

void Level2::Update()
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
	else if (window->KeyDown('G'))
	{
		// passa manualmente para o GameOver
		Engine::Next<GameOver>();
	}
	else if (window->KeyDown('W'))
	{
		// passa manualmente para o Congratulations
		Engine::Next<Win>();
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
		// finaliza o game
		Engine::Next<Win>();
	}
}

// ------------------------------------------------------------------------------

void Level2::Draw()
{
	// desenha cena
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();

	// desenha bounding box dos objetos
	if (viewBBox)
		scene->DrawBBox();

}

// ------------------------------------------------------------------------------