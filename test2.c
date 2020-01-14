#include <stdio.h> 
#include <string.h>

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



    //variables globales
    char data[6][3][61];
    char ligne[125];
    char grandeurs[3][125]={"Constante diélectrique", "Conductivité électrique", "Température", "Potentiel matriciel"};
    char unites[4][8]={"F/m", "S/m", "°C", "kPa"};

 //envoie demande d'une mesure 



    void separation(char* ligne[125],char* output[4][61]){
        const char* separators="+-";
        int i;
        char lignecpy[125];
        for (i=0; i<4; i++){
            strcpy(data[i],lignecpy);
            char* valtoken=strtok(lignecpy, separators);
            while (valtoken != NULL){
            sprintf(valtoken,"[out]: %s ",ordre?ordre:"No response");
            valtoken=strtok(NULL, separators);
            }
    }


    void affichage_valeurs(){
        int i;
        for (i=0; i<6; i++){
           // Serial.println(data[i]);
           printf("adress : %s; info1 : %s; info2 : %s; info3 : %s;\n",data[i][0],data[i][1],data[i][2],data[i][3]);
        }
    }

    /* la fct automatise la mesure sur les capteurs 5TE et MPS et traîte les données en dissociant les différentes valeurs physiques acquises */
    /* void daq(){
        int i;
        char val[125];
        for (i=0; i<6; i++){
            mesure(val, i+1);
            strcpy(data[i],val);
    }
    } */




int main(){

    //test affichage
    int i;
    int j;
    int val;
    char str[61];
    for (i=0;i<6;i++){
        for (j=0;j<4;j++){
            val=i+j;
            sprintf(str, "%d", val);
            strcpy(data[i][j],str);
        }
    }

    strcpy(ligne,"4-12.6+20.6");

    
    //affichage
    affichage_valeurs();   
}