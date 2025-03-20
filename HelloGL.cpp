#include "HelloGL.hpp"

HelloGL::HelloGL(int argc, char* argv[]) {
	rotation = 0.0f;
	camera = new Camera();
	camera->eye = { 0.0f, 0.0f, 1.0f };
	camera->center = { 0.0f, 0.0f, 0.0f };
	camera->up = { 0.0f, 1.0f, 0.0f };
	GLUTCallbacks::Init(this); // Initializes the callback function
	glutInit(&argc, argv); // Initializes the GLUT library
	glutInitDisplayMode(GLUT_DOUBLE); // Sets the display mode (enables double buffering)
	glutInitWindowSize(1000, 1000); // Sets the window size
	glutInitWindowPosition(100, 100); // Sets the window position
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glMatrixMode(GL_PROJECTION); // Switches to the projection matrix
	glLoadIdentity(); // Loads the identity matrix
	glViewport(0, 0, 1000, 1000); // Sets the viewport to match the window
	gluPerspective(45, 1, 1, 1000); // Sets the perspective projection, 1000); // Sets the perspective projection
	glMatrixMode(GL_MODELVIEW); // Switches to the modelview matrix
	glutMainLoop(); // Enters the GLUT main loop
}

int main(int argc, char* argv[]) {
	HelloGL* game = new HelloGL(argc, argv); // Creates a new instance of the game
}

HelloGL::~HelloGL(void) {
	delete camera;
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); // Clears the color buffer

	DrawPolygon();

	glFlush(); // Flushes the buffer to the GPU

	glutSwapBuffers(); // Swaps the buffers
}

void HelloGL::Update() {
	glLoadIdentity();
	if (rotation >= 360) {
		rotation = 0.0f;
	}
	glutPostRedisplay();
}

void HelloGL::DrawPolygon() {
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation, -1.0f, -1.0f, -1.0f);

	glBegin(GL_QUADS);
	// Rectangle
	glColor3f(1.0f, 0.0f, 1.0f); // Pink
	glVertex2f(-0.5, 0.5);
	glVertex2f(-0.9, 0.5);
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(-0.9, -0.5);
	glVertex2f(-0.5, -0.5);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation, 1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLES); 
	// Equilateral triangle
	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex2f(0.75, 0.15);
	glColor3f(1.0f, 0.0f, 0.5f); // Red-pink
	glVertex2f(0.5, -0.15);
	glVertex2f(0.9, -0.15);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation, 1.0f, -1.0f, 1.0f);

	glBegin(GL_QUADS);
	// Square
	glColor3f(0.0f, 1.0f, 1.0f); // Cyan
	glVertex2f(0.4, 0.4);
	glVertex2f(-0.4, 0.4);
	glColor3f(0.0f, 0.0f, 1.0f); // Blue
	glVertex2f(-0.4, -0.4);
	glVertex2f(0.4, -0.4);
	glEnd();

	glPopMatrix();
}

void HelloGL::keyboard(unsigned char key, int x, int y) {
	if (key == 'd')
		rotation += 2.0f;
	else if (key == 'a')
		rotation -= 2.0f;
}