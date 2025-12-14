#include "walker.h"

walker::walker(SDL_Color color, SDL_Rect rect)
    : color(color),
    rect(rect)
{}

void walker::move(int direction, int gap, std::vector<walker>& trail) {

    for (int i = 0; i < gap; i++) {

        switch (direction) {
            case 1:
                rect.x += RECT_WIDTH;
                break;
            case 2:
                rect.y += RECT_HEIGHT;
                break;
            case 3:
                rect.x -= RECT_WIDTH;
                break;
            case 4:
                rect.y -= RECT_HEIGHT;
                break;
        }

        trail.push_back(*this);

    }
}

