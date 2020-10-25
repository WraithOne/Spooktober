#pragma once
#include <Scene.h>

class Intro : public Scene
{
public:
	Intro();
	~Intro();

	void Load();

	void Input(SDL_Event* event);
	void Update(float* elapsedTime);
	void Render(SDL_Renderer* renderer);

	void unLoad();

	bool isLoaded();
private:
	bool m_isLoaded;
};