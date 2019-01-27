//
// Created by Mela on 2019-01-27.
//

#ifndef UNTITLED_WINDOW_H
#define UNTITLED_WINDOW_H

#include "SDL2/SDL.h"
#include "variables.h"

class Window
{
private:
    bool windowed;
    bool windowOK;

public:
    Window();
};

Window::Window()
{
    /// set up window and renderer
    screen = SDL_CreateWindow("Helicopter Game Window",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          640, 480,
                                          SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(screen, -1, 0);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    /// window errors check
    if( screen == NULL )
    { windowOK = false; return;}
    else { windowOK = true; }

    windowed = true;
}

#endif //UNTITLED_WINDOW_H
