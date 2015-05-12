
#include "lib/framework.hpp"


int main() {
  AppEnv env(512, 512);

  while (env.isOpen()) {
    env.begin();


    env.end();
  }
}
