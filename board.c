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

void placeMines(char ** board, int mines){
  int rows = sizeof(board) / sizeof(board[0]);
  int columns = sizeof(board[0]) / sizeof(board[0][0]);
  int randx;
  int randy;
  while(mines){
    randx = (rand() % (columns + 1)) + columns;
    randy = (rand() % (rows + 1)) + rows;
    if(board[randx][randy] != "X"){
      board[randx][randy] = "X";
      mines--;
    }
  }
}

char ** makeBoard(int difficulty){
  char ** newBoard;
  if(difficulty == 1){
    return newBoard[16][20];
  }
  else if(difficulty == 2){
    return newBoard[32][40];
  }
  else{
    return newBoard[40][50];
  }
}

int main(){
  return 0;
}
