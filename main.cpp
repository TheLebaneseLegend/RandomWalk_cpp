#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>
#include <SDL.h>
#include <random>
#include <chrono>

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
    struct DrawnRect {
        SDL_Rect rect;
        SDL_Color color;
    };

    //set rectangle color
    SDL_Color black = { 0, 0, 0, 255 };

    //create vector to store trail of rectangle
    std::vector<DrawnRect> rects;

    //draw first rectangle and add to screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect rect1 = {(SCREEN_WIDTH / 2) - (RECT_WIDTH / 2), (SCREEN_HEIGHT / 2) - (RECT_HEIGHT / 2), RECT_WIDTH, RECT_HEIGHT};

    rects.push_back({rect1, black});
    SDL_RenderFillRect(renderer, &rect1);

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
                    rect1.x += RECT_WIDTH;
                    rects.push_back({rect1, black});
                }
                break;
            case 2:
                for (int i = 0; i < GAP; i++) {
                    rect1.y += RECT_HEIGHT;
                    rects.push_back({rect1, black});
                }
                break;
            case 3:
                for (int i = 0; i < GAP; i++) {
                    rect1.x -= RECT_WIDTH;
                    rects.push_back({rect1, black});
                    }
                break;
            case 4:
                 for (int i = 0; i < GAP; i++) {
                     rect1.y -= RECT_HEIGHT;
                     rects.push_back({rect1, black});
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
        for (DrawnRect& rect : rects) {
            SDL_RenderFillRect(renderer, &rect.rect);

        }

        //write to screen
        SDL_RenderPresent(renderer);

        //delay
        //SDL_Delay(10);

        // std::cout << " " << randNum1 << std::endl;
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
