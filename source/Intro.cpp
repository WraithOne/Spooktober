#include <Intro.h>


Intro::Intro()
{
    // Init variables HERE
    m_isLoaded = false;
}

Intro::~Intro()
{
    // unLoad if not happend
    unLoad();
}

void Intro::Load()
{
    // Load assets HERE
    if (!m_isLoaded)
    {
        m_isLoaded = true;
    }

}

void Intro::Input(SDL_Event* event)
{
    switch (event->key.keysym.sym)
    {
    case SDLK_UP:
           
        break;

    case SDLK_DOWN:
            
        break;

    case SDLK_LEFT:
            
        break;

    case SDLK_RIGHT:
            
        break;

    case SDLK_ESCAPE:
        SDL_Event sdlevent;
        sdlevent.type = SDL_QUIT;
        SDL_PushEvent(&sdlevent);
        break;
    default:
        break;
    }
}

void Intro::Update(float* elapsedTime)
{
    
}
void Intro::Render(SDL_Renderer* renderer)
{

}

void Intro::unLoad()
{
    // Safe unLoad assets HERE
    m_isLoaded = false;
}

bool Intro::isLoaded()
{
    return m_isLoaded;
}
