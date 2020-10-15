
typedef struct {
    GLuint TextId;
    int x,y,larg,alt;
    void (*draw)(int x, int y,int larg, int alt, GLuint idTextura);
}Obstaculo;

typedef struct {
    GLuint * TextId;
    float color[4];
    int x,y,larg,alt;
    int leftBorder,rightBorder;
    void (*draw)(int x, int y,int larg, int alt,GLuint idTextura);
}PlayerObject;
