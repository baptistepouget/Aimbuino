#include <EEPROM.h>
#include <SPI.h>
#include <Gamebuino.h>

Gamebuino gb;

const char strFreeMode[] PROGMEM = "Free Mode";
const char strChallenge[] PROGMEM = "Challenge";
const char strLeaderBoard[] PROGMEM = "LeaderBoard";
const char strExit[] PROGMEM = "Exit";
const char* const menu[4] PROGMEM = {strFreeMode,strChallenge,strLeaderBoard,strExit};

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

typedef struct {
  char  pseudo[8] = "";
  int score = 0;
  char mode = 'f';
} Score;

typedef struct {
Score leaderBoard[6];
} Save;

Save save;

float tpsD= 0;
float tpsF= 0;
int perdu = 1;
char mode = 'v';
char gameMode = 'm';
int score = 0;
int mscore = 0;
int xPanier = 50;
int yPanier = 20;
int IBallex = 6;
int IBalley = 38;
int sensFViser = 1;
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
  for (int i =0;i<3;i++)
  {
    save.leaderBoard[i].mode = 'c';
  }
 // Serial.begin(9600);
  gb.begin();
  gb.titleScreen(F("AimBuino"));
  gb.pickRandomSeed();
  initJeu();

}

void loop() {
  if (gb.update()){
//    Serial.println(save.leaderBoard[0].pseudo);    
//    Serial.println(save.leaderBoard[3].pseudo);

    if ((gameMode == ('c'))||(gameMode == ('f'))){
      decor();
      switch (mode){
      case 'p':
      physique();
      break;
      case 'v':
      viser();
      break;
    }
    }
    switch (gameMode)
    {
      case 'c':
      challenge();
      break;
      case 'l':
      scorePanel();
      break;
      case 'm':
      switch(gb.menu(menu,4))
      {
      case -1:
      gb.titleScreen(F("AimBuino"));
      break;
      case 0:
      perdu = 0;
      gameMode = 'f';
      score = 0;
      initJeu();
      break;
      case 1:
      perdu = 0;
      gameMode = 'c';
      tpsD = gb.frameCount;      
      score = 0;
      initJeu();
      break;
      perdu = 0;
      case 2:
      gameMode = 'l';      
      score = 0;
      initJeu();
      break;
      case 3:    
      perdu = 0;  
      score = 0;
      initJeu();
      gb.titleScreen(F("AimBuino"));
      break;
      }
      break;
    }
    if (perdu) {

   /*   if (gb.buttons.pressed(BTN_C)){
        gameMode = 'm';
        perdu = 0;
      }*/
      initJeu();   
    
        for (int i=0; i<3; i++)
       {
           if ((save.leaderBoard[i].score < score)&&(gameMode == 'c')){
            for (int j=3; j>i;j--)
            {
              save.leaderBoard[j] = save.leaderBoard[j-1];
            }
            save.leaderBoard[i].score = score;
            gb.keyboard(save.leaderBoard[i].pseudo,8);
            i = 7;
            saveData();

          }
          if ((save.leaderBoard[i+3].score < score)&&(gameMode == 'f')){
            for (int j= 6; j>i;j--)
            {
              save.leaderBoard[j] = save.leaderBoard[j-1];
            }
            save.leaderBoard[i+3].score = score;
            gb.keyboard(save.leaderBoard[i+3].pseudo,8);
            i = 7;
            saveData();
           }
        }
        perdu = 0;
        gameMode = 'l';
      }
      }
}








