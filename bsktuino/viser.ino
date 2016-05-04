
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
    if (gb.buttons.repeat(BTN_B,1)){
    FViser += 1;
  }
  if (gb.buttons.released(BTN_B) || (FViser >= 16)){
    FViser *= 2;
    t = 0;
    mode = 'p';
    }
}

