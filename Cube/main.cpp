
#include "lib/framework.hpp"

//-----------------------------------
// Boxの頂点

//
//   E.         F.
// A.         B.
//
//
//   H.         G.
// D.         C.
//

// 座標をVec2fで用意(初期化も同時に行う)
Vec2f pA = Vec2f(0.f, 0.f);
Vec2f pB = Vec2f(50.f, 0.f);
Vec2f pC = Vec2f(50.f, -50.f);
Vec2f pD = Vec2f(0.f, -50.f);

// 後ろの面の座標は表面のxとyに5づつ足してるよ
Vec2f pE = pA + Vec2f(5.f, 5.f);
Vec2f pF = pB + Vec2f(5.f, 5.f);
Vec2f pG = pC + Vec2f(5.f, 5.f);
Vec2f pH = pD + Vec2f(5.f, 5.f);

// 移動速度
const float Move_Speed = 4.0f;


void drawCube() {
  drawLine(pA.x(), pA.y(), pB.x(), pB.y(),
           2, Color::white);
  drawLine(pB.x(), pB.y(), pC.x(), pC.y(),
           2, Color::white);
  drawLine(pC.x(), pC.y(), pD.x(), pD.y(),
           2, Color::white);
  drawLine(pD.x(), pD.y(), pA.x(), pA.y(),
           2, Color::white);

  drawLine(pA.x(), pA.y(), pE.x(), pE.y(),
           2, Color::white);
  drawLine(pB.x(), pB.y(), pF.x(), pF.y(),
           2, Color::white);
  drawLine(pC.x(), pC.y(), pG.x(), pG.y(),
           2, Color::white);
  drawLine(pD.x(), pD.y(), pH.x(), pH.y(),
           2, Color::white);

  drawLine(pE.x(), pE.y(), pF.x(), pF.y(),
           2, Color::white);
  drawLine(pF.x(), pF.y(), pG.x(), pG.y(),
           2, Color::white);
  drawLine(pG.x(), pG.y(), pH.x(), pH.y(),
           2, Color::white);
  drawLine(pH.x(), pH.y(), pE.x(), pE.y(),
           2, Color::white);
}

void moveRight() {
  pA.x() += Move_Speed;
  pB.x() += Move_Speed;
  pC.x() += Move_Speed;
  pD.x() += Move_Speed;
}

void moveLeft() {
  pA.x() -= Move_Speed;
  pB.x() -= Move_Speed;
  pC.x() -= Move_Speed;
  pD.x() -= Move_Speed;
}

int main() {
  AppEnv env(640, 480);

  while (env.isOpen()) {
    env.begin();
    
    if (env.isPressKey(GLFW_KEY_D)) {
      moveRight();
    }
    if (env.isPressKey(GLFW_KEY_A)) {
      moveLeft();
    }

    pE.x() = pA.x() * 0.94f;
    pF.x() = pB.x() * 0.94f;
    pG.x() = pC.x() * 0.94f;
    pH.x() = pD.x() * 0.94f;

    drawCube();

    env.end();
  }
}
