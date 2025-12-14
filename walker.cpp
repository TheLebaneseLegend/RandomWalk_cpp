#include "walker.h"

void walker::create_rect(int x, int y, int w, int h) {
    SDL_Rect rect = {x, y, w, h};
}

void walker::set_color(Uint8 r = 0 , Uint8 g = 0, Uint8 b = 0, Uint8 a = 255) {
    SDL_Color color = {r, g, b, a};
}

// void walker::move(int x, int y) {
//
// }

walker::walker(int x, int y, int w, int h, int r, int g, int b, int a) {
    set_color(r, g, b, a);
    create_rect(x, y, w, h);
}
