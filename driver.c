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
#include "play.h"

int main(int argc, char * argv[]){
  srand(time(NULL));

  char username[20];
  printf("Have you played before (y/n)? ");
  char ans[5];
  fgets(ans,sizeof(ans), stdin);
  if(!strncmp(ans,"y",1)){
    printf("What is your username? ");
    fgets(username, 256, stdin);
    findPlayer(username);
  }else{
    printf("What would you like your username to be? ");
    fgets(username, 256, stdin);
    printPlayer(makePlayer(username));
  }

  char diff[10];
  struct Minesweeper *currentgame;

  printf("YO! Enter a difficulty: easy, medium, hard, or other:\n");
  fgets(diff,sizeof(diff),stdin);
  printf("YOOOOOOOO\n");
  if(!strncmp(diff, "easy", 4)){
    currentgame = makeBoard(1);
  }
  else if(!strncmp(diff, "medium", 6)){
    currentgame = makeBoard(2);
  }
  else if(!strncmp(diff, "hard", 4)){
    currentgame = makeBoard(3);
  }
  //else if (!strncmp(diff, "other", 1)){
  else{
    currentgame = makeBoard(4);
  }

  printBoard(currentgame);
  placeMines(currentgame);
  printBoard(currentgame);


  int i;
  for (i=0; i<currentgame->rows; i++)
    free(currentgame->board[i]);
  free(currentgame->board);

  return 0;
}
