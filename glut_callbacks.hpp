#pragma once

class hello_gl;

namespace glut_callbacks
{
	void display();
	void init(hello_gl* gl);
	void keyboard(unsigned char key, int x, int y);
	void timer(int preferred_refresh);
}
