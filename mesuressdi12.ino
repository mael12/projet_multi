#include <SDISerial.h>
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

//in order to recieve data you must choose a pin that supports interupts
#define DATALINE_PIN 2
#define INVERTED 1
#define MAX_TIMEOUT 1000
//see:   http://arduino.cc/en/Reference/attachInterrupt
//for pins that support interupts (2 or 3 typically)


SDISerial connection(DATALINE_PIN, INVERTED);
char tmp_buffer[10];
double data[6][4];
char grandeurs[4][125]={"Constante diélectrique", "Conductivité électrique", "Température", "Potentiel matriciel"}; //---inclure dans arborescence data[6][4][61] x
char unites[4][8]={"F/m", "S/m", "°C", "kPa"};

//envoie demande d'une mesure

void mesure(char* output,int adress){
  char message[4];
  memset(message,0,strlen(message));
  char ad;
  ad = adress + '0';
  message[0]=ad;
  strcat(message,"D0!\0"); 
  //Serial.print("Envoyé : ");
  //Serial.println(message);
  char* resp = connection.sdi_query(message,1000);
  sprintf(output,"%s",resp?resp:"No response");
  
  //Serial.println("----------");
  //Serial.println(resp);
  //Serial.println("----------");
}

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
  char message[128];
   for (i=0; i<6; i++){
     sprintf(message,"Device %f, values : %f %f %f\n",data[i][0],data[i][1],data[i][2],data[i][3]);
     Serial.println(message);
  }
}


void enregistrement(){
  int i;
  char ligne[125];
  for (i=0; i<6; i++){
    mesure(ligne, i+1);
    separation_ligne(ligne,data[i]);
  }
}


void setup(){
  
   Serial.begin(9600);
   connection.begin();
   delay(1000);
   Serial.println("Initialization Complete");
   Serial.flush();
  
}


void loop(){
   enregistrement();
   affichage_valeurs();
   Serial.flush();
   delay(1000);  
}
