#pragma once
#include <SDL.h>
#include <CPU.h>

class Program
{
public:
	CPU static cpu;
	int static startup();
	int static mainLoop();
private:
	static const int SCREEN_WIDTH = 1024;
	static const int SCREEN_HEIGHT = 768;
	static const int STARTUP_FLAGS = SDL_WINDOW_SHOWN /*| SDL_WINDOW_FULLSCREEN*/;
	static SDL_Window* window;
	static SDL_Surface* surface;

	void static cleanup();
};