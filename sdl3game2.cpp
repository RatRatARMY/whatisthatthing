//
// Created by ratratarmy on 01/02/2026.
//

#include "sdl3game2.hpp"
#include <SDL3/SDL.h>
void game2::launch() {
    if (not SDL_Init(SDL_INIT_VIDEO)) SDL_Log("Cannot init SDL for some reason: %s", SDL_GetError());
}