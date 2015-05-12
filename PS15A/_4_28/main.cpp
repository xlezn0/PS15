
#include "lib/framework.hpp"
#include <iostream>


int main() {
  AppEnv env(600, 400);

  Color color(1, 0, 0);
  Font  font("res/nicomoji-plus_v0.9.ttf");

  while (env.isOpen()) {
    env.begin();

    Vec2f pos = env.mousePosition();

    if (env.isPressButton(Mouse::LEFT)) {
      color = Color(1, 1, 1);
    } else {
      color = Color(1, 0, 0);
    }
    drawFillBox(pos.x() - 25, pos.y() - 25,
                50, 50, color);

    font.size(30);
    font.draw("マウス動かしてみて！", Vec2f(-100, -100), Color::white);
    font.draw("クリックしてみて！",   Vec2f(-100, -130), Color::white);

    env.end();
  }
}
