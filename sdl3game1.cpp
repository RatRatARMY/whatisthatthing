//
// Created by ratratarmy on 01/02/2026.
//

#include "sdl3game1.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <random>
#include <cmath>
#include <ctime>
#include "newrand.hpp"
int game1::launch() {
    srand(static_cast<unsigned>(time(nullptr)));
    if (not SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Cannot init SDL for some reason: %s", SDL_GetError());
        return 1;
    }
    if (not TTF_Init()) {
        SDL_Log("Cannot init SDL_ttf for some reason: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    const int SCREEN_WIDTH = 960;
    const int SCREEN_HEIGHT = 720;
    const int FPS = 60;
    SDL_Window* rootwnd = SDL_CreateWindow("Created with SDL3", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (not rootwnd) {
        SDL_Log("Cannot create window: %s", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(rootwnd, nullptr);
    if (not renderer) {
        SDL_Log("Cannot create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(rootwnd);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_Texture* bg_img = IMG_LoadTexture(renderer, "assets/sdl/spr_background1.png");
    SDL_Texture* apple_img = IMG_LoadTexture(renderer, "assets/sdl/spr_apple.png");
    SDL_Texture* cat_img = IMG_LoadTexture(renderer, "assets/sdl/spr_cat.png");
    if (not bg_img or not apple_img or not cat_img) {
        SDL_Log("Cannot load image for some reason. Make sure these images are in the assets folder: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(rootwnd);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    TTF_Font* score_font = TTF_OpenFont("assets/sdl/ARIAL.TTF", 24);
    TTF_Font* time_font = TTF_OpenFont("assets/sdl/ARIAL.TTF", 24);
    if (not score_font or not time_font) {
        SDL_Log("Cannot load font for some reason. Make sure these fonts are in the assets folder: %s", SDL_GetError());
        SDL_DestroyTexture(bg_img);
        SDL_DestroyTexture(apple_img);
        SDL_DestroyTexture(cat_img);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(rootwnd);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    int score = 0;
    int time_remaining = FPS * 60; // 60 frames = 1 sec
    int apple_x = randint(0, 960 - 124);
    int apple_y = 0;
    int apple_speed = 5;
    int cat_x = 0;
    int cat_y = 480;
    int cat_speed = 0;
    bool can_collide = true;
    bool game_over = false;
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
                case SDL_EVENT_KEY_DOWN:
                    if (e.key.key == SDLK_LEFT or e.key.key == SDLK_A) {
                        cat_speed = -4;
                    }
                    else if (e.key.key == SDLK_RIGHT or e.key.key == SDLK_D) {
                        cat_speed = 4;
                    }
                    break;
                case SDL_EVENT_KEY_UP:
                    cat_speed = 0;
                    break;
            }
        }
        if (not game_over) {
            cat_x += cat_speed;
            if (cat_x < 0) cat_x = 0;
            else if (cat_x > SCREEN_WIDTH - 192) cat_x = SCREEN_WIDTH - 192;
            apple_y += apple_speed;
            float dx = static_cast<float>(cat_x - apple_x);
            float dy = static_cast<float>(cat_y - apple_y);
            float distance = std::sqrt(dx * dx + dy * dy);
            time_remaining--;
            if (apple_y > SCREEN_HEIGHT) {
                apple_y = 0;
                apple_x = randint(0, 960 - 124);
                can_collide = true;
            }
            if (can_collide and distance < 60) {
                score++;
                apple_y = 0;
                apple_x = randint(0, 960 - 124);
                can_collide = false;
            }
            if (apple_y > 200) {
                can_collide = true;
            }
            if (time_remaining == 0) {
                game_over = true;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_FRect bg_rect = {0, 0, static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT)};
        SDL_RenderTexture(renderer, bg_img, nullptr, &bg_rect);
        if (not game_over) {
            SDL_FRect cat_rect = {static_cast<float>(cat_x), static_cast<float>(cat_y), 192, 201};
            SDL_RenderTexture(renderer, cat_img, nullptr, &cat_rect);
        }
        SDL_FRect apple_rect = {static_cast<float>(apple_x), static_cast<float>(apple_y), 124, 127};
        SDL_RenderTexture(renderer, apple_img, nullptr, &apple_rect);
        SDL_Color white = {255, 255, 255, 255};
        std::string score_str = "Score: " + std::to_string(score);
        SDL_Surface* score_surface = TTF_RenderText_Solid(score_font, score_str.c_str(), 0, white);
        SDL_Texture* score_texture = SDL_CreateTextureFromSurface(renderer, score_surface);
        SDL_FRect score_rect = {0, 0, static_cast<float>(score_surface->w), static_cast<float>(score_surface->h)};
        SDL_RenderTexture(renderer, score_texture, nullptr, &score_rect);
        SDL_DestroySurface(score_surface);
        SDL_DestroyTexture(score_texture);
        std::string time_str = "Time: " + std::to_string(static_cast<int>(time_remaining / 60.f));
        SDL_Surface* time_surface = TTF_RenderText_Solid(time_font, time_str.c_str(), 0, white);
        SDL_Texture* time_texture = SDL_CreateTextureFromSurface(renderer, time_surface);
        SDL_FRect time_rect = {0, 20, static_cast<float>(time_surface->w), static_cast<float>(time_surface->h)};
        SDL_RenderTexture(renderer, time_texture, nullptr, &time_rect);
        SDL_DestroySurface(time_surface);
        SDL_DestroyTexture(time_texture);
        SDL_RenderPresent(renderer);
        Uint64 current_time = SDL_GetTicksNS();
        Uint64 frame_time_ns = 1000000000 / FPS;
        if (current_time - last_time < frame_time_ns) {
            SDL_DelayNS(frame_time_ns - (current_time - last_time));
        }
        last_time = SDL_GetTicksNS();
    }
    SDL_DestroyTexture(bg_img);
    SDL_DestroyTexture(apple_img);
    SDL_DestroyTexture(cat_img);
    TTF_CloseFont(score_font);
    TTF_CloseFont(time_font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(rootwnd);
    TTF_Quit();
    SDL_Quit();
    return 0;
}