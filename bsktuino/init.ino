//Initialisation des variables

void initJeu(){
  balle.x = IBallex;
  balle.y = IBalley;
  NViser = (1/4)*PI;
  FViser = 5;
  t = 0;
  mode = 'v';
  xPanier = random(24,LCDWIDTH-lPanier);
  yPanier = random(6,LCDHEIGHT-8);
}

