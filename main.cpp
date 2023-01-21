#include "character.h"
#include "raylib/include/raylib.h"
#include "raylib/include/raymath.h"


int main() {
  const int WinWidth{384};
  const int WinHeight{384};
  InitWindow(WinWidth, WinHeight, "Uttej's Top-Down");

  Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
  Vector2 mapPos{0., 0.};

  Character knight;
  knight.setScreenPos(WinWidth, WinHeight);

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);

    mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

    // draw the map
    DrawTextureEx(map, mapPos, 0, 4, WHITE);
    knight.tick(GetFrameTime());

    EndDrawing();
  }

  CloseWindow();
}