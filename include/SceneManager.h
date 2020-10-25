#pragma once
#include <3rdparty.h>
#include <Scene.h>
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void addScene(Scene* scene, std::string name);
	void removeScene(std::string name);
	void setActive(std::string name);
	void loadScene();
	void unloadScene();

	void InputScene(SDL_Event* event);
	void UpdateScene(float* elapsedTime);
	void RenderScene(SDL_Renderer* renderer);

private:
	std::unordered_map<std::string, Scene*> m_Scenes;
	Scene* m_activeScene;
};

class defaultScene : public Scene
{
public:
	defaultScene();
	~defaultScene();

	void Load();

	void Input(SDL_Event* event);
	void Update(float* elapsedTime);
	void Render(SDL_Renderer* renderer);

	void unLoad();

	bool isLoaded();
private:
	bool m_isLoaded;
};
