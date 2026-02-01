//
// Created by ratratarmy on 01/02/2026.
//

#include "sdl3game3.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
void game3::launch() {
    if (not SDL_Init(SDL_INIT_VIDEO)) SDL_Log("Cannot init SDL for some reason: %s", SDL_GetError());
}