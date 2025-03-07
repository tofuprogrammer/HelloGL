#include "HelloGL.hpp"

HelloGL::HelloGL(int argc, char* argv[]) {
	GLUTCallbacks::Init(this); // Initializes the callback function
	glutInit(&argc, argv); // Initializes the GLUT library
	glutCreateWindow("HelloGL");
	glutInitWindowSize(800, 600); // Sets the window size
	glutDisplayFunc(GLUTCallbacks::Display);
	glutMainLoop();
}

int main(int argc, char* argv[]) {
	HelloGL* game = new HelloGL(argc, argv); // Creates a new instance of the game
}

HelloGL::~HelloGL(void) {
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 1.0f); // Pink
	glVertex2f(-0.75, 0.5);
	glVertex2f(0.75, 0.5);
	glColor3f(1.0f, 1.0f, 0.0f); // Brown
	glVertex2f(0.75, -0.5);
	glVertex2f(-0.75, -0.5);
	glEnd();
	glFlush();
}