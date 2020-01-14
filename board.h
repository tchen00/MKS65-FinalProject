struct Minesweeper{
  struct space **board;
  int rows;
  int columns;
  int size;
  int mines;
};

struct space{
  int revealed;
  int mine;
  int neighborcount;
  int marked; //corresponds to the player number who found it
};

void placeMines(struct Minesweeper *gameboard);
void printBoard(struct Minesweeper *gameboard);
struct Minesweeper *makeBoard(int difficulty);
struct space createSpace();
void freeBoard(struct Minesweeper *gameboard);
