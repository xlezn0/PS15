
#include "lib/framework.hpp"


int main() {
  AppEnv env(600, 400);

  Vec2f pos   = Vec2f::Zero();
  Vec2f size  = Vec2f(50, 50);
  float speed = 4;

  while (env.isOpen()) {
    env.begin();

    if (env.isPressKey('D')) { pos.x() += speed; } // 右に移動
    if (env.isPressKey('A')) { pos.x() -= speed; } // 左に移動
    if (env.isPressKey('W')) { pos.y() += speed; } // 上に移動
    if (env.isPressKey('S')) { pos.y() -= speed; } // 下に移動

    drawFillBox(pos.x(),  pos.y(),
                size.x(), size.y(),
                Color::white);

    env.end();
  }
}
