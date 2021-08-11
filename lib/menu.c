#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

 
pmenu ajoutMenuConstructeur(char * id , char * nom , char* ingredients , char * prix ){
    pmenu nouveaumenu ;
    nouveaumenu = malloc(sizeof(char*)*5);
    nouveaumenu->id=id;
    nouveaumenu->ingredients=ingredients;
    nouveaumenu->prix=prix;
    nouveaumenu->nom=nom;
    return nouveaumenu;
    

}

