//
// Created by ratratarmy on 01/02/2026.
//

#include "sdl3game3.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "newrand.hpp"
int game3::launch() {
    const int SCREEN_WIDTH = 960;
    const int SCREEN_HEIGHT = 720;
    const int FPS = 60;
    if (not SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Cannot init SDL for some reason: %s", SDL_GetError());
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("Created with SDL3", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (not window) {
        SDL_Log("Cannot create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if (not renderer) {
        SDL_Log("Cannot create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    SDL_Texture* bg_img = IMG_LoadTexture(renderer, "assets/sdl/spr_background2.png");
    SDL_Texture* shark_img = IMG_LoadTexture(renderer, "assets/sdl/spr_shark.png");
    if (not bg_img or not shark_img) {
        SDL_Log("Cannot load image for some reason. Make sure these images are in the assets folder: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    float shark_x = static_cast<float>(randint(0, SCREEN_WIDTH - 282));
    float shark_y = static_cast<float>(randint(0, SCREEN_HEIGHT - 205));
    float shark_start_x = shark_x; float shark_start_y = shark_y;
    float shark_target_x = static_cast<float>(randint(0, SCREEN_WIDTH - 282));
    float shark_target_y = static_cast<float>(randint(0, SCREEN_HEIGHT - 205));
    float glide_time = 1.f;
    Uint64 start_time = SDL_GetTicksNS();
    // main loop
    bool running = true;
    SDL_Event e;
    Uint64 last_time = SDL_GetTicksNS();
    while (running) {
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
            }
        }
        Uint64 curr_time = SDL_GetTicksNS();
        float elapsed_time = static_cast<float>(curr_time - start_time) / 1000000000.f;
        if (elapsed_time < glide_time) {
            float t = elapsed_time / glide_time;
            shark_x = shark_start_x + (shark_target_x - shark_start_x) * t;
            shark_y = shark_start_y + (shark_target_y - shark_start_y) * t;
        }
        else {
            shark_x = shark_target_x;
            shark_y = shark_target_y;
            shark_start_x = shark_x;
            shark_start_y = shark_y;
            shark_target_x = static_cast<float>(randint(0, SCREEN_WIDTH - 282));
            shark_target_y = static_cast<float>(randint(0, SCREEN_HEIGHT - 205));
            start_time = curr_time;
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_FRect bg_rect = {0, 0, static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT)};
        SDL_RenderTexture(renderer, bg_img, nullptr, &bg_rect);
        SDL_FRect shark_rect = {shark_x, shark_y, 282, 205};
        SDL_RenderTexture(renderer, shark_img, nullptr, &shark_rect);
        SDL_RenderPresent(renderer);
        Uint64 frame_time_ns = 1000000000 / FPS;
        Uint64 next_time = SDL_GetTicksNS();
        if (next_time - last_time < frame_time_ns) {
            SDL_DelayNS(frame_time_ns - (next_time - last_time));
        }
        last_time = SDL_GetTicksNS();
    }
    SDL_DestroyTexture(shark_img);
    SDL_DestroyTexture(bg_img);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}