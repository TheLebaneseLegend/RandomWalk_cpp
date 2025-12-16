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
int RECT_WIDTH = 4;
int RECT_HEIGHT = 4;
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

    SDL_Color black = SDL_Color(0, 0, 0, 255);
    SDL_Color blue = SDL_Color(25, 130, 196, 255);
    SDL_Color red = SDL_Color(255, 89, 94, 255);
    SDL_Color green = SDL_Color(138, 201, 38, 255);
    SDL_Color purple = SDL_Color(106, 76, 147, 255);
    SDL_Rect rect1 = {(SCREEN_WIDTH / 2) - (RECT_WIDTH / 2), (SCREEN_HEIGHT / 2) - (RECT_HEIGHT / 2), RECT_WIDTH, RECT_HEIGHT};

    //create struct to store rectangles at each frame, holds trails
    walker walker1 = walker(black, rect1);
    walker walker2 = walker(blue, rect1);
    walker walker3 = walker(red, rect1);
    walker walker4 = walker(green, rect1);
    walker walker5 = walker(purple, rect1);


    //create vector to store trail of rectangle
    std::vector<walker> walkers;

    walkers.push_back(walker1);
    SDL_RenderFillRect(renderer, &walker1.rect);

    walkers.push_back(walker2);
    SDL_RenderFillRect(renderer, &walker2.rect);

    walkers.push_back(walker3);
    SDL_RenderFillRect(renderer, &walker3.rect);

    walkers.push_back(walker4);
    SDL_RenderFillRect(renderer, &walker4.rect);

    walkers.push_back(walker5);
    SDL_RenderFillRect(renderer, &walker5.rect);

    //event loop
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        //depending on which direction is generated, we move the rectangle GAP widths/heights and store move in vector
        walker1.move(dist(rng), GAP, walkers);
        walker2.move(dist(rng), GAP, walkers);
        walker3.move(dist(rng), GAP, walkers);
        walker4.move(dist(rng), GAP, walkers);
        walker5.move(dist(rng), GAP, walkers);

        //redraw screen
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        //draw each move in vector
        for (walker& walker : walkers) {
            SDL_SetRenderDrawColor(renderer, walker.color.r, walker.color.g, walker.color.b, walker.color.a);
            SDL_RenderFillRect(renderer, &walker.rect);
        }

        //write to screen
        SDL_RenderPresent(renderer);

        //delay
        //SDL_Delay(25);

    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
