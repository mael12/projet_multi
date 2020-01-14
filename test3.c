#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

/*
pbs :
valeurs moches parfois :
-trouver pourquoi



Initialization Complete
1

No response
3+17.38+0.62+20.0C]G

4-12.6+20.6F]

5-11.9+20.5GcY

6-13.8+20.3C[V


*/


double data[6][4];


void separation_ligne(char* ligne,double* ligne_double){
  int init_size = strlen(ligne);
  char delim[] = "+-";
  char *ptr = strtok(ligne, delim);
  char info[13];
  int i=0;
  while (ptr != NULL)
  {
    strcpy(info,ptr);
    ligne_double[i]=atof(info);
    ptr = strtok(NULL, delim);
    i++;
  }
}

void affichage_valeurs(){
  int i;
   for (i=0; i<6; i++){
     printf("Device %f, values : %f %f %f\n",data[i][0],data[i][1],data[i][2],data[i][3]);
  }
}


void enregistrement(){
  int i;
  char ligne[125];
  for (i=0; i<6; i++){
    strcpy(ligne,"1+12.3-4.5ukfkutf");
    separation_ligne(ligne,data[i]);
  }
}


void main(){
   enregistrement();
   affichage_valeurs();
}