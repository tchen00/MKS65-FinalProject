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
int getMineCount(struct Minesweeper *gameboard, int x, int y);
void findMineCounts(struct Minesweeper *gameboard);
struct Minesweeper *makeBoard(int difficulty);
void printBoard(struct Minesweeper *gameboard);
void showAns(struct Minesweeper * gameboard);
struct space createSpace();
void freeBoard(struct Minesweeper *gameboard);
