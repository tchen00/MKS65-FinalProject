#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <ctype.h>

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

void placeMines(struct Minesweeper * gameboard){
  //might be sus here.
  char ** board = gameboard->board;
  int minesremaining = gameboard->mines;
  printf("PLACING MINES...\n");
  int randr;
  int randc;
  while (minesremaining){
    randr = rand() % gameboard->rows;
    randc = rand() % gameboard->columns;
    if (board[randr][randc] != 'X'){
      board[randr][randc] = 'X';
      minesremaining--;
    }
  }
  printf("MINES PLACED!\n");
}

void printBoard(struct Minesweeper *gameboard){
  //again, this might be sus.
  char ** board = gameboard->board;
  printf("DISPLAYING BOARD...\n");
  int i, j;
  printf("\t   ");
  for (j = 0; j < gameboard->columns; j ++){
    printf("%d   ", j);
    if (j < 9)
      printf(" ");
  }
  printf("\n");
  for (i = 0; i < gameboard->rows; i ++){
    printf("%d\t", i);
    for (j = 0; j < gameboard->columns; j ++){
      printf("[ %c ]", board[i][j]);
    }
    printf("\n");
  }
}


struct Minesweeper *makeBoard(struct Minesweeper *gameboard, int difficulty){
  printf("difficulty: %d\n", difficulty);
  int r, c, i, j, mines;
  if(difficulty == 1){
    r = 16, c = 20, mines = 15;
  }
  else if(difficulty == 2){
    r = 32, c = 40, mines = 31;
  }
  else if(difficulty == 3){
    r = 40, c = 50, mines = 55;
  }
  else{
    printf("Enter # of rows: ");
    scanf("%d", &r);
    printf("Enter # of columns: ");
    scanf("%d", &c);
    printf("Enter number of mines: ");
    scanf("%d", &mines);
  }

  gameboard->rows = r;
  gameboard->columns = c;
  gameboard->mines = mines;

  gameboard->size = r * c;


  int rowsize = r * sizeof(char*);
  int columnsize = c * sizeof(char);
  gameboard->board = (char**)malloc(rowsize);
  for (i=0; i<r; i++)
    gameboard->board[i] = (char*)malloc(columnsize);
  printf("r * sizeof(char*): %d\n", rowsize);
  printf("c * sizeof(char): %d\n", columnsize);
  printf("size of entire board: %d\n", rowsize * columnsize);
  for (i = 0; i < r; i++)
      for (j = 0; j < c; j++)
         gameboard->board[i][j] = '0';
  return gameboard;
}

int main(int argc, char *argv[]){
  srand(time(NULL));
  char * diff;
  struct Minesweeper *currentgame = (struct Minesweeper *)malloc(sizeof(struct Minesweeper));

  printf("YO! Enter a difficulty: easy, medium, hard, or other:\n");
  fgets(diff,sizeof(diff),stdin);
  if(!strncmp(diff, "easy", 1)){
    currentgame = makeBoard(currentgame, 1);
  }
  else if(!strncmp(diff, "medium", 1)){
    currentgame = makeBoard(currentgame, 2);
  }
  else if(!strncmp(diff, "hard", 1)){
    currentgame = makeBoard(currentgame, 3);
  }
  //else if (!strncmp(diff, "other", 1)){
  else{
    currentgame = makeBoard(currentgame, 4);
  }

  printBoard(currentgame);
  placeMines(currentgame);
  printBoard(currentgame);
  return 0;
}
