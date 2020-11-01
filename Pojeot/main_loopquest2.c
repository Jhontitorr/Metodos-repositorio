#include "cliente.h"
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand (time(NULL));
    int rando;



  int clientSocket = inicializa_e_conecta(7891);
  char buffer[1024];
  int i = 0;
  while (1)
  {
    sleep(2);
     rando = rand();
     rando = rando%99;
    sprintf(buffer,"%d", rando);
    send(clientSocket,buffer,strlen(buffer)+1,0);
    printf("Number sent: %s\n", buffer);
    i++;
 }
  return 0;
}
