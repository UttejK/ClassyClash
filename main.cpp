#include "raylib/include/raylib.h"
#include "raylib/include/raymath.h"

int main()
{
    const int WinWidth{384};
    const int WinHeight{384};
    InitWindow(WinWidth, WinHeight, "Uttej's Top-Down");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.,0.};

    float speed{5};

    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};
        if (IsKeyDown(KEY_A)) direction.x -= 1.;
        if (IsKeyDown(KEY_D)) direction.x += 1.;
        if (IsKeyDown(KEY_W)) direction.y -= 1.;
        if (IsKeyDown(KEY_S)) direction.y += 1.;

        if (Vector2Length(direction) != 0.) {
            // set mapPos = mapPos - direction
            
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));

        }


        
        DrawTextureEx(map, mapPos, 0, 4, WHITE);
        

        
        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}