#include "Geral.h"


//Dificuldades
//1 -- > Facil
//2 -- > Normal
//3 -- > Dificil
//4 -- > Insano
int difficulty = 2;//Dificuldade inicial normal
int lives;
int maxObstaculos;
int difficultyPercentage;
const float tickFreq = 1000/TICK_MSEC;//Representa a Frequencia do programa
double velocidadeScorePlayer = 0;//Velocidade em que o player ganha pontos de distancia
const float playerBackColor[] = {1,1,1,1};
bool derrota = False; //So e verdadeiro quando acaba o jogo por derrota
bool ammo = True;
int teste = 0;


void endPause();
void startPause();

void fPause(){
    if (pause == False){
        startPause();
    }else{
        endPause();
    }
}

void startPause(){
    pause = True;
    pauseTimer();
}

void endPause(){
    if ((pause != False)||(derrota == False)) {
        pause = False;
        startTimer();
        tick(pause);
    }
}

void loadTimer(){//Inicia o timer do jogo
    initTimer();
}

void loadDifficulty(){
    srand(time(NULL));//Coloca seed para gerar valores aleatorios
    lives = 6/difficulty;//A quantidade de vidas e equivalente a divisao de 6 pela dificuldade
    velocidadeScorePlayer = difficulty * ((double)TICK_MSEC/200);//Coloca a velociadade em que o jogador percorrera a distancia
    maxObstaculos = DIFFICULTYMULTIPLIER * difficulty;//cada nivel de dificuldade acresenta mais 5 objetos na tela
    difficultyPercentage = (DIFFICULTYMULTIPLIER * difficulty*2);//Porcentagem de dificuldade,cada uma aumenta 5%
}

void loadGame(){
    initScenario();
    pause = True;
    ammo = True;
    loadScores();
    loadDifficulty();
    loadTimer();
    obstaculos = malloc(maxObstaculos*sizeof(Obstaculo));
    loadPlayer(PLAYER_POSX, PLAYER_POSY, PLAYER_LARG, PLAYER_ALT, PLAYER_CROUCH, (float*)playerBackColor);
    initCannons();
    derrota = False;
    endPause();
}

void endGame(){
    endInvulnerability();
    startPause();
    while (quantidadeObstaculos > 0){
        removeObstaculo(quantidadeObstaculos-1);
    }
    free(obstaculos);
    quantidadeObstaculos = 0;
    resetTimer();
}

void restartGame(){
    endGame();
    wait((tickFreq/2),loadGame);
}

void damageHit(){
    if (invulnerable == True){
        return;
    }
    if (lives > 0){
        invulnerability();
        printf("hit\n");
        lives--;
    }else {
        startPause();
        derrota = True;
        printf("DERROTA\n");
    }
}

void reloadFiringAmmo(){
    ammo = True;
}

void tick(int i){
    if (pause){//Para o jogo caso esteja pausado;
        return;
    }
    moveScenario();


    teste++;
    if (teste >= 128){
        printf("\nOK");
        teste = 0;
    }

    //restringe a funcao que gera obstaculos aleatorios a ser chamada apenas
    //quando tiverem passado alguns ticks
    if (ammo != False){
        ammo = False;
        randomObstacleGenerator();
        wait(600/difficulty,reloadFiringAmmo);
    }

    (*jumping)();

    moveObstaculos();
    playerRunTextureChange();

    distaciaPercorrida += velocidadeScorePlayer;

    for (i = 0;i<quantidadeObstaculos;i++){//Detecta se existe colisao com algum objeto
        if(detectCollision(&obstaculos[i])){
            damageHit();
        }
    }

    glutTimerFunc(TICK_MSEC,tick,pause);
}
