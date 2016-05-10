//Phase post viser
void physique(){
  // if (balle.y > LCDHEIGHT) { mode = 'v'; init(); }
  t += 0.1;
  balle.x =  FViser * cos(NViser) *  t + IBallex;
  balle.y = (0.5)*10*t*t + FViser * sin(NViser) * t + IBalley;
  if ((balle.y > LCDHEIGHT)||(balle.x > LCDWIDTH)||(balle.x < 0))
  {
    gb.sound.playCancel();
    initJeu();
    if (gameMode == 'f')
    {
       perdu = 1;
       restoreData();
    }
  }
  int d = (xPanier+4 - balle.x)*(xPanier+4 - balle.x) + (yPanier+4 - balle.y)*(yPanier+4 - balle.y);
  if (d < ((balle.r+4)*(balle.r+4)))
  {
    gb.sound.playOK();
    score += 1;
    initJeu();
  }
    if (gb.buttons.pressed(BTN_C))
    {
      gameMode = 'm';
    }
}

/*
 *  PFD
 *  f = m*A
 *  f = p = m*g
 *  Ay = g
 *  Ax = A0
 *  On intÃ¨gre
 *  Vx = A0 * t + FViser * cos(NViser)
 *  Vy = g*t + FViser*sin(NViser)
 *  encore
 *  Xx = FViser * cos(NViser) * t
 *  Xy = (1/2)*sq(t) +  FViser * sin(NViser) * t + IBalley;
 * 
 */


