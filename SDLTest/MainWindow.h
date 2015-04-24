#pragma once


#include "common.h"


class MainWindow{
	

	//Vars
private:
	SDL_Window *mainWindow;
	SDL_Renderer *renderer;
	SDL_Surface *bmp;
	SDL_Texture *texture;
	bool isInitialized;

	//Methods

private:
	void initWindow();
	void initRenderer();
	void loadBitmap();
	void drawBitmap();
	void drawLoop();

public:
	MainWindow();
	~MainWindow();
	


};