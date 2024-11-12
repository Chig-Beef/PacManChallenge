#include "config.h"
#include "include/raylib.h"
#include "level.h"

typedef struct Player {
  int x;
  int y;
} Player;

void playerInit(Player *p) {
  p->x = 3 * TILE_SIZE;
  p->y = 3 * TILE_SIZE;
}

void playerUpdate(Player *p, Level *l) {}

void playerDraw(Player *p) {
  DrawRectangle(p->x, p->y, TILE_SIZE, TILE_SIZE, PLAYER_COLOR);
}
