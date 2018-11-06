/*
* Identifier l'hote à travers son nom en utilisant de DNS
*/


#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[]) {

  //définition de la structure hostent
  struct hostent *hote = NULL ;

  //donner le nom de l'hote
  const char *nomHote = "www.ensias.ma" ;

  //définition de la structure ip
  struct in_addr ip ;

  //gethostbyname va nous chercher la structure in_addr du nomHote
  hote = gethostbyname(nomHote) ;

  //cas de ip introuvable
  if(hote == NULL)
  {
    fprintf(stderr, "Nom hote %s inconnu. \n",nomHote);
    exit(EXIT_FAILURE) ;
  }

  //copier le contenu de h_addr_list dans ip.s_addr
  memcpy(&(ip.s_addr), hote->h_addr_list[0], sizeof(u_long)) ;

  // inet_ntoa va nous rendre l ip de la forme 192. ...
  printf("%s-----------------%s\n",nomHote, inet_ntoa(ip));

  return 0;
}
