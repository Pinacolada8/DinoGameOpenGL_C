#include <GL/glew.h>

#include "Geral.h"

#define QUANTIDADE_TEXTURAS 40 // Quantidade total de texturas utilizadas pelo programa
#define CANNON_STARTPOINT 2 //Onde comeca as texturas de canhao no vetor de enderecos de textura
#define SCENARIO_STARTPOINT 17 //Onde comeca as texturas do cenario no vetor de enderecos de textura
#define PLAYER_STARTPOINT 29 //Onde comeca as texturas do player no vetor de enderecos de textura



const char * paths [] = {//Local das texturas
    "GameResources/Textures/pause.png",             //0 -- Textura do Pause
    "GameResources/Textures/InGameMenu.png",        //1 -- Textura do In Game Menu
    "GameResources/Textures/Cannons/Cannon0.png",   //2 -- Textura do canhao
    "GameResources/Textures/Cannons/Cannon1.png",   //3 -- Textura do canhao
    "GameResources/Textures/Cannons/Cannon2.png",   //4 -- Textura do canhao
    "GameResources/Textures/Cannons/Cannon3.png",   //5 -- Textura do canhao
    "GameResources/Textures/Cannons/Cannon4.png",   //6 -- Textura do canhao
    "GameResources/Textures/Cannons/Cannon5.png",   //7 -- Textura do canhao
    "GameResources/Textures/Cannons/Cannon6.png",   //8 -- Textura do canhao
    "GameResources/Textures/Cannons/Cannon7.png",   //9 -- Textura do canhao
    "GameResources/Textures/Cannons/Cannon8.png",   //10 -- Textura do canhao
    "GameResources/Textures/Cannons/Cannon9.png",   //11 -- Textura do canhao
    "GameResources/Textures/Cannons/Cannon10.png",  //12 -- Textura do canhao
    "GameResources/Textures/Cannons/Cannon11.png",  //13 -- Textura do canhao
    "GameResources/Textures/Cannons/Cannon12.png",  //14 -- Textura do canhao
    "GameResources/Textures/Cannons/Missile.png",   //15 -- Textura do Missel
    "GameResources/Textures/Menu.png",              //16 -- Textura do Menu
    "GameResources/Textures/Scenario/Layer_0010.png",   //17 -- Textura do Scenario
    "GameResources/Textures/Scenario/Layer_0009.png",   //18 -- Textura do Scenario
    "GameResources/Textures/Scenario/Layer_0008.png",   //19 -- Textura do Scenario
    "GameResources/Textures/Scenario/Layer_0007.png",   //20 -- Textura do Scenario
    "GameResources/Textures/Scenario/Layer_0006.png",   //21 -- Textura do Scenario
    "GameResources/Textures/Scenario/Layer_0005.png",   //22 -- Textura do Scenario
    "GameResources/Textures/Scenario/Layer_0004.png",   //23 -- Textura do Scenario
    "GameResources/Textures/Scenario/Layer_0003.png",   //24 -- Textura do Scenario
    "GameResources/Textures/Scenario/Layer_0002.png",   //25 -- Textura do Scenario
    "GameResources/Textures/Scenario/Layer_0001.png",   //26 -- Textura do Scenario
    "GameResources/Textures/Scenario/Layer_0001.png",   //27 -- Textura do Scenario
    "GameResources/Textures/Credits.png",               //28 -- Textura dos Creditos
    "GameResources/Textures/Player/Run (1).png",        //29 -- Textura do Player
    "GameResources/Textures/Player/Run (2).png",        //30 -- Textura do Player
    "GameResources/Textures/Player/Run (3).png",        //31 -- Textura do Player
    "GameResources/Textures/Player/Run (4).png",        //32 -- Textura do Player
    "GameResources/Textures/Player/Run (5).png",        //33 -- Textura do Player
    "GameResources/Textures/Player/Run (6).png",        //34 -- Textura do Player
    "GameResources/Textures/Player/Run (7).png",        //35 -- Textura do Player
    "GameResources/Textures/Player/Run (8).png",        //36 -- Textura do Player
    "GameResources/Textures/Player/Crouch.png",         //37 -- Textura do Player
    "GameResources/Textures/GameOver.png",              //38 -- Textura do Game Over
    "GameResources/Textures/Options.png"                //39 -- Textura das Opcoes
};


GLuint texturas[QUANTIDADE_TEXTURAS];    // id das texturas
GLuint * cannonTex = &texturas[CANNON_STARTPOINT];//Ponteiro para o inicio das texturas de canhao
GLuint * scenarioTex = &texturas[SCENARIO_STARTPOINT];//Ponteiro para o inicio das texturas do cenario
GLuint * playerRunTex = &texturas[PLAYER_STARTPOINT];//Ponteiro para o inicio das texturas do player correndo


GLuint load_texture(const char path[]) {
    GLuint id;
    printf("%s\n",path);
    
  id = SOIL_load_OGL_texture(
    path,
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );

  if (id == 0) {
    printf("Erro carregando textura: '%s'\n", SOIL_last_result());
  }
  return id;
}

void load_allTextures (){
    int i;
    for (i=0;i<QUANTIDADE_TEXTURAS;i++){
        texturas[i] = load_texture(paths[i]);
    }
   
}