void scorePanel() 
{
      gb.display.cursorX = 0;
      gb.display.cursorY = 0;
      restoreData();
      gb.display.println("LeaderBoard : ");
      gb.display.println("Challenge / Free mode");
      for (int i = 0; i<3; i++)
      {
      gb.display.cursorX = 0;
      gb.display.print(save.leaderBoard[i].pseudo);
      gb.display.cursorX = LCDWIDTH/2;
      gb.display.println(save.leaderBoard[i+3].pseudo);
      gb.display.cursorX = 0;
      gb.display.print(save.leaderBoard[i].score);
      gb.display.cursorX = LCDWIDTH/2;
      gb.display.println(save.leaderBoard[i+3].score);
      }
      if (gb.buttons.pressed(BTN_C)) {
        gameMode = 'm';
      }
}


