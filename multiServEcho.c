/*--------------------------------------------*/

amusez-vous à créer des client en tapant
telnet 127.0.0.1 9090
sur différents terminaux


/*--------------------------------------------*/

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
#include <time.h>
int main(int argc, char const *argv[]) {

  /*--------------defintion du temps -------------------------*/

  time_t laDate ;
  time(&laDate) ;

  struct tm laDateFmt = *localtime(&laDate) ;

  /*-----------------------------------------------------------*/

  int dss , dsc ;
  char* reqt = calloc(1024,sizeof(char)) ;
  char* reps = calloc(1024,sizeof(char)) ;

  struct sockaddr_in aSrv, aClt ;
  socklen_t lgAdrClt = sizeof(struct sockaddr) ;

  aSrv.sin_family = AF_INET ;
  aSrv.sin_port = htons(9090) ;
  inet_aton("127.0.0.1",&(aSrv.sin_addr)) ;
  memset(&aSrv.sin_zero,'0',8) ;
  dss = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP) ;
  bind(dss,(struct sockaddr *)&aSrv,sizeof(struct sockaddr)) ;
  listen(dss,10) ;

  while (1) {
    dsc = accept(dss,(struct sockaddr*)&aClt ,&lgAdrClt) ;
    printf("Nouveau client connecté ......\n");
    if (fork()!=0) {
      close(dsc) ;
    }else{
      close(dss);
      while (1) {
        memset(reps,'\0', 1024) ;
        strcpy(reps , "Tapez votre message : ") ;
        send(dsc , reps , strlen(reps) , 0) ;
        memset(reps,'\0' , 1024) ;
        memset(reqt,'\0' , 1024) ;
        if (recv(dsc,reqt,1024,0)>0) {
          if (strncmp("HEUREDATE",reqt,9) == 0) {
            sprintf(reqt,"JOUR : %d \t mois : %d \t l'année : %d \n",laDateFmt.tm_mday,laDateFmt.tm_mon +1, laDateFmt.tm_year +1900) ;
            send(dsc,reqt , strlen(reqt),0) ;
          }else if (strncmp("HEURE",reqt,5) == 0) {
            sprintf(reqt,"%d",laDateFmt.tm_hour);
            send(dsc,reqt , strlen(reqt),0) ;
          }else if (strncmp("DATE",reqt,4) == 0) {
            strcpy(reqt,asctime(&laDateFmt));
            send(dsc,reqt , strlen(reqt),0) ;
          }else if (strncmp(reqt,"EXIT",4) ==0) {
            strcpy(reps,"Fin de connexion ......") ;
            send(dsc,reps,strlen(reps),0);
            break ;
          }
          else send(dsc,reqt , strlen(reqt),0) ;
        }
      }
      close(dsc) ;
      return EXIT_SUCCESS ;
    }
  }
  close(dss);
  return EXIT_SUCCESS ;
}
