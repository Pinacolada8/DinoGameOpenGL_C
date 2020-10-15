#include "Geral.h"

Obstaculo * obstaculos;
int quantidadeObstaculos=0;

void generateObstacleTypes(int type);


void addObstaculo(int x, int y,int larg, int alt, GLuint idTextura){//Adiciona um obstaculo
    if (quantidadeObstaculos == maxObstaculos){
        return;
    }
    initObstaculo(&obstaculos[quantidadeObstaculos],drawRetangulo);
    obstaculos[quantidadeObstaculos].alt=alt;
    obstaculos[quantidadeObstaculos].larg=larg;
    obstaculos[quantidadeObstaculos].x=x;
    obstaculos[quantidadeObstaculos].y=y;
    obstaculos[quantidadeObstaculos].TextId = idTextura;

    quantidadeObstaculos++;
}

void removeObstaculo(int pos){//Remove o obstaculo na posicao "pos"
    int i;
    for (i=pos;i<quantidadeObstaculos-1;i++){
        obstaculos[i].x = obstaculos[i+1].x;
        obstaculos[i].y = obstaculos[i+1].y;
        obstaculos[i].alt = obstaculos[i+1].alt;
        obstaculos[i].larg = obstaculos[i+1].larg;
        obstaculos[i].draw = obstaculos[i+1].draw;
    }
    quantidadeObstaculos--;
}

void moveObstaculos(){//Move o obstaculo
    int i;
    for (i=0;i<quantidadeObstaculos;i++){
        obstaculos[i].x -= difficulty;
        if (obstaculos[i].x + obstaculos[i].larg/2 < 0){
            removeObstaculo(i);
        }
    }

}

void randomObstacleGenerator(){//Gera um obstaculo aleatoriamente     
    if((rand()%101) < difficultyPercentage){        
        generateObstacleTypes(rand()%4);
    }
}

void generateObstacleTypes(int type){    
    switch (type){
        case 0:
            cannonFire(0);
            break;
        case 1:
            cannonFire(0);
            cannonFire(1);
            break;
        case 2:
            cannonFire(2);
            cannonFire(3);
            break;
        case 3:
            cannonFire(1);
            cannonFire(2);
            cannonFire(3);
            break;         
        default:
            break;
    }
}