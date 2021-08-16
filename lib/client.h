#ifndef CLIENT

#define CLIENT




typedef struct client{

    char* id;
    char * nom;
    char * codePostal; 
    char *  telephone; 
    char* solde;
   



}client , * pclient;

 // pour ajouter un client on procéde comme ca ajoutrestaurateur( ajoutrestaurateurConstructeur(id , ...) , ...)


void ajoutClient(pclient client , int * err, char * path );
pclient ajoutClientConstructeur(char * id , char * codePostal , char* telephone , char * solde ,char * nom);
char * chercherLigneIdClient(int i, char * path , int* err);
int afficherSoldeClient(int id) ;
int modifierSoldeClient(int id, int modification) ;





#endif
