#include "Geral.h"


bool inGameMenuActive = False;


void activateInGameMenu(){
    inGameMenuActive = True;
    startPause();
    selectState(2);
}

void closeInGameMenu(){
    selectState(0);    
    inGameMenuActive = False;    
    endPause();     
}


