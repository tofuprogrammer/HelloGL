#pragma once

class HelloGL;

namespace GLUTCallbacks
{
	void Display();
	void Init(HelloGL* gl);
	void Keyboard(unsigned char key, int x, int y);
	void Timer(int preferredRefresh);
}
