#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


char ligne[125];
double ligne_double[4];

void separation_ligne(char* ligne,double* ligne_double){
	int init_size = strlen(ligne);
	char delim[] = "+-";
	char *ptr = strtok(ligne, delim);
  char info[13];
  int i=0;
  while (ptr != NULL)
	{
    strcpy(info,ptr);
		ptr = strtok(NULL, delim);
    ligne_double[i]=atof(info);
    printf("chain : %s\n",info);
    printf("double : %f\n",ligne_double[i]);
    i++;
	}
}


int main(){

  strcpy(ligne,"4.0-12.6+25.1erjgmuerqg");
  separation_ligne(ligne,ligne_double);

}