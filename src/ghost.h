#ifndef _GHOST_H_
#define _GHOST_H_

#include "config.h"
#include "include/raylib.h"
#include "level.h"
#include "player.h"

typedef struct Ghost {
  int x;
  int y;
  GhostType type;
  dir lastDir;
} Ghost;

void ghostInit(Ghost *g, GhostType type);

void blinkyUpdate(Ghost *g, Level *l, Player *p);

void pinkyUpdate(Ghost *g, Level *l, Player *p);

void inkyUpdate(Ghost *g, Level *l, Player *p, Ghost *blinky);

void clydeUpdate(Ghost *g, Level *l, Player *p);

void ghostUpdate(Ghost *g, Player *p);

void ghostDraw(Ghost *g);

#endif
