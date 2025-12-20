# Example file showing a basic pygame "game loop"
import pygame

SCREEN_WIDTH = 1280
SCREEN_HEIGHT = 960
SQUARE_SIDE = 10
START_X = (SCREEN_WIDTH / 2) - (SQUARE_SIDE / 2)
START_Y = (SCREEN_HEIGHT / 2) - (SQUARE_SIDE / 2)

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
    pygame.draw.rect(screen, "black", (START_X , START_Y, SQUARE_SIDE, SQUARE_SIDE))

    # flip() the display to put your work on screen
    pygame.display.flip()

    clock.tick(60)  # limits FPS to 60

pygame.quit()
