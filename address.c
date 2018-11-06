/*
*Initialisation d'une
*address d'après polycope
*/

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  //definition d'une addresse serveur
  struct sockaddr_in monAdress ;

  //definition
  monAdress.sin_family = AF_INET ;
  monAdress.sin_port = htons(99) ;
  inet_aton("127.0.0.1", &(monAdress.sin_addr));

  //clearing sin_address

  memset(&(monAdress.sin_zero),'0',8) ;



  return 0;
}
