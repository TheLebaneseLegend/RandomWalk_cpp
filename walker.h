#pragma once
#ifndef RANDOMWALK_WALKER_H
#define RANDOMWALK_WALKER_H
#include <SDL.h>
#include <cstdlib>
#include <vector>

class walker {
public:
    int RECT_WIDTH = 4;
    int RECT_HEIGHT = 4;
    int SCREEN_WIDTH = SCREEN_WIDTH;
    int SCREEN_HEIGHT = SCREEN_HEIGHT;

    SDL_Rect rect;
    SDL_Color color;

    void move(int direction, int gap, std::vector<walker>& addto);

    walker(SDL_Color color, SDL_Rect rect);

};


#endif
