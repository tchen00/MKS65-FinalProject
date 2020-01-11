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

struct player findPlayer(char * name){
  int fd, rd;
  fd = open("player.csv", O_RDONLY);
  if (fd < 0){
    printf("open errno: %s\n", strerror(errno));
  }
  char buff[100];
  rd = read(fd, buff, 100);
  if (rd < 0){
    printf("read errno: %s\n", strerror(errno));
  }
  char *s = buff;

  //go thru the csv file line by line till the first element is the name
  //then create the player as seen below:
  struct player foundPlayer;
  strcpy(foundPlayer.name, strsep(&s, ","));
  foundPlayer.pastgames = sscanf(strsep(&s, ","), '%d');
  foundPlayer.victories = sscanf(strsep(&s, ","), '%d');
  foundPlayer.losses = sscanf(strsep(&s, ","), '%d');
  return foundPlayer;
}

void printPlayer(struct player user){
  printf("Player info:\n");
  printf("Name: %s\n", user.name);
  printf("# of past games: %d\n", user.pastgames);
  printf("# of victories: %d\n", user.victories);
  printf("# of losses: %d\n", user.losses);
}

void addPlayer(struct player user){
  int fd, rd, wr;
  fd = open("player.csv", O_WRONLY | O_APPEND);
  if (fd < 0){
    printf("open errno: %s\n", strerror(errno));
  }
  printf("%s\n", user.name);
  char line[20];
  sprintf(line, "%s,%d,%d,%d\n", user.name, user.pastgames, user.victories, user.losses);
  printf("%d", strlen(line));
  //idk if this line below does anything.
  //im tryna make it so there isn't so much garbage in the string.
  //the string should look like alvinyao,0,0,0 and that's it, no more junk after
  //but uhh idk how to do that yet. so for now there's a shit ton of random binary shit i think.
  line[strlen(line)] = '\0';
  printf("%s", line);
  wr = write(fd, line, strlen(line));
  if (wr < 0){
    printf("write errno: %s\n", strerror(errno));
  }
  close(fd);
}


//void editStudent(struct Student *newStudent, char* newName, int newGrade) {
//  strcpy(newStudent->name, newName);
//  newStudent->grade = newGrade;
//}
