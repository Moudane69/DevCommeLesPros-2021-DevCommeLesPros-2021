#ifndef MENU

#define MENU




typedef struct menu{

    char* id;
    char * nom;
    char * ingredients; 
    char* prix;
   



}menu , *pmenu;

void ajoutMenu(pmenu menu , int * err, char * path );

pmenu ajoutMenuConstructeur(char * id , char * nom , char* ingredients , char * prix );
char * chercherLigneIdMenu(int i, char * path , int* err);







#endif
