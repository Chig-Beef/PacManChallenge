#include "config.h"
#include "include/raylib.h"

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

void levelDraw(Level *l) {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      if (l->grid[row][col] == 1) {
        DrawRectangle(col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE, TILE_SIZE,
                      WALL_COLOR);
      }
    }
  }
}
