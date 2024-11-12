#ifndef _CONFIG_H_
#define _CONFIG_H_

#define TILE_SIZE 30
#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 720
#define ROWS SCREEN_HEIGHT / TILE_SIZE
#define COLS SCREEN_WIDTH / TILE_SIZE
#define WALL_COLOR (Color){0, 0, 255, 255}
#define PLAYER_COLOR (Color){255, 255, 0, 255}
#define GHOST_COLOR (Color){255, 0, 0, 255}

typedef unsigned char GhostType;

#define BLINKY (GhostType)0
#define PINKY (GhostType)1
#define INKY (GhostType)2
#define CLYDE (GhostType)3

#endif
