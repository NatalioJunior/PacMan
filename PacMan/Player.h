/**********************************************************************************
// Player (Arquivo de Cabeçalho)
//
// Criação:     01 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Player do jogo PacMan
//
**********************************************************************************/

#ifndef _PACMAN_PLAYER_H_
#define _PACMAN_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "Scene.h"
// ---------------------------------------------------------------------------------
// Constantes Globais

// estados possíveis para o jogador
enum PLAYERMOVE { STOPED, UP, DOWN, LEFT, RIGHT };
enum PLAYESTATE { PURSUE, FLEE };

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
	Sprite* spriteL = nullptr;         // sprite do player indo para esquerda
	Sprite* spriteR = nullptr;         // sprite do player indo para direita
	Sprite* spriteU = nullptr;         // sprite do player indo para cima
	Sprite* spriteD = nullptr;         // sprite do player indo para baixo
	float velX = 0;                    // velocidade horizontal do player
	float velY = 0;                    // velocidade vertical do player

	static Scene* scene;			   // ponteiro para Scene

	int scoreP = 0;					   // contador de pontos do jogo

	float stateTime = 0;			   // cronômetro para passagem do efeito azul


public:
	uint state = FLEE;
	uint currState = STOPED;            // estado atual do jogador
	uint nextState = STOPED;            // próximo estado do jogador
	bool ctrlWeb = false;

	Player();                           // construtor
	Player(Scene* sc);                  // construtor
						
	~Player();                          // destrutor

	void Stop();                        // pára jogador
	void Up();                          // muda direção para cima
	void Down();                        // muda direção para baixo
	void Left();                        // muda direção para esquerda
	void Right();                       // muda direção para direita

	void OnCollision(Object* obj);			// resolução da colisão
	void PivotCollision(Object* obj);		// resolve colisão com pivô
	void foodCollision(Object* obj);		// resolve colisão com comida
	void specialCollision(Object* obj);		// resolve colisão com comida especial
	void ghostCollision(Object* obj);		//Colisao com ghost
	void ObstacleCollision(Object* obj);	//Colisao com ghost

	void Update();                      // atualização do objeto
	void Draw();                        // desenho do objeto

	void setScene(Scene* sc);

	inline void setScore(int score) {
		scoreP = score;
	
	}
	inline int getScore() {
		return scoreP;
		
	}

};

// ---------------------------------------------------------------------------------

#endif