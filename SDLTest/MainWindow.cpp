#include "MainWindow.h"
#include <string>


	MainWindow::MainWindow(){
		initWindow();
		initRenderer();
		loadBitmap();
		drawBitmap(); 
		drawLoop();
	}

	MainWindow::~MainWindow(){
		if (mainWindow != nullptr){
			delete mainWindow;
		}
	}
	
	
	void MainWindow::initWindow(){
		mainWindow = SDL_CreateWindow("Hello world!", 100, 100, 2560, 1440, SDL_WINDOWEVENT_SHOWN);
		if (nullptr == mainWindow){
			std::cout << "SDL_Window creation failed: " << SDL_GetError() << std::endl;
			SDL_Quit();
			isInitialized = false;
		}
		else isInitialized = true;
	}

	void MainWindow::initRenderer(){
		renderer = SDL_CreateRenderer(mainWindow, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		if (nullptr == renderer){
			isInitialized = false;
			SDL_DestroyWindow(mainWindow);
		}
		

	}

	void MainWindow::loadBitmap(){

		std::string imagePath = res_path::getResPath() + "hello.bmp";
		bmp = SDL_LoadBMP(imagePath.c_str());
		if (nullptr == bmp){
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(mainWindow);
			std::cout << "Error loading bitmap " << SDL_GetError() << std::endl;
			SDL_Quit();
		}
	}

	void MainWindow::drawBitmap(){
		texture = SDL_CreateTextureFromSurface(renderer, bmp);
		SDL_FreeSurface(bmp);
		if (texture == nullptr){
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(mainWindow);
			std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
		}
	}

	void MainWindow::drawLoop(){
		//A sleepy rendering loop, wait for 3 seconds and render and present the screen each time
		for (int i = 0; i < 3; ++i){
			//First clear the renderer
			SDL_RenderClear(renderer);
			//Draw the texture
			SDL_RenderCopy(renderer, texture, NULL, NULL);
			//Update the screen
			SDL_RenderPresent(renderer);
			//Take a quick break after all that hard work
			SDL_Delay(1000);
		}

	}