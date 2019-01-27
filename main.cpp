#include <iostream>
#include "SDL2/SDL_image.h"
//#include <SDL2/SDL_mixer.h>
#include <string>
#include "SDL2/SDL.h"
#include "window.h"
#include "loader.h"
#include "game_functions.h"

int main(int argc, char* args[])
{
    bool cont=true;

    if(!init()) { return 1; }

    int opt;
    SDL_Delay(2000);

    while(cont)
    {
        opt=game_menu();        /// menu load
        switch(opt){
            case 1:
            /// play
              //  play();
                break;
            case 2:
            /// quit
                cont=false;
                break;
            default:
                break;
        }
    }

    clean_up(); /// clear objects
    return 0;
}