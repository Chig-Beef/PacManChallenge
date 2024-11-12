#include "config.h"
#include "ghost.h"
#include "include/raylib.h"
#include "level.h"
#include "player.h"

void update(Level *l, Player *p, Ghost *blinky) {}

void draw(Level *l, Player *p, Ghost *blinky) {
  BeginDrawing();
  ClearBackground((Color){0, 0, 0, 255});

  levelDraw(l);
  playerDraw(p);
  ghostDraw(blinky);

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

  Ghost blinky;
  ghostInit(&blinky, BLINKY);

  while (!WindowShouldClose()) {
    update(&l, &p, &blinky);
    draw(&l, &p, &blinky);
    // printf("%d\n", GetFPS());
  }

  CloseWindow();

  return 0;
}
