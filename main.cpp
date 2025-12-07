#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>
#include <SDL.h>

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;
int RECT_WIDTH = 10;
int RECT_HEIGHT = 10;

int main() {
    srand(time(NULL));



    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect rect = {(SCREEN_WIDTH / 2) - (RECT_WIDTH / 2), (SCREEN_HEIGHT / 2) - (RECT_HEIGHT / 2), RECT_WIDTH, RECT_HEIGHT};
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        int randNum = (rand() % 4) + 1;
        switch (randNum) {
            case 1:
                rect.x += 10;
                break;
            case 2:
                rect.y += 10;
                break;
            case 3:
                rect.x -= 10;
                break;
            case 4:
                rect.y -= 10;
                break;
        }

            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect);
            SDL_RenderPresent(renderer);

        SDL_Delay(1000);
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
