float NViser = (1/4)*PI;
float FViser = 5;
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
    if (gb.buttons.repeat(BTN_UP,1)){
    FViser += 1;
  }
    if (gb.buttons.repeat(BTN_DOWN,1)){
    FViser -= 1;
  }    
  if (gb.buttons.pressed(BTN_A)){
    mode = 'p';
    }
}
