#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>
#include <SDL.h>
#include <random>
#include <chrono>
#include "walker.h"

int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 960;
int RECT_WIDTH = 2;
int RECT_HEIGHT = 2;
int GAP = 2;

int main() {

    //set seed for randomness in direction choosing
    uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32)};
    std::mt19937_64 rng(ss);
    std::uniform_int_distribution<int> dist(1, 4);

    //intialize window and renderer
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Random Walk c++", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, NULL, NULL);

    //white window background
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    //create struct to store rectangles at each frame, holds trails
    walker walker1 = walker((SCREEN_WIDTH / 2) - (RECT_WIDTH / 2), (SCREEN_HEIGHT / 2) - (RECT_HEIGHT / 2), RECT_WIDTH, RECT_HEIGHT, 0, 0, 0, 255);

    //set rectangle color
    walker1.set_color(0, 0, 0, 255);

    //create vector to store trail of rectangle
    std::vector<walker> walkers;


    walkers.push_back(walker1);
    SDL_RenderFillRect(renderer, &walker1.rect);

    //event loop
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        //generate random number each frame using seed from above
        int randNum1 = dist(rng);

        //depending on which direction is generated, we move the rectangle GAP widths/heights and store move in vector
        switch (randNum1) {
            case 1:
                for (int i = 0; i < GAP; i++) {
                    walker1.rect.x += RECT_WIDTH;
                    walkers.push_back(walker1);
                }
                break;
            case 2:
                for (int i = 0; i < GAP; i++) {
                    walker1.rect.y += RECT_HEIGHT;
                    walkers.push_back(walker1);
                }
                break;
            case 3:
                for (int i = 0; i < GAP; i++) {
                    walker1.rect.x -= RECT_WIDTH;
                    walkers.push_back(walker1);
                    }
                break;
            case 4:
                 for (int i = 0; i < GAP; i++) {
                     walker1.rect.y -= RECT_HEIGHT;
                     walkers.push_back(walker1);
                 }
                break;
            default:
                break;
        }

        //redraw screen
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        //draw each move in vector
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        for (walker& walker : walkers) {
            SDL_RenderFillRect(renderer, &walker.rect);
        }

        //write to screen
        SDL_RenderPresent(renderer);

        //delay
        SDL_Delay(10);

        // std::cout << " " << randNum1 << std::endl;
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
