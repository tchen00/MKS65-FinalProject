struct Minesweeper{
  char **board;
  int rows;
  int columns;
  int size;
  int mines;
};

struct space{
  int mine;
  int neighbors;
  int marked; //corresponds to the player number who found it
};

void placeMines(struct Minesweeper *gameboard);
void printBoard(struct Minesweeper *gameboard);
struct Minesweeper *makeBoard(int difficulty);
void freeBoard(struct Minesweeper *gameboard);
struct space createSpace();
