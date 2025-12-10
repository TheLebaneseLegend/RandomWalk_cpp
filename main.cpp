#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>
#include <SDL.h>
#include <random>
#include <chrono>

int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 960;
int RECT_WIDTH = 4;
int RECT_HEIGHT = 4;
int VELOCITY = 10;

int main() {

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Random Walk c++", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, NULL, NULL);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    struct DrawnRect {
        SDL_Rect rect;
        SDL_Color color;
    };

    std::vector<DrawnRect> rects;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect rect1 = {(SCREEN_WIDTH / 2) - (RECT_WIDTH / 2), (SCREEN_HEIGHT / 2) - (RECT_HEIGHT / 2), RECT_WIDTH, RECT_HEIGHT};

    rects.push_back({rect1, SDL_Color{0, 0, 0, 255}});
    SDL_RenderFillRect(renderer, &rect1);

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32)};
        std::mt19937_64 rng(ss); // Seed the engine with the seed sequence
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        int randomNumber = dist(rng) * 100;
        int randNum1 = (randomNumber % 4) + 1;

        switch (randNum1) {
            case 1:
                rect1.x += RECT_WIDTH;
                break;
            case 2:
                rect1.y += RECT_HEIGHT;
                break;
            case 3:
                rect1.x -= RECT_WIDTH;
                break;
            case 4:
                rect1.y -= RECT_HEIGHT;
                break;
            default:
                break;
        }

        rects.push_back({rect1, SDL_Color{0, 0, 0, 255}});

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        for (DrawnRect& rect : rects) {
            SDL_RenderFillRect(renderer, &rect.rect);

        }
            // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            // SDL_RenderFillRect(renderer, &rect1);

        SDL_RenderPresent(renderer);

        // SDL_Delay(1);

        //std::cout << randNum1 << " " << randNum2 << std::endl;
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
