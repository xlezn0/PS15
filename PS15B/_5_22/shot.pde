float pos_x, pos_y;
float speed;
boolean isShot;

void setup() {
  size(400, 600);
  isShot = false;
  speed = 8.0f;
}

void draw() {
  background(100);
  
  if (isShot) {
    pos_y -= speed;
    ellipse(pos_x, pos_y, 50, 50);
  }
}

void mouseClicked() {
  pos_x = mouseX;
  pos_y = mouseY;
  isShot = true;
}


