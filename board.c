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

#include "board.h"

void placeMines(struct Minesweeper *gameboard){
  struct space ** board = gameboard->board;
  int minesremaining = gameboard->mines;
  printf("PLACING MINES...\n");
  int randr;
  int randc;
  while (minesremaining){
    randr = rand() % gameboard->rows;
    randc = rand() % gameboard->columns;
    if (board[randr][randc].mine == 0){
      board[randr][randc].mine = -1;
      minesremaining--;
    }
  }
  printf("MINES PLACED!\n");
}

//IN PROGRESS 11/13/20.
int getMineCount(struct Minesweeper *gameboard, int y, int x){
  int count = 0;
  int i, j;
  //unfortunately, it's a mad long thing to see if the coordinates are valid.
  //it works though. so that's a W in my books.
  for (i = -1; i <= 1; i++){
    for (j = -1; j <= 1; j++){
      if (!(i == 0 && j == 0)){
        if (y + i >= 0 && x + j >= 0 && y + i < gameboard->rows && x + i < gameboard->columns){
          if (gameboard->board[y+i][x+j].mine == -1){
            count ++;
          }
        }
      }
    }
  }
  return count;
}

void findMineCounts(struct Minesweeper *gameboard){
  int i, j;
  for (i = 0; i < gameboard->rows; i ++){
    for (j = 0; j < gameboard->columns; j ++){
      gameboard->board[i][j].neighborcount = getMineCount(gameboard, i, j);
    }
  }
}

void uncoverSpace(struct Minesweeper *gameboard, int y, int x){
  int i, j;
  gameboard->board[y][x].revealed = 1;
  printf("%d", gameboard->board[y][x].mine);
  printf("revealed!");
  if (gameboard->board[y][x].mine == 0){
    for (i = -1; i <= 1; i++){
      for (j = -1; j <= 1; j++){
        if (!(i == 0 && j == 0)){
          if (y + i >= 0 && x + j >= 0 && y + i < gameboard->rows && x + i < gameboard->columns){
            uncoverSpace(gameboard, y + i, x + j);
          }
        }
      }
    }
  }
}
/*
python uncover board function. it's recursive!!
def uncover_board(self, y, x):
    if self.board[y][x] != None:
        return
    mine_count = self.get_mine_count(y, x)
    self.board[y][x] = mine_count
    self.user_view(y, x)
    if mine_count == 0:
        for (i,j) in self.adjacent_coordinates(y, x):
            self.uncover_board(i, j)
            */

struct Minesweeper *makeBoard(int difficulty){
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

  //creating struct pointer
  struct Minesweeper *gameboard;
  //allocating memory
  gameboard = (struct Minesweeper *)malloc(sizeof(struct Minesweeper));
  gameboard->rows = r;
  gameboard->columns = c;
  gameboard->mines = mines;
  gameboard->size = r * c;


  int rowsize = r * sizeof(struct space*);
  int columnsize = c * sizeof(struct space);
  gameboard->board = (struct space**)malloc(rowsize);
  for (i=0; i<r; i++)
    gameboard->board[i] = (struct space*)malloc(columnsize);
  printf("r * sizeof(struct space*): %d\n", rowsize);
  printf("c * sizeof(struct space): %d\n", columnsize);
  printf("size of entire board: %d\n", rowsize * columnsize);
  for (i = 0; i < r; i++)
      for (j = 0; j < c; j++)
         gameboard->board[i][j] = createSpace();

  return gameboard;
}

void printBoard(struct Minesweeper *gameboard){
  struct space ** board = gameboard->board;
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
      printf("[ ");
      //if the space is not yet revealed, print '_'.
      if (!board[i][j].revealed){
        printf("_");
      }
      //else, if the space is indeed revealed:
      else{
        //if the space is a mine, print *.
        if (board[i][j].mine == -1){
          printf("*");
        }
        //if the space is just a normal space, print the number of neighboring mines.
        //neighborcount will be calculated later.
        else{
          printf("%d", board[i][j].neighborcount);
        }
      }
      printf(" ]");
    }
    printf("\n");
  }
}

void showAns(struct Minesweeper *gameboard){
  struct space ** board = gameboard->board;
  printf("DISPLAYING ANSWERS...\n");
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
      printf("[ ");
      if (board[i][j].mine == -1){
        printf("*");
      }
      else{
        printf("%d", board[i][j].neighborcount);
      }
      printf(" ]");
    }
    printf("\n");
  }
}

struct space createSpace(){
  struct space temp;
  temp.revealed = 0;
  temp.mine = 0;
  temp.neighborcount = 0;
  temp.marked = 0;
  return temp;
}

void freeBoard(struct Minesweeper *gameboard){
  int i;
  for (i=0; i<gameboard->rows; i++)
    free(gameboard->board[i]);
  free(gameboard->board);
}
