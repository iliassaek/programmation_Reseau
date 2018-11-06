#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[]) {
  struct hostent *hote = NULL ;
  const char *nomHote = "www.ensias.ma" ;
  struct in_addr ip ;

  hote = gethostbyname(nomHote) ;

  if(hote == NULL)
  {
    fprintf(stderr, "Nom hote %s inconnu. \n",nomHote);
    exit(EXIT_FAILURE) ;
  }

  memcpy(&(ip.s_addr), hote->h_addr_list[0], sizeof(u_long)) ;
  printf("%s-----------------%s\n",nomHote, inet_ntoa(ip));

  return 0;
}
