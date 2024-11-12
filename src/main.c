#include "config.h"
#include "include/raylib.h"
#include "level.h"

void update() {}

void draw() {
  BeginDrawing();
  ClearBackground((Color){0, 0, 0, 255});
  EndDrawing();
}

int main(int argc, char *argv[]) {
  SetTraceLogLevel(LOG_NONE);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pac-Man One-Day Challenge");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    update();
    draw();
    // printf("%d\n", GetFPS());
  }

  CloseWindow();

  return 0;
}
