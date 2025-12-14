#include "walker.h"


// void walker::move(int x, int y) {
//
// }

walker::walker(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    color = {r, g, b, a};
    rect = {x, y, w, h};
}
