#include "config.h"
#include "include/raylib.h"
#include "level.h"
#include "player.h"

typedef struct Ghost {
  int x;
  int y;
  GhostType type;
} Ghost;

void ghostInit(Ghost *g, GhostType type) {
  g->x = 5 * TILE_SIZE;
  g->y = 5 * TILE_SIZE;
  g->type = type;
}

void ghostUpdate(Ghost *g, Level *l, Player *p) {}

void ghostDraw(Ghost *g) {
  DrawRectangle(g->x, g->y, TILE_SIZE, TILE_SIZE, GHOST_COLOR);
}
