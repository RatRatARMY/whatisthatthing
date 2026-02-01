//
// Created by ratratarmy on 01/02/2026.
//

#include "sdl3game6.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
void game6::launch() {
    if (not SDL_Init(SDL_INIT_VIDEO)) SDL_Log("Cannot init SDL for some reason: %s", SDL_GetError());
}