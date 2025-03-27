#include "GLUTCallbacks.hpp"
#include "Classes.hpp"

namespace GLUTCallbacks {
	namespace {
		HelloGL* helloGL = nullptr;
	}

	void Init(HelloGL* gl) {
		helloGL = gl;
	}

	void Display() {
		if (helloGL != nullptr) {
			helloGL->Display();
		}
	}

	void Timer(int preferredRefresh) {
		if (helloGL != nullptr) {
			int timeToUpdate = glutGet(GLUT_ELAPSED_TIME);
			helloGL->Update();
			timeToUpdate = glutGet(GLUT_ELAPSED_TIME) - timeToUpdate;
			glutTimerFunc(preferredRefresh - timeToUpdate, GLUTCallbacks::Timer, preferredRefresh);
		}
	}

	void Keyboard(unsigned char key, int x, int y) {
		if (helloGL != nullptr) {
			helloGL->Keyboard(key, x, y);
		}
	}
}