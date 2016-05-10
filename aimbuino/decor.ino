
void decor(){
  gb.display.drawCircle(balle.x,balle.y,balle.r);
  gb.display.print("Score: ");
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
  gb.display.print("High Score: ");
  gb.display.print(mscore);
  gb.display.drawBitmap(xPanier,yPanier,Cible);
  }


