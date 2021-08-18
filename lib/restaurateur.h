#ifndef RESTAURATEUR

#define RESTAURATEUR




typedef struct restaurateur{

    char* id;
    char * nom;
    char * codePostal; 
    char *  telephone; 
    char* solde;
    char* menu;
    char * type ; 



}restaurateur , * prestaurateur;


 // pour ajouter un restaurateur on procéde comme ca ajoutrestaurateur( ajoutrestaurateurConstructeur(id , ...))
void ajoutRestaurateur(prestaurateur restaurateur , int * err, char * path );

prestaurateur ajoutRestaurateurConstructeur(char * id , char * nom , char* codepostal , char * telephone , char * type , char * menu , char * solde );
char * chercherLigneIdRestaurateur(int i, char * path , int* err);
int afficherSoldeRestaurant(int id) ;
int modifierSoldeRestaurant(int id, int modification) ;
int ajouterItem(int id, int item_id) ; // cette fonction permet d'ajouter un item d'id item_id pour le restaurateur connecté d'id id
int supprimerItem(int id, int item_id) ; // cette fonction permet de supprimer un item d'id item_id pour le restaurateur connecté d'id id




#endif
