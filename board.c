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
  int randx;
  int randy;
  while (mines){
    randx = (rand() % (columns + 1)) + columns;
    randy = (rand() % (rows + 1)) + rows;
    if (board[randx][randy] != 'X'){
      board[randx][randy] = 'X';
      mines--;
    }
  }
}

char ** makeBoard(int difficulty){
  int x, y, i, j, mines;
  if(difficulty == 1 ){
    x = 16, y = 20, mines = 15;
  }
  else if(difficulty == 2){
    x = 32, y = 40, mines = 31;
  }
  else if(difficulty == 3){
    x = 40, y = 50, mines = 55;
  }
  else{
    printf("Enter x dimensions: ");
    scanf("%d", &x);
    printf("Enter y dimensions: ");
    scanf("%d", &y);
    printf("Enter number of mines: ");
    scanf("%d", &mines);
  }
  char **newBoard;
  int rowsize = x * sizeof(char*);
  int columnsize = y * sizeof(char);
  newBoard = malloc(rowsize;
  printf("x * sizeof(char*): %d\n", rowsize);
  for (i=0; i<x; i++)
       newBoard[i] = malloc(columnsize);
  printf("y * sizeof(char): %d\n", y * sizeof(char));
  printf("size of entire board: %d\n", rowsize * columnsize);


  for (i = 0; i < x; i++)
      for (j = 0; j < y; j++)
         newBoard[i][j] = '0';
  printBoard(newBoard);
  placeMines(newBoard, x, y, mines);
  printBoard(newBoard);
  return newBoard;
}

void printBoard(char ** board){
  int rows = sizeof(board) / sizeof(board[0]);
  int columns = sizeof(board[0]) / sizeof(board[0][0]);
  printf("%d\n", rows);
  printf("%d\n", columns);
  int i, j;
  for (i = 0; i < rows; i ++){
    for (j = 0; j < columns; j ++){
      printf("[%c]", board[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]){
  char * diff;
  char ** currentgame;

  printf("YO! Enter a difficulty: easy, medium, hard:\n");
  fgets(diff,sizeof(diff),stdin);
  if(!strncmp(diff, "easy", 1)){
    currentgame = makeBoard(1);
  }
  else if(!strncmp(diff, "medium",1)){
    currentgame = makeBoard(2);
  }
  else if(!strncmp(diff, "hard",1)){
    currentgame = makeBoard(3);
  }
  else{
    currentgame = makeBoard(4);
  }

  return 0;
}
