#include "classes.hpp"
#include "hello_gl.hpp"

namespace glut_callbacks
{
	hello_gl* m_hello_gl = nullptr;

	void display()
	{
		if (m_hello_gl != nullptr)
		{
			m_hello_gl->display();
		}
	}

	void init(hello_gl* gl)
	{
		m_hello_gl = gl;
	}

	void keyboard(unsigned char key, int x, int y)
	{
		if (m_hello_gl != nullptr)
		{
			m_hello_gl->keyboard(key, x, y);
		}
	}

	void timer(int preferred_refresh)
	{
		if (m_hello_gl != nullptr)
		{
			int time_to_update = glutGet(GLUT_ELAPSED_TIME);
			m_hello_gl->update();
			time_to_update = glutGet(GLUT_ELAPSED_TIME) - time_to_update;
			glutTimerFunc(preferred_refresh - time_to_update, glut_callbacks::timer, preferred_refresh);
		}
	}
}
