#include "config.h"
#include "include/raylib.h"
#include "level.h"

typedef struct Player {
  int x;
  int y;
  dir lastDir;
} Player;

void playerInit(Player *p) {
  p->x = 3 * TILE_SIZE;
  p->y = 3 * TILE_SIZE;
  p->lastDir = LEFT;
}

void playerMoveInDirection(Player *p) {
  switch (p->lastDir) {
  case LEFT:
    p->x--;
    break;
  case RIGHT:
    p->x++;
    break;
  case UP:
    p->y--;
    break;
  case DOWN:
    p->y++;
    break;
  }
}

void playerUpdate(Player *p, Level *l) {
  // Still moving to the next position
  if (p->x % TILE_SIZE != 0 || p->y % TILE_SIZE != 0) {
    playerMoveInDirection(p);
    return;
  }

  // Eat the pellet
  int row = p->y / TILE_SIZE;
  int col = p->x / TILE_SIZE;
  if (l->grid[row][col] == 2) {
    l->grid[row][col] = 0;
  }

  // For each key, check the tile to move
  // into is free, then start moving in
  // that direction

  if (IsKeyDown(KEY_A)) {
    if (p->x / TILE_SIZE > 0) {
      if (l->grid[p->y / TILE_SIZE][p->x / TILE_SIZE - 1] != 1) {
        p->x--;
        p->lastDir = LEFT;
      }
    } else {
      p->x = SCREEN_WIDTH - TILE_SIZE;
      p->lastDir = LEFT;
    }
    return;
  }

  if (IsKeyDown(KEY_D)) {
    if (p->x / TILE_SIZE < COLS - 1) {
      if (l->grid[p->y / TILE_SIZE][p->x / TILE_SIZE + 1] != 1) {
        p->x++;
        p->lastDir = RIGHT;
      }
    } else {
      p->x = 0;
      p->lastDir = RIGHT;
    }
    return;
  }

  if (IsKeyDown(KEY_W)) {
    if (p->y / TILE_SIZE > 0) {
      if (l->grid[p->y / TILE_SIZE - 1][p->x / TILE_SIZE] != 1) {
        p->y--;
        p->lastDir = UP;
      }
    }
    return;
  }

  if (IsKeyDown(KEY_S)) {
    if (p->y / TILE_SIZE < ROWS - 1) {
      if (l->grid[p->y / TILE_SIZE + 1][p->x / TILE_SIZE] != 1) {
        p->y++;
        p->lastDir = DOWN;
      }
    }
    return;
  }
}

void playerDraw(Player *p) {
  DrawRectangle(p->x, p->y, TILE_SIZE, TILE_SIZE, PLAYER_COLOR);
}
