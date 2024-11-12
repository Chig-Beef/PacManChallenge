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
} Ghost;

void ghostInit(Ghost *g, GhostType type);

void ghostUpdate(Ghost *g, Level *l, Player *p);

void ghostDraw(Ghost *g);

#endif
