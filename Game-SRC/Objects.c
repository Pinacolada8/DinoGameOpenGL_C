
#include "Geral.h"



void initObstaculo(Obstaculo * o, void (*d)(int x, int y,int larg, int alt, GLuint idTextura)){
    (*o).draw = d;
}

void objectMoveX(Obstaculo * o,int x){//Realiza o movimento no eixo X
    (*o).x-= x;
}

void initPlayer(PlayerObject * o, void (*d)(int x, int y,int larg, int alt,GLuint idTextura)){    
    (*o).draw = d;
}

