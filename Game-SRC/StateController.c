#include "StateController.h"

function states[] = {//Estados do jogo
    selectGameState,    //0 -- Estado do jogo
    selectMenuState,    //1 -- Estado do Menu
    selectInGameMenuState, //2 -- Estado In Game Menu
    selectCreditsState,  //3 -- Credits State
    selectOptionState       //4 -- Option State
};

void selectState(int selection){ 
    (*states[selection])();
}