#include "character.h"
#include "raylib/include/raymath.h"

Character::Character() {
	width = (float)texture.width / maxFrames;
	height = (float)texture.height;
}

void Character::setScreenPos(int winWidth, int winHeight) {
  screenPos = {(float)winWidth / 2.f -
                   4.f * (0.5f * width),
               (float)winHeight / 2.f - 4.f * (0.5f * height)};
}

void Character::tick(float deltaTime) {
	
	worldPosLastFrame = worldPos;

  Vector2 direction{};
  if (IsKeyDown(KEY_A))
    direction.x -= 1.;
  if (IsKeyDown(KEY_D))
    direction.x += 1.;
  if (IsKeyDown(KEY_W))
    direction.y -= 1.;
  if (IsKeyDown(KEY_S))
    direction.y += 1.;

  if (Vector2Length(direction) != 0.) {
    // set worldPos = worldPos + direction

    worldPos =
        Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));

    // Turnary Operators
    direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
    texture = run;


  } else
    texture = idle;

  // update animation frame
  runningTime += deltaTime;
  if (runningTime >= updateTime) {
    frame++;
    runningTime = 0.f;
    if (frame > maxFrames)
      frame = 0;
  }

  // draw the character
  Rectangle source{width * frame, 0.f,
                   rightLeft * width,
                   height};
  Rectangle dest{screenPos.x, screenPos.y, 4.f * width,
                 4.f * height};

  DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}

void Character::undoMovement(){
	worldPos = worldPosLastFrame;
}