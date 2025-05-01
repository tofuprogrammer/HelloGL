#include "classes.hpp"
#include "glut_callbacks.hpp"
#include "GL/freeglut.h"
#include "hello_gl.hpp"

namespace glut_callbacks
{
	namespace
	{
		hello_gl* hello_gl = nullptr;
	}

	void display()
	{
		if (hello_gl != nullptr)
		{
			hello_gl->display();
		}
	}

	void init(hello_gl* gl)
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

	void timer(int target_refresh_interval)
	{
		if (hello_gl != nullptr)
		{
			int time_to_update = glutGet(GLUT_ELAPSED_TIME);
			hello_gl->update();
			time_to_update = glutGet(GLUT_ELAPSED_TIME) - time_to_update;
			glutTimerFunc(target_refresh_interval - time_to_update, timer, target_refresh_interval);
		}
	}
}
