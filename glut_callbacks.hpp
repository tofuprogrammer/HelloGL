#pragma once

class Hello_gl;

namespace glut_callbacks
{
	void display();
	void init(Hello_gl* gl);
	void keyboard(unsigned char key, int x, int y);
	void timer(int preferred_refresh);
}