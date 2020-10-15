#include <GL/glew.h>

#include "Geral.h"

PlayerObject player;//Representa uma instacia do objeto jogador
int const jumpSpeed = 9;//Velocidade inicial do pulo
int chao = 0;//Altura do chao no determinado momento
int standSize;//Altura do jogador em pe
int crouchSize;//Altura do jogador agachado
float const runTextChangeMultiplier = 0.05;
float runTextPos = 0;
GLuint playerRunningTex;
float jumpBuff = 0;


void loadPlayer(int x, int y, int larg, int alt, int crouch, float color[4]){
    initPlayer(&player,drawPlayerR);
    playerRunningTex = *playerRunTex;
    player.x = x;
    player.y = y;
    player.larg = larg;
    player.alt = alt;
    player.leftBorder = x - (larg/2) + PLAYER_TEXTURE_HITFIX;
    player.rightBorder = x + (larg/2) + PLAYER_TEXTURE_HITFIX;
    player.color[0]=color[0];
    player.color[1]=color[1];
    player.color[2]=color[2];
    player.color[3]=color[3];
    standSize = alt;
    crouchSize = crouch;
    player.TextId = &playerRunningTex;    
    
}
    
bool detectCollision(Obstaculo * o){
    if((player.rightBorder >= (o->x - o->larg/2)) && (player.leftBorder <= (o->x + o->larg/2))){//Define a area de colisao no eixo X
        if ((player.y <= (o->y + o->alt)) && ((player.y + player.alt) >= o->y ) ){//Define a area de colisao no eixo y
            return True;
        }
    }
    
    return False;
}

void jump(){ // Realiza o pulo do jogador 
    if (player.y == 0){//Somente pula caso o jogador esteja no chao
        objectJump(&(player.y),jumpSpeed,chao);   
    }
}

void crouch(){ //Agacha o jogador
    player.alt = crouchSize;
    player.TextId = &texturas[37]; 
    jumpBuff = -0.1;
}

void stand(){ //Levanta o jogador depois que ele agacha
    player.alt = standSize;
    player.TextId = &playerRunningTex; 
    jumpBuff = 0;
}

void playerRunTextureChange(){
    playerRunningTex = playerRunTex[(int)runTextPos];
    runTextPos += runTextChangeMultiplier;
    if(runTextPos >= PLAYER_TEXTURE_RUN_QTDE){
        runTextPos = 0;
    }
}