#include "Geral.h"

float layerPos[SCENARIO_LAYER_QTDE];
const float scnarioSpeedMultiplier= 0.0001;

void initScenario(){
    int i;
    for (i=0;i<SCENARIO_LAYER_QTDE;i++) {
        layerPos[i]=0;
    }
}

void moveScenario(){
    int i;
    for (i=0;i<SCENARIO_LAYER_QTDE;i++) {
        layerPos[i]+=i*scnarioSpeedMultiplier;
        if(layerPos[i] >= 10000){
            layerPos[i] =0;
        }
    }
}


