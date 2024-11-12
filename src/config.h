#ifndef _CONFIG_H_
#define _CONFIG_H_

#define TILE_SIZE 30
#define HALF_TILE_SIZE (TILE_SIZE >> 1)
#define SCREEN_WIDTH 690
#define SCREEN_HEIGHT 690
#define ROWS SCREEN_HEIGHT / TILE_SIZE
#define COLS SCREEN_WIDTH / TILE_SIZE
#define WALL_COLOR (Color){0, 0, 255, 255}
#define PLAYER_COLOR (Color){255, 255, 0, 255}
#define PELLET_COLOR (Color){255, 255, 96, 255}

typedef unsigned char GhostType;

#define BLINKY (GhostType)0
#define PINKY (GhostType)1
#define INKY (GhostType)2
#define CLYDE (GhostType)3

#define BLINKY_COLOR (Color){255, 0, 0, 255}
#define PINKY_COLOR (Color){255, 196, 196, 255}
#define INKY_COLOR (Color){128, 128, 255, 255}
#define CLYDE_COLOR (Color){255, 128, 0, 255}

#endif
