#include <iostream>
#include "Tetris.h"
bool Tetris::isvalid()
{
	for (int i = 0; i < 4; i++)
		if (items[i].x < 0 || items[i].x >= Cols || items[i].y >= Lines)
			return false;
		else if (field[items[i].y][items[i].x])
			return false;
	return true;
}

void Tetris::nextTetrimino()
{
	color = 1 + rand() % 7;
	int n = rand() % 7;
	for (int i = 0; i < 4; i++)
	{
		items[i].x = figures[n][i] % 4;
		items[i].y = int(figures[n][i] / 4);
	}
}

void Tetris::handleEvents()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			running = false;
			break;
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				rotate = true;
				break;
			case SDLK_LEFT:
				dx = -1;
				break;
			case SDLK_RIGHT:
				dx = 1;
				break;

			default:
				break;
			}
		default:
			break;
		}
	}
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_DOWN])
		delay = 50;
}

void Tetris::updateRender()
{
	SDL_RenderCopy(render, background, NULL, NULL);
	for (int i = 0; i < Lines; i++)
		for (int j = 0; j < Cols; j++)
			if (field[i][j])
			{
				setRectPos(srcR, field[i][j] * BlockW);
				setRectPos(destR, j * BlockW, i * BlockH);
				moveRectPos(destR, BlockW, ScreenH - (Lines + 1) * BlockH);
				SDL_RenderCopy(render, blocks, &srcR, &destR);
			}
	for (int i = 0; i < 4; i++)
	{
		setRectPos(srcR, color * BlockW);
		setRectPos(destR, items[i].x * BlockW, items[i].y * BlockH);
		moveRectPos(destR, BlockW, ScreenH - (Lines + 1) * BlockH);
		SDL_RenderCopy(render, blocks, &srcR, &destR);
	}

	SDL_RenderPresent(render);

}