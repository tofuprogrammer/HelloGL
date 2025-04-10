#include "Classes.hpp"
#include "GLUTCallbacks.hpp"
#include "HelloGL.hpp"
#include "GL/freeglut.h"

namespace GLUTCallbacks
{
	namespace
	{
		HelloGL* helloGL = nullptr;
	}

	void Display()
	{
		if (helloGL != nullptr)
		{
			helloGL->Display();
		}
	}

	void Init(HelloGL* gl)
	{
		helloGL = gl;
	}

	void Keyboard(unsigned char key, int x, int y)
	{
		if (helloGL != nullptr)
		{
			helloGL->Keyboard(key, x, y);
		}
	}

	void Timer(int preferredRefresh)
	{
		if (helloGL != nullptr)
		{
			int timeToUpdate = glutGet(GLUT_ELAPSED_TIME);
			helloGL->Update();
			timeToUpdate = glutGet(GLUT_ELAPSED_TIME) - timeToUpdate;
			glutTimerFunc(preferredRefresh - timeToUpdate, GLUTCallbacks::Timer, preferredRefresh);
		}
	}
}
