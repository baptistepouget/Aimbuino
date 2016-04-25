#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;
char mode = 'v';

int xPanier = 50;
int yPanier = 20;
int IBallex = 6;
int IBalley = 38;
int t = IBallex;
float NViser = (1/4)*PI;
float FViser = 5;

void physique();
void viser();
void decor();
void initJeu();

typedef struct {
float x = 6;
float y = 38;
int r = 3;
} Balle;

Balle balle;


void setup() {
  gb.begin();
  initJeu();
  gb.titleScreen(F("Basketuino"));

}

void loop() {
  if (gb.update()){
    
    switch (mode){
      case 'p':
      physique();
      break;
      case 'v':
      viser();
      break;
    }
    if (gb.buttons.pressed(BTN_C)) {
      gb.titleScreen(F("Basketuino"));
      initJeu(); 
      }
    gb.display.drawCircle(balle.x,balle.y,balle.r);
  }

}





