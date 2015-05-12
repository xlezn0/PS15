
#include "lib/framework.hpp"

enum WindowSize {
  WIDTH = 512,
  HEIGHT = 512,
};


int main() {
  AppEnv env(WIDTH, HEIGHT);

  Vec2f position   = Vec2f::Zero();
  Vec2f size       = Vec2f(50, 50);
  Vec2f scale      = Vec2f(1, 1);
  Vec2f offset     = Vec2f(0, 100);
  float division   = 40;
  float line_width = 2;
  float angle      = 0;

  while (env.isOpen()) {
    env.begin();

    angle += 0.1f;

    drawCircle(position.x(), position.y(), size.x(), size.y(),
               line_width,
               division,
               Color::white,
               angle,
               scale,
               offset);

    env.end();
  }
}
