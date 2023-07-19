#pragma once

#include <SDL2/SDL.h>

#include "../include/game.hpp"
#include "../include/controls.hpp"



class Controls
{
public:
    // defines controls and handles them
    void updateControls(SDL_Event* p_event)
    {
        if(p_event->type == SDL_KEYDOWN)
        {
            switch(p_event->key.keysym.sym)
            {
                case SDLK_w:
                    std::cout << "up" << std::endl;
                    break;
                case SDLK_a:
                    std::cout << "left" << std::endl;
                    break;
                case SDLK_s:
                    std::cout << "down" << std::endl;
                    break;
                case SDLK_d:
                    std::cout << "right" << std::endl;
                    break;
            }
        }
    }
private:
};