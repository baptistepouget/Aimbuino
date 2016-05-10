void challenge() {
  tpsF = gb.frameCount - tpsD;
  if ((tpsF) > ( 60*20))
  {
    perdu = 1;
    restoreData();
  }
  gb.display.println("");
  gb.display.print(60.0 - ( tpsF / 20.0));
  gb.display.print("s");
}


/* 20 FPS soit 1/20 secondes par frame*/

