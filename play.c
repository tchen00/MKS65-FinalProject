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
};

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

int main(int argc, char * argv[]){
  char * username;
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
