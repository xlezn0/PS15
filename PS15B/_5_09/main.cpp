
#include "lib/framework.hpp"


int main() {
  AppEnv env(600, 400);

  Vec2f pos   = Vec2f::Zero();
  float size  = 50;
  float speed = 6;

  while (env.isOpen()) {
    env.begin();

    pos.x() += speed;

    if (pos.x() >  600 / 2 - size) { speed *= -1; }
    if (pos.x() < -600 / 2)        { speed *= -1; }

    drawBox(pos.x(), pos.y(),
            size, size,
            5,
            Color::white);

    env.end();
  }
}
