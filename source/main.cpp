//Using SDL and standard IO
#include<3rdparty.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;
const unsigned TARGETFPS = 60;
const char* WINDOWTITLE = "Spooktober by Dark Abyss";
const int MAXFRAMESKIP = 5;

int main(int argc, char** argv)
{
	// SDL every System
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* w = SDL_CreateWindow(WINDOWTITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	SDL_Renderer* r = SDL_CreateRenderer(w, -1, 0/*SDL_RENDERER_PRESENTVSYNC*/);

	// Mixer only OGG files
	Mix_Init(MIX_INIT_OGG);
	//Image only PNG files
	IMG_Init(IMG_INIT_PNG);

	SDL_bool paused = SDL_FALSE, running = SDL_TRUE;
	Uint64 nextFrame = SDL_GetPerformanceCounter();
	

	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = SDL_FALSE;
				paused = SDL_TRUE;
				break;
			case SDL_WINDOWEVENT:
				switch (event.window.event)
				{
				case SDL_WINDOWEVENT_FOCUS_LOST:
					paused = SDL_TRUE;
					break;
				case SDL_WINDOWEVENT_FOCUS_GAINED:
					paused = SDL_FALSE;
					nextFrame = SDL_GetPerformanceCounter();
					break;
				}
			// Input HERE
			// Scene.Input(event);
				break;
			}
		}
		if (!paused && SDL_GetPerformanceCounter() >= nextFrame)
		{
			int framesSkipped = 0;
			do
			{ 
				// Update HERE
				//Scene.Update(elapsedTime);

				nextFrame += SDL_GetPerformanceFrequency() / TARGETFPS; /* max fps */
			} while (SDL_GetPerformanceCounter() >= nextFrame && framesSkipped++ < MAXFRAMESKIP);/* maximum frames to skip */
			
			// ClearColor
			SDL_SetRenderDrawColor(r, 0x00, 0x00, 0x00, 0xFF);
			// Clear Screen
			SDL_RenderClear(r);
			
			// Rendering HERE
			//Scene.Render(r);

			// Present
			SDL_RenderPresent(r);
		}
		else
			SDL_Delay(1); /* give back CPU time*/
	}

	// Shutdown
	Mix_Quit();
	IMG_Quit();
	SDL_DestroyRenderer(r);
	SDL_DestroyWindow(w);
	SDL_Quit();

	return 0;
}