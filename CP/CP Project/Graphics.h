#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <Windows.h>

class Graphics {
	public:

	private:
		static HANDLE Hout;
		static HANDLE Hin;
};

HANDLE Graphics::Hout = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE Graphics::Hin = GetStdHandle(STD_INPUT_HANDLE);

#endif