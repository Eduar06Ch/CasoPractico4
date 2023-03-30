#include <GL/glut.h> // Biblioteca de OpenGL
#include <iostream> // Biblioteca de entrada y salida
#include <math.h> // Biblioteca matemática

// Definir el número de lados del polígono
#define N 5

// Definir los puntos del polígono
float vertices[N][2] = {{-0.5, -0.5}, {-0.25, 0.5}, {0.25, 0.5}, {0.5, -0.5}, {0, -0.75}};

// Variables para las transformaciones
float tx = 0, ty = 0; // Traslación
float sx = 1, sy = 1; // Escalamiento
float theta = 0; // Rotación

// Función de dibujado
void drawPolygon() {
    // Limpiar la pantalla
    glClear(GL_COLOR_BUFFER_BIT);

    // Dibujar el polígono
    glBegin(GL_POLYGON);
    for (int i = 0; i < N; i++) {
        glVertex2f(vertices[i][0], vertices[i][1]);
    }
    glEnd();

    // Actualizar la pantalla
    glutSwapBuffers();
}

// Función de teclado
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Traslación
         case 'w':
            ty += 0.1;
            break;
        case 's':
            ty -= 0.1;
            break;
        case 'a':
            tx -= 0.1;
            break;
        case 'd':
            tx += 0.1;
            break;
        // Escalamiento
        case '+':
            sx += 0.1;
            sy += 0.1;
            break;
        case '-':
            sx -= 0.1;
            sy -= 0.1;
            break;
        // Rotación
        case 'r':
            theta += 10;
            break;
        case 't':
            theta -= 10;
            break;
    }
    // Aplicar transformaciones
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(tx, ty, 0);
    glRotatef(theta, 0, 0, 1);
    glScalef(sx, sy, 1);
    glutPostRedisplay();
}

// Función de inicialización
void init() {
    // Configurar el modo de visualización
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

// Función principal
int main(int argc, char** argv) {
    // Inicializar OpenGL y GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Polígono");

    // Configurar la función de dibujado y de teclado
    glutDisplayFunc(drawPolygon);
    glutKeyboardFunc(keyboard);

    // Configurar la función de inicialización
    init();

    // Iniciar el bucle de eventos
    glutMainLoop();

    return 0;
}
