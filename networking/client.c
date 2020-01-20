#include "networking.h"

int main(int argc, char **argv) {

  int server_socket;
  char x[BUFFER_SIZE];
  char y[BUFFER_SIZE];
  char choice[BUFFER_SIZE];
  char buffer[BUFFER_SIZE * 3];

  if (argc == 2)
    server_socket = client_setup( argv[1]);
  else
    server_socket = client_setup( TEST_IP );

  while (1) {
    printf("Enter an x-coor: ");
    fgets(x, sizeof(buffer), stdin);

    printf("Enter a y-coor: ");
    fgets(y, sizeof(buffer), stdin);

    printf("Uncover or flag? (f/u): ");
    fgets(choice, sizeof(buffer), stdin);
    strcpy(buffer, x);
    strcat(buffer, y);
    strcat(buffer, choice);
    *strchr(buffer,'\n') = 0;
    write(server_socket, buffer, sizeof(buffer));
    read(server_socket, buffer, sizeof(buffer));
    printf("received: [%s]\n", buffer);
  }
}
