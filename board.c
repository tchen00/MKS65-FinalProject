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

struct mine{
  int marked; //corresponds to the player number who found it
};

void placeMines(char ** board, int rows, int columns, int mines){
  int randr;
  int randc;
  int minesremaining = mines;
  while (minesremaining){
    randr = rand() % rows;
    randc = rand() % columns;
    if (board[randr][randc] != 'X'){
      board[randr][randc] = 'X';
      minesremaining--;
    }
  }
}

void printBoard(char ** board, int rows, int columns){
  printf("%d\n", rows);
  printf("%d\n", columns);
  int i, j;
  printf("\t   ");
  for (j = 0; j < columns; j ++){
    printf("%d   ", j);
    if (j < 9)
      printf(" ");
  }
  printf("\n");
  for (i = 0; i < rows; i ++){
    printf("%d\t", i);
    for (j = 0; j < columns; j ++){
      printf("[ %c ]", board[i][j]);
    }
    printf("\n");
  }
}


char ** makeBoard(int difficulty){
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
  char **newBoard;
  int rowsize = r * sizeof(char*);
  int columnsize = c * sizeof(char);
  newBoard = malloc(rowsize);
  printf("r * sizeof(char*): %d\n", rowsize);
  for (i=0; i<r; i++)
       newBoard[i] = malloc(columnsize);
  printf("c * sizeof(char): %d\n", columnsize);
  printf("size of entire board: %d\n", rowsize * columnsize);


  for (i = 0; i < r; i++)
      for (j = 0; j < c; j++)
         newBoard[i][j] = '0';

  printBoard(newBoard, r, c);
  placeMines(newBoard, r, c, mines);
  printf("yo");
  printBoard(newBoard, r, c);
  printf("yooooooooooooooo\n");
  return newBoard;
}

int main(int argc, char *argv[]){
  char * diff;
  char ** currentgame;

  printf("YO! Enter a difficulty: easy, medium, hard, or other:\n");
  fgets(diff,sizeof(diff),stdin);
  if(!strncmp(diff, "easy", 1)){
    currentgame = makeBoard(1);
  }
  else if(!strncmp(diff, "medium", 1)){
    currentgame = makeBoard(2);
  }
  else if(!strncmp(diff, "hard", 1)){
    currentgame = makeBoard(3);
  }
  //else if (!strncmp(diff, "other", 1)){
  else{
    currentgame = makeBoard(4);
  }
  return 0;
}
