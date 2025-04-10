#include "HelloGL.hpp"

#define REFRESHRATE 8

HelloGL::HelloGL(int argc, char* argv[])
{
	InitGL(argc, argv);
	InitObjects();
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clears the color buffer

	for (int iterator = 0; iterator < 200; iterator++) {
		cube[iterator]->Draw();
	}

	glFlush(); // Flushes the buffer to the GPU

	glutSwapBuffers(); // Swaps the buffers
}

void HelloGL::Update() {
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	for (int iterator = 0; iterator < 200; iterator++) {
		cube[iterator]->Update();
	}
	if (rotation >= 360) {
		rotation = 0.0f;
	}
	glutPostRedisplay();
}

void HelloGL::Keyboard(unsigned char key, int x, int y) {
	if (key == 'd')
		rotation += 2.0f;
	if (key == 'a')
		rotation -= 2.0f;
	if (key == 'j')
		camera->eye.x -= 2.0f;
	if (key == 'l')
		camera->eye.x += 2.0f;
	if (key == 'p')
		camera->eye.y += 2.0f;
	if (key == '.')
		camera->eye.y -= 2.0f;
	if (key == '=')
		camera->eye.z += 2.0f;
	if (key == '-')
		camera->eye.z -= 2.0f;
}

void HelloGL::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this); // Initializes the callback function
	glutInit(&argc, argv); // Initializes the GLUT library
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); // Sets the display mode (enables double buffering and depth testing)
	glutInitWindowSize(800, 600); // Sets the window size
	glutInitWindowPosition(100, 100); // Sets the window position
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);

	glMatrixMode(GL_PROJECTION); // Switches to the projection matrix
	glLoadIdentity(); // Loads the identity matrix
	glViewport(0, 0, 1000, 1000); // Sets the viewport to match the window
	gluPerspective(55, 4.0/3.0f, 0.1f, 1000); // Sets the perspective projection
	glMatrixMode(GL_MODELVIEW); // Switches to the modelview matrix
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Sets the clear color to black
	glEnable(GL_DEPTH_TEST); // Enables depth testing
	glEnable(GL_CULL_FACE); // Enables backface culling
	glCullFace(GL_BACK); // Culls the backface
}

void HelloGL::InitObjects()
{
	rotation = 0.0f;
	camera = new Camera();
	for (int iteration = 0; iteration < 200; iteration++)
	{
		cube[iteration] = new Cube(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
	camera->eye.x = 3.0f; camera->eye.y = 0.0f; camera->eye.z = -123.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	Cube::Load((char*) "cube.txt");
}
