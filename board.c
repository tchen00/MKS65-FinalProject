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
/*
IN PROGRESS 11/13/20.
int getMineCount(struct Minesweeper *gameboard, int i, int j){
  int count = 0;
  //we gotta figure out how to get the adjacent coordinates!
  //then we gotta go thru them and see if they are mines. if they are, count += 1.
  for x, y in gameboard->board[i][j].adjacentCoors{
    if (gameboard->board[x][y].mine == -1){
      count += 1
    }
  }
  return count
}

void findMineCounts(struct Minesweeper *gameboard){
  for (i = 0; i < gameboard->rows; i ++){
    for (j = 0; j < gameboard->columns; j ++){
      gameboard->board[i][j].neighborcount = getMineCount(gameboard, i, j);
    }
  }
}
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
