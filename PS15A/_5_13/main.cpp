
#include "lib/framework.hpp"


int main() {
  AppEnv env(600, 400);

  Vec2f player_pos   = Vec2f::Zero();
  Vec2f player_size  = Vec2f(50, 50);
  Color player_color = Color::white;

  Vec2f enemy_pos   = Vec2f(100, 0);
  Vec2f enemy_size  = Vec2f(50, 50);
  Color enemy_color = Color::red;

  while (env.isOpen()) {
    env.begin();

    player_pos = env.mousePosition();

    player_color = Color::white;
    if (player_pos.x() + player_size.x() > enemy_pos.x()) {
      if (player_pos.x() < enemy_pos.x() + enemy_size.x()) {
        if (player_pos.y() + player_size.y() > enemy_pos.y()) {
          if (player_pos.y() < enemy_pos.y() + enemy_size.y()) {
            player_color = Color::red;
          }
        }
      }
    }

    // enemy
    drawFillBox(enemy_pos.x(), enemy_pos.y(),
                enemy_size.x(), enemy_size.y(),
                enemy_color);

    // player
    drawFillBox(player_pos.x(), player_pos.y(),
                player_size.x(), player_size.y(),
                player_color);

    env.end();
  }
}
