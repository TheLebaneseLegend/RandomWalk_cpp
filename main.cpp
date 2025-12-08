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

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    std::vector<SDL_Rect> rects;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect rect1 = {(SCREEN_WIDTH / 2) - (RECT_WIDTH / 2), (SCREEN_HEIGHT / 2) - (RECT_HEIGHT / 2), RECT_WIDTH, RECT_HEIGHT};
    SDL_RenderFillRect(renderer, &rect1);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect rect2 = {(SCREEN_WIDTH / 2) - (RECT_WIDTH / 2), (SCREEN_HEIGHT / 2) - (RECT_HEIGHT / 2), RECT_WIDTH, RECT_HEIGHT};
    SDL_RenderFillRect(renderer, &rect2);

    SDL_RenderPresent(renderer);

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        int randNum1 = (rand() % 4) + 1;
        int randNum2 = (rand() % 4) + 1;

        switch (randNum1) {
            case 1:
                rect1.x += 10;
                break;
            case 2:
                rect1.y += 10;
                break;
            case 3:
                rect1.x -= 10;
                break;
            case 4:
                rect1.y -= 10;
                break;
            default:
                break;
        }

        switch (randNum2) {
            case 1:
                rect2.x += 10;
                break;
            case 2:
                rect2.y += 10;
                break;
            case 3:
                rect2.x -= 10;
                break;
            case 4:
                rect2.y -= 10;
                break;
            default:
                break;
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect1);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect2);

        SDL_RenderPresent(renderer);


        SDL_Delay(200);

        std::cout << randNum1 << " " << randNum2 << std::endl;
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
