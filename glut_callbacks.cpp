#include "Classes.hpp"
#include "Hello_gl.hpp"

namespace glut_callbacks
{
	Hello_gl* hello_gl = nullptr;

	void display()
	{
		if (hello_gl != nullptr)
		{
			hello_gl->display();
		}
	}

	void init(Hello_gl* gl)
	{
		hello_gl = gl;
	}

	void keyboard(unsigned char key, int x, int y)
	{
		if (hello_gl != nullptr)
		{
			hello_gl->keyboard(key, x, y);
		}
	}

	void timer(int preferred_refresh)
	{
		if (hello_gl != nullptr)
		{
			int time_to_update = glutGet(GLUT_ELAPSED_TIME);
			hello_gl->update();
			time_to_update = glutGet(GLUT_ELAPSED_TIME) - time_to_update;
			glutTimerFunc(preferred_refresh - time_to_update, glut_callbacks::timer, preferred_refresh);
		}
	}
}