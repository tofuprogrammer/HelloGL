#include "structures.hpp"
#include "glut_callbacks.hpp"
#include "GL/freeglut.h"
#include "hello_gl.hpp"

namespace glut_callbacks
{
	namespace
	{
		hello_gl* hello_gl_instance = nullptr;
	}

	void display()
	{
		if (hello_gl_instance != nullptr)
		{
			hello_gl_instance->display();
		}
	}

	void init(hello_gl* gl)
	{
		hello_gl_instance = gl;
	}

	void keyboard(unsigned char key, int x, int y)
	{
		if (hello_gl_instance != nullptr)
		{
			hello_gl_instance->keyboard(key, x, y);
		}
	}

	void timer(int target_refresh_interval)
	{
		if (hello_gl_instance != nullptr)
		{
			int time_to_update = glutGet(GLUT_ELAPSED_TIME);
			hello_gl_instance->update();
			time_to_update = glutGet(GLUT_ELAPSED_TIME) - time_to_update;
			glutTimerFunc(target_refresh_interval - time_to_update, timer, target_refresh_interval);
		}
	}
}
