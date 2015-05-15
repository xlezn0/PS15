
#include "lib/framework.hpp"


int main() {
  AppEnv env(600, 400);
  env.bgColor(Color::white);

  Vec2f pos  = Vec2f(-100, -128);
  Vec2f size = Vec2f(200, 256);
  Texture image("res/mario.png");
  float cut_pos_x = 0.0f;

  while (env.isOpen()) {
    env.begin();

    if (env.isPushKey('A')) { cut_pos_x =   0.0f; }
    if (env.isPushKey('D')) { cut_pos_x = 200.0f; }

    drawTextureBox(pos.x(), pos.y(), size.x(), size.y(),
                   cut_pos_x, 0, size.x(), size.y(),
                   image,
                   Color::white);

    env.end();
  }
}
