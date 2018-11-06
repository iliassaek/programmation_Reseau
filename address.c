/*
*Initialisation d'une
*address d'après polycope
*
*n'oublie pas arpa/inet pour éviter
*le warning de inet_ntoa
*/

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[]) {

  //definition d'une addresse serveur
  struct sockaddr_in monAdress ;

  //definition de la famille qui est la même de la socket
  monAdress.sin_family = AF_INET ;

  //convertir le port vers le format Network By Order
  monAdress.sin_port = htons(99) ;

  //Transformer l'adresse locale au format struct in_addr
  inet_aton("127.0.0.1", &(monAdress.sin_addr));

  //clearing sin_address

  memset(&(monAdress.sin_zero),'0',8) ;



  return 0;
}
