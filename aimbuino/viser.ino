
//Phase pour viser
void viser(){
  float x = balle.x + FViser * cos(NViser);
  float y = balle.y + FViser * sin(NViser);
  gb.display.drawLine(balle.x,balle.y,x,y);
  if (gb.buttons.repeat(BTN_RIGHT,1)){
    NViser += PI/64;
  }
    if (gb.buttons.repeat(BTN_LEFT,1)){
    NViser -= PI/64;
  }
    if (gb.buttons.repeat(BTN_A,1)){
    FViser += sensFViser;
  }
  if (gb.buttons.released(BTN_A)){
    FViser *= 2;
    t = 0;
    mode = 'p';
    gb.sound.playTick();
    }
    if ((FViser > 17)||(FViser < 5)){
      sensFViser *= -1;      
    }
     if (gb.buttons.pressed(BTN_C))
    {
      gameMode = 'm';
      }
}


