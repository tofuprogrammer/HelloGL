#include "HelloGL.hpp"

HelloGL::HelloGL(int argc, char* argv[]) {
	GLUTCallbacks::Init(this); // Initializes the callback function
	glutInit(&argc, argv); // Initializes the GLUT library
	glutInitWindowSize(1920, 1080); // Sets the window size
	glutCreateWindow("HelloGL");
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
	DrawPolygon();
	glFlush();
}

void HelloGL::DrawPolygon() {
	glBegin(GL_QUADS);
		// Rectangle
		glColor3f(1.0f, 0.0f, 1.0f); // Pink
		glVertex2f(-0.85, 0.5);
		glVertex2f(-0.95, 0.5);
		glColor3f(1.0f, 1.0f, 0.0f); // Yellow
		glVertex2f(-0.95, -0.5);
		glVertex2f(-0.85, -0.5);
		glEnd();

	glBegin(GL_TRIANGLES); 
		// Equilateral triangle
		glColor3f(1.0f, 1.0f, 1.0f); // White
		glVertex2f(-0.75, -0.4);
		glColor3f(1.0f, 0.0f, 0.5f); // Red-pink
		glVertex2f(-0.8, -0.5);
		glVertex2f(-0.7, -0.5);
		glEnd();

}