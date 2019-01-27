//
// Created by Mela on 2019-01-27.
//

#ifndef UNTITLED_LOADER_H
#define UNTITLED_LOADER_H

#include <SDL2/SDL.h>
#include "variables.h"

bool init()
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }
    screen = SDL_CreateWindow("My Game Window",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          640, 480,
                                          SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(screen, -1, 0);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    /// catch screen error
    return screen != NULL;

}
void clean_up()
{
    SDL_FreeSurface( heli );
    SDL_FreeSurface( OBSTACLES );
    SDL_FreeSurface( background );
    SDL_FreeSurface( welcome);
    SDL_FreeSurface( transparent);

    SDL_Quit();
}

#endif //UNTITLED_LOADER_H
