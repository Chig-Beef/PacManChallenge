#include "config.h"
#include "include/raylib.h"
#include "level.h"

void update(Level *l) {}

void draw(Level *l) {
  BeginDrawing();
  ClearBackground((Color){0, 0, 0, 255});

  levelDraw(l);

  EndDrawing();
}

int main(int argc, char *argv[]) {
  SetTraceLogLevel(LOG_NONE);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pac-Man One-Day Challenge");
  SetTargetFPS(60);

  Level l;

  levelInit(&l);

  while (!WindowShouldClose()) {
    update(&l);
    draw(&l);
    // printf("%d\n", GetFPS());
  }

  CloseWindow();

  return 0;
}
