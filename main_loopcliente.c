#include "cliente.h"
#include <unistd.h>
#include <stdint.h>

int main()
{
  int clientSocket = inicializa_e_conecta(7891);
  char buffer[1024];
  int i = 0;
  while (1)
  {
    sleep(3);
    sprintf(buffer,"Quem quer cafe? %d\n", i);
    send(clientSocket,buffer,strlen(buffer)+1,0);
    printf("Data sent: %s", buffer);
    i++;
  }
  return 0;
}
