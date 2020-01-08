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

struct player{
  char name[100];
  int pastgames;
  int victories;
  int losses;
  boolean online;
}

struct player makePlayer(char * name){
  struct ptudent newPlayer;
  strcpy(newPlayer.name, name);
  newPlayer.pastgames = 0;
  newPlayer.victories = 0;
  newPlayer.losses = 0;
  newPlayer.online = true;
  return newPlayer;
}

void findPlayer(char * name){

}

void makePlayer(char * name){

}

void printPlayer(struct Player user){
  printf("Player info:\n");
  printf("Name:\t%s\n", user.name);
  printf("# of past games:\t%d\n\n", user.pastgames);
  printf("# of victories:\t%d\n\n", user.victories);
  printf("# of losses:\t%d\n\n", user.losses);
  printf("Connected!\n");
}

void editStudent(struct Student *newStudent, char* newName, int newGrade) {
  strcpy(newStudent->name, newName);
  newStudent->grade = newGrade;
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
