#define VERBOSE
#define DEBUG

#include <Program.h>
#include <stdio.h>
#include <string>

int main(int argc, char* args[])
{
	int result = Program::startup();
	if (result != 0)
	{
		return result;
	}
	result = Program::mainLoop();
	return result;
}

SDL_Window* Program::window;
SDL_Surface* Program::surface;
CPU Program::cpu;
int Program::mainLoop()
{
	cpu = CPU();
	bool running = true;
	while (running)
	{
		cpu.tick();
		//Fill the surface white
		SDL_FillRect(surface, 0, SDL_MapRGB(surface->format, 255, 255, 255));
		//Update the surface
		SDL_UpdateWindowSurface(window);
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0)
		{
#ifdef VERBOSE
			printf("EVENT %s             \r", std::to_string(event.type).c_str());
#endif
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}
	}
#ifdef DEBUG
	SDL_Delay(2000);
#endif
	return 0;
}

int Program::startup()
{
	window = 0;
	surface = 0;
	printf("INIT SDL VIDEO\n");
	int init = SDL_Init(SDL_INIT_VIDEO);
	if (init < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		cleanup();
		return 1;
	}

	printf("Creating window\n");
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, STARTUP_FLAGS);
	if (window == 0)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		cleanup();
		return 2;
	}
	printf("Getting window surface\n");
	surface = SDL_GetWindowSurface(window);
	return 0;
}

void Program::cleanup()
{
	printf("Cleaning up\n");
	SDL_DestroyWindow(window);
	SDL_Quit();
}