#include <stdio.h>
#include <time.h>


int main(int argc, char const *argv[]) {
  time_t laDate ;
  time(&laDate) ;

  struct tm laDateFmt = *localtime(&laDate) ;

//accès aux différents champs de la date

//Date
  printf("la date du systeme est : %s \n",asctime(&laDateFmt));

//Heure
  printf("l'heure %d \n",(laDateFmt.tm_hour));

//Heure date

  printf("L'heure : %d \t la date : %s",laDateFmt.tm_hour,asctime(&laDateFmt) );

  printf("le mois %d \n",(laDateFmt.tm_mon +1));
  printf("l'année %d \n",(laDateFmt.tm_year +1900)) ;
  return 0;
}
