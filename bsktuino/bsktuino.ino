#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;

const byte Cible[] PROGMEM = {8,8,
B00011000,
B01111110,
B01100110,
B11011011,
B11011011,
B01100110,
B01111110,
B00011000,
};

char mode = 'v';
int score = 0;
int mscore = 0;
int lPanier = 12;
int xPanier = 50;
int yPanier = 20;
int IBallex = 6;
int IBalley = 38;
float t = 0;
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
  //Serial.begin(9600);
  gb.begin();
  initJeu();
  gb.titleScreen(F("Basketuino"));
  gb.pickRandomSeed();

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
    decor();
    if (gb.buttons.pressed(BTN_C)) {
      gb.titleScreen(F("Basketuino"));
      initJeu(); 
      score = 0;
      }
    gb.display.drawCircle(balle.x,balle.y,balle.r);
  }

}






