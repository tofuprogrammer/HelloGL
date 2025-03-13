#include "HelloGL.hpp"

HelloGL::HelloGL(int argc, char* argv[]) {
	rotation = 0.0f;
	GLUTCallbacks::Init(this); // Initializes the callback function
	glutInit(&argc, argv); // Initializes the GLUT library
	glutInitWindowSize(1920, 1080); // Sets the window size
	glutCreateWindow("HelloGL");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutMainLoop();
}

int main(int argc, char* argv[]) {
	HelloGL* game = new HelloGL(argc, argv); // Creates a new instance of the game
}

HelloGL::~HelloGL(void) {
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); // Clears the color buffer

	DrawPolygon();

	glFlush(); // Flushes the buffer to the GPU
}

void HelloGL::Update() {
	rotation += 2.0f;
	if (rotation >= 360) {
		rotation = 0.0f;
	}
	glutPostRedisplay();
}

void HelloGL::DrawPolygon() {
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);

	glBegin(GL_QUADS);
		// Rectangle
		glColor3f(1.0f, 0.0f, 1.0f); // Pink
		glVertex2f(-0.6, 0.5);
		glVertex2f(-0.9, 0.5);
		glColor3f(1.0f, 1.0f, 0.0f); // Yellow
		glVertex2f(-0.9, -0.5);
		glVertex2f(-0.6, -0.5);
		glEnd();

	glPopMatrix();

	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);

	glBegin(GL_TRIANGLES); 
		// Equilateral triangle
		glColor3f(1.0f, 1.0f, 1.0f); // White
		glVertex2f(0.75, 0.15);
		glColor3f(1.0f, 0.0f, 0.5f); // Red-pink
		glVertex2f(0.6, -0.15);
		glVertex2f(0.9, -0.15);
		glEnd();

	glPopMatrix();
}