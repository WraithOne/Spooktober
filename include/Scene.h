#pragma once
#include <3rdparty.h>

class Scene
{
public:
	virtual void Load() = 0;

	virtual void Input(SDL_Event* event) = 0;
	virtual void Update(float* elapsedTime) = 0;
	virtual void Render(SDL_Renderer* renderer) = 0;

	virtual void unLoad() = 0;

	virtual bool isLoaded() = 0;
};
