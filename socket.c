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

  // creation de la socket d'une manière classique
  if ((ds = socket(PF_INET , SOCK_STREAM, IPPROTO_TCP))==-1)
  {
    printf("Erreur lors de la création de la socket !!!!!!\n");
  }else{

    // le resultat nous donne 3
    printf("le numéro du descripteur identifiant ce socket est %d\n",ds);
  }
  return 0;
}
