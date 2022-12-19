#pragma once
#ifndef TETRIS_H_
#define TETRIS_H_

#include <SDL/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
class Tetris
{
public:
	Tetris()
	{
	}
	~Tetris()
	{
	}
	void setCurrentTime(Uint32 t)
	{
		currentTime = t;
	}
	bool isrunning()
	{
		return running;
	}


};


#endif // !TETRIS_H_
