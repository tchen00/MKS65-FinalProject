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

void findPlayer(char * name){

}

void makePlayer(char * name){

}

int main(int argc, char * argv[]){
  char * username;
  printf("Have you played before (y/n)? ");
  char * ans;
  fgets(ans, 4, stdin);
  if(!strcmp(ans,"y")){
    printf("What is your username? ");
    fgets(username, 256, stdin);
    findPlayer(username);
  }else{
    printf("What would you like your username to be? ");
    makePlayer(username);
  }
  printf("Type in a difficulty (easy, medium, expert): ");
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
