#pragma once
#ifndef RANDOMWALK_WALKER_H
#define RANDOMWALK_WALKER_H
#include <SDL.h>

class walker {
public:
    int RECT_WIDTH = 2;
    int RECT_HEIGHT = 2;
    int SCREEN_WIDTH = SCREEN_WIDTH;
    int SCREEN_HEIGHT = SCREEN_HEIGHT;

    SDL_Rect rect;
    SDL_Color color;

    void set_pos(int x, int y);
    void move(int x, int y);

    walker(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

};


#endif
