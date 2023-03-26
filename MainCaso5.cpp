#include <GL/glut.h> // Incluimos la librería de OPEN GL
#include <iostream>

using namespace std;

// Definimos los vértices del pentágono
GLfloat vertices[][2]={{-0.5,-0.3},{0.5,-0.3},{0.8,0.3},{0.0,0.8},{-0.8,0.3}};

// Función para dibujar el polígono
void drawPolygon(){
    glClear(GL_COLOR_BUFFER_BIT); // Limpiamos la ventana gráfica
    glMatrixMode(GL_MODELVIEW); // Seleccionamos la matriz de modelo/vista
    glLoadIdentity(); // Cargamos la matriz identidad
    
    // Dibujamos el polígono
    glColor3f(1.0,0.0,0.0); // Color rojo
    glBegin(GL_POLYGON); // Empezamos a dibujar el polígono
    for(int i=0;i<5;i++){ // Iteramos sobre los vértices del pentágono
        glVertex2fv(vertices[i]); // Agregamos cada vértice al polígono
    }
    glEnd(); // Terminamos de dibujar el polígono
    glFlush(); // Forzamos la ejecución de los comandos de OPEN GL
    
    // Aplicamos transformaciones
    glTranslatef(0.5, -0.5, 0.0); // Traslación
    glScalef(0.8, 0.8, 0.8); // Escalamiento
    glRotatef(30.0, 0.0, 0.0, 1.0); // Rotación
    
    // Dibujamos el polígono transformado
    glColor3f(0.0,0.0,1.0); // Color azul
    glBegin(GL_POLYGON); // Empezamos a dibujar el polígono
    for(int i=0;i<5;i++){ // Iteramos sobre los vértices del pentágono
        glVertex2fv(vertices[i]); // Agregamos cada vértice al polígono
    }
    glEnd(); // Terminamos de dibujar el polígono
    glFlush(); // Forzamos la ejecución de los comandos de OPEN GL
}

int main(int argc, char** argv){
    glutInit(&argc, argv); // Inicializamos GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Definimos el modo de visualización
    glutInitWindowSize(500, 500); // Definimos el tamaño de la ventana
    glutCreateWindow("Poligono"); // Creamos la ventana
    glutDisplayFunc(drawPolygon); // Especificamos la función de dibujo
    glutMainLoop(); // Iniciamos el ciclo de eventos de GLUT
    return 0;
}
