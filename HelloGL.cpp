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
}