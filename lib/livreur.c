#include "livreur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>


 
plivreur ajoutLivreurConstructeur(char * id , char * nom , char* telephone , char * deplacemnts ,char * restaurant , char * solde){ 
    plivreur nouveauLivreur ;

        nouveauLivreur = malloc(sizeof(char*)*7);
        nouveauLivreur->id=id;
        nouveauLivreur->telephone=telephone;
        nouveauLivreur->solde=solde;
        nouveauLivreur->deplacements=deplacemnts;
        nouveauLivreur->nom=nom;
        nouveauLivreur->restaurant=restaurant;
        
    return nouveauLivreur;
    

}
