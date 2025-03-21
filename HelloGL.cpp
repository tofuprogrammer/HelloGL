#include "HelloGL.hpp"

Vertex HelloGL::vertices[] = {
1, 1, 1, -1, 1, 1, -1,-1, 1, // v0-v1-v2 (front)
-1,-1, 1, 1,-1, 1, 1, 1, 1, // v2-v3-v0

1, 1, 1, 1,-1, 1, 1,-1,-1, // v0-v3-v4 (right)
1,-1,-1, 1, 1,-1, 1, 1, 1, // v4-v5-v0

1, 1, 1, 1, 1,-1, -1, 1,-1, // v0-v5-v6 (top)
-1, 1,-1, -1, 1, 1, 1, 1, 1, // v6-v1-v0

-1, 1, 1, -1, 1,-1, -1,-1,-1, // v1-v6-v7 (left)
-1,-1,-1, -1,-1, 1, -1, 1, 1, // v7-v2-v1

-1,-1,-1, 1,-1,-1, 1,-1, 1, // v7-v4-v3 (bottom)
1,-1, 1, -1,-1, 1, -1,-1,-1, // v3-v2-v7

1,-1,-1, -1,-1,-1, -1, 1,-1, // v4-v7-v6 (back)
-1, 1,-1, 1, 1,-1, 1,-1,-1 }; // v6-v5-v4

Colour HelloGL::colours[] = {
1, 1, 1, 1, 1, 0, 1, 0, 0, // v0-v1-v2 (front)
1, 0, 0, 1, 0, 1, 1, 1, 1, // v2-v3-v0

1, 1, 1, 1, 0, 1, 0, 0, 1, // v0-v3-v4 (right)
0, 0, 1, 0, 1, 1, 1, 1, 1, // v4-v5-v0

1, 1, 1, 0, 1, 1, 0, 1, 0, // v0-v5-v6 (top)
0, 1, 0, 1, 1, 0, 1, 1, 1, // v6-v1-v0

1, 1, 0, 0, 1, 0, 0, 0, 0, // v1-v6-v7 (left)
0, 0, 0, 1, 0, 0, 1, 1, 0, // v7-v2-v1

0, 0, 0, 0, 0, 1, 1, 0, 1, // v7-v4-v3 (bottom)
1, 0, 1, 1, 0, 0, 0, 0, 0, // v3-v2-v7

0, 0, 1, 0, 0, 0, 0, 1, 0, // v4-v7-v6 (back)
0, 1, 0, 0, 1, 1, 0, 0, 1 // v6-v5-v4
};

Vertex HelloGL::indexedVertices[] = {
1, 1, 1, -1, 1, 1, // v0, v1
-1, -1, 1, 1, -1, 1, // v2, v3
1, -1, -1, 1, 1, -1, // v4, v5
-1, 1, -1, -1, -1, -1 // v6, v7
};

Colour HelloGL::indexedColours[] = {
1, 1, 1, 1, 1, 0, // v0, v1
1, 0, 0, 1, 0, 1, // v2, v3
0, 0, 1, 0, 1, 1, // v4, v5
0, 1, 0, 0, 0, 0 // v6, v7
};

GLushort HelloGL::indices[] = {
0, 1, 2, 2, 3, 0, // front
0, 3, 4, 4, 5, 0, // right
0, 5, 6, 6, 1, 0, // top
1, 6, 7, 7, 2, 1, // left
7, 4, 3, 3, 2, 7, // bottom
4, 7, 6, 6, 5, 4 // back
};

HelloGL::HelloGL(int argc, char* argv[]) {
	rotation = 0.0f;
	camera = new Camera();
	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
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
	gluPerspective(45, 1, 1, 1000); // Sets the perspective projection
	glMatrixMode(GL_MODELVIEW); // Switches to the modelview matrix
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Sets the clear color to black
	glEnable(GL_CULL_FACE); // Enables backface culling
	glCullFace(GL_BACK); // Culls the backface

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

	// DrawPolygon();
	// DrawTorus();
	// DrawCube();
	// DrawCubeArray();
	DrawIndexedCube();

	glFlush(); // Flushes the buffer to the GPU

	glutSwapBuffers(); // Swaps the buffers
}

void HelloGL::Update() {
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
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

void HelloGL::DrawTorus() {
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation, 1.0f, 1.0f, 1.0f);
	glutWireTorus(0.4, 1.0, 50, 50);
	glPopMatrix();
}

void HelloGL::DrawCube() {
	glPushMatrix();
	glRotatef(rotation, -1.0f, -1.0f, -1.0f);

	glBegin(GL_TRIANGLES);
	// face v0-v1-v2
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);

	// face v2-v3-v0
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);

	// face v0-v3-v4
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);

	// face v4-v5-v0
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);

	// face v0-v5-v6
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);

	// face v6-v1-v0
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);

	// face v1-v6-v7
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);

	// face v7-v2-v1
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);

	// face v7-v4-v3
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);

	// face v3-v2-v7
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);

	// face v4-v7-v6
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);

	// face v6-v5-v4
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);

	glEnd();

	glPopMatrix();
}

void HelloGL::DrawCubeArray() {
	glPushMatrix();
	glRotatef(rotation, -1.0f, -1.0f, -1.0f);

	glBegin(GL_TRIANGLES);
	for (int index = 0; index < 36; index++) {
		glColor3fv(&colours[index].r);
		glVertex3fv(&vertices[index].x);
	}
	glEnd();

	glPopMatrix();
}

void HelloGL::DrawIndexedCube() {
	glPushMatrix();
	glRotatef(rotation, -1.0f, -1.0f, -1.0f);

	glBegin(GL_TRIANGLES);
	for (int index = 0; index < 36; index++) {
		glColor3fv(&indexedColours[indices[index]].r);
		glVertex3fv(&indexedVertices[indices[index]].x);
	}
	glEnd();

	glPopMatrix();
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