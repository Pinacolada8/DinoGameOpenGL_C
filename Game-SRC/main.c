//Adiciona os outros arquivos, e variaveis universais e os includes
#include "Geral.h"



//Prototypes(main)
void redimensiona(int w, int h);
void drawGame(void);
void atualizaTela();

//Variaveis Globais
int RESOLUTION_WIDTH = 1280;//RESOLUCAO
int RESOLUTION_HEIGHT = 720;//RESOLUCAO
bool pause = True;



int main(int argc, char** argv) {

    // Acordando o GLUT
    glutInit(&argc, argv);

    // Definindo a versão do OpenGL que vamos usar
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    // Configuração inicial da janela do GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(100, 100);


    glutCreateWindow("Dino Run");
    glClear(GL_COLOR_BUFFER_BIT);
    
    //Configuracoes
    glClearColor(1, 1, 1, 1);    
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    

    // Registrando Callbacks
    glutReshapeFunc(redimensiona);    
    glutIdleFunc(atualizaTela);   
    
    //Iniciando o jogo
    load_allTextures();    
    selectState(1); 
    
    glutMainLoop();

    return (EXIT_SUCCESS);
}

void redimensiona(int w, int h) {

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    
    if((w != RESOLUTION_WIDTH) || (h != RESOLUTION_HEIGHT)){
        glutReshapeWindow(RESOLUTION_WIDTH,RESOLUTION_HEIGHT);//Resolucao somente podem ser alteradas pelo proprio jogo
    }
    
    
    glOrtho(0,MAX_X, -FLOOR_DEPTH, MAX_Y , -1.0,1.0);
    //A tela sempre sera dividida na mesma quantidade de unidades, pois nao tera
    //como existir uma tela fora da proporcao
        
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();    
}


void atualizaTela(){ //Faz com que o computador atue com a maior quantidade de fps que ele conseguir
    glutPostRedisplay();
}