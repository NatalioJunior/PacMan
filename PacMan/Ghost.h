/**********************************************************************************
// Ghost (Arquivo de Cabeçalho)
// 
// Criação:     01 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Fantasmas do PacMan
//
**********************************************************************************/

#ifndef _PACMAN_GHOST_H_
#define _PACMAN_GHOST_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "Player.h"                     // jogador do PacMan

// ---------------------------------------------------------------------------------
// Constantes Globais

// estados possíveis para os inimigos;
enum ENEMYTYPE  { BLACK, WHITE, PUMPKIN };

class Ghost : public Object
{
private:
    Sprite* fleeL = nullptr;            // sprite de fuga do inimigo
    Sprite* fleeR = nullptr;            // sprite de fuga do inimigo
    Sprite* fleeU = nullptr;            // sprite de fuga do inimigo
    Sprite* fleeD = nullptr;            // sprite de fuga do inimigo

    Sprite * spriteL = nullptr;         // sprite do inimigo
    Sprite* spriteR = nullptr;          // sprite do inimigo
    Sprite* spriteU = nullptr;          // sprite do inimigo
    Sprite* spriteD = nullptr;          // sprite do inimigo
    Player * player = nullptr;          // ponteiro para jogador
    float distX = 0;                    // distância do inimigo em relação ao jogador pelo eixo X
    float distY = 0;                    // distância do inimigo em relação ao jogador pelo eixo Y

public:
    float stateTime = 0;                // cronômetro para saída do fantasma do covil
    bool gameStart = false;             // indica se o jogo já começou
    float velX = 0;                     // velocidade horizontal
    float velY = 0;                     // velocidade vertical

    uint state = PURSUE;                // estado de movimentos do inimigo em relação ao jogador
    uint currentMove = STOPED;          // movimento atual do inimigo
    uint nextMove = STOPED;             // próximo movimento do inimigo

    Ghost(Player* p, float X, float Y, float time = 0, uint enemy = WHITE);       // construtor
    ~Ghost();                                                                 // destrutor

    void Stop();                        // pára jogador
    void Up();                          // muda direção para cima
    void Down();                        // muda direção para baixo
    void Left();                        // muda direção para esquerda
    void Right();                       // muda direção para direita

    void OnCollision(Object* obj);		// resolução da colisão
    void PivotCollision(Object* obj);	// resolve colisão com pivô
    void GhostCollision(Object* obj);	// Colisao com ghost

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif