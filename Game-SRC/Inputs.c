
//Define que faz parte do pacote
#include "Geral.h"

//Controla todo o input do jogo

void teclado(unsigned char key, int x, int y) {
    switch (key) {
        // Tecla ESC
        case 27:
            activateInGameMenu();               
            break;
           
        case 'P':
        case 'p':
            fPause();
            break;
            
        case ' ':            
            jump();           
            break;
           
        case 'r':
        case 'R':
            restartGame();
            break;
            
        case 'g':
            //cannonFire(0);//Para fim de testes apenas
            break;
            
        default:
            break;
    }
}

void specialKeysPress(int key,int x,int y){
    switch(key){
        case GLUT_KEY_UP:
            jump();
            break;
            
        case GLUT_KEY_DOWN:
            crouch();
            break;           
     
        default:
            break;
    }               
}

void specialKeysRelease(int key,int x,int y){
    switch(key){        
        case GLUT_KEY_DOWN:
            stand();
            break;
            
        default:
            break;
    }   

}

float mouseFixX(int x){//Conserta a posicao do mouse em relacao ao glOrtho em qualquer resolucao
    return ((float)x * ((float)MAX_X/RESOLUTION_WIDTH));
}

float mouseFixY(int y){//Conserta a posicao do mouse em relacao ao glOrtho em qualquer resolucao
    return ((float)MAX_Y - ((float)y * ((float)(MAX_Y+FLOOR_DEPTH)/RESOLUTION_HEIGHT)));
}