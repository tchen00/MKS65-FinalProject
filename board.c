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

void placeMines(char ** board, int mines){
  int rows = sizeof(board) / sizeof(board[0]);
  int columns = sizeof(board[0]) / sizeof(board[0][0]);
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

  char **newBoard = (char **)malloc(x * sizeof(char *));
  for (i=0; i<x; i++)
       newBoard[i] = (char *)malloc(y * sizeof(char));
  placeMines(newBoard, mines);
  return newBoard;
}
/*
void printBoard(char ** board){
  int i = 0;
  for (;i++; i <= )
}
*/
int main(int argc, char *argv[]){
  char * diff;
  char ** currentgame;

  printf("YO! Enter a difficulty: easy, medium, hard.");
  fgets(diff,sizeof(diff),stdin);
  if(!strcmp(diff, "easy")){
    currentgame = makeBoard(1);
  }
  else if(!strcmp(diff, "medium")){
    currentgame = makeBoard(2);
  }
  else if(!strcmp(diff, "expert")){
    currentgame = makeBoard(3);
  }
  return 0;
}
