#include "config.h"
#include "ghost.h"
#include "include/raylib.h"
#include "level.h"
#include "player.h"

void update(Level *l, Player *p, Ghost *blinky, Ghost *pinky, Ghost *inky,
            Ghost *clyde) {}

void draw(Level *l, Player *p, Ghost *blinky, Ghost *pinky, Ghost *inky,
          Ghost *clyde) {
  BeginDrawing();
  ClearBackground((Color){0, 0, 0, 255});

  levelDraw(l);
  playerDraw(p);
  ghostDraw(blinky);
  ghostDraw(pinky);
  ghostDraw(inky);
  ghostDraw(clyde);

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

  Ghost blinky, pinky, inky, clyde;
  ghostInit(&blinky, BLINKY);
  ghostInit(&pinky, PINKY);
  ghostInit(&inky, INKY);
  ghostInit(&clyde, CLYDE);

  while (!WindowShouldClose()) {
    update(&l, &p, &blinky, &pinky, &inky, &clyde);
    draw(&l, &p, &blinky, &pinky, &inky, &clyde);
    // printf("%d\n", GetFPS());
  }

  CloseWindow();

  return 0;
}
