
#include "lib/framework.hpp"


int main() {
  AppEnv env(600, 400);
  env.bgColor(Color::white);

  Vec2f pos  = Vec2f(-100, -200);
  Vec2f size = Vec2f(200, 256);
  float cut_pos_x  =    0.0f;
  float bound_line = -200.0f;
  float jump_power =    8.0f;
  float gravidy    =   -0.3f;
  float vector_y   =    0.0f;

  Texture image("res/mario.png");
  Media se_jump("res/se_jump.wav");
  Media se_say("res/se_say.wav");

  Font font("res/nicomoji-plus_v0.9.ttf");

  while (env.isOpen()) {
    env.begin();

    if (env.isPushKey('A')) { cut_pos_x =   0.0f; }
    if (env.isPushKey('D')) { cut_pos_x = 200.0f; }
    
    vector_y += gravidy;
    pos.y()  += vector_y;

    if (pos.y() < bound_line) {
      pos.y() = bound_line;
    }

    if (env.isPushKey(GLFW_KEY_SPACE)) {
      vector_y = jump_power;
      se_jump.play();
    }

    if (env.isPushKey(GLFW_KEY_S)) {
      se_say.play();
    }

    drawTextureBox(pos.x(), pos.y(), size.x(), size.y(),
                   cut_pos_x, 0, size.x(), size.y(),
                   image,
                   Color::white);

    font.size(30);
    font.draw("AとDで右向き、左向きの画像が切り替わるよ！", Vec2f(-280, 160), Color::black);
    font.draw("Spaceでジャンプ！", Vec2f(-120, 110), Color::black);
    font.draw("Sでセリフ", Vec2f(-60, 60), Color::black);

    env.end();
  }
}
