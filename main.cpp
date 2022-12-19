#include "Tetris.h"
#include <iostream>
int main(int argc, char* argv[])
{
	using namespace std;
	srand(time(0));
	Tetris* tetris = new Tetris();
	const char* title = "Tetris";
	if (tetris->init(title))
	{
		
	}
	else
	{
		cout << "Failed to initialize";
	}

	tetris->clean();

	return 0;
}

