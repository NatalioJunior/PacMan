/**********************************************************************************
// Player (Arquivo de Cabe�alho)
//
// Cria��o:     01 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Player do jogo PacMan
//
**********************************************************************************/

#ifndef _PACMAN_PLAYER_H_
#define _PACMAN_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "Scene.h"
// ---------------------------------------------------------------------------------
// Constantes Globais

// estados poss�veis para o jogador
enum PLAYERMOVE { STOPED, UP, DOWN, LEFT, RIGHT };
enum PLAYESTATE { PURSUE, FLEE };
enum PLAYERCOMAND {NONE,NEXT,RESTART,HOME};

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

	static Scene* scene;

	int scoreP = 0;

	float stateTime = 0;


public:
	uint state = FLEE;
	uint currState = STOPED;            // estado atual do jogador
	uint nextState = STOPED;            // pr�ximo estado do jogador
	uint currentComand = NONE;

	Player();                           // construtor
	Player(Scene* sc);                  // construtor
						
	~Player();                          // destrutor

	void Stop();                        // p�ra jogador
	void Up();                          // muda dire��o para cima
	void Down();                        // muda dire��o para baixo
	void Left();                        // muda dire��o para esquerda
	void Right();                       // muda dire��o para direita

	void OnCollision(Object* obj);		// resolu��o da colis�o
	void PivotCollision(Object* obj);	// resolve colis�o com piv�
	void foodCollision(Object* obj);	// resolve colis�o com comida
	void specialCollision(Object* obj); // resolve colis�o com comida especial
	void ghostCollision(Object* obj); //Colisao com ghost


	void Update();                      // atualiza��o do objeto
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