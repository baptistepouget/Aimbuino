
void decor(){
  gb.display.drawCircle(balle.x,balle.y,balle.r);
  gb.display.cursorX = 0;
  gb.display.cursorY = 0;
  gb.display.print(F("Score: "));
  gb.display.println(score);
  switch (gameMode)
  {
    case 'c':
    mscore = save.leaderBoard[0].score;
    break;
    case 'f':
    mscore = save.leaderBoard[3].score;
    break;
  }
  gb.display.print(F("High Score: "));
  gb.display.print(mscore);
  gb.display.drawBitmap(xPanier,yPanier,Cible);
  }


