void scorePanel() 
{
      gb.display.println("LeaderBoard : ");
      gb.display.println("Challenge / Free mode");
      for (int i = 0; i<3; i++)
      {
      gb.display.print(save.leaderBoard[i].pseudo);
      gb.display.print("   ");
      gb.display.println(save.leaderBoard[i].pseudo);
      gb.display.print(save.leaderBoard[i+3].score);
      gb.display.print("   ");
      gb.display.println(save.leaderBoard[i+3].score);
      }
}

