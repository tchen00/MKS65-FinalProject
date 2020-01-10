struct Minesweeper{
  char **board;
  int rows;
  int columns;
  int size;
  int mines;
};

struct mine{
  int marked; //corresponds to the player number who found it
};

struct player{
  char name[100];
  int pastgames;
  int victories;
  int losses;
};

void placeMines(struct Minesweeper * gameboard);
void printBoard(struct Minesweeper *gameboard);
struct Minesweeper *makeBoard(int difficulty);
struct player makePlayer(char * name);
void findPlayer(char * name);
void printPlayer(struct player user);
