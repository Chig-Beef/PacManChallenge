#include "include/raylib.h"

const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 720;

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
