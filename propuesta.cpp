#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

using namespace std;
float g = 9.8, v = 12, ang = 45;

void dibujar()
{
	glClear(GL_COLOR_BUFFER_BIT);//borra la pantalla gráfica como un CLS o un clear

	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(30.0, 0.0, 0.0);
	glVertex3f(0.0, 30.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_POINTS);
	float rad = ang / 57.3;
	for (float x = 0; x <= 1000; x = x + 0.2)
	{
		float y = tan(rad) * x - (g / (2 * v * v * cos(rad) * cos(rad))) * x * x;
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(x, y, 0.0);
		if (y < 0) break;
	}
	glEnd();
	glFlush();
}

void cambiarTamano(int ancho, int alto)
{
	if (alto == 0) alto = 1;
	float razon = 1.0 * ancho / alto;
	glMatrixMode(GL_PROJECTION);//activa el modo de proyeccion
	glLoadIdentity();//carga la imagen
	glViewport(0, 0, ancho, alto);
	gluPerspective(45, razon, 1, 1000);//cambia la perspectiva de acuerdo a la razon
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(10.0, 7.0, 20.0,//donde esta la camara
		10.0, 7.0, 0.0,//hacia donde esta viendo
		0.0, 1.0, 0.0);//cual es el eje hacia arriba
}

void Teclado(unsigned char tecla, int x, int y)
{
	switch (tecla)
	{
	case 27: exit(0); break;
	case 'f': glutFullScreen(); break;
	case 'r': glutReshapeWindow(1000, 600); glutPositionWindow(500, 200); break;
	case 'w': ang += 1; dibujar(); break;
	case 's': ang -= 1; dibujar(); break;
	case 'd': v += 1; dibujar(); break;
	case 'a': v -= 1; dibujar(); break;

	case 32:

		glPointSize(3);
		glBegin(GL_POINTS);
		glColor3f(1.0, 1.0, 1.0);
		float rad = ang / 57.3;
		for (float x = 0; x <= 1000; x = x + .02)
		{
			float y = tan(rad) * x - (g / (2 * v * v * cos(rad) * cos(rad))) * x * x;
			glVertex3f(x, y, 0.0);
			if (y < 0) break;
		}
		glEnd();
		glFlush();
	}
}

void Flechas(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP: ang += 1; dibujar(); break;
	case GLUT_KEY_DOWN: ang -= 1; dibujar(); break;
	case GLUT_KEY_RIGHT: v += 1; dibujar(); break;
	case GLUT_KEY_LEFT: v -= 1; dibujar(); break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(500, 200);
	glutInitWindowSize(1000, 600);
	glutCreateWindow("Tiro parabólico");
	glutKeyboardFunc(Teclado);
	glutSpecialFunc(Flechas);
	glutDisplayFunc(dibujar);
	glutReshapeFunc(cambiarTamano);
	glutMainLoop();

	return 0;
}