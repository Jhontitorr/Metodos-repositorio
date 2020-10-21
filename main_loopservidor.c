#include "servidor.h"
#include <stdint.h>

int main()
{
  int s_sock = inicializa_e_espera(7891);
  char buffer[1024];
  while (1)
  {
    if (recv(s_sock, buffer, 1024, 0))
      printf("Data received: %s",buffer);
  }
  return 0;
}
