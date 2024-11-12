#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "config.h"

typedef struct Level {
  int grid[ROWS][COLS];
} Level;

void levelInit(Level *l);

#endif
