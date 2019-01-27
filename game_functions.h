//
// Created by Mela on 2019-01-27.
//

#ifndef UNTITLED_GAME_FUNCTIONS_H
#define UNTITLED_GAME_FUNCTIONS_H

#include <sstream>
#include "variables.h"
#include "window.h"
#include "timer.h"

void clean_menu_surfaces();
void update_screen(Timer& time,int score);

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    ///Holds offsets
    SDL_Rect offset;

    ///Get offsets
    offset.x = x;
    offset.y = y;

    ///Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

int game_menu()
{
    int choice;
    int x,y;

    menu = load_image("images/menu/menu.png");
    play_menu = load_image("images/menu/play.png");
    quit_menu = load_image("images/menu/quit.png");

    bool session=true;

    apply_surface(0,0,menu, screen);

    while(session)
        while(SDL_PollEvent(&mouse_event))
        {
            if(mouse_event.type==SDL_MOUSEMOTION)       /// mouse move catch
            {
                x = mouse_event.motion.x;           /// mouse coords
                y = mouse_event.motion.y;

                if((x>960)&&(x<1210)&&(y>120)&&(y<180))     /// start
                {
                    apply_surface(0,0,play_menu,screen);
                }

                else if((x>960)&&(x<1210)&&(y>200)&&(y<280))       /// quit
                {
                    apply_surface(0,0,quit_menu,screen);

                }
                else
                {
                    apply_surface(0,0,menu,screen);
                }

                SDL_RenderClear(renderer);
                SDL_RenderPresent(renderer);
                // SDL_Flip(screen);                               ///UPDATES THE SCREEN
            }
            if(mouse_event.type == SDL_MOUSEBUTTONDOWN)             /// mouse press
            {
                x = mouse_event.motion.x;                       /// mouse coords
                y = mouse_event.motion.y;

                if((x>960)&&(x<1210)&&(y>120)&&(y<180))
                {
                    choice = 1;                             /// start
                    session = false;
                }
                else if((x>960)&&(x<1210)&&(y>200)&&(y<280))
                {
                    choice = 2;                 /// quit
                    session = false;
                }
            }

            switch( mouse_event.type )
            {
                case SDL_KEYDOWN:
                    if( mouse_event.key.keysym.sym == SDLK_ESCAPE )
                    {
                        choice = 2;             /// escape clicked
                        session = false;
                    }
                    break;

                case SDL_QUIT:
                    choice = 2;
                    session = false;
                    break;
            }
        }
    clean_menu_surfaces();
    return choice;
}
//void update_screen(Timer& TimE,int score)       ///UPDATES THE SCREEN
//{
//    std::stringstream samaya;
//    int a=TimE.get_ticks();
//    if(a<60000)
//    {
//        samaya<< "SCORE: "<<score
//              <<"  TIME: " << a/60000<<" : "<<a / 1000;            ///DISPLAYS SCORE AND TIME
//    }
//    else
//    {
//        int sec=a/1000;
//        int min=0;
//        min=sec/60;
//        sec-=min*60;
//        samaya<< "SCORE:  "<<score
//              << "    TIME: " << min<<" : "<<sec;
//
//    }
//    message = TTF_RenderText_Solid( font , samaya.str().c_str() , textColor ) ;
//    apply_surface((1366-message->w)/2,0,message,screen);
//    SDL_FreeSurface(message);
//
//}
SDL_Surface *load_image( std::string filename,int n=0 )         ///FUNCTION FOR LOADING IMAGE
{
    ///The image that's loaded
    SDL_Surface* loadedImage = NULL;

    ///The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    ///Load the image
    loadedImage = IMG_Load( filename.c_str() );

    ///If the image loaded
    if( loadedImage != NULL )
    {
        ///Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        ///Free the old surface
        SDL_FreeSurface( loadedImage );

        ///If the surface was optimized
        if( optimizedImage != NULL )
        {
            if(n==0)
            {

                ///Map the color key
                Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 73, 203, 58 );

                ///Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
                SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
            }
            else if(n==1)
            {
                ///Map the color key
                Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 255, 255, 128 );

                ///Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
                SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
            }

        }
    }

    ///Return the optimized surface
    return optimizedImage;
}

void clean_menu_surfaces()
{
    SDL_FreeSurface(menu);
    SDL_FreeSurface(play_menu);
    SDL_FreeSurface(quit_menu);
}

#endif //UNTITLED_GAME_FUNCTIONS_H
