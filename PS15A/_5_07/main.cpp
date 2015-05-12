#include "lib/framework.hpp"

enum WindowSize {
  WIDTH  = 512,
  HEIGHT = 512,
};


int main() {
  AppEnv env(WIDTH, HEIGHT);
  env.bgColor(Color::white);

  Texture image1("res/pork.png");
  Texture image2("res/comment.png");
  Vec2f pos = Vec2f(-WIDTH / 2, -80.f);
  Vec2f size = Vec2f(WIDTH, 128.f);

  float angle = 0.f;
  float angle_speed = 1.f;

  float direction = 1;

  Font font("res/nicomoji-plus_v0.9.ttf");

  while (env.isOpen()) {
    env.begin();

    angle += angle_speed;
    if (env.isPressKey('S')) {
      angle += angle_speed * 5;
    }
    if (env.isPushKey('D')) {
      direction *= -1;
    }
    if (direction == 1) {
      pos.x() = -WIDTH / 2;
    } else {
      pos.x() = WIDTH / 2;
    }

    drawTextureBox(pos.x(), pos.y(), size.x(), size.y(),
                   angle,         0, size.x(), size.y(),
                   image1,
                   Color::white,
                   0.f, Vec2f(direction, 1), Vec2f(0, 0));

    if (env.isPressKey('C')) {
      drawTextureBox(pos.x(), pos.y() + size.y(), size.x(), size.y(),
                     angle, 0, size.x(), size.y(),
                     image2,
                     Color::white,
                     0.f, Vec2f(direction, 1), Vec2f(0, 0));
    }


    font.size(36);
    font.draw("Sを押すとスクロールスピードUP!", Vec2f(-230, -140), Color::black);
    font.draw("Cを押すとしゃべるよ!", Vec2f(-230, -180), Color::black);
    font.draw("Dを押すと移動方向が変わるよ!", Vec2f(-230, -220), Color::black);

    env.end();
  }
}
