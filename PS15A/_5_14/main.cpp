
#include "lib/framework.hpp"

enum WindowSize {
  WIDTH = 600,
  HEIGHT = 400,
};


int main() {
  AppEnv env(WIDTH, HEIGHT);

  Random random;
  random.setSeed(time(nullptr));

  const int Point_Max = 10;
  Vec2f pos[Point_Max];
  float radius = 5;
  bool  isActive[Point_Max];

  for (int i = 0; i < Point_Max; ++i) {
    pos[i] = Vec2f::Zero();
    isActive[i] = false;
  }

  while (env.isOpen()) {
    env.begin();

    if (env.isPushButton(Mouse::LEFT)) {
      for (int i = 0; i < Point_Max; ++i) {
        if (!isActive[i]) {
          isActive[i] = true;
          pos[i] = Vec2f(random(-WIDTH / 2,  WIDTH / 2),
                         random(-HEIGHT / 2, HEIGHT / 2));
          break;
        }
      }
    }

    for (int i = 0; i < Point_Max; ++i) {
      if (isActive[i]) {
        drawPoint(pos[i].x(), pos[i].y(), radius, Color::white);
      }
    }

    env.end();
  }
}
