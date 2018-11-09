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
  aSrv.sin_port = htons(80) ;
  inet_aton("127.0.0.1",&(aSrv.sin_addr)) ;
  memset(&aSrv.sin_zero,'0',8) ;


//creation de la socket serveur
  ds = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP) ;
  printf("ds : %d", ds) ;


//On va lier la socket au réseau ou bien on ouvre la fenêtre
  if (connect(ds, (struct sockaddr *)&aSrv, sizeof(struct sockaddr))  == -1)
  {
    perror("Probleme de connection au serveur") ;
    return EXIT_FAILURE ;
  }

// Clearing reqt
  memset(reqt, '\0', 1024) ;

// like scanf + affected to reqt
  fgets(reqt,1024,stdin) ;
	int len = strlen(reqt);
  reqt[len-1] = '\r';
reqt[len] = '\n'; 
reqt[len+1] = '\0'; 
  
// send the reqt to server
  send(ds, reqt,strlen(reqt),0) ;

//recieving response from server and showing it
  memset(reps, '\0', 1024) ;
  if (recv(ds,reps,1024,0)>0)
  {
    for(int i =0;i<strlen(reps);i++)
    {
	if(reps[i] == '\n') reps[i] = '\0' ;
}
    printf("message reçu est : %s\n",reps);
  }

//clearing reqt
  memset(reqt,'\0',1024) ;

//closing client
  close(ds) ;


  return EXIT_SUCCESS ;
}
