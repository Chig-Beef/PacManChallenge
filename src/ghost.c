#include "config.h"
#include "include/raylib.h"
#include "level.h"
#include "player.h"
#include <math.h>
#include <stdlib.h>

typedef struct Ghost {
  int x;
  int y;
  GhostType type;
  dir lastDir;
} Ghost;

void ghostInit(Ghost *g, GhostType type) {
  g->x = (9 + type) * TILE_SIZE;
  g->y = 11 * TILE_SIZE;
  g->type = type;

  // Make sure the can move out of the
  // containment area
  switch (type) {
  case BLINKY:
    g->lastDir = RIGHT;
    break;
  case PINKY:
    g->lastDir = RIGHT;
    break;
  case INKY:
    g->lastDir = UP;
    break;
  case CLYDE:
    g->lastDir = LEFT;
    break;
  }
}

void ghostMoveInDirection(Ghost *g) {
  switch (g->lastDir) {
  case LEFT:
    g->x--;
    break;
  case RIGHT:
    g->x++;
    break;
  case UP:
    g->y--;
    break;
  case DOWN:
    g->y++;
    break;
  }
}

void trackToTile(Ghost *g, Level *l, int tx, int ty) {
  bool validDirs[4] = {
      true,
      true,
      true,
      true,
  };

  // Can't move backwards
  switch (g->lastDir) {
  case LEFT:
    validDirs[RIGHT] = false;
    break;
  case RIGHT:
    validDirs[LEFT] = false;
    break;
  case UP:
    validDirs[DOWN] = false;
    break;
  case DOWN:
    validDirs[UP] = false;
    break;
  }

  // Don't move into a wall
  if (g->x / TILE_SIZE > 0) {
    if (l->grid[g->y / TILE_SIZE][g->x / TILE_SIZE - 1] == 1) {
      validDirs[LEFT] = false;
    }
  } else {
    // TODO: Moving here should wrap around
    validDirs[LEFT] = false;
  }

  if (g->x / TILE_SIZE < COLS - 1) {
    if (l->grid[g->y / TILE_SIZE][g->x / TILE_SIZE + 1] == 1) {
      validDirs[RIGHT] = false;
    }
  } else {
    // TODO: Moving here should wrap around
    validDirs[RIGHT] = false;
  }

  if (g->y / TILE_SIZE > 0) {
    if (l->grid[g->y / TILE_SIZE - 1][g->x / TILE_SIZE] == 1) {
      validDirs[UP] = false;
    }
  }

  if (g->y / TILE_SIZE < ROWS - 1) {
    if (l->grid[g->y / TILE_SIZE + 1][g->x / TILE_SIZE] == 1) {
      validDirs[DOWN] = false;
    }
  }

  // Now try to move towards target tile
  int nextPositions[4][2] = {
      {g->x - TILE_SIZE, g->y},
      {g->x + TILE_SIZE, g->y},
      {g->x, g->y - TILE_SIZE},
      {g->x, g->y + TILE_SIZE},
  };

  dir bestDirection = (dir)-1;
  int bestDistance = -1;
  int dis, dx, dy;

  // Find the best direction to move
  for (int i = 0; i < 4; i++) {
    if (!validDirs[i]) {
      continue;
    }

    dx = nextPositions[i][0] - tx;
    dy = nextPositions[i][1] - ty;
    dis = sqrt((double)(dx * dx + dy * dy));

    if (dis < bestDistance || bestDistance == -1) {
      bestDistance = dis;
      bestDirection = (dir)i;
    }
  }

  // This will occur if they get stuck in
  // the containment area
  if (bestDirection == (dir)-1) {
    g->lastDir++;
    return;
  }

  // Move in the direction
  g->lastDir = bestDirection;
  ghostMoveInDirection(g);
}

void blinkyUpdate(Ghost *g, Level *l, Player *p) {
  // Still moving to the next position
  if (g->x % TILE_SIZE != 0 || g->y % TILE_SIZE != 0) {
    ghostMoveInDirection(g);
    return;
  }

  // Blinky's target tile is always the tile
  // that the player is currently on
  int tx = p->x;
  int ty = p->y;

  trackToTile(g, l, tx, ty);
}

void pinkyUpdate(Ghost *g, Level *l, Player *p) {
  // Still moving to the next position
  if (g->x % TILE_SIZE != 0 || g->y % TILE_SIZE != 0) {
    ghostMoveInDirection(g);
    return;
  }

  // Pinky's target tile is 4 tiles forward
  // in the direction the player is moving
  int tx = p->x;
  int ty = p->y;

  switch (p->lastDir) {
  case LEFT:
    tx -= TILE_SIZE << 2;
    break;
  case RIGHT:
    tx += TILE_SIZE << 2;
    break;
  case UP:
    ty -= TILE_SIZE << 2;
    break;
  case DOWN:
    ty += TILE_SIZE << 2;
    break;
  }

  trackToTile(g, l, tx, ty);
}

void inkyUpdate(Ghost *g, Level *l, Player *p) {}

void clydeUpdate(Ghost *g, Level *l, Player *p) {
  // Still moving to the next position
  if (g->x % TILE_SIZE != 0 || g->y % TILE_SIZE != 0) {
    ghostMoveInDirection(g);
    return;
  }

  // Clyde's target is the player's
  // position if they're within 8 tiles
  int tx = p->x;
  int ty = p->y;

  // Otherwise, scatter
  int dx = g->x - tx;
  int dy = g->y - ty;
  double dis = sqrt(dx * dx + dy * dy);
  if (dis < 8 * TILE_SIZE) {
    // Out of bounds scatter position
    tx = -TILE_SIZE;
    ty = (ROWS + 2) * TILE_SIZE;
  }

  trackToTile(g, l, tx, ty);
}

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
