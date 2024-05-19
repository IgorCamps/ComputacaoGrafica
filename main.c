#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int R = 255, G = 213, B = 175;
int R2 = 0, G2 = 0, B2 = 0;
int rs, gs, bs;

int flagCabeca = 2, flagBoca = 1, flagChapeu = 1, flagOlhos = 1, flagNariz = 3, flagSombra = 2;
float radBoca = 0.1;
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
    if (flagOlhos == 6)
        metade = 2;
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 800);

    glutInitWindowPosition(0, 0);

    glutCreateWindow(argv[0]);

    glClearColor(0.0, 0.0, 0.0, 0.0);

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

    // Desenha a camiseta do personagem
    glColor3ub(0, 64, 128); // Cor azul para a camiseta
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, -0.25); // Canto inferior esquerdo
    glVertex2f(-0.25, -0.8);  // Canto inferior direito
    glVertex2f(0.25, -0.8);   // Topo direito
    glVertex2f(0.25, -0.25);  // Topo esquerdo
    glEnd();
    glColor3ub(0, 40, 81); // Cor azul para a camiseta
    glBegin(GL_POLYGON);
    glVertex2f(-0.35, -0.25); // Canto inferior esquerdo
    glVertex2f(-0.4, -0.55);  // Canto inferior direito
    glVertex2f(-0.25, -0.55); // Topo direito
    glVertex2f(-0.25, -0.25); // Topo esquerdo
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.35, -0.25); // Canto inferior esquerdo
    glVertex2f(0.4, -0.55);  // Canto inferior direito
    glVertex2f(0.25, -0.55); // Topo direito
    glVertex2f(0.25, -0.25); // Topo esquerdo
    glEnd();
    glColor3ub(R, G, B);
    glBegin(GL_POLYGON);
    glVertex2f(-0.35, -0.9);  // Canto inferior esquerdo
    glVertex2f(-0.35, -0.55); // Canto inferior direito
    glVertex2f(-0.25, -0.55); // Topo direito
    glVertex2f(-0.25, -0.9);  // Topo esquerdo
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.35, -0.9);  // Canto inferior esquerdo
    glVertex2f(0.35, -0.55); // Canto inferior direito
    glVertex2f(0.25, -0.55); // Topo direito
    glVertex2f(0.25, -0.9);  // Topo esquerdo
    glEnd();

    // Flag para cabeça
    switch (flagCabeca)
    {
    case 1:
        glColor3ub(R, G, B);
        glBegin(GL_POLYGON);
        circulo(0.0, 0.0, 0.25, 30);
        glEnd();
        break;
    case 2:
        glColor3ub(R, G, B);
        glBegin(GL_POLYGON);
        circulo(0.0, 0.0, 0.25, 30);
        glEnd();

        glBegin(GL_POLYGON);
        circulo(0.12, -0.2, 0.07, 30);
        glEnd();

        glBegin(GL_POLYGON);
        circulo(-0.12, -0.2, 0.07, 30);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-0.235, -0.08); // 0
        glVertex2f(-0.187, -0.22); // 1
        glVertex2f(0.187, -0.22);  // 2
        glVertex2f(0.235, -0.08);  // 3
        glEnd();

        glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.187, 0.12); // Canto inferior esquerdo
        glVertex2f(-0.13, -0.27); // Canto inferior direito
        glVertex2f(0.187, 0.12);  // Topo
        glVertex2f(0.13, -0.27);  // Topo
        glEnd();
        break;
    case 3:
        glColor3ub(R, G, B);
        glBegin(GL_POLYGON);
        circulo(0.0, 0.0, 0.25, 30);
        glEnd();

        glBegin(GL_POLYGON);
        circulo(0.08, -0.18, 0.12, 10);
        glEnd();

        glBegin(GL_POLYGON);
        circulo(-0.08, -0.18, 0.12, 10);
        glEnd();
        break;
    case 4:
        glColor3ub(R, G, B);
        glBegin(GL_POLYGON);
        circulo(0.0, 0.0, 0.25, 30);
        glEnd();

        glBegin(GL_POLYGON);
        circulo(0.12, -0.2, 0.07, 30);
        glEnd();

        glBegin(GL_POLYGON);
        circulo(-0.12, -0.2, 0.07, 30);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-0.235, -0.08); // 0
        glVertex2f(-0.187, -0.22); // 1
        glVertex2f(0.187, -0.22);  // 2
        glVertex2f(0.235, -0.08);  // 3
        glEnd();

        glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.187, 0.12); // Canto inferior esquerdo
        glVertex2f(-0.13, -0.27); // Canto inferior direito
        glVertex2f(0.187, 0.12);  // Topo
        glVertex2f(0.13, -0.27);  // Topo
        glEnd();

        glBegin(GL_POLYGON);
        circulo(0.0, -0.22, 0.11, 30);
        glEnd();
        break;
    case 5:
        glColor3ub(R, G, B);
        glBegin(GL_POLYGON);
        circulo(0.0, 0.04, 0.28, 30);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-0.205, 0.21); // 0
        glVertex2f(-0.23, 0.17);  // 1
        glVertex2f(-0.23, -0.24); // 2
        glVertex2f(-0.17, -0.30); // 3
        glVertex2f(0.17, -0.30);  // 4
        glVertex2f(0.23, -0.24);  // 5
        glVertex2f(0.23, 0.17);   // 6
        glVertex2f(0.205, 0.21);  // 7
        glEnd();
        break;
    default:
        glColor3ub(R, G, B);
        glBegin(GL_POLYGON);
        glVertex2f(-0.21, 0.23);   // 0
        glVertex2f(-0.235, 0.19);  // 1
        glVertex2f(-0.235, -0.26); // 2
        glVertex2f(-0.175, -0.32); // 3
        glVertex2f(0.175, -0.32);  // 4
        glVertex2f(0.235, -0.26);  // 5
        glVertex2f(0.235, 0.19);   // 6
        glVertex2f(0.21, 0.23);    // 7
        glEnd();
        break;
    }

    // Criando olhos e mudando cor
    switch (flagOlhos)
    {
    case 1:
        glColor3ub(R2, G2, B2);
        glBegin(GL_POLYGON);
        circulo(0.1, 0, 0.04, 50);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-0.15, 0.02);  // 1
        glVertex2f(-0.15, -0.02); // 2
        glVertex2f(-0.03, -0.02); // 3
        glVertex2f(-0.03, 0.02);  // 4
        glEnd();
        break;
    case 2:
        glColor3ub(R2, G2, B2);
        glBegin(GL_POLYGON);
        glVertex2f(0.15, 0.02);  // 1
        glVertex2f(0.15, -0.02); // 2
        glVertex2f(0.03, -0.02); // 3
        glVertex2f(0.03, 0.02);  // 4
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-0.15, 0.02);  // 1
        glVertex2f(-0.15, -0.02); // 2
        glVertex2f(-0.03, -0.02); // 3
        glVertex2f(-0.03, 0.02);  // 4
        glEnd();
        break;
    case 3:
        glColor3ub(R2, G2, B2);

        glBegin(GL_POLYGON);
        circulo(0.08, 0, 0.04, 50);
        glEnd();

        glBegin(GL_POLYGON);
        circulo(-0.08, 0, 0.04, 50);
        glEnd();
        break;
    case 4:
        glColor3ub(R2, G2, B2);
        glBegin(GL_POLYGON);
        circulo(0.1, 0, 0.04, 50);
        glEnd();
        glBegin(GL_POLYGON);
        circulo(-0.1, 0, 0.04, 50);
        glEnd();
        break;
    case 5:
        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        circulo(0.1, 0, 0.08, 50);
        glEnd();
        glBegin(GL_POLYGON);
        circulo(-0.1, 0, 0.08, 50);
        glEnd();
        glColor3ub(R2, G2, B2);
        glBegin(GL_POLYGON);
        circulo(0.1, 0, 0.065, 50);
        glEnd();
        glBegin(GL_POLYGON);
        circulo(-0.1, 0, 0.065, 50);
        glEnd();
        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        circulo(0.08, 0.02, 0.03, 50);
        glEnd();
        glBegin(GL_POLYGON);
        circulo(-0.12, 0.02, 0.03, 50);
        glEnd();
        glBegin(GL_POLYGON);
        circulo(0.13, -0.02, 0.015, 50);
        glEnd();
        glBegin(GL_POLYGON);
        circulo(-0.07, -0.02, 0.015, 50);
        glEnd();
        break;
    default:
        glColor3ub(79, 50, 25);
        glBegin(GL_POLYGON);
        oval(0.1, 0, 0.06, 50, 2);
        glEnd();
        glColor3ub(R, G, B);
        glBegin(GL_POLYGON);
        oval(0.1, 0, 0.04, 50, 2);
        glEnd();
        glColor3ub(255, 130, 149);
        glBegin(GL_POLYGON);
        oval(0.17, -0.15, 0.04, 50, 1);
        glEnd();

        glColor3ub(79, 50, 25);
        glBegin(GL_POLYGON);
        oval(-0.1, 0, 0.06, 50, 2);
        glEnd();
        glColor3ub(R, G, B);
        glBegin(GL_POLYGON);
        oval(-0.1, 0, 0.04, 50, 2);
        glEnd();
        glColor3ub(255, 130, 149);
        glBegin(GL_POLYGON);
        oval(-0.17, -0.15, 0.04, 50, 1);
        glEnd();
        break;
    }
    // Flag para boca
    switch (flagBoca)
    {
    case 1:
        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        meiaLua(0,0.13, radBoca, 30);
        glEnd();
        break;
    case 2:
        glColor3ub(0, 0, 0);
        glBegin(GL_POLYGON);
        oval(0, -0.2, 0.06, 50, 2); 
        glEnd();
        glColor3ub(255, 213, 175);
        glBegin(GL_POLYGON);
        oval(0, -0.2, 0.04, 50, 2); 
        glEnd();  
        break;
    case 3:
        glColor3ub(193, 13, 49);
        glBegin(GL_POLYGON);
        meiaLua(0,0.18, 0.02, 30); //ponta da língua
        glEnd(); 
        glBegin(GL_POLYGON); //comprimento da língua
        glVertex2f(-0.02, -0.18); // Canto inferior esquerdo
        glVertex2f(-0.02, -0.13); // Canto inferior direito
        glVertex2f(0.02, -0.13); // Topo
        glVertex2f(0.02, -0.18); // Topo
        glEnd();
        glColor3ub(0, 0, 0);
        glBegin(GL_POLYGON); //linha preta
        glVertex2f(-0.05, -0.12); // Canto inferior esquerdo
        glVertex2f(-0.05, -0.13); // Canto inferior direito
        glVertex2f(0.05, -0.13); // Topo
        glVertex2f(0.05, -0.12); // Topo
        glEnd();
        break;
    case 4:
        glColor3ub(255, 255, 255);

        glBegin(GL_POLYGON);
        glVertex2f(-0.1, -0.2); // Canto inferior esquerdo
        glVertex2f(-0.1, -0.1); // Canto inferior direito
        glVertex2f(0.1, -0.1);  // Topo
        glVertex2f(0.1, -0.2);  // Topo
        glEnd();
        glColor3ub(0, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(-0.1, -0.15); // Canto inferior esquerdo
        glVertex2f(-0.1, -0.14); // Canto inferior direito
        glVertex2f(0.1, -0.14);  // Topo
        glVertex2f(0.1, -0.15);  // Topo
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(0.06, -0.2); // Canto inferior esquerdo
        glVertex2f(0.06, -0.1); // Canto inferior direito
        glVertex2f(0.07, -0.1); // Topo
        glVertex2f(0.07, -0.2); // Topo
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-0.06, -0.2); // Canto inferior esquerdo
        glVertex2f(-0.06, -0.1); // Canto inferior direito
        glVertex2f(-0.07, -0.1); // Topo
        glVertex2f(-0.07, -0.2); // Topo
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(0.005, -0.2);  // Canto inferior esquerdo
        glVertex2f(0.005, -0.1);  // Canto inferior direito
        glVertex2f(-0.005, -0.1); // Topo
        glVertex2f(-0.005, -0.2); // Topo
        glEnd();
        break;
    case 5:
        glColor3ub(255, 0, 0); // Vermelho
        glBegin(GL_POLYGON);
        glVertex2f(-0.1, -0.15); // Canto inferior esquerdo
        glVertex2f(-0.1, -0.1);  // Canto inferior direito
        glVertex2f(0.1, -0.1);   // Topo
        glVertex2f(0.1, -0.15);  // Topo
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-0.1, -0.18);  // Canto inferior esquerdo
        glVertex2f(-0.1, -0.15);  // Canto inferior direito
        glVertex2f(-0.08, -0.15); // Topo
        glVertex2f(-0.08, -0.18); // Topo
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(0.1, -0.18);  // Canto inferior esquerdo
        glVertex2f(0.1, -0.15);  // Canto inferior direito
        glVertex2f(0.08, -0.15); // Topo
        glVertex2f(0.08, -0.18); // Topo
        glEnd();
        break;
    default:
        glColor3ub(206, 0, 5); // Vermelho
        glBegin(GL_POLYGON);
        circulo(0, -0.17, 0.05, 50);
        glEnd();
        break;
    }
    // Desenhar nariz
    switch (flagNariz)
    {
    case 1:
        glColor3ub(255, 0, 0); // Cor vermelha para o nariz
        glBegin(GL_TRIANGLES);
        glVertex2f(0, 0);         // Ponto superior do triângulo
        glVertex2f(-0.02, -0.05); // Ponto inferior esquerdo do triângulo
        glVertex2f(0.02, -0.05);  // Ponto inferior direito do triângulo
        glEnd();
        break;
    case 2:
        glColor3ub(0, 0, 0); // Cor vermelha para o nariz
        glBegin(GL_TRIANGLES);
        glVertex2f(0, 0);         // Ponto superior do triângulo
        glVertex2f(-0.02, -0.05); // Ponto inferior esquerdo do triângulo
        glVertex2f(0.02, -0.05);  // Ponto inferior direito do triângulo
        glEnd();

        glColor3ub(0, 0, 0); // Cor vermelha para o nariz
        glBegin(GL_TRIANGLES);
        glVertex2f(0, 0);         // Ponto superior do triângulo
        glVertex2f(-0.02, -0.05); // Ponto inferior esquerdo do triângulo
        glVertex2f(0.02, -0.05);  // Ponto inferior direito do triângulo
        glEnd();
        glColor3ub(R, G, B); // Cor vermelha para o nariz
        glBegin(GL_TRIANGLES);
        glVertex2f(0.01, -0.02);  // Ponto superior do triângulo
        glVertex2f(-0.01, -0.04); // Ponto inferior esquerdo do triângulo
        glVertex2f(0.02, -0.04);  // Ponto inferior direito do triângulo
        glEnd();
        break;
    case 3:
        glColor3ub(0, 0, 0);
        glBegin(GL_POLYGON);
        circulo(-0.02, -0.05, 0.01, 30);
        glEnd();
        glBegin(GL_POLYGON);
        circulo(0.02, -0.05, 0.01, 30);
        glEnd();
        break;
    case 4:
        glColor3ub(244, 117, 123); // Cor vermelha para o nariz
        glBegin(GL_POLYGON);
        glVertex2f(-0.06, -0.1);  // Canto inferior esquerdo
        glVertex2f(-0.05, -0.04); // Canto inferior direito
        glVertex2f(0.05, -0.04);  // Topo
        glVertex2f(0.06, -0.1);   // Topo
        glEnd();
        break;
    case 5:
        glColor3ub(244, 117, 123); // Cor vermelha para o nariz
        glBegin(GL_POLYGON);
        glVertex2f(0.01, -0.03);  // Canto inferior esquerdo
        glVertex2f(-0.01, -0.03); // Canto inferior direito
        glVertex2f(-0.02, -0.08); // Topo
        glVertex2f(0.02, -0.08);  // Topo
        glEnd();
        break;
    default:
        glColor3ub(255, 0, 0);
        glBegin(GL_POLYGON);
        circulo(0, -0.07, 0.04, 50);
        glEnd();
        break;
    }

    // SOMBRANCELHA
    switch (flagSombra)
    {
    case 1:
        glColor3ub(0, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(-0.19, 0.06); // 1
        glVertex2f(-0.19, 0.04); // 2
        glVertex2f(-0.04, 0.01); // 3
        glVertex2f(-0.04, 0.04); // 4
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(0.19, 0.06); // 1
        glVertex2f(0.19, 0.04); // 2
        glVertex2f(0.04, 0.01); // 3
        glVertex2f(0.04, 0.04); // 4
        glEnd();
        break;
    case 2:
        glColor3ub(0, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(-0.15, 0.06); // 1
        glVertex2f(-0.19, 0.04); // 2
        glVertex2f(-0.04, 0.07); // 3
        glVertex2f(-0.04, 0.1);  // 4
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(0.15, 0.06); // 1
        glVertex2f(0.19, 0.04); // 2
        glVertex2f(0.04, 0.07); // 3
        glVertex2f(0.04, 0.1);  // 4
        glEnd();
        break;
    case 3:
        glColor3ub(0, 0, 0);

        glBegin(GL_POLYGON);
        glVertex2f(-0.2, 0.08); // 1
        glVertex2f(-0.2, 0.06); // 2
        glVertex2f(0.2, 0.06);  // 3
        glVertex2f(0.2, 0.08);  // 4
        glEnd();
        break;
    case 4:

        glColor3ub(0, 0, 0);

        glBegin(GL_POLYGON);
        glVertex2f(-0.14, 0.08); // 1
        glVertex2f(-0.14, 0.06); // 2
        glVertex2f(-0.15, 0.06); // 3
        glVertex2f(-0.15, 0.08); // 4
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-0.13, 0.08); // 1
        glVertex2f(-0.13, 0.06); // 2
        glVertex2f(-0.05, 0.06); // 3
        glVertex2f(-0.05, 0.08); // 4
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(0.05, 0.08); // 1
        glVertex2f(0.05, 0.06); // 2
        glVertex2f(0.15, 0.06); // 3
        glVertex2f(0.15, 0.08); // 4
        glEnd();
        break;
    case 5:
        glColor3ub(200, 0, 0);
        glBegin(GL_POLYGON);
        circulo(0, 0.06, 0.015, 50);
        glEnd();
        break;
    default:
        glColor3ub(0, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(-0.1, 0.06); // 1
        glVertex2f(-0.1, 0.05); // 2
        glVertex2f(0.1, 0.05);  // 3
        glVertex2f(0.1, 0.06);  // 4
        glEnd();
        glColor3ub(0, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(-0.1, 0.09); // 1
        glVertex2f(-0.1, 0.08); // 2
        glVertex2f(0.1, 0.08);  // 3
        glVertex2f(0.1, 0.09);  // 4
        glEnd();
        break;
    }

    // CHAPEEEEU DE PALHAAAAA GERAL
    switch (flagChapeu)
    {
    case 1:
        glColor3ub(193, 0, 0);
        glBegin(GL_POLYGON);      // Desenha a parte vermelha do gorro
        glVertex2f(-0.144, 0.35); // Canto inferior esquerdo
        glVertex2f(0.35, 0.5);    // Canto inferior direito
        glVertex2f(-0.07, 0.5);   // Topo
        glEnd();

        // Desenha o gorro de Natal
        glColor3ub(255, 0, 0); // Cor vermelha para o gorro
        glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.22, 0.19); // Canto inferior esquerdo
        glVertex2f(-0.07, 0.5);  // Canto inferior direito
        glVertex2f(0.22, 0.19);  // Topo
        glVertex2f(0.07, 0.5);   // Topo
        glEnd();

        // Desenha a parte branca do gorro
        glColor3ub(255, 255, 255); // Cor branca para a parte branca do gorro
        glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.25, 0.12); // Canto inferior esquerdo
        glVertex2f(-0.25, 0.19); // Canto inferior direito
        glVertex2f(0.25, 0.12);  // Topo
        glVertex2f(0.25, 0.19);  // Topo
        glEnd();

        // Desenha a bola no topo do gorro
        glColor3ub(255, 255, 255); // Cor vermelha para a bola
        glBegin(GL_POLYGON);
        circulo(0.35, 0.5, 0.05, 30); // Desenha um círculo centrado no topo do gorro
        glEnd();

        glFlush();
        break;
    case 2:
        glColor3ub(98, 98, 98);
        glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.25, 0.19); // Canto inferior esquerdo
        glVertex2f(-0.3, 0.55);  // Canto inferior direito
        glVertex2f(0.25, 0.19);  // Topo
        glVertex2f(0.3, 0.55);   // Topo
        glEnd();

        glColor3ub(88, 88, 88); //
        glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.3, 0.12); // Canto inferior esquerdo
        glVertex2f(-0.3, 0.19); // Canto inferior direito
        glVertex2f(0.3, 0.12);  // Topo
        glVertex2f(0.3, 0.19);  // Topo
        glEnd();

        glColor3ub(30, 147, 38); //
        glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.25, 0.21); // Canto inferior esquerdo
        glVertex2f(-0.25, 0.19); // Canto inferior direito
        glVertex2f(0.25, 0.21);  // Topo
        glVertex2f(0.25, 0.19);  // Topo
        glEnd();
        break;
    case 3:
        glColor3ub(255, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(-0.21, 0.33);  // 0
        glVertex2f(-0.235, 0.29); // 1
        glVertex2f(-0.235, 0.1);  // 2
        glVertex2f(-0.175, 0.05); // 3
        glVertex2f(0.175, 0.05);  // 4
        glVertex2f(0.235, 0.1);   // 5
        glVertex2f(0.235, 0.29);  // 6
        glVertex2f(0.21, 0.33);   // 7
        glEnd();

        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        circulo(0, 0.2, 0.08, 50);
        glEnd();

        glColor3ub(0, 0, 0);
        glBegin(GL_LINE_STRIP);
        glVertex2f(-0.06, 0.16); // Ponto 1
        glVertex2f(-0.03, 0.25); // Ponto 2
        glVertex2f(0.0, 0.2);    // Ponto 3
        glVertex2f(0.03, 0.25);  // Ponto 4
        glVertex2f(0.06, 0.16);  // Ponto 5
        glEnd();
        break;
    case 4:
        glColor3ub(255, 201, 14); // Cor branca para a parte branca do gorro
        glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.38, 0.12); // Canto inferior esquerdo
        glVertex2f(-0.38, 0.19); // Canto inferior direito
        glVertex2f(0.38, 0.12);  // Topo
        glVertex2f(0.38, 0.19);  // Topo
        glEnd();

        glBegin(GL_POLYGON);
        meiaLua(0, -0.15, -0.28, 30);
        glEnd();

        glColor3ub(255, 0, 0);
        glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.28, 0.22); // Canto inferior esquerdo
        glVertex2f(-0.28, 0.19); // Canto inferior direito
        glVertex2f(0.28, 0.22);  // Topo
        glVertex2f(0.28, 0.19);  // Topo
        glEnd();
        break;
    case 5:
        glColor3ub(80, 80, 80); //
        glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.3, 0.12); // Canto inferior esquerdo
        glVertex2f(-0.3, 0.39); // Canto inferior direito
        glVertex2f(0.3, 0.12);  // Topo
        glVertex2f(0.3, 0.39);  // Topo
        glEnd();
        glColor3ub(62, 62, 62); //
        glBegin(GL_QUAD_STRIP);
        glVertex2f(0, 0.25);    // Canto inferior esquerdo
        glVertex2f(-0.5, 0.39); // Canto inferior direito
        glVertex2f(0.5, 0.39);  // Topo
        glVertex2f(0, 0.45);    // Topo
        glEnd();
        glColor3ub(255, 201, 14); //
        glBegin(GL_TRIANGLES);
        glVertex2f(0.48, 0.15); // Vértice 1
        glVertex2f(0.52, 0.15); // Vértice 2
        glVertex2f(0.5, 0.39);  // Vértice 3
        glEnd();
        break;
    default:
        glColor3ub(0, 128, 0);
        glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.25, 0.19); // Canto inferior esquerdo
        glVertex2f(-0.3, 0.55);  // Canto inferior direito
        glVertex2f(0.25, 0.19);  // Topo
        glVertex2f(0.3, 0.55);   // Topo
        glEnd();

        glColor3ub(0, 128, 0); //
        glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.3, 0.12); // Canto inferior esquerdo
        glVertex2f(-0.3, 0.19); // Canto inferior direito
        glVertex2f(0.3, 0.12);  // Topo
        glVertex2f(0.3, 0.19);  // Topo
        glEnd();
        // faixa cinza
        glColor3ub(81, 81, 81); //
        glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.27, 0.25); // Canto inferior esquerdo
        glVertex2f(-0.27, 0.19); // Canto inferior direito
        glVertex2f(0.27, 0.25);  // Topo
        glVertex2f(0.27, 0.19);  // Topo
        glEnd();
        // fivela dourada
        glColor3ub(250, 189, 5); //
        glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.05, 0.27); // Canto inferior esquerdo
        glVertex2f(-0.05, 0.19); // Canto inferior direito
        glVertex2f(0.05, 0.27);  // Topo
        glVertex2f(0.05, 0.19);  // Topo
        glEnd();
        glColor3ub(81, 81, 81); //
        glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.04, 0.26); // Canto inferior esquerdo
        glVertex2f(-0.04, 0.2);  // Canto inferior direito
        glVertex2f(0.04, 0.26);  // Topo
        glVertex2f(0.04, 0.2);   // Topo
        glEnd();
        break;
    }

    glFlush();
}

// TECLAS COMNUNS
void keyboard(unsigned char key, int x, int y)
{
    // printf("*** Tratamento de teclas comuns\n");
    // printf(">>> Tecla pressionada: %c\n", key);
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
        glutPostRedisplay();
        break;
    case '6':
        flagOlhos = 6;
        glutPostRedisplay();
        break;

    // Olho azul
    case 'u':
        R2 = 125;
        G2 = 173;
        B2 = 217;
        glutPostRedisplay();
        break;
    // Olho preto
    case 'i':
        R2 = 0;
        G2 = 0;
        B2 = 0;
        glutPostRedisplay();
        break;
    // Olho castanho
    case 'o':
        R2 = 79;
        G2 = 50;
        B2 = 25;
        glutPostRedisplay();
        break;

    // Boca
    // FLAG PARA BOCA
    case 'q':
        flagBoca = 1;
        glutPostRedisplay();
        break;
    case 'w':
        flagBoca = 2;
        glutPostRedisplay();
        break;
    case 'e':
        flagBoca = 3;
        glutPostRedisplay();
        break;
    case 'r':
        flagBoca = 4;
        glutPostRedisplay();
        break;
    case 't':
        flagBoca = 5;
        glutPostRedisplay();
        break;
    case 'y':
        flagBoca = 6;
        glutPostRedisplay();
        break;

    // NARIZZZZZZ RAFIVIS
    case 'z':
        flagNariz = 1;
        glutPostRedisplay();
        break;
    case 'x':
        flagNariz = 2;
        glutPostRedisplay();
        break;
    case 'c':
        flagNariz = 3;
        glutPostRedisplay();
        break;
    case 'v':
        flagNariz = 4;
        glutPostRedisplay();
        break;
    case 'b':
        flagNariz = 5;
        glutPostRedisplay();
        break;
    case 'n':
        flagNariz = 6;
        glutPostRedisplay();
        break;

    // SOMBRANCELHA
    case 'a':
        flagSombra = 1;
        glutPostRedisplay();
        break;
    case 's':
        flagSombra = 2;
        glutPostRedisplay();
        break;
    case 'd':
        flagSombra = 3;
        glutPostRedisplay();
        break;
    case 'f':
        flagSombra = 4;
        glutPostRedisplay();
        break;
    case 'g':
        flagSombra = 5;
        glutPostRedisplay();
        break;
    case 'h':
        flagSombra = 6;
        glutPostRedisplay();
        break;

    // Mudas cor de pele
    case 'j':
        R = 253;
        G = 238;
        B = 212;
        glutPostRedisplay();
        break;
    case 'k':
        R = 247;
        G = 219;
        B = 187;
        glutPostRedisplay();
        break;
    case 'l':
        R = 238;
        G = 187;
        B = 152;
        glutPostRedisplay();
        break;
    case 'm':
        R = 214;
        G = 162;
        B = 123;
        glutPostRedisplay();
        break;
    case '7':
        R = 190;
        G = 130;
        B = 106;
        glutPostRedisplay();
        break;
    case '8':
        R = 136;
        G = 86;
        B = 61;
        glutPostRedisplay();
        break;
    }
}

void Special_keyboard(GLint tecla, int x, int y)
{
    switch (tecla)
    {
    // CABECAS F1 ... F6
    case GLUT_KEY_F1:
        flagCabeca = 1;
        radBoca = 0.1;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F2:
        flagCabeca = 2;
        radBoca = 0.1;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F3:
        flagCabeca = 3;
        radBoca = 0.1;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F4:
        flagCabeca = 4;
        radBoca = 0.12;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F5:
        flagCabeca = 5;
        radBoca = 0.12;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F6:
        flagCabeca = 6;
        radBoca = 0.12;
        glutPostRedisplay();
        break;

    // Flag do CHAPEU
    case GLUT_KEY_F7:
        flagChapeu = 1;
        glutPostRedisplay();
        break;

    case GLUT_KEY_F8:
        flagChapeu = 2;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F9:
        flagChapeu = 3;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F10:
        flagChapeu = 4;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F11:
        flagChapeu = 5;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F12:
        flagChapeu = 6;
        glutPostRedisplay();
        break;
    }
}

void DesenhaTexto(char *string)
{
    glColor3ub(136, 0, 121);
    glPushMatrix();
    glRasterPos2f(-0.4, 0.95);
    while (*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
    glPopMatrix();
    glColor3ub(255, 255, 255);
}

void DesenhaMenu()
{
    char string[] = "Cabeca: F1 ... F6";
    char *pont;
    pont = string;
    glColor3ub(255, 128, 0);
    glPushMatrix();
    glRasterPos2f(-1, 0.85);
    while (*pont)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *pont++);
    glPopMatrix();

    char string2[] = "Chapeu: F7 ... F12";
    pont = string2;
    glColor3ub(255, 128, 0);
    glPushMatrix();
    glRasterPos2f(-1, 0.75);
    while (*pont)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *pont++);
    glPopMatrix();

    char string3[] = "Olhos: 1 ... 6";
    pont = string3;
    glColor3ub(255, 128, 0);
    glPushMatrix();
    glRasterPos2f(-1, 0.65);
    while (*pont)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *pont++);
    glPopMatrix();

    char string4[] = "Boca: 'q', 'w', 'e', 'r', 't', y'";
    pont = string4;
    glColor3ub(255, 128, 0);
    glPushMatrix();
    glRasterPos2f(0.07, 0.85);
    while (*pont)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *pont++);
    glPopMatrix();

    char string5[] = "Sombrancelha 'a', 's', 'd', 'f', 'g', h'";
    pont = string5;
    glColor3ub(255, 128, 0);
    glPushMatrix();
    glRasterPos2f(0.07, 0.75);
    while (*pont)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *pont++);
    glPopMatrix();

    char string6[] = "Nariz: 'z', 'x', 'c', 'v', 'b', 'n'";
    pont = string6;
    glColor3ub(255, 128, 0);
    glPushMatrix();
    glRasterPos2f(0.07, 0.65);
    while (*pont)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *pont++);
    glPopMatrix();

    char string7[] = "Tom de pele: '7', '8', 'j', 'l', 'm'";
    pont = string7;
    glColor3ub(255, 128, 0);
    glPushMatrix();
    glRasterPos2f(-1, 0.55);
    while (*pont)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *pont++);
    glPopMatrix();

    char string8[] = "Cor do olho: 'u', 'i', 'o'";
    pont = string8;
    glColor3ub(255, 128, 0);
    glPushMatrix();
    glRasterPos2f(0.07, 0.55);
    while (*pont)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *pont++);
    glPopMatrix();
}

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
    for (int i = 0; i <= numSegments1 / 2; i++)
    {
        float angle = 2.0f * PI * i / numSegments1;
        angle / 2;
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
    for (int i = 0; i <= numSegments / metade; ++i)
    {
        float angle = 2.0f * PI * i / numSegments;
        float x = centerX + (radius * cos(angle));
        float y = centerY + (radius * sin(angle));
        glVertex2f(x, y / 2);
    }
    glEnd();
}