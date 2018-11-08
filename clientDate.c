#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

//déclaration descripteur client et descripteur serveur
  int ds;

//déclaration d'un buffer
  char* reqt = calloc(2014, sizeof(char)) ;
  char* reps = calloc(2014, sizeof(char)) ;

//déclaration de structures IP de communication avec le serveur
  struct sockaddr_in aSrv ;

//defintion classique de l'adresse serveur family/port/addr/zero
  aSrv.sin_family = AF_INET ;
  aSrv.sin_port = htons(9097) ;
  inet_aton("127.0.0.1",&(aSrv.sin_addr)) ;
  memset(&aSrv.sin_zero,'0',8) ;


//creation de la socket serveur
  ds = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP) ;
  printf("ds : %d \n", ds) ;


//On va lier la socket au réseau ou bien on ouvre la fenêtre
  if (connect(ds, (struct sockaddr *)&aSrv, sizeof(struct sockaddr))  == -1)
  {
    perror("Probleme de connection au serveur") ;
    return EXIT_FAILURE ;
  }

// Clearing reqt
  memset(reqt, '\0', 2014) ;

// like scanf + affected to reqt
  fgets(reqt,10000,stdin) ;

// send the reqt to server
  send(ds, reqt,strlen(reqt),0) ;

//recieving response from server and showing it
  while (recv(ds,reps,1024,0)>0)
  {
    printf("message reçu est : %s\n",reps);
  }

//clearing reqt
  memset(reqt,'\0',2014) ;

//closing client
  close(ds) ;


  return EXIT_SUCCESS ;
}
