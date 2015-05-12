
#include "lib/framework.hpp"

enum WindowSize {
  WIDTH  = 600,
  HEIGHT = 400,
};


int main() {
  AppEnv env(WIDTH, HEIGHT);
  Vec2f pos;
  Vec2f size = Vec2f(50, 50);
  float angle = 0;
  Font  font("res/nicomoji-plus_v0.9.ttf");

  while (env.isOpen()) {
    pos = env.mousePosition();
    if (env.isPressButton(Mouse::LEFT)) {
      angle = angle + 0.2f;
    }

    env.begin();

    if (env.isPressButton(Mouse::LEFT)){

      // ビーム
      drawLine(pos.x(), pos.y(),
               0.0f, 0.0f, 5,
               Color(pos.x() / 600 + 0.4f, // red
               pos.y() / 500 + 0.4f,       // gre
               0.4f));                     // blu

      // クルクル回ってるやつ
      drawArc(pos.x(), pos.y(),
              size.x() * 1.5f, size.y() * 1.5f,
              angle, angle + 0.4f,
              100, 3, Color::white);

      drawArc(pos.x(), pos.y(),
              size.x() * 1.5f, size.y() * 1.5f,
              angle + 2.0f, angle + 2.4f,
              100, 3, Color::white);

      drawArc(pos.x(), pos.y(),
              size.x() * 1.5f, size.y() * 1.5f,
              angle + 4.2f, angle + 4.6f,
              100, 3, Color::white);

      // 文字列描画「ビーム発射！」
      font.size(40);
      font.draw("ビーム発射！", Vec2f(-100, -180), Color::white);
    }

    // マウスについてくる四角形
    drawFillBox(pos.x() - (size.x() / 2),
                pos.y() - (size.y() / 2),
                size.x(), size.y(),
                Color(pos.x() / 600 + 0.4f, // red
                pos.y() / 500 + 0.4f,       // gre
                0.4f));                     // blu

    // 文字列描画
    font.size(50);
    font.draw("クリック長押ししてね！", Vec2f(-210, 100), Color::white);

    env.end();
  }
}
