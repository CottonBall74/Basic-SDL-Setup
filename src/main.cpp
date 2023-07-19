#include <iostream>

#include "../include/game.hpp"
#include "../include/object.hpp"
#include "../include/math.hpp"

#define _WINDOW_WIDTH_ 500
#define _WINDOW_HEIGHT_ 500


// sdl main function
int main(int argc, char* argv[])
{
    Game game;

    // initialized everything in SDL and makes a window with the given name and other parameters
    game.init("SetupSDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _WINDOW_WIDTH_, _WINDOW_HEIGHT_);

    // creating a texture
    SDL_Texture* plane = game.loadTexture("assets/sprites/Hii.png");
    // applying it and making an Object
    Object plane1(plane, Vec2F(_WINDOW_WIDTH_ / 2, _WINDOW_HEIGHT_ / 2), Vec2I(1000, 1000), _WINDOW_WIDTH_ / 5, _WINDOW_HEIGHT_ / 5);
    
    // the main gameloop
    while(game.running())
    { 
        // we call finctions here line by line
        game.handleEvents();

        game.clearWindow();
        game.render(plane1);
        game.renderWindow();
    }

    // the quit function to free all the memory and exit the application
    game.quit();

    return 0;
}