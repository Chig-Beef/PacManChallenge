#include "config.h"

typedef struct Level {
  int grid[ROWS][COLS];
} Level;

// 0 = Nothing
// 1 = Wall

void levelInit(Level *l) {
  // Top
  for (int i = 0; i < COLS; i++) {
    l->grid[0][i] = 1;
  }

  // Bottom
  for (int i = 0; i < COLS; i++) {
    l->grid[ROWS - 1][i] = 1;
  }

  // Left wall
  for (int i = 0; i < ROWS; i++) {
    l->grid[i][0] = 1;
  }

  // Right wall
  for (int i = 0; i < ROWS; i++) {
    l->grid[i][COLS - 1] = 1;
  }
}
