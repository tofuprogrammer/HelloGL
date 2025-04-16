#include "gl/freeglut.h"
#include "glut_callbacks.hpp"
#include "hello_gl.hpp"
#include "mesh_loader.hpp"

#define REFRESHRATE 8

hello_gl::hello_gl(int argc, char* argv[])
{
	init_gl(argc, argv);
	init_objects();
	glutMainLoop(); // Enters the GLUT main loop
}

int main(int argc, char* argv[])
{
	hello_gl* game = new hello_gl(argc, argv); // Creates a new instance of the game
}

hello_gl::~hello_gl()
{
	delete m_camera;
}

void hello_gl::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clears the color buffer

	for (int iterator = 0; iterator < 200; iterator++)
	{
		m_cube[iterator]->draw();
	}

	glFlush(); // Flushes the buffer to the GPU

	glutSwapBuffers(); // Swaps the buffers
}

void hello_gl::update()
{
	glLoadIdentity();
	gluLookAt(m_camera->eye.x, m_camera->eye.y, m_camera->eye.z, m_camera->center.x, m_camera->center.y, m_camera->center.z, m_camera->up.x, m_camera->up.y, m_camera->up.z);
	for (int iterator = 0; iterator < 200; iterator++)
	{
		m_cube[iterator]->update();
	}
	if (m_rotation >= 360)
	{
		m_rotation = 0.0f;
	}
	glutPostRedisplay();
}

void hello_gl::keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
		m_rotation += 2.0f;
	if (key == 'a')
		m_rotation -= 2.0f;
	if (key == 'j')
		m_camera->eye.x -= 2.0f;
	if (key == 'l')
		m_camera->eye.x += 2.0f;
	if (key == 'p')
		m_camera->eye.y += 2.0f;
	if (key == '.')
		m_camera->eye.y -= 2.0f;
	if (key == '=')
		m_camera->eye.z += 2.0f;
	if (key == '-')
		m_camera->eye.z -= 2.0f;
}

void hello_gl::init_gl(int argc, char* argv[])
{
	glut_callbacks::init(this); // Initializes the callback function
	glutInit(&argc, argv); // Initializes the GLUT library
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); // Sets the display mode (enables double buffering and depth testing)
	glutInitWindowSize(800, 600); // Sets the window size
	glutInitWindowPosition(100, 100); // Sets the window position
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(glut_callbacks::display);
	glutTimerFunc(REFRESHRATE, glut_callbacks::timer, REFRESHRATE);
	glutKeyboardFunc(glut_callbacks::keyboard);

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

void hello_gl::init_objects()
{
	m_rotation = 0.0f;
	m_camera = new camera();
	mesh* cube_mesh = mesh_loader::load("cube.txt");
	for (int iteration = 0; iteration < 200; iteration++)
	{
		m_cube[iteration] = new cube(cube_mesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
	m_camera->eye.x = 3.0f; m_camera->eye.y = 0.0f; m_camera->eye.z = -123.0f;
	m_camera->center.x = 0.0f; m_camera->center.y = 0.0f; m_camera->center.z = 0.0f;
	m_camera->up.x = 0.0f; m_camera->up.y = 1.0f; m_camera->up.z = 0.0f;
}
