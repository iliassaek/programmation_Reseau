#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[]) {
  int ds ;

//défintion de l'adresse serveur
  struct sockaddr_in aSrv ;
  aSrv.sin_family = AF_INET ;
  aSrv.sin_port = htons(80) ;
  inet_aton("127.0.0.1",&(aSrv.sin_addr)) ;
  memset(&aSrv.sin_zero,'0',8) ;

//création d'une socket par laquelle on va se connecter
  ds = socket(PF_INET, SOCK_STREAM , IPPROTO_TCP) ;

//il s'agit d'un network local on test les ports

//si le port est occupé donc un serveur lui est associé
  if(connect(ds,(struct sockaddr *)&aSrv,sizeof(struct sockaddr)) != -1)
    printf("un serveur est connecté au port %d \n ", ntohs(aSrv.sin_port)) ;
  else
  {

// sinon le port n'est pas en écoute de notre socket
    printf("Probleme de connexion au serveur ecoutant sur le port : %d \n",ntohs(aSrv.sin_port));
    return EXIT_FAILURE ;
  }
  return 0;
}
