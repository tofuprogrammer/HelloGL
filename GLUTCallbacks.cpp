#include "GLUTCallbacks.hpp"
#include "HelloGL.hpp"

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
			helloGL->Update();
			glutTimerFunc(preferredRefresh, GLUTCallbacks::Timer, preferredRefresh);
		}
	}
}