#pragma once

#include <iostream>

#include "../include/math.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



// this is an object class that creates a GameObject
class Object
{
public:
    // this is an object class constructer that takes a texture, the position, the original img/obj size and the img/obj size you want
    Object(SDL_Texture* p_texture, Vec2F p_pos, Vec2I p_owh, int p_w, int p_h)
    : pos(p_pos), owh(p_owh), texture(p_texture)
    {   
        // what the original texture size and position was
        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.w = owh.x;
        srcRect.h = owh.y;

        // what the size and position the texture will be
        destRect.x = pos.x;
        destRect.y = pos.y;
        destRect.w = p_w;
        destRect.h = p_h;
    }

    // getting the position of the object
    Vec2F& getPos()
    { return pos; }

    // return functions
    SDL_Texture* getTexture()
    { return texture; }
    SDL_Rect* getSrcRect()
    { return &srcRect; }
    SDL_Rect* getDestRect()
    { return &destRect; }

private:
    Vec2F pos;
    Vec2I owh;

    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
};