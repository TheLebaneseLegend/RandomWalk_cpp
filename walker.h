#pragma once
#ifndef RANDOMWALK_WALKER_H
#define RANDOMWALK_WALKER_H
#include <SDL.h>

class walker {
public:
    int RECT_WIDTH = 2;
    int RECT_HEIGHT = 2;

    SDL_Rect rect;
    SDL_Color color;

    void set_color(int r, int g, int b, int a);
    void create_rect(int x, int y, int w, int h);
    void set_pos(int x, int y);
    void move(int x, int y);


};


#endif
