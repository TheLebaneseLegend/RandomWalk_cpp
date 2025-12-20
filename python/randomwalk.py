# Example file showing a basic pygame "game loop"
import pygame
import numpy as np

SCREEN_WIDTH = 1280
SCREEN_HEIGHT = 960
SQUARE_SIDE = 4
GAP = 4
START_X = (SCREEN_WIDTH / 2) - (SQUARE_SIDE / 2)
START_Y = (SCREEN_HEIGHT / 2) - (SQUARE_SIDE / 2)
DRAW_X_Y = [[START_X, START_Y]]

# pygame setup
pygame.init()
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
clock = pygame.time.Clock()
running = True

while running:
    # poll for events
    # pygame.QUIT event means the user clicked X to close your window
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # fill the screen with a color to wipe away anything from last frame
    screen.fill("white")

    # RENDER YOUR GAME HERE
    for coords in DRAW_X_Y:
        pygame.draw.rect(screen, "black", (coords[0], coords[1], SQUARE_SIDE, SQUARE_SIDE))

    move = np.random.randint(low=1, high=5)
    lastx, lasty = DRAW_X_Y[-1]

    for i in range(GAP+1):
        if move == 1:
            if lastx + SQUARE_SIDE >= SCREEN_WIDTH:
                DRAW_X_Y.append([lastx, lasty])
            else:
                DRAW_X_Y.append([lastx + SQUARE_SIDE, lasty])

        if move == 2:
            if lastx - SQUARE_SIDE <= 0:
                DRAW_X_Y.append([lastx, lasty])
            else:
                DRAW_X_Y.append([lastx - SQUARE_SIDE, lasty])

        if move == 3:
            if lasty + SQUARE_SIDE >= SCREEN_HEIGHT:
                DRAW_X_Y.append([lastx, lasty])
            else:
                DRAW_X_Y.append([lastx, lasty + SQUARE_SIDE])

        if move == 4:
            if lasty - SQUARE_SIDE <= 0:
                DRAW_X_Y.append([lastx, lasty])
            else:
                DRAW_X_Y.append([lastx, lasty - SQUARE_SIDE])




    # flip() the display to put your work on screen
    pygame.display.flip()


    clock.tick(120)  # limits FPS to 120

pygame.quit()
