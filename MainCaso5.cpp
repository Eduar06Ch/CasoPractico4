#include <GL/glut.h> // Incluimos la librer�a de OPEN GL
#include <iostream>

using namespace std;

// Definimos los v�rtices del pent�gono
GLfloat vertices[][2]={{-0.5,-0.3},{0.5,-0.3},{0.8,0.3},{0.0,0.8},{-0.8,0.3}};

// Funci�n para dibujar el pol�gono
void drawPolygon(){
    glClear(GL_COLOR_BUFFER_BIT); // Limpiamos la ventana gr�fica
    glMatrixMode(GL_MODELVIEW); // Seleccionamos la matriz de modelo/vista
    glLoadIdentity(); // Cargamos la matriz identidad
    
    // Dibujamos el pol�gono
    glColor3f(1.0,0.0,0.0); // Color rojo
    glBegin(GL_POLYGON); // Empezamos a dibujar el pol�gono
    for(int i=0;i<5;i++){ // Iteramos sobre los v�rtices del pent�gono
        glVertex2fv(vertices[i]); // Agregamos cada v�rtice al pol�gono
    }
    glEnd(); // Terminamos de dibujar el pol�gono
    glFlush(); // Forzamos la ejecuci�n de los comandos de OPEN GL
    
    // Aplicamos transformaciones
    glTranslatef(0.5, -0.5, 0.0); // Traslaci�n
    glScalef(0.8, 0.8, 0.8); // Escalamiento
    glRotatef(30.0, 0.0, 0.0, 1.0); // Rotaci�n
    
    // Dibujamos el pol�gono transformado
    glColor3f(0.0,0.0,1.0); // Color azul
    glBegin(GL_POLYGON); // Empezamos a dibujar el pol�gono
    for(int i=0;i<5;i++){ // Iteramos sobre los v�rtices del pent�gono
        glVertex2fv(vertices[i]); // Agregamos cada v�rtice al pol�gono
    }
    glEnd(); // Terminamos de dibujar el pol�gono
    glFlush(); // Forzamos la ejecuci�n de los comandos de OPEN GL
}

int main(int argc, char** argv){
    glutInit(&argc, argv); // Inicializamos GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Definimos el modo de visualizaci�n
    glutInitWindowSize(500, 500); // Definimos el tama�o de la ventana
    glutCreateWindow("Poligono"); // Creamos la ventana
    glutDisplayFunc(drawPolygon); // Especificamos la funci�n de dibujo
    glutMainLoop(); // Iniciamos el ciclo de eventos de GLUT
    return 0;
}
