#ifndef LIVREUR

#define LIVREUR




typedef struct livreur{

    char* id;
    char * nom;
    char *  telephone;  
    char * deplacements; 
    char * restaurant ;
    char* solde;


}livreur , * plivreur;


void ajoutLivreur(plivreur livreur , int * err, char * path );

plivreur ajoutLivreurConstructeur(char * id , char * nom , char* telephone , char * deplacemnts ,char * restaurant , char * solde);

char * chercherLigneIdLivreur(int i, char * path , int* err);






#endif
