#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>


pclient ajoutClientConstructeur(char * id , char * codePostal , char* telephone , char * solde ,char * nom){
    
    
    pclient nouveauClient ;
    nouveauClient = malloc(sizeof(char*)*6);
    nouveauClient->id=id;
    nouveauClient->telephone=telephone;
    nouveauClient->solde=solde;
    nouveauClient->codePostal=codePostal;
    nouveauClient->nom=nom;
    
    return nouveauClient;
    

}



void  ajoutClient(pclient client , int * err , char * path  ){
    
    FILE * tableClient ;



    if( access( path, F_OK ) == 0 ) { // regarder si le fichier exist avec la fonction access de <unistd.h> car le parametre a ou a+ crée toujours le fichier s'il n'existe pas 
        *err = 0; // s'il n'y a pas une erreur d'ouverture alors err va prendre la valeur 1
        tableClient = fopen(path, "a+" );
        fprintf(tableClient, "%s%s%s%s%s%s%s%s%s%s", client->id, "," , client->nom, "," ,client->codePostal, "," , client->telephone,"," , client->solde , "\n");
        fclose(tableClient);
        return ;  

    }else {


        *err = 1; // s'il y a une erreur d'ouverture du fichier alors err va prendre la valeur 1
        printf("fichier non trouvé dans 'ajoutClient' function \n");
        return;


    }


}



char * chercherLigneIdClient(int i , char * path, int* err  ){ 
    int boucle, line = i+1 ;
    char chaine[100];
    char* ligne= malloc(sizeof(char)*100);
    if( access( path, F_OK ) != 0 ) { // regarder si le fichier exist avec la fonction access de <unistd.h> car le parametre a ou a+ crée toujours le fichier s'il n'existe pas
   
    
        *err = 1 ;// s'il y a une erreur d'ouverture du fichier alors err va prendre la valeur 1
        printf("erreur dans l'ouverture du fichier CSV.. exit\n");
        return NULL;

    } 
    FILE *fichierCsv = fopen(path, "r");
    *err = 0 ;//s'il n'y a pas une erreur d'ouverture alors err va prendre la valeur 1
    for(boucle = 0;boucle<line;++boucle){
        

        if(0==fgets(chaine, sizeof(chaine), fichierCsv)){
            break;
        }
    }
    fclose(fichierCsv);
    ligne= &chaine[0]; 
    return ligne;


}


