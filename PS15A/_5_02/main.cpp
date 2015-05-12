
#include "lib/framework.hpp"


int main() {
  int Width  = 600;
  int Height = 300;

  AppEnv env(Width, Height);

  float pos_x   = 0;
  float pos_y   = 0;
  float size_wh = 50;

  while (env.isOpen()) {
    env.begin();

    pos_x += 3;
    if (pos_x + size_wh > Width / 2) {
      pos_x = -Width / 2;
    }
    drawFillBox(pos_x, pos_y, size_wh, size_wh, Color::cyan);

    env.end();
  }
}
