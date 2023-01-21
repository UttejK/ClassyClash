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

    Texture2D knightIdle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knightRun = LoadTexture("characters/knight_run_spritesheet.png");

    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 knightPos{
        (float)WinWidth/2.f - 4.f * (0.5f * (float)knight.width/6.f),
        (float)WinHeight/2.f - 4.f * (0.5f * (float)knight.height)
    };

    float rightLeft{1.f};
    // 1: Right, -1: Left

    // animation variables
    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.0/12.0};


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

            //Turnary Operators
            direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
            knight = knightRun;

        }
        else knight = knightIdle;


        // draw the map
        DrawTextureEx(map, mapPos, 0, 4, WHITE);

        // update animation frame
        runningTime += GetFrameTime();
        if (runningTime >= updateTime)
        {
            frame++;
            runningTime = 0.f;
            if (frame > maxFrames) frame = 0;
        }
        
        //draw the character
        Rectangle source{(float)knight.width/6.f * frame, 0.f, rightLeft * (float)knight.width/6.f, (float)knight.height};
        Rectangle dest{knightPos.x, knightPos.y, 4.f * (float)knight.width/6.f, 4.f * (float)knight.height};

        DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);

        
        EndDrawing();
    }
    UnloadTexture(map);
    UnloadTexture(knight);
    UnloadTexture(knightIdle);
    UnloadTexture(knightRun);
    CloseWindow();
}