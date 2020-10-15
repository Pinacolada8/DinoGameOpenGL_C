#include "StateController.h"

void drawGame(void) {
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    
    base(FLOOR_DEPTH,0,NULL);
    
    for(i=0;i<SCENARIO_LAYER_QTDE;i++){
        drawScenario(scenarioTex[i],layerPos[i]);
    }
    
    if((pause == True) && (inGameMenuActive == False)){
        drawNotificationSquare(PAUSE_POSX,PAUSE_POSY,PAUSE_BASE,PAUSE_ALT, texturas[0]);
    }
    
    if (derrota != False){
        drawNotificationSquare(MAX_X/2,MAX_Y/2,GAMEOVER_LARG,GAMEOVER_ALT, texturas[38]);
    }
  
    player.draw(player.x,player.y - PLAYER_TEXTURE_GROUND,PLAYER_TEXTURE_WIDTH,PLAYER_TEXTURE_HEIGHT,*(player.TextId));    
    
    drawRetangulo(CANNON_POSX,CANNON_POSY_1,CANNON_LARG,CANNON_ALT,specificCannonTex[0]);
    drawRetangulo(CANNON_POSX,CANNON_POSY_2,CANNON_LARG,CANNON_ALT,specificCannonTex[1]);
    drawRetangulo(CANNON_POSX,CANNON_POSY_3,CANNON_LARG,CANNON_ALT,specificCannonTex[2]);
    drawRetangulo(CANNON_POSX,CANNON_POSY_4,CANNON_LARG,CANNON_ALT,specificCannonTex[3]);
    
    for(i =0;i<quantidadeObstaculos;i++){//Desenha os obstaculos
        obstaculos[i].draw(obstaculos[i].x,obstaculos[i].y,obstaculos[i].larg,obstaculos[i].alt,obstaculos[i].TextId);  
    }
    
    drawRelogio(TIMER_POSX,TIMER_POSY,getTimer());
    drawLives(LIVES_POSX,LIVES_POSY,lives);
    drawScore(SCORE_POSX, SCORE_POSY,distaciaPercorrida);   
    

    if(inGameMenuActive == True){
        drawNotificationSquare(INGAMEMENU_POSX,INGAMEMENU_POSY,INGAMEMENU_BASE,INGAMEMENU_ALT, texturas[1]);
    }
    
  
    
    glDisable(GL_TEXTURE_2D); 
    glutSwapBuffers();
    
}

void selectGameState(){
    glutDisplayFunc(drawGame);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(specialKeysPress);
    glutSpecialUpFunc(specialKeysRelease);    
}