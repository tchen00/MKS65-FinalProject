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
    if (board[randx][randy] != "X"){
      board[randx][randy] = "X";
      mines--;
    }
  }
}

char ** makeBoard(int difficulty){
  char ** newBoard;
  int x,y, mines;
  if(difficulty == 1 ){
    char ** newBoard[16][20];
    placeMines(newBoard,15);
  }
  else if(difficulty == 2){
    char ** newBoard[32][40];
    placeMines(newBoard,31);
  }
  else if(difficulty == 3){
    char ** newBoard[40][50];
    placeMines(newBoard,55);
  }
  else{
    printf("Enter x dimensions: ");
    fgets(x, 256, stdin);
    printf("Enter y dimensions: ");
    fgets(y, 256, stdin);
    printf("Enter number of mines: ");
    fgets(mines, 256, stdin);
    char ** newBoard[x][y];
    placeMines(newBoard,mines);
  }
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
  fgets(diff,4,stdin);
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
