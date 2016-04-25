#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;
char mode = 'v';

typedef struct {
float x = 6;
float y = 38;
int r = 3;
} Balle;

Balle balle;


void setup() {
  gb.begin();
  gb.titleScreen(F("Basketuino"));

}

void loop() {
  if (gb.update()){
    viser();
    gb.display.drawCircle(balle.x,balle.y,balle.r);
  }

}





