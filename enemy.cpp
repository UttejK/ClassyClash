#include "enemy.h"
#include "raylib/include/raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
    : worldPos(pos), texture(idle_texture), idle(idle_texture),
      run(run_texture) {
  // Set the enemy's initial position
  width = (float)texture.width / maxFrames;
  height = (float)texture.height;
}

void Enemy::tick(float deltaTime) {
  worldPosLastFrame = worldPos;

  runningTime += deltaTime;
  if (runningTime >= updateTime) {
    frame++;
    runningTime = 0.f;
    if (frame > maxFrames)
      frame = 0;
  }

  // draw the character
  Rectangle source{width * frame, 0.f, rightLeft * width, height};
  Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};

  DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}

void Enemy::undoMovement() { worldPos = worldPosLastFrame; }

Rectangle Enemy::getCollisionRec() {
  return Rectangle{screenPos.x, screenPos.y, width * scale, height * scale};
}