#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int R = 255, G = 213, B = 175;
int R2 = 0, G2 = 0, B2 = 0;
int rs, gs, bs;

int flag = 0, flagCabeca = 1, flagBoca = 2, flagOlhos = 6;
float radBoca = 0.22;
int metade = 1;

void display(void);
void keyboard(unsigned char key, int x, int y);
void Special_keyboard(GLint tecla, int x, int y);
void DesenhaTexto(char *string);
void DesenhaMenu();
void circulo(float centerX, float centerY, float radius, int numSegments);
void meiaLua(float centerX1, float centerY1, float radius1, int numSegments1);
void oval(float centerX, float centerY, float radius, int numSegments, int metade);

int main(int argc, char **argv)
{
    rs = R2, gs = G2, bs = B2;
    if(flagOlhos == 6)
        metade = 2;
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 800);

    glutInitWindowPosition(0, 0);

    glutCreateWindow(argv[0]);

    glClearColor(1.0, 0.0, 1.0, 0.0);

    glOrtho(-1, 1, -1, 1, -1, 1);

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutSpecialFunc(Special_keyboard);

    glutMainLoop();

    printf("\nTestando... \n");
    return 0;
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    DesenhaTexto("Vamos criar seu personagem!!!");
    DesenhaMenu();

    
    // Flag para cabeça
    if (flagCabeca == 1)
    {   
        glColor3ub(R, G, B);
        glBegin(GL_POLYGON);
            circulo(0.0, 0.0, 0.7, 30);
        glEnd();
    }else if (flagCabeca == 2)
    {   
        glColor3ub(R, G, B);
        glBegin(GL_POLYGON);
            circulo(0.0, 0.0, 0.55, 30);
        glEnd();
    }else if(flagCabeca == 3){
        glColor3ub(R, G, B);
        glBegin(GL_POLYGON);
            circulo(0.0, 0.0, 0.55, 30);
        glEnd();
        glBegin(GL_POLYGON);
            circulo(0.1, -0.38, 0.3, 12);
        glEnd();
        glBegin(GL_POLYGON);
            circulo(-0.1, -0.38, 0.3, 12);
        glEnd();
        glBegin(GL_POLYGON);
            circulo(0, -0.5, 0.25, 12);
        glEnd();
    }else if(flagCabeca == 4){
        glColor3ub(R, G, B);
        glBegin(GL_POLYGON);
            circulo(0.0, 0.0, 0.56, 60);
        glEnd();
        glBegin(GL_POLYGON);
            circulo(0.2, -0.38, 0.3, 30);
        glEnd();
        glBegin(GL_POLYGON);
            circulo(-0.2, -0.38, 0.3, 30);
        glEnd();
        glBegin(GL_POLYGON);
            circulo(0, -0.5, 0.3, 30);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex2f(-0.55,0.1); //0
            glVertex2f(-0.55,-0.1); //1
            glVertex2f(-0.48,-0.5); //2
            glVertex2f(0.48,-0.5); //3 
            glVertex2f(0.55,- 0.1); //4
            glVertex2f(0.53,0.1); //5
         glEnd();        
    }else if (flagCabeca == 5){
        glColor3ub(R, G, B);
        glBegin(GL_POLYGON);
            circulo(0.0, 0.0, 0.6, 60);
        glEnd();
        glBegin(GL_POLYGON);
            circulo(0.2, -0.38, 0.3, 30);
        glEnd();
        glBegin(GL_POLYGON);
            circulo(-0.2, -0.38, 0.3, 30);
        glEnd();
        glBegin(GL_POLYGON);
            circulo(0, -0.5, 0.3, 30);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex2f(-0.5,0.3); //0
            glVertex2f(-0.5, -0.6); //1
            glVertex2f(-0.3, -0.8); //2
            glVertex2f(0.3, -0.8); //3
            glVertex2f(0.5,-0.6); //4
            glVertex2f(0.5,0.3); //5
         glEnd();   
    }else{
        glColor3ub(R, G, B);
        glBegin(GL_POLYGON);
            circulo(0.2, -0.38, 0.3, 30);
        glEnd();
        glBegin(GL_POLYGON);
            circulo(-0.2, -0.38, 0.3, 30);
        glEnd();
        glBegin(GL_POLYGON);
            circulo(0, -0.5, 0.3, 30);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex2f(-0.4,0.4); //0
            glVertex2f(-0.5,0.3);
            glVertex2f(-0.5, -0.6); //1
            glVertex2f(-0.3, -0.8); //2
            glVertex2f(0.3, -0.8); //3
            glVertex2f(0.5,-0.6); //4
            glVertex2f(0.5,0.3); //5
            glVertex2f(0.4,0.4);
         glEnd(); 
    }      
    // // Óculos
    // glColor3ub(0, 0, 0); // Cor preta
    // glBegin(GL_POLYGON);
    // circulo(0.25, -0.15, 0.2, 50); // Centro: (0.1, 0.1), Raio: 0.1, Segmentos: 50
    // glEnd();

    // glBegin(GL_POLYGON);
    // circulo(-0.25, -0.15, 0.2, 50); // Centro: (0.1, 0.1), Raio: 0.1, Segmentos: 50
    // glEnd();


    // glColor3ub(0, 0, 0);
    // glBegin(GL_POLYGON);
    
    //   glVertex2f(-0.1,-0.1);
    //   glVertex2f(0.1,-0.1);
    //   glVertex2f(0.1,-0.2);
    //   glVertex2f(-0.1,-0.2);   

    // glEnd();

    // // Parte de dentro do óculos
    // glColor3ub(R, G, B);

    // glBegin(GL_POLYGON);
    // circulo(-0.25, -0.15, 0.16, 50);
    // glEnd();
    // glBegin(GL_POLYGON);
    // circulo(0.25, -0.15, 0.16, 50); 
    // glEnd();

    // Criando olhos e mudando cor
    if (flagOlhos == 1)
    {
        glColor3ub(R2, G2, B2);  
        glBegin(GL_POLYGON);
        circulo(0.2, -0.15, 0.07, 50); 
        glEnd();
        glBegin(GL_POLYGON);
        circulo(-0.2, -0.15, 0.07, 50);
        glEnd();
    }else if (flagOlhos == 2)
    {
        glColor3ub(R2, G2, B2);  
        glBegin(GL_POLYGON);
        glVertex2f(-0.3,0.01);  // 1
        glVertex2f(-0.3,-0.05);   // 2
        glVertex2f(-0.1,-0.05);   // 3
        glVertex2f(-0.1,0.01); // 4
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(0.3,0.01);  // 1
        glVertex2f(0.3,-0.05);   // 2
        glVertex2f(0.1,-0.05);   // 3
        glVertex2f(0.1,0.01); // 4
        glEnd();
    }else if (flagOlhos == 3)
    {
        glColor3ub(R2, G2, B2);  
        glBegin(GL_POLYGON);
        glVertex2f(-0.3,0.03);  // 1
        glVertex2f(-0.3,-0.01);   // 2
        glVertex2f(-0.1,-0.12);   // 3
        glVertex2f(-0.1,-0.06); // 4
        glEnd();

        glBegin(GL_POLYGON);
        circulo(-0.17, -0.13, 0.069, 50);
        glEnd();
        
        glColor3ub(R2, G2, B2);  
        glBegin(GL_POLYGON);
        glVertex2f(0.3,0.03);  // 1
        glVertex2f(0.3,-0.01);   // 2
        glVertex2f(0.1,-0.12);   // 3
        glVertex2f(0.1,-0.06); // 4
        glEnd();

        glBegin(GL_POLYGON);
        circulo(0.17, -0.13, 0.069, 50);
        glEnd();
    }else if (flagOlhos == 4)
    {
        glColor3ub(R2, G2, B2);  
        glBegin(GL_POLYGON);
        circulo(0.2, -0.15, 0.07, 50); 
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-0.3,-0.12); // 1
        glVertex2f(-0.3,-0.17);// 2
        glVertex2f(-0.1,-0.17);// 3
        glVertex2f(-0.1,-0.12); // 4
        glEnd();
    }else if (flagOlhos == 5)
    {
        glColor3ub(R2, G2, B2);
        glBegin(GL_POLYGON);
        oval(0.2, -0.15, 0.1, 50, metade); 
        glEnd();
        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        oval(0.2, -0.15, 0.07, 50, metade); 
        glEnd();
        glColor3ub(R2, G2, B2);  
        glBegin(GL_POLYGON);
        circulo(0.2, -0.07, 0.04, 50); 
        glEnd();

        glColor3ub(R2, G2, B2);
        glBegin(GL_POLYGON);
        oval(-0.2, -0.15, 0.1, 50, metade); 
        glEnd();
        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        oval(-0.2, -0.15, 0.07, 50, metade); 
        glEnd();
        glColor3ub(R2, G2, B2);  
        glBegin(GL_POLYGON);
        circulo(-0.2, -0.07, 0.04, 50); 
        glEnd();
    }else{
        glColor3ub(R2, G2, B2);
        glBegin(GL_POLYGON);
        oval(0.2, -0.15, 0.1, 50, metade); 
        glEnd();

        glColor3ub(R, G, B);
        glBegin(GL_POLYGON);
        oval(0.2, -0.15, 0.07, 50, metade); 
        glEnd();

        glColor3ub(R2, G2, B2);
        glBegin(GL_POLYGON);
        oval(-0.2, -0.15, 0.1, 50, metade); 
        glEnd();
        glColor3ub(R, G, B);
        glBegin(GL_POLYGON);
        oval(-0.2, -0.15, 0.07, 50, metade); 
        glEnd();

    }

    

    // if (flag == 1)
    // {
    // // Sharingan
    // glColor3ub(rs, gs, bs);
    // glBegin(GL_POLYGON);
    // circulo(-0.23, -0.13, 0.01, 50);
    // glEnd();

    // glBegin(GL_POLYGON);
    // circulo(-0.2, -0.18, 0.01, 50);
    // glEnd();

    // glBegin(GL_POLYGON);
    // circulo(-0.17, -0.13, 0.01, 50);
    // glEnd();


    // // Sharingan
    // glBegin(GL_POLYGON);
    // circulo(0.23, -0.13, 0.01, 50);
    // glEnd();

    // glBegin(GL_POLYGON);
    // circulo(0.2, -0.18, 0.01, 50);
    // glEnd();

    // glBegin(GL_POLYGON);
    // circulo(0.17, -0.13, 0.01, 50);
    // glEnd();
    // }

    // Flag para boca
    if (flagBoca == 1)
    {
        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
            meiaLua(0, 0.4, radBoca, 30);
        glEnd(); 
    }else if (flagBoca == 2){
        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
            oval(0, -0.4, radBoca, 30, metade);
        glEnd();     
    }
    
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    printf("*** Tratamento de teclas comuns\n");
    printf(">>> Tecla pressionada: %c\n", key);
    switch (key)
    {
    case 27:
        exit(0);
    break;
    // CASOS PARA OLHOS
    case '1':
    flagOlhos = 1;
    glutPostRedisplay();
    break;
    case '2':
    flagOlhos = 2;
    glutPostRedisplay();
    break;
    case '3':
    flagOlhos = 3;
    glutPostRedisplay();
    break;
    case '4':
    flagOlhos = 4;
    glutPostRedisplay();
    break;
    case '5':
    flagOlhos = 5;
    metade = 1;
    glutPostRedisplay();
    break;
    case '6':
    flagOlhos = 6;
    metade = 2;
    glutPostRedisplay();
    break;

    // Olho azul
    case 'u':
        R2 = 125;
        G2 = 173;
        B2 = 217;
        flag = 0;
        glutPostRedisplay();
    break;
    // Olho verde
    case 'i':
        R2 = 136;
        G2 = 145;
        B2 = 116;
        flag = 0;
        glutPostRedisplay();
    break;
    // Olho castanho
    case 'o':
        R2 = 79;
        G2 = 50;
        B2 = 25;
        flag = 0;
        glutPostRedisplay();
    break;

    // SHARINGAN
    case 'p':
        R2 = 255;
        G2 = 0;
        B2 = 0;
        rs = 0;
        gs = 0; 
        bs = 0;
        flag = 1;
    glutPostRedisplay();
    break;

    // Boca
    case 'q':
        flagBoca = 1;
        glutPostRedisplay();
    break;
    case 'w':
        flagBoca = 2;
        glutPostRedisplay();
    break;
    }
    
    
}

void Special_keyboard(GLint tecla, int x, int y)
{
    switch (tecla)
    {
    // CABECAS 1 .. 6
    case GLUT_KEY_F1:
        flagCabeca = 1;
        radBoca = 0.22;
        glutPostRedisplay();
        break;  
    case GLUT_KEY_F2:
        flagCabeca = 2;
        radBoca = 0.14;
        glutPostRedisplay();
        break;   
    case GLUT_KEY_F3:
        flagCabeca = 3;
        radBoca = 0.22;
        glutPostRedisplay();
        break; 
    case GLUT_KEY_F4:
        flagCabeca = 4;
        radBoca = 0.22;
        glutPostRedisplay();
        break;     
    case GLUT_KEY_F5:
        flagCabeca = 5;
        radBoca = 0.22;
        glutPostRedisplay();
        break; 
    case GLUT_KEY_F6:
        flagCabeca = 6;
        radBoca = 0.22;
        glutPostRedisplay();
        break; 
    

    // COR DE PELE F7 ... F12
    case GLUT_KEY_F7:
        R = 253;
        G = 238;
        B = 212;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F8:
        R = 247;
        G = 219;
        B = 187;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F9:
        R = 238;
        G = 187;
        B = 152;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F10:
        R = 214;
        G = 162;
        B = 123;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F11:
        R = 190;
        G = 130;
        B = 106;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F12:
        R = 136;
        G = 86;
        B = 61;
        glutPostRedisplay();
        break;
    }
}

void DesenhaTexto(char *string)
{
    glColor3ub(150, 200, 250);
    glPushMatrix();
    glRasterPos2f(-0.4, 0.8);
    while (*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
    glPopMatrix();
    glColor3ub(255, 255, 255);
}

void DesenhaMenu()
{
    char string[] = "Aperte F7 ... F12: Mudar cor de pele!";
    char *pont;

    pont = string;
    glColor3ub(150, 200, 250);
    glPushMatrix();
    glRasterPos2f(-1, 0.7);
    while (*pont)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *pont++);
    glPopMatrix();

    char string2[] = "Aperte 1 ... 6: Mudar cor do cabelo";
    char *pont2;

    pont2 = string2;
    glColor3ub(150, 200, 250);
    glPushMatrix();
    glRasterPos2f(-1, 0.6);
    while (*pont2)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *pont2++);
    glPopMatrix();

    glColor3ub(255, 255, 255);
}

/* Essa função desenha um círculo;
centerX é o eixo x e vai de 0 até 1. Ex: 0.5 ou 0.05 e por ai vai.
centerY é o eixo y e vai de 0 até 1. Ex: -0.5 ou 0.5 e por ai vai

radius é o raio dele, basicamente o tamanho.

numSegmentos é a quantidade de pontos para formar um círculo. Normalmente uso 50
*/
void circulo(float centerX, float centerY, float radius, int numSegments)
{
    glBegin(GL_POLYGON);
    float PI = 3.14f;
    for (int i = 0; i <= numSegments; ++i)
    {
        float angle = 2.0f * PI * i / numSegments;
        float x = centerX + (radius * cos(angle));
        float y = centerY + (radius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();
}

void meiaLua(float centerX1, float centerY1, float radius1, int numSegments1)
{
    glBegin(GL_POLYGON);
    float PI = 3.14f;
    for (int i = 0; i <= numSegments1/2; i++)
    {
        float angle = 2.0f * PI * i / numSegments1;
        angle/2;
        float x = centerX1 + (radius1 * cos(angle));
        float y = centerY1 + (radius1 * sin(angle));
        glVertex2f(-x, -y);
    }
    glEnd();
}

void oval(float centerX, float centerY, float radius, int numSegments, int metade)
{
    glBegin(GL_POLYGON);
    float PI = 3.14f;
    for (int i = 0; i <= numSegments/metade; ++i)
    {
        float angle = 2.0f * PI * i / numSegments;
        float x = centerX + (radius * cos(angle));
        float y = centerY + (radius * sin(angle));
        glVertex2f(x, y/2);
    }
    glEnd();
}