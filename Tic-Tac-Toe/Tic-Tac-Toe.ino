const int MAX_MOVES = 9;
const int ScreenRolls = 30;
int foot = 0;
int notification = 2;
int n = 0;
void setup() {
  Serial.begin(115200);
}
void loop() {
  CleanScreen();
  int i;
  n = 0;
  char board[3][3] = { '7', '8', '9',
                       '4', '5', '6',
                       '1', '2', '3'
                     };

  printBoard(board);
  Event(notification);
  for (i = 0; i < MAX_MOVES; i++) {
    getNextMove(board);
    win(board);
    Event(notification);
    if (notification == 0 || notification == 1) {
      notification = 2;
      restart();
      break;
    }
    n++;
  }
}
void win(char a[3][3]) {
  int i, j, k;
  char key;
  if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[2][2] == a[0][0]) {
    key = a[0][0];
    if (key == 79) {
      notification = 0;
    }
    else {
      notification = 1;
    }
  }
  else if ( a[2][0] == a[1][1] && a[1][1] == a[0][2] && a[2][0] == a[0][2])
  {
    key = a[0][2];
    if (key == 79) {
      notification = 0;
    }
    else {
      notification = 1;
    }
  }
  else {
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        if (a[i][j] == 79 || a[i][j] == 'X') {
          key = a[i][j];
          for (k = 0; k < 3; k++) {
            if (a[i][k] != key) {
              break;
            }
          }
          if (k == 3) {
            if (key == 79) {
              notification = 0;
            }
            else {
              notification = 1;
            }
            break;
          }
          for (k = 0; k < 3; k++) {
            if (a[k][j] != key) {
              break;
            }
          }
          if (k == 3) {
            if (key == 79) {
              notification = 0;
            }
            else {
              notification = 1;
            }

            return;
          }
        }
      }
    }
  }
}
void Event(char key) {//done
  if (n < MAX_MOVES - 1) {
    if (notification == 0) {
      Serial.println("  ║║                                          ║║" );
      Serial.println("  ║╠══════════════════════════════════════════╣║" );
      Serial.println("  ║║              PLAYER O WIN!               ║║" );
      Serial.println("  ║║         PRESS ANY KEY TO RESTART!        ║║" );
      Serial.println("  ║╚══════════════════════════════════════════╝║" );
      Serial.println("  ╚════════════════════════════════════════════╝" );
    }
    else if ( notification == 1) {
      Serial.println("  ║║                                          ║║");
      Serial.println("  ║╠══════════════════════════════════════════╣║" );
      Serial.println("  ║║              PLAYER X WIN!               ║║" );
      Serial.println("  ║║         PRESS ANY KEY TO RESTART!        ║║" );
      Serial.println("  ║╚══════════════════════════════════════════╝║" );
      Serial.println("  ╚════════════════════════════════════════════╝" );
    }
    else if (notification == 2 ) {
      Serial.println("  ║║                                          ║║" );
      Serial.println("  ║╠══════════════════════════════════════════╣║" );
      if (foot % 2 == 0) {
        Serial.println("  ║║            PLAYER O's TURN               ║║");
      }
      else {
        Serial.println("  ║║            PLAYER X's TURN!              ║║");

      }
      Serial.println("  ║║             MAKE YOUR MOVE!              ║║" );
      Serial.println("  ║╚══════════════════════════════════════════╝║" );
      Serial.println("  ╚════════════════════════════════════════════╝" );
    }
    else if (notification == 4) {
      Serial.println("  ║║                                          ║║" );
      Serial.println("  ║╠══════════════════════════════════════════╣║" );
      if (foot % 2 == 0) {
        Serial.println("  ║║            PLAYER O'S TURN               ║║");
      }
      else {
        Serial.println("  ║║            PLAYER X'S TURN!              ║║");

      }
      Serial.println("  ║║ SPOT HAS BEEN TAKEN! PLEASE PICK ANOTHER ║║" );
      Serial.println("  ║╚══════════════════════════════════════════╝║" );
      Serial.println("  ╚════════════════════════════════════════════╝" );
      notification = 2;
    }
  }
  else {
    Serial.println("  ║║                                          ║║");
    Serial.println("  ║╠══════════════════════════════════════════╣║" );
    Serial.println("  ║║               GAME OVER!!                ║║" );
    Serial.println("  ║║         PRESS ANY KEY TO RESTART!        ║║" );
    Serial.println("                   ║╚══════════════════════════════════════════╝║" );
    Serial.println("  ╚════════════════════════════════════════════╝" );
    notification = 2;
  }
}
void printBoard(char board[3][3]) {//done
  Serial.println("  ╔════════════════════════════════════════════╗");
  Serial.println("  ║╔══════════════TIC-TAC-TOE═════════════════╗║");
  Serial.println("  ║║                                          ║║" );
  Serial.println("  ║║    YOUR MOVES          AVAILABLE MOVES   ║║");
  Serial.println("  ║╠══════════════════════════════════════════╣║" );
  Serial.println("  ║║                                          ║║" );
  if (board[0][0] == 79 || board[0][0] == 88) {
    Serial.print("  ║║   ");
    Serial.print(board[0][0]);
  }
  else {
    Serial.print("  ║║    ");
  }
  Serial.print("  |  ");
  if (board[0][1] == 79 || board[0][1] == 88) {
    Serial.print(board[0][1]);
  }
  else {
    Serial.print(" ");
  }
  Serial.print("  |  ");
  if (board[0][2] == 79 || board[0][2] == 88)  {
    Serial.print(board[0][2]);
  }
  else {
    Serial.print(" ");
  }
  Serial.print("      |  ");
  if (board[0][0] == 79 || board[0][0] == 88) {
    Serial.print("   ");
  }
  else {
    Serial.print("7  ");
  }
  Serial.print("|");
  if (board[0][1] == 79 || board[0][1] == 88) {
    Serial.print("     ");
  }
  else {
    Serial.print("  8  ");
  }
  Serial.print("|");
  if (board[0][2] == 79 || board[0][2] == 88) {
    Serial.println("     | ║║");
    //Serial.println("|");
  }
  else {
    Serial.print("  9  ");
    Serial.println("| ║║");
  }

  Serial.println("  ║║ -----+-----+-----    |-----+-----+-----| ║║");
  if (board[1][0] == 79 || board[1][0] == 88) {
    Serial.print("  ║║   ");
    Serial.print(board[1][0]);
  }
  else {
    Serial.print("  ║║    ");
  }
  Serial.print("  |  ");
  if (board[1][1] == 79 || board[1][1] == 88) {
    Serial.print(board[1][1]);
  }
  else {
    Serial.print(" ");
  }
  Serial.print("  |  ");
  if (board[1][2] == 79 || board[1][2] == 88)  {
    Serial.print(board[1][2]);
  }
  else {
    Serial.print(" ");
  }
  Serial.print("      | ");
  if (board[1][0] == 79 || board[1][0] == 88) {
    Serial.print("    ");
  }
  else {
    Serial.print(" 4  ");
  }
  Serial.print("|");
  if (board[1][1] == 79 || board[1][1] == 88) {
    Serial.print("     ");
  }
  else {
    Serial.print("  5  ");
  }
  Serial.print("|");
  if (board[1][2] == 79 || board[1][2] == 88) {
    Serial.println("     | ║║");
  }
  else {
    Serial.print("  6  ");
    Serial.println("| ║║");
  }
  Serial.println("  ║║ -----+-----+-----    |-----+-----+-----| ║║");
  if (board[2][0] == 79 || board[2][0] == 88) {
    Serial.print("  ║║   ");
    Serial.print(board[2][0]);
  }
  else {
    Serial.print("  ║║    ");
  }
  Serial.print("  |  ");
  if (board[2][1] == 79 || board[2][1] == 88) {
    Serial.print(board[2][1]);
  }
  else {
    Serial.print(" ");
  }
  Serial.print("  |  ");
  if (board[2][2] == 79 || board[2][2] == 88)  {
    Serial.print(board[2][2]);
  }
  else {
    Serial.print(" ");
  }
  Serial.print("      |  ");
  if (board[2][0] == 79 || board[2][0] == 88) {
    Serial.print("   ");
  }
  else {
    Serial.print("1  ");
  }
  Serial.print("|");
  if (board[2][1] == 79 || board[2][1] == 88) {
    Serial.print("     ");
  }
  else {
    Serial.print("  2  ");
  }
  Serial.print("|");
  if (board[2][2] == 79 || board[2][2] == 88) {
    Serial.println("     | ║║ ");
  }
  else {
    Serial.print("  3  ");
    Serial.println("| ║║");
  }
}
void getNextMove(char board[3][3]) {//done
  int i, j, s, t;
  char m;
  while (1) {
    s = -1;
    t = -1;
    if (Serial.available() > 0) {
      m = Serial.read();
      for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
          if (board[i][j] == m) {
            s = i;
            t = j;
          }
        }
      }
      if (s == -1 && t == -1) {
        notification = 4;
        CleanScreen();
        printBoard(board);
        Event(notification);
      }
      else {
        break;
      }

    }
  }
  if (foot % 2 == 0) {
    board[s][t] = 79;
  }
  else {
    board[s][t] = 'X';
  }
  foot++;
  CleanScreen();
  printBoard(board);
}
void CleanScreen() {//done
  for (int temptime = 0; temptime < ScreenRolls; temptime++) {
    Serial.println("");
  }
}
void restart() {
  while (1) {
    if (Serial.available() > 0) {
      char m = Serial.read();
      break;
    }
  }
}
