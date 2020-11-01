#include "servidor.h"
#include <stdint.h>

int inicializa_e_espera(uint16_t porta)
{
  int welcomeSocket, newSocket;
  struct sockaddr_in serverAddr;
  struct sockaddr_in client;
  WSADATA wsaData;
  if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
  {
      printf("Erro de versao do WSocket!\n");
      exit(1);
  }
  welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(porta);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
  bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
  if(listen(welcomeSocket,5)==0)
    printf("Esperando...\n");
  else
    printf("Erro!\n");
  int addr_size = sizeof(struct sockaddr_in);
  newSocket = accept(welcomeSocket, (struct sockaddr *) &client, &addr_size);

  return newSocket;
}
