struct player{
  char name[100];
  int pastgames;
  int victories;
  int losses;
};

struct player makePlayer(char * name);
void findPlayer(char * name);
void printPlayer(struct player user);
