#include "restaurateur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>


prestaurateur ajoutRestaurateurConstructeur(char * id , char * nom , char* codePostal , char * telephone , char * type , char * menu , char * solde){
    
    prestaurateur nouveaurestaurateur ;
    nouveaurestaurateur = malloc(sizeof(char*)*8);
    nouveaurestaurateur->id=id;
    nouveaurestaurateur->telephone=telephone;
    nouveaurestaurateur->solde=solde;
    nouveaurestaurateur->menu=menu;
    nouveaurestaurateur->type=type;
    nouveaurestaurateur->codePostal=codePostal;
    nouveaurestaurateur->nom=nom;
    return nouveaurestaurateur;
    

}
