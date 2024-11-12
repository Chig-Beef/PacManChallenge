#include "config.h"
#include "include/raylib.h"
#include "level.h"
#include "player.h"

void update(Level *l, Player *p) {}

void draw(Level *l, Player *p) {
  BeginDrawing();
  ClearBackground((Color){0, 0, 0, 255});

  levelDraw(l);
  playerDraw(p);

  EndDrawing();
}

int main(int argc, char *argv[]) {
  SetTraceLogLevel(LOG_NONE);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pac-Man One-Day Challenge");
  SetTargetFPS(60);

  Level l;
  levelInit(&l);

  Player p;
  playerInit(&p);

  while (!WindowShouldClose()) {
    update(&l, &p);
    draw(&l, &p);
    // printf("%d\n", GetFPS());
  }

  CloseWindow();

  return 0;
}
