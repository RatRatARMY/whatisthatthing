//
// Created by ratratarmy on 01/02/2026.
//

#include "sdl3game1.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
void game1::launch() {
    if (not SDL_Init(SDL_INIT_VIDEO)) SDL_Log("Cannot init SDL for some reason: %s", SDL_GetError());
    if (not TTF_Init()) SDL_Log("Cannot init SDL_ttf for some reason: %s", SDL_GetError());
}