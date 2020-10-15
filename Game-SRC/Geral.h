/*
 * File:   Prototypes.h
 */

//Este Arquivo contem os Includes Globais do prjeto
#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

//#include <SDL2/SDL.h>
//#include <SDL2/SDL_mixer.h>


#include "Objects.h"
//-------------------------

//Constantes universais
#define ASPECT_RATIO 1.777777778 //proporcao da tela
#define MAX_X  1600 // Valor maximo de unidades na direcao X
#define MAX_Y  820 // Valor maximo de unidades na direcao Y(sem contar com a profundidade do chao)
#define FLOOR_DEPTH 80 //Profundidade do chao do jogo
#define TICK_MSEC 7.8125 //Tempo em milisegundos em que devemos chamar a funcao para obter um tickrate de 128;
#define DIFFICULTYMULTIPLIER 10 // Multiplicador de dificuldade

#define SCORE_NUMBERHOUSES 12 // Quantidade de casas do numero de score
#define SCORE_POSX 1000 //Posicao X da Pontuacao
#define SCORE_POSY 650 //Posicao Y da Pontuacao

#define TIMER_POSX 600 //Posicao X do timer
#define TIMER_POSY 650 //Posicao Y do Relogio

#define LIVES_POSX 800 //Posicao X das Vidas
#define LIVES_POSY 650 //Posicao Y das Vidas

#define PAUSE_POSX 800 //Posicao X do pause
#define PAUSE_POSY 300 //Posicao Y do pause
#define PAUSE_BASE 300 // Tamanho da base da imagem do pause
#define PAUSE_ALT 300 // Tamanho da altura da imagem do pause

#define INGAMEMENU_POSX 800 //Posicao X do in game menu
#define INGAMEMENU_POSY 300 //Posicao Y do in game menu
#define INGAMEMENU_BASE 300 // Tamanho da base da imagem do in game menu
#define INGAMEMENU_ALT 300 // Tamanho da altura da imagem do in game menu
#define INGAMEMENU_BUTTON_WIDTH 226 //Largura dos botoes do in game menu
#define INGAMEMENU_BUTTON_HEIGHT 36 //Altura dos botoes do in game menu
#define INGAMEMENU_BUTTON_POSX (149 + INGAMEMENU_POSX - (INGAMEMENU_BASE/2)) // Posicao X de todos os botoes
#define INGAMEMENU_BUTTON_CONTINUAR (202 + INGAMEMENU_POSY - (INGAMEMENU_ALT/2)) //Posicao Y do botao
#define INGAMEMENU_BUTTON_RESTART (148 + INGAMEMENU_POSY - (INGAMEMENU_ALT/2)) //Posicao Y do  botao
#define INGAMEMENU_BUTTON_MAINMENU (94 + INGAMEMENU_POSY - (INGAMEMENU_ALT/2)) //Posicao Y do botao
#define INGAMEMENU_BUTTON_EXIT (40 + INGAMEMENU_POSY - (INGAMEMENU_ALT/2)) //Posicao Y do botao

#define GAMEMENU_BUTTON_WIDTH 340 //Largura dos botoes do game menu
#define GAMEMENU_BUTTON_HEIGHT 54 //Altura dos botoes do game menu
#define GAMEMENU_BUTTON_POSX 800 // Posicao X de todos os botoes
#define GAMEMENU_BUTTON_START (MAX_Y - 340) //Posicao Y do botao
#define GAMEMENU_BUTTON_HIGHSCORES (MAX_Y - 420) //Posicao Y do  botao
#define GAMEMENU_BUTTON_CREDITS (MAX_Y - 502) //Posicao Y do botao
#define GAMEMENU_BUTTON_OPCOES (MAX_Y - 582) //Posicao Y do botao
#define GAMEMENU_BUTTON_EXIT (MAX_Y - 660) //Posicao Y do botao

#define OPTION_BUTTON_WIDTH 342 //Largura dos botoes do option menu
#define OPTION_BUTTON_HEIGHT 54 //Altura dos botoes do option menu
#define OPTION_BUTTON_VOLTAR_POSX 1258 // Posicao X do botao de voltar
#define OPTION_BUTTON_VOLTAR_POSY (MAX_Y - 716) // Posicao Y do botao de voltar
#define OPTION_DIFICULDADE_POSX 498 //Posicao X dos botoes de dificuldade
#define OPTION_RESOLUCAO_POSX 1072//Posicao X dos botoes de dificuldade
#define OPTION_BUTTON_POSY_1 (538 - FLOOR_DEPTH)//Posicao Y dos botoes 1
#define OPTION_BUTTON_POSY_2 (456 - FLOOR_DEPTH)//Posicao Y dos botoes 2
#define OPTION_BUTTON_POSY_3 (374 - FLOOR_DEPTH)//Posicao Y dos botoes 3
#define OPTION_BUTTON_POSY_4 (294 - FLOOR_DEPTH)//Posicao Y dos botoes 4

#define PLAYER_POSX 300 //Posicao X do Player
#define PLAYER_POSY 0 //Posicao Y do Player
#define PLAYER_LARG 150 //Largura do Player
#define PLAYER_ALT 160 // Altura do Player
#define PLAYER_CROUCH 100 //Altura do Player agachado
#define PLAYER_TEXTURE_HITFIX (-38) //Tamanho para consertar o hitcode do jogador
#define PLAYER_TEXTURE_HEIGHT 200 //Altura da textura do jogador
#define PLAYER_TEXTURE_WIDTH 288 //Largura da textura do jogador
#define PLAYER_TEXTURE_GROUND 40  //Chao da textura do jogador
#define PLAYER_TEXTURE_RUN_QTDE 8 //Quantidade de texturas da corrida do jogador

#define MISSILE_ALT 100 //Altura do missel
#define MISSILE_LARG 86 //Largura do missel
#define MISSILE_SPAWN_POSX 1480//Posica X de spawn do Missel
#define MISSILE_POSY_MULTIPLIER 101 //Multiplicador dos pontos de spawn dos misseis

#define CANNON_LARG 190 //Lagura da textura de um canhao
#define CANNON_ALT 100 //Altura da textura de um canhao
#define CANNON_POSX 1505 //Posicao X dos canhoes
#define CANNON_POSY_1 0 //Posicao Y do canhao 1
#define CANNON_POSY_2 101 //Posicao Y do canhao 2
#define CANNON_POSY_3 202 //Posicao Y do canhao 3
#define CANNON_POSY_4 303 //Posicao Y do canhao 4
#define CANNON_QTDE 4 //Quantidade de canhoes
#define CANNON_TEXTURE_QTDE 13 //Quantidade de texturas que formam o canhao

#define SCENARIO_LAYER_QTDE 11 //Quantidade de texturas que formam o canhao
#define SCENARIO_PHEIGHT 0.773 //Porcentagem do tamanho utilizado na altura das texturas

#define SHOWMENU_BUTTON_WIDHT 342 //Largura dos botoes dos creditos e Highscores
#define SHOWMENU_BUTTON_HEIGHT 54 //Altura dos botoes dos creditos e Highscores
#define SHOWMENU_BUTTON_POSX 1258 // Posicao X do botao de voltar
#define SHOWMENU_BUTTON_POSY (MAX_Y - 716) // Posicao Y do botao de voltar

#define GAMEOVER_LARG 1000 //largura do gameover
#define GAMEOVER_ALT 708 //Altura do gameover


//-------------------------

//Cria um tipo que representa uma funcao que tem como parametros void e retorna void
typedef void (*function)(void);
//-------------------------

//Cria um tipo Boolean em C
typedef enum { False = 0, True = !False } bool;
//-------------------------

//Prototypes dos outros arquivos
//Inputs
float mouseFixX(int x);
float mouseFixY(int y);
void teclado(unsigned char key, int x, int y);
void specialKeysPress(int key,int x,int y);
void specialKeysRelease(int key,int x,int y);
//Desenhos
void base(int alt,int idTexture,float **pos);
void drawRetangulo(int x, int y,int larg, int alt, GLuint idTextura);
void drawPlayerR(int x, int y, int larg, int alt, GLuint idTexture);
void drawRelogio(int x,int y,unsigned long int relog);
void drawNotificationSquare(int x, int y,int base,int alt, GLuint textID);
void drawLives(int x, int y, int vidas);
void drawScore(int x, int y,double score);
void drawFullScreen(GLuint idTextura);
void drawScenario(GLuint idTextura,float texPos);
//Textures
void load_allTextures ();
//Scenario
void initScenario();
void moveScenario();
//Objects
void initObstaculo(Obstaculo * o, void (*d)(int x, int y,int larg, int alt, GLuint idTextura));
void initPlayer(PlayerObject * o, void (*d)(int x, int y,int larg, int alt,GLuint idTextura));
//GameLogic
void startPause();
void endPause();
void tick(int i);
void loadGame();
void restartGame();
void fPause();
void endGame();
//Obstacles
void randomObstacleGenerator();
void addObstaculo(int x, int y,int larg, int alt, GLuint idTextura);
void removeObstaculo(int pos);
void moveObstaculos();
//Player
void playerRunTextureChange();
void loadPlayer(int x, int y, int larg, int alt, int crouch, float color[4]);
void jump();
void crouch();
void stand();
bool detectCollision(Obstaculo * o);
//Physics
void objectJump(int * objectPos,int startSpeed,int floor);
//Timer
void setAlarm(function F ,int remainingSeg);
void removeAlarm(int pos);
unsigned long int getTimer();
void setTimer(unsigned long int t);
void resetTimer();
void startTimer();
void pauseTimer();
void initTimer();
//Texto
void texto(void* font, char* s, float x, float y);
//PowerUp_invulnerability
void invulnerability();
void endInvulnerability();
//Scores
void loadScores();
//Wait
void wait(int ticks,function f);
void nullFunc();
//InGameMenu
void activateInGameMenu();
//States
void selectState(int selection);
void closeInGameMenu();
//Cannon
void cannonFire(int cannonSelected);
void initCannons();
//Sounds
void initSounds();
//-------------------------

// Contem as Variaveis Globais Universais utilizadas(Compartilhadas entre arquivos)
//Main
extern int RESOLUTION_WIDTH;
extern int RESOLUTION_HEIGHT;
extern bool pause;
//Texturas
extern GLuint texturas[];
extern GLuint * cannonTex;
extern GLuint * scenarioTex;
extern GLuint * playerRunTex;
//GameLogic
extern float const tickFreq;
extern int lives;
extern bool derrota;
extern int difficultyPercentage;
extern int maxObstaculos;
extern int difficulty;
//Obstacles
extern Obstaculo * obstaculos;
extern int quantidadeObstaculos;
//Player
extern PlayerObject player;
extern GLuint * playerTex;
extern float jumpBuff;
//Physics
extern function jumping;
//PowerUp_invulnerability
extern bool invulnerable;
//InGameMenu
extern bool inGameMenuActive;
//Scores
extern double distaciaPercorrida;
//Texto
extern const float defaultColorTexto[4];
//Cannon
extern GLuint specificCannonTex[CANNON_QTDE];
//Scenario
extern float layerPos[SCENARIO_LAYER_QTDE];
//-------------------------
