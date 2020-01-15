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
  printf("Have you played before (y/n)? ");
  char ans[5];
  fgets(ans,sizeof(ans), stdin);

  struct player playerOne;
  char username[20];
  if(!strncmp(ans,"y",1)){
    printf("What is your username? ");
    fgets(username, 256, stdin);
    username[strlen(username) - 1] = '\0';
    //playerOne = findPlayer(username);
  }else{
    printf("What would you like your username to be? ");
    fgets(username, 256, stdin);
    username[strlen(username) - 1] = '\0';
    playerOne = makePlayer(username);
    printPlayer(playerOne);
  }

  char diff[10];
  struct Minesweeper *currentgame;

  printf("Enter a difficulty (easy, medium, hard, or other):\n");
  fgets(diff,sizeof(diff),stdin);
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

  placeMines(currentgame);
  findMineCounts(currentgame);
  printBoard(currentgame);
  showAns(currentgame);

  int x, y;
  int turns = 0;
  while (1){
    printf("Uncover a space.\n");
    printf("Enter row #:");
    scanf("%d", &y);
    printf("Enter a column #:");
    scanf("%d", &x);
    uncoverSpace(currentgame, y, x);
    turns ++;
    printBoard(currentgame);
    if (checkDone(currentgame) == 1){
      break;
    }
  }
  printf("YOU WIN!!!!!!!! YAYAYAYAYAYYAYAYAYAYAYYAYAYY\n");
  showAns(currentgame);
  printf("Congrats! turn counter: %d turns!!\n", turns);

  addPlayer(playerOne);
  freeBoard(currentgame);

  return 0;
}
