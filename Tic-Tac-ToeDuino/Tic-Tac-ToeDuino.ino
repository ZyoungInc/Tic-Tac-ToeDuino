const int MAX_MOVES = 9;
const int ScreenRolls = 30;
void printBoard(char board[3][3]);
void getNextMove(char board[3][3]);
void win(char board[3][3]);
void whowin(char key);
int foot = 0;
void setup() {
  Serial.begin(115200);
}
void loop() {
  int i;
  int n = 0;
  char board[3][3] = { '7', '8', '9',
                       '4', '5', '6',
                       '1', '2', '3'
                     };

  printBoard(board);
  for (i = 0; i < MAX_MOVES; i++) {
    getNextMove(board);
    win(board);
    n++;
  }
  if (n = MAX_MOVES) {
    Serial.println("gameover!");
    restart();
  }

}
void win(char a[3][3]) {
  int i, j, k;
  char key;
  if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[2][2] == a[0][0]) {
    key = a[0][0];
    whowin(key);
  }
  else if ( a[2][0] == a[1][1] && a[1][1] == a[0][2] && a[2][0] == a[0][2])
  {
    key = a[0][2];
    whowin(key);
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
            whowin(key);
            break;
          }
          for (k = 0; k < 3; k++) {
            if (a[k][j] != key) {
              break;
            }
          }
          if (k == 3) {
            whowin(key);

            return;
          }
        }
      }
    }
  }
}
void whowin(char key) {//done
  if (key == 79) {
    Serial.println("  ║║                                          ║║" );
    Serial.println("  ║║══════════════════════════════════════════║║" );
    Serial.println("  ║║             PLAYER O Winner!             ║║" );
    Serial.println("  ║║══════════════════════════════════════════║║" );
  }
  else {
    Serial.println("  ║║                                          ║║" );
    Serial.println("  ║║══════════════════════════════════════════║║" );
    Serial.println("  ║║             PLAYER X Winner!             ║║");
    Serial.println("  ║║══════════════════════════════════════════║║" );

  }
  
}
void printBoard(char board[3][3]) {//done
  Serial.println("  ╔════════════════════════════════════════════╗");
  Serial.println("  ║╔══════════════Tic-Tac-Toe═════════════════╗║");
  Serial.println("  ║║                                          ║║" );
  if (foot % 2 == 0) {
    Serial.println("  ║║            PLAYER O's TURN               ║║");
  }
  else {
    Serial.println("  ║║            PLAYER X's TURN!              ║║");

  }

  Serial.println("  ║║                                          ║║" );
  Serial.println("  ║║    Your Moves         Available Moves    ║║");
  Serial.println("  ║║~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~║║");
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
  Serial.print("  |   ");
  if (board[1][2] == 79 || board[1][2] == 88)  {
    Serial.print(board[1][2]);
  }
  else {
    Serial.print(" ");
  }
  Serial.print("     | ");
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
  Serial.println("  ║║                                          ║║");
  Serial.print("  ║║~~~~~~~~~~~");
  Serial.print( " Make your move!!! ");
  Serial.println("~~~~~~~~~~~~║║");
  Serial.println("  ║║                                          ║║");
  Serial.println("  ║╚══════════════════════════════════════════╝║ ");
  Serial.println("  ╚════════════════════════════════════════════╝");
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
        Serial.println("The Spot has been taken. Please pick another" );
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
  Serial.println("Would you like to replay (Y/N)?");
  while (1) {
    if (Serial.available() > 0) {
      char m = Serial.read();
      if (m == 'y') {
        break;
      }
    }
  }

}
