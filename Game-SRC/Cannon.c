#include "Geral.h"

GLuint specificCannonTex[CANNON_QTDE];
int textChangeCounter[CANNON_QTDE];

void cannonTextureChange(int cannonSelected);

void initCannons(){
    specificCannonTex[0] = *cannonTex;
    specificCannonTex[1] = *cannonTex;
    specificCannonTex[2] = *cannonTex;
    specificCannonTex[3] = *cannonTex;
}

void cannonFire(int cannonSelected){    
    textChangeCounter[cannonSelected] = 1;
    cannonTextureChange(cannonSelected);
}

void cannonTextureChange(int cannonSelected){
    if (textChangeCounter[cannonSelected] < CANNON_TEXTURE_QTDE){
        specificCannonTex[cannonSelected] = cannonTex[textChangeCounter[cannonSelected]];
        textChangeCounter[cannonSelected]++;
        glutTimerFunc(30,cannonTextureChange,cannonSelected);
    }else{
        specificCannonTex[cannonSelected] = *cannonTex;
        addObstaculo(MISSILE_SPAWN_POSX,(cannonSelected*MISSILE_POSY_MULTIPLIER),MISSILE_LARG,MISSILE_ALT,texturas[15]);
    }
}