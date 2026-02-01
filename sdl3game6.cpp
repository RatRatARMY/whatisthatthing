//
// Created by ratratarmy on 01/02/2026.
//

#include "sdl3game6.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <limits>
#include "newrand.hpp"
#include <cmath>

int game6::launch() {
    const int SCREEN_WIDTH = 1152;
    const int SCREEN_HEIGHT = 864;
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
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if (not renderer) {
        SDL_Log("Cannot create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_Texture* bg_img = IMG_LoadTexture(renderer, "assets/sdl/spr_background3.png");
    SDL_Texture* rocketship_img = IMG_LoadTexture(renderer, "assets/sdl/spr_rocketship.png");
    SDL_Texture* star_img = IMG_LoadTexture(renderer, "assets/sdl/spr_star.png");
    if (not bg_img or not rocketship_img or not star_img) {
        SDL_Log("Cannot load image for some reason. Make sure these images are in the assets folder: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    TTF_Font* score_font = TTF_OpenFont("assets/sdl/ARIAL.TTF", 24);
    if (not score_font) {
        SDL_Log("Cannot load font for some reason. Make sure this font is in the assets folder: %s", SDL_GetError());
        SDL_DestroyTexture(bg_img);
        SDL_DestroyTexture(rocketship_img);
        SDL_DestroyTexture(star_img);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    int score = 0;
    int star_x = randint(0, SCREEN_WIDTH - 91);
    int star_y = 0;
    int star_speed = 5;
    int rocketship_x = 576;
    int rocketship_y = SCREEN_HEIGHT - 185;
    int rocketship_speed = 0;
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
                        rocketship_speed = -5;
                    }
                    else if (e.key.key == SDLK_RIGHT or e.key.key == SDLK_D) {
                        rocketship_speed = 5;
                    }
                    break;
                case SDL_EVENT_KEY_UP:
                    rocketship_speed = 0;
                    break;
            }
        }
        if (not game_over) {
            rocketship_x += rocketship_speed;
            if (rocketship_x < 0) rocketship_x = 0;
            else if (rocketship_x > SCREEN_WIDTH - 126) rocketship_x = SCREEN_WIDTH - 126;
            star_y += star_speed;
            float dx = static_cast<float>(rocketship_x - star_x);
            float dy = static_cast<float>(rocketship_y - star_y);
            float distance = std::sqrt(dx * dx + dy * dy);
            if (star_y > SCREEN_HEIGHT) {
                star_y = 0;
                star_x = randint(0, SCREEN_WIDTH - 91);
                can_collide = true;
            }
            if (can_collide and distance < 60) {
                score++;
                star_y = 0;
                star_x = randint(0, SCREEN_WIDTH - 91);
                can_collide = false;
            }
            if (star_y < 200) can_collide = true;
            if (score == std::numeric_limits<int>::max()) game_over = true;
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_FRect bg_rect = {0, 0, static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT)};
        SDL_RenderTexture(renderer, bg_img, nullptr, &bg_rect);
        if (not game_over) {
            SDL_FRect rocketship_rect = {static_cast<float>(rocketship_x), static_cast<float>(rocketship_y), 126, 185};
            SDL_RenderTexture(renderer, rocketship_img, nullptr, &rocketship_rect);
            SDL_FRect star_rect = {static_cast<float>(star_x), static_cast<float>(star_y), 91, 90};
            SDL_RenderTexture(renderer, star_img, nullptr, &star_rect);
        }
        SDL_Color white = {255, 255, 255, 255};
        std::string score_str = "Score: " + std::to_string(score);
        SDL_Surface* score_surface = TTF_RenderText_Solid(score_font, score_str.c_str(), 0, white);
        SDL_Texture* score_texture = SDL_CreateTextureFromSurface(renderer, score_surface);
        SDL_FRect score_rect = {0, 0, static_cast<float>(score_surface->w), static_cast<float>(score_surface->h)};
        SDL_RenderTexture(renderer, score_texture, nullptr, &score_rect);
        SDL_DestroySurface(score_surface);
        SDL_DestroyTexture(score_texture);
        SDL_RenderPresent(renderer);
        Uint64 current_time = SDL_GetTicksNS();
        Uint64 frame_time_ns = 1000000000 / FPS;
        if (current_time - last_time < frame_time_ns) {
            SDL_DelayNS(frame_time_ns - (current_time - last_time));
        }
        last_time = SDL_GetTicksNS();
    }
    SDL_DestroyTexture(bg_img);
    SDL_DestroyTexture(rocketship_img);
    SDL_DestroyTexture(star_img);
    TTF_CloseFont(score_font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}