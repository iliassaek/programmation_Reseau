/*
*Le but du programme :
*le client envoie une requete
*le serveur reçoit la requete
*le serveur renvoie la même requete sans traitement
*le client reçoit sa requête
*/



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
  int dss,dsc ;

//déclaration d'un buffer
  char* reqt = calloc(1024, sizeof(char)) ;

//déclaration de structures IP de communication serv et client
  struct sockaddr_in aSrv, aClt;

//une longueur de la structure ip client elle nous servira en accept
  socklen_t lgAdrClt = sizeof(struct sockaddr) ;

//defintion classique de l'adresse serveur family/port/addr/zero
  aSrv.sin_family = AF_INET ;
  aSrv.sin_port = htons(9097) ;
  inet_aton("127.0.0.1",&(aSrv.sin_addr)) ;
  memset(&aSrv.sin_zero,'0',8) ;


//creation de la socket serveur
  dss = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP) ;
  printf("dss : %d", dss) ;


//On va lier la socket au réseau ou bien on ouvre la fenêtre
  if (bind( dss, (struct sockaddr *)&aSrv, sizeof(struct sockaddr) ) == -1)
  {
    perror("Probleme du bind") ;
    return EXIT_FAILURE ;
  }

// on détermine le nombre de connexions simultannées possibles
  if (listen(dss,10)==-1) {
    perror("Probleme du listen") ;
    return EXIT_FAILURE ;
  }


  while (1) {

//On accepte la connexion du client sachant que accept agit sur un buffer de connexions
    dsc = accept(dss,(struct sockaddr*)&aClt, &lgAdrClt) ;
    memset(reqt,'\0', 1024) ;

//on reçoit sur reqt le message venant par la socket client
    if (recv(dsc,reqt,1024,0)>0)
    {
// on envoie vers le client le message contenu dans reqt
      send(dsc,reqt,strlen(reqt),0) ;
    }

//on ferme la connexion avec le client
    close(dsc) ;
  }
//on ferme la cnx du serveur
  close(dss) ;

  return 0;
}
