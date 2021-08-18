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
int afficherRestaurantCodePostal(int id_client) ;
int afficherRestaurantType(char* typeClient) ;
int afficherRestaurantCodePostalType(int id_client, char *typeClient) ;



#endif
