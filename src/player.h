#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "config.h"
#include "include/raylib.h"
#include "level.h"

typedef struct Player {
  int x;
  int y;
  dir lastDir;
} Player;

void playerInit(Player *p);

void playerUpdate(Player *p, Level *l);

void playerDraw(Player *p);

#endif
