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
