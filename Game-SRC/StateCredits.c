#include "StateController.h"

void showMenuMouse(int button, int state,int x, int y){        
    int fixedX = (float)mouseFixX(x);
    int fixedY = (float)mouseFixY(y);  
    
    if ((state == GLUT_UP)&&(button == GLUT_LEFT_BUTTON)){
        //Como todos os botoes tem o mesmo tamanho, e o X do centro e o mesmo podemos utilizar apenas um if
        if((fixedX >= (SHOWMENU_BUTTON_POSX - (SHOWMENU_BUTTON_WIDHT/2))) && (fixedX <= (SHOWMENU_BUTTON_POSX+( SHOWMENU_BUTTON_WIDHT/2)))){ 
            if((fixedY >= SHOWMENU_BUTTON_POSY-(SHOWMENU_BUTTON_HEIGHT/2)) && (fixedY <= SHOWMENU_BUTTON_POSY+(SHOWMENU_BUTTON_HEIGHT/2))){                
                selectState(1);               
            }
        }
    }
    
}

void drawCreditsScreen(void) {    
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    
    drawFullScreen(texturas[28]);
    
    glDisable(GL_TEXTURE_2D); 
    glutSwapBuffers();
    
}

void selectCreditsState(){
    glutDisplayFunc(drawCreditsScreen);
    glutKeyboardFunc(NULL);
    glutSpecialFunc(NULL);
    glutSpecialUpFunc(NULL);
    glutMouseFunc(showMenuMouse);
}