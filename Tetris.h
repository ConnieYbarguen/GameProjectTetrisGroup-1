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
	bool isvalid();

	bool init(const char* title);
	void nextTetrimino();
	void handleEvents();
	void setRectPos(SDL_Rect& rect, int x = 0, int y = 0, int w = BlockW, int h = BlockH);
	void moveRectPos(SDL_Rect& rect, int x, int y);
	void gameplay();
	void updateRender();
	void clean();


};


#endif // !TETRIS_H_
