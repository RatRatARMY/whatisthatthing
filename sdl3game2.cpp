//
// Created by ratratarmy on 01/02/2026.
//

#include "sdl3game2.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <limits>
#include "newrand.hpp"
#include <cmath>
int game2::launch() {
    const int SCREEN_WIDTH = 960;
    const int SCREEN_HEIGHT = 720;
    const int FPS = 60;
    if (not SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Cannot init SDL for some reason: %s", SDL_GetError());
        return 1;
    }
    if (not TTF_Init()) {
        SDL_Log("Cannot init SDL_ttf for some reason: %s", SDL_GetError());
        SDL_Quit();
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
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_Texture* cat_img = IMG_LoadTexture(renderer, "assets/sdl/spr_cat.png");
    SDL_Texture* beachball_img = IMG_LoadTexture(renderer, "assets/sdl/spr_beachball.png");
    if (not cat_img or not beachball_img) {
        SDL_Log("Cannot load image for some reason. Make sure these images are in the assets folder: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    TTF_Font* score_font = TTF_OpenFont("assets/sdl/ARIAL.TTF", 24);
    if (not score_font) {
        SDL_Log("Cannot load font for some reason. Make sure this font is in the assets folder: %s", SDL_GetError());
        SDL_DestroyTexture(cat_img);
        SDL_DestroyTexture(beachball_img);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    int score = 0;
    int cat_x = 200;
    int cat_y = 300;
    float beachball_x = static_cast<float>(randint(0, SCREEN_WIDTH - 136));
    float beachball_y = static_cast<float>(randint(0, SCREEN_HEIGHT - 131));
    float beachball_start_x = beachball_x; float beachball_start_y = beachball_y;
    float beachball_target_x = static_cast<float>(randint(0, SCREEN_WIDTH - 136)); float beachball_target_y = static_cast<float>(randint(0, SCREEN_HEIGHT - 131));
    float glide_time = 1.f;
    Uint64 start_time = SDL_GetTicksNS();
    int cat_speed_x = 0;
    int cat_speed_y = 0;
    bool can_collide = true;
    bool game_over = false;
    //main loop
    bool running = true;
    SDL_Event e;
    Uint64 last_time = SDL_GetTicksNS();
    while (running) {
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
                case SDL_EVENT_KEY_DOWN:
                    if (e.key.key == SDLK_UP or e.key.key == SDLK_W) {
                        cat_speed_y = -4;
                    }
                    else if (e.key.key == SDLK_LEFT or e.key.key == SDLK_A) {
                        cat_speed_x = -4;
                    }
                    else if (e.key.key == SDLK_DOWN or e.key.key == SDLK_S) {
                        cat_speed_y = 4;
                    }
                    else if (e.key.key == SDLK_RIGHT or e.key.key == SDLK_D) {
                        cat_speed_x = 4;
                    }
                    break;
                case SDL_EVENT_KEY_UP:
                    cat_speed_x = 0;
                    cat_speed_y = 0;
                    break;
            }
        }
        if (not game_over) {
            cat_x += cat_speed_x;
            cat_y += cat_speed_y;
            if (cat_x < 0) cat_x = 0;
            if (cat_x > SCREEN_WIDTH - 192) cat_x = SCREEN_WIDTH - 192;
            if (cat_y < 0) cat_y = 0;
            if (cat_y > SCREEN_HEIGHT - 201) cat_y = SCREEN_HEIGHT - 201;
            Uint64 curr_time = SDL_GetTicksNS();
            float elapsed_time = static_cast<float>(curr_time - start_time) / 1000000000.f;
            if (elapsed_time < glide_time) {
                float t = elapsed_time / glide_time;
                beachball_x = beachball_start_x + (beachball_target_x - beachball_start_x) * t;
                beachball_y = beachball_start_y + (beachball_target_y - beachball_start_y) * t;
            } else {
                beachball_x = beachball_target_x; beachball_y = beachball_target_y;
                beachball_start_x = beachball_x; beachball_start_y = beachball_y;
                beachball_target_x = static_cast<float>(randint(0, SCREEN_WIDTH - 136)); beachball_target_y = static_cast<float>(randint(0, SCREEN_HEIGHT - 131));
                start_time = curr_time;
            }
            float dx = static_cast<float>(cat_x) - beachball_x;
            float dy = static_cast<float>(cat_y) - beachball_y;
            float distance = std::sqrt(dx * dx + dy * dy);
            if (can_collide and distance < 60) {
                score++;
                beachball_x = static_cast<float>(randint(0, SCREEN_WIDTH - 136));
                beachball_y = static_cast<float>(randint(0, SCREEN_HEIGHT - 131));
                start_time = SDL_GetTicksNS();
                can_collide = false;
            }
            if (score == std::numeric_limits<int>::max()) game_over = true;
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderClear(renderer);
            SDL_FRect cat_rect = {static_cast<float>(cat_x), static_cast<float>(cat_y), 192.f, 201.f};
            SDL_RenderTexture(renderer, cat_img, nullptr, &cat_rect);
            SDL_FRect beachball_rect = {beachball_x, beachball_y, 136.f, 131.f};
            SDL_RenderTexture(renderer, beachball_img, nullptr, &beachball_rect);
            SDL_Color black = {0, 0, 0, 255};
            std::string score_str = "Score: " + std::to_string(score);
            SDL_Surface* score_surface = TTF_RenderText_Solid(score_font, score_str.c_str(), 0, black);
            SDL_Texture* score_texture = SDL_CreateTextureFromSurface(renderer, score_surface);
            SDL_FRect score_rect = {0, 0, static_cast<float>(score_surface->w), static_cast<float>(score_surface->h)};
            SDL_RenderTexture(renderer, score_texture, nullptr, &score_rect);
            SDL_DestroySurface(score_surface);
            SDL_DestroyTexture(score_texture);
            SDL_RenderPresent(renderer);
            Uint64 frame_time_ns = 1000000000 / FPS;
            Uint64 next_time = SDL_GetTicksNS();
            if (next_time - last_time < frame_time_ns) {
                SDL_DelayNS(frame_time_ns - (next_time - last_time));
            }
            last_time = SDL_GetTicksNS();
        }
    }
    SDL_DestroyTexture(cat_img);
    SDL_DestroyTexture(beachball_img);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}