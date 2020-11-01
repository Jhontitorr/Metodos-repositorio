#include "servidor.h"
#include <stdint.h>

int main()
{
    int num1, num2;

  int s_sock = inicializa_e_espera(7891);
  char buffer[1024];
  num1 = 0;
  num2 = 0;

  while (1)
  {
    if (recv(s_sock, buffer, 1024, 0)){
      num1 = num2;
      sscanf (buffer, "%d", &num2);

      printf("Data received: %s ",buffer);
      if (num1+num2 > 50){
        printf("Somar maior que 50 e valor igual a :%d\n", num1+num2);
      }
      else{
        printf("soma foi menor que 50, %d\n", num1+num2);
      }
    }

  }
  return 0;
}
