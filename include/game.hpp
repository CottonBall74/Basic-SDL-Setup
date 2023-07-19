#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../include/object.hpp"



class Game
{
public:
    // default constructor
    Game()
    : isRunning(true), window(nullptr), renderer(nullptr)
    {}

    // initializes SDL and a window
    void init(const char *p_title, int p_xpos, int p_ypos, int p_width, int p_height);

    // cleans up the game and quits
    void quit();

    // handles events
    void handleEvents();

    // clears the window
    void clearWindow();
    // renders stuff to the window
    void renderWindow();

    // loads and displays a texture
    SDL_Texture* loadTexture(const char* p_filePath);
    void render(Object& p_texture);

    // checks if the game is running
    bool running()
    { return isRunning; }

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
};