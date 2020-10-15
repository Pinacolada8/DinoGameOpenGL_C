
//Define que faz parte do pacote

#include <GL/glew.h>

#include "Geral.h"

void base(int depth,int idTexture,float **texture){    
    glBindTexture(GL_TEXTURE_2D, idTexture);
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_TRIANGLE_FAN);
        //glTexCoord2fv(texture[0]); //Estao comentadas em Funcao de teste, pois ainda nao existem texturas no programa
        //glTexCoord2fv(texture[1]);
        //glTexCoord2fv(texture[2]);
        //glTexCoord2fv(texture[3]);

        glVertex2f(0,-depth);
        glVertex2f(MAX_X,-depth);
        glVertex2f(MAX_X,0);
        glVertex2f(0,0);
    glEnd();
}

void drawRetangulo(int x, int y,int larg, int alt, GLuint idTextura){//Retangulo, ponto na alura 0
    glBindTexture(GL_TEXTURE_2D, idTextura);
    glColor4f(1,1,1,1);
    int larg2 = larg/2;//Metade da largura
    glPushMatrix();
    glTranslatef(x, y, 0);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0,0);glVertex2f(-larg2,0);
            glTexCoord2f(1,0);glVertex2f(+larg2,0);
            glTexCoord2f(1,1);glVertex2f(+larg2,+alt);
            glTexCoord2f(0,1);glVertex2f(-larg2,+alt);
        glEnd();
    glPopMatrix();
}

void drawPlayerR(int x, int y, int larg, int alt, GLuint idTexture){
    glBindTexture(GL_TEXTURE_2D, idTexture);
    glColor4fv(player.color);
    float larg2 = (float)larg/2;//Metade da largura
    glPushMatrix();
    glTranslatef(x, y, 0);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);glVertex2f(-larg2,0);
            glTexCoord2f(1, 0);glVertex2f(+larg2,0);
            glTexCoord2f(1, 1);glVertex2f(+larg2,+alt);
            glTexCoord2f(0, 1);glVertex2f(-larg2,+alt);
        glEnd();
    glPopMatrix();
}

void drawRelogio(int x,int y,unsigned long int relog){
    glColor4fv((float*)defaultColorTexto);
    char number[12];
    int trash = snprintf(number,12,"Time: %lu",relog);
    texto(GLUT_BITMAP_HELVETICA_18, number, x, y);
}

void drawNotificationSquare(int x, int y,int base,int alt, GLuint textID){
    base /=2;//Divide a base por 2 para facilitar operacoes
    alt /=2;//Divide a altura por 2 para facilitar operacoes
    glBindTexture(GL_TEXTURE_2D, textID);
    glColor4f(1,1,1,1);
    glPushMatrix();
    glTranslatef(x, y, 0);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);glVertex2f(-base,-alt);//Valores referentes ao tamanho da imagem de pause
            glTexCoord2f(1, 0);glVertex2f(base,-alt);
            glTexCoord2f(1, 1);glVertex2f(base,alt);
            glTexCoord2f(0, 1);glVertex2f(-base,alt);
        glEnd();
    glPopMatrix();

}

void drawLives(int x, int y, int vidas){
    glColor4fv((float*)defaultColorTexto);
    char number[10];
    int trash = snprintf(number,10,"Lifes: %i",vidas);
    texto(GLUT_BITMAP_HELVETICA_18, number, x, y);
}

void drawScore(int x, int y,double score){
    glColor4fv((float*)defaultColorTexto);
    char number[8+SCORE_NUMBERHOUSES];
    int trash = snprintf(number,8+SCORE_NUMBERHOUSES,"Score: %012.lf",score);
    texto(GLUT_BITMAP_HELVETICA_18, number, x, y);
}

void drawFullScreen(GLuint idTextura){
    glBindTexture(GL_TEXTURE_2D, idTextura); 
    glColor4f(1,1,1,1);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0,0);glVertex2f(0,- FLOOR_DEPTH);
        glTexCoord2f(1,0);glVertex2f(MAX_X,-FLOOR_DEPTH);
        glTexCoord2f(1,1);glVertex2f(MAX_X,MAX_Y);
        glTexCoord2f(0,1);glVertex2f(0,MAX_Y);
    glEnd();    
}

void drawScenario(GLuint idTextura,float texPos){
    glBindTexture(GL_TEXTURE_2D, idTextura);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glColor4f(1,1,1,1);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(texPos,0);glVertex2f(0,- FLOOR_DEPTH);
        glTexCoord2f((texPos + 1),0);glVertex2f(MAX_X,-FLOOR_DEPTH);
        glTexCoord2f((texPos + 1),SCENARIO_PHEIGHT);glVertex2f(MAX_X,MAX_Y);
        glTexCoord2f(texPos,SCENARIO_PHEIGHT);glVertex2f(0,MAX_Y);
    glEnd();    
}



