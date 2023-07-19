#include <iostream>

#include "../include/game.hpp"
#include "../include/object.hpp"
#include "../include/controls.hpp"

#include <SDL2/SDL_image.h>



void Game::init(const char *p_title, int p_xpos, int p_ypos, int p_width, int p_height)
{
    // creates window
    window = SDL_CreateWindow(p_title, p_xpos, p_ypos, p_width, p_height, SDL_WINDOW_SHOWN);
    if(window == nullptr)
        std::cout << "ERRORRR... Create_Window: " << SDL_GetError() << std::endl;
    // creates renderer for window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr)
        std::cout << "ERRORRR... Create_Renderer: " << SDL_GetError() << std::endl;

    // Inits SDL and SDL_image
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        std::cout << "ERRORRR... Init_SDL (Everything): " << SDL_GetError() << std::endl;

    if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
        std::cout << "ERRORRR... Init_SDL (PNG): " << SDL_GetError() << std::endl;
}


// cleans up the game
void Game::quit()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    IMG_Quit();

    std::cout << "Game Closed" << std::endl;
}
 

// takes an image and returns a texture
SDL_Texture* Game::loadTexture(const char* p_filePath)
{
    SDL_Texture* theTexture = nullptr;
    
    // loads the image in an SDL_Surface form and gives an ERRORRR... if something goes wrong
    SDL_Surface* theSurface = IMG_Load(p_filePath);
    if(theSurface == nullptr)
        std::cout << "ERRORRR... while loading surface: " << SDL_GetError() << IMG_GetError() << std::endl;
    // else just creates a texture out of the surface
    else
    {
        theTexture = SDL_CreateTextureFromSurface(renderer, theSurface);
        if(theTexture == nullptr)
            std::cout << "ERRORRR... while creating texture: " << SDL_GetError() << IMG_GetError() << std::endl;
        // if nothing goes wrong, it will free the now, useless surface and returns a texture created from that surface
        else
        {
            SDL_FreeSurface(theSurface);
            return theTexture;
        }
    }
    // if something goes really wrong, it will just return null
    return nullptr;
}

// render the texture on the screen
void Game::render(Object& p_texture)
{
    SDL_RenderCopy(renderer, p_texture.getTexture(), p_texture.getSrcRect(), p_texture.getDestRect());
}
// clears the window && renders stuff
void Game::clearWindow()
{
    SDL_RenderClear(renderer);
}
// renders the result on the screen
void Game::renderWindow()
{
    SDL_RenderPresent(renderer);
}


// handles events
void Game::handleEvents()
{
    // copied the controls class
    Controls controls;

    // checking for the SDL_Events
    SDL_Event event;
    SDL_PollEvent(&event);

    if(event.type == SDL_QUIT)
        isRunning = false;
    // if we dont quit, we just check for other events
    else
        controls.updateControls(&event);
}