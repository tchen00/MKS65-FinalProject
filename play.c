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

#include "play.h"

struct player makePlayer(char * name){
  struct player newPlayer;
  strcpy(newPlayer.name, name);
  newPlayer.pastgames = 0;
  newPlayer.victories = 0;
  newPlayer.losses = 0;
  return newPlayer;
}

void findPlayer(char * name){

}

void printPlayer(struct player user){
  printf("Player info:\n");
  printf("Name: %s\n", user.name);
  printf("# of past games: %d\n", user.pastgames);
  printf("# of victories: %d\n", user.victories);
  printf("# of losses: %d\n", user.losses);
  printf("Welcome Back!\n");
}

//void editStudent(struct Student *newStudent, char* newName, int newGrade) {
//  strcpy(newStudent->name, newName);
//  newStudent->grade = newGrade;
//}
