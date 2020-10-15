#include "Geral.h"

float const gravityAcceleration = 14; // Representa a aceleracao da gravidade
int * extObjectPos;
float speed;
int extChao;

function jumping = nullFunc;

void jumpLoop();

void objectJump(int * objectPos,int startSpeed,int chao){
    extObjectPos = objectPos;    
    speed = (float)startSpeed;
    extChao = chao;
    
    //jumpLoop(1);//OLD CODE, Esta aqui caso aconteca algum Bug com o codigo novo
    
    jumping = jumpLoop;
}


/*OLD CODE, Esta aqui caso aconteca algum Bug com o codigo novo
void jumpLoop(int t){    
    *extObjectPos += speed;
    speed -= gravityAcceleration * (float)(1/tickFreq); //MRUV        
    
    if (*extObjectPos > extChao){
        glutTimerFunc(TICK_MSEC,jumpLoop,1);        
    }else{
        *extObjectPos = extChao;        
    } 
}
 */

void jumpLoop(){    
    *extObjectPos += speed + jumpBuff;
    speed -= gravityAcceleration * (float)(1/tickFreq); //MRUV        
    
    if (*extObjectPos < extChao){
        *extObjectPos = extChao;   
        jumping = nullFunc;
    }  
}


