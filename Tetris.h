#pragma una vez
#ifndef TETRIS_H_
#definir TETRIS_H_

#incluir <SDL / SDL.h>
#incluir <SDL2 / SDL_image.h>
#incluir <cuerda>
clase Tetris
{
público:
	Tetris()
	{
	}
	~Tetris()
	{
	}

	vacío setCurrentTime(Uint32 t)
	{
		currentTime = t;
	}

	bool correr()
	{
		regreso corriendo;
	}
	//CORRIGIENDO Y AGREGANDO
	bool es válido();

	bool init(const char* título);
	vacío nextTetrimino();
	vacío handleEvents();
	vacío setRectPos(SDL_Rect& rect, int x = 0, int y = 0, int w = BlockW, int h = BlockH);
	vacío moveRectPos(SDL_Rect& rect, int X, int y);
	vacío juego();
	vacío updateRender();
	vacío limpio();

privado:
	enum { ScreenW = 600, ScreenH = 760 };
	enum { BlockW = 36, Bloque H = 36 };
	enum { Líneas = 20, Cols = 10 };
	Ventana SDL_Window* = NULL;
	SDL_Renderer* render = NULL;
	SDL_Texture* fondo = NULL,* bloques = NULL;
	SDL_Rect srcR = { 0, 0, BlockW, BlockH }, destR = { 0, 0, BlockW, BlockH };

	bool ejecutando = falso;
	int campo[Líneas][Cols] = { 0 };
	estático const int cifras[7][4];
	estructura Punto
	{
		int x, y;
	} artículos[4], copia de seguridad[4];
	int color = 1;
	int dx = 0;
	bool rotar = falso;
	sin firmar int retraso = 300;
	Uint32 startTime = 0, currentTime = 0;
};


#endif // !TETRIS_H_