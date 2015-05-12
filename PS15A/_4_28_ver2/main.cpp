
#include "lib/framework.hpp"


int main() {
  AppEnv env(600, 400);

  float count = 0.0f;

  // この値を変更すると消えたり付いたりするタイミングが切り替わる
  float Anime_Interval = 30;

  while (env.isOpen()) {
    env.begin();

    count++;

    if ((count > 0) &&
        (count < Anime_Interval))
    {
      drawFillBox(0, 0, 50, 50, Color::white);
    }

    if ((count > Anime_Interval * 2) &&
        (count < Anime_Interval * 3))
    {
      drawFillBox(0, 0, 50, 50, Color::cyan);
    }

    if (count > Anime_Interval * 4) {
      count = 0;
    }

    env.end();
  }
}
