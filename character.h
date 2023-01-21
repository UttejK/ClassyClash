#include "raylib/include/raylib.h"

class Character {
public:
	Character();
  Vector2 getWorldPos() { return worldPos; }
  void setScreenPos(int winWidth, int winHeight);
  void tick(float deltaTime);
  
  void undoMovement();

private:
  Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
  Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
  Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
  Vector2 screenPos{};
  Vector2 worldPos{};

  Vector2 worldPosLastFrame{0,0};

  // 1: Right, -1: Left
  float rightLeft{1.f};

  // animation variables
  float runningTime{};
  int frame{};
  int maxFrames{6};
  float updateTime{1.0 / 12.0};

  float speed{8.f};

  float width{};
  float height{};
};