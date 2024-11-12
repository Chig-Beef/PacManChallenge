#include "config.h"
#include "include/raylib.h"
#include "level.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Ghost {
  int x;
  int y;
  GhostType type;
} Ghost;

void ghostInit(Ghost *g, GhostType type) {
  g->x = (9 + type) * TILE_SIZE;
  g->y = 11 * TILE_SIZE;
  g->type = type;
}

void blinkyUpdate(Ghost *g, Level *l, Player *p) {}

void pinkyUpdate(Ghost *g, Level *l, Player *p) {}

void inkyUpdate(Ghost *g, Level *l, Player *p) {}

void clydeUpdate(Ghost *g, Level *l, Player *p) {}

void ghostUpdate(Ghost *g, Player *p) {
  if (p->x / TILE_SIZE == g->x / TILE_SIZE &&
      p->y / TILE_SIZE == g->y / TILE_SIZE) {
    // Lost the game!
    exit(0);
  }
}

void ghostDraw(Ghost *g) {
  switch (g->type) {
  case BLINKY:
    DrawRectangle(g->x, g->y, TILE_SIZE, TILE_SIZE, BLINKY_COLOR);
    break;
  case PINKY:
    DrawRectangle(g->x, g->y, TILE_SIZE, TILE_SIZE, PINKY_COLOR);
    break;
  case INKY:
    DrawRectangle(g->x, g->y, TILE_SIZE, TILE_SIZE, INKY_COLOR);
    break;
  case CLYDE:
    DrawRectangle(g->x, g->y, TILE_SIZE, TILE_SIZE, CLYDE_COLOR);
    break;
  }
}
