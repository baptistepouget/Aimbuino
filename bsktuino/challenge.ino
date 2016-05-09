void challenge(){
      tpsF += gb.frameCount - tpsD;
      if (((tpsF - tpsD)/20.0) > 60)
      {
        perdu = 1;
        tpsF = tpsD = gb.frameCount;
      }
      gb.display.println("Time left");
      gb.display.print(60.0-(tpsF - tpsD)/20.0);
}


/* 20 FPS soit 1/20 secondes par frame
