#include "restaurateur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "fonctionsCommunes.h"


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


void  ajoutRestaurateur(prestaurateur restaurateur , int * err , char * path  ){
    
    FILE * tablerestaurateur ;


    // regarder si le fichier exist avec la fonction access( ) de <unistd.h> car le parametre a ou a+ crée toujours le fichier s'il n'existe pas 
    if( access( path, F_OK ) == 0 ) { 
        *err = 0; // s'il n'y a pas une erreur d'ouverture alors err va prendre la valeur 0
        tablerestaurateur = fopen(path, "a+" );
        fprintf(tablerestaurateur, "%s,%s,%s,%s,%s,%s,%s%s", restaurateur->id,  restaurateur->nom, restaurateur->codePostal,restaurateur->telephone,  restaurateur->type, restaurateur->menu, restaurateur->solde , "\n");
        fclose(tablerestaurateur);
        return ;  

    }else {


        *err = 1; // s'il y a une erreur d'ouverture alors err va prendre la valeur 1
        printf("fichier non trouvé dans 'ajoutrestaurateur' function \n");
        return;


    }


}



char * chercherLigneIdRestaurateur(int i , char * path, int* err  ){
    int boucle, line = i+1 ;
    char chaine[100];
    char* ligne= malloc(sizeof(char)*100);
    if( access( path, F_OK ) != 0 ) {    // regarder si le fichier exist avec la fonction access( ) de <unistd.h> car le parametre a ou a+ crée toujours le fichier s'il n'existe pas 

   
    
        *err = 1 ;// s'il y a une erreur d'ouverture alors err va prendre la valeur 1
        printf("erreur dans l'ouverture du fichier CSV.. exit\n");
        return NULL;

    } 
    FILE *fichierCsv = fopen(path, "r");
    *err = 0 ;// s'il n'y a pas une erreur d'ouverture alors err va prendre la valeur 0
    for(boucle = 0;boucle<line;++boucle){
        

        if(0==fgets(chaine, sizeof(chaine), fichierCsv)){
            break;
        }
    }
    fclose(fichierCsv);
    ligne= &chaine[0];
    return ligne;


}


int afficherSoldeRestaurant(int id){
    FILE *fichier;
    int solde ;
    char line[1024] ;
    fichier = fopen("dataBase/tableRestaurants.csv", "r") ;
    if(fichier != NULL){
        while (fgets(line, 1024, fichier))
        {
            // On parcours l'ensemble des id de ligne
            char* tmp_1 = strdup(line);
            // Si on trouve l'id rechercher
            // On crée le tableau avec le meme id (en int) et le type de l'utilisateur
            // 1. Pour restaurateur
            if(atoi(getfield_2(tmp_1, 1)) == id){
                solde = atoi(getfield_2(line, 7)) ;
                // Je peux return solde direct
                printf("%d\n", solde);
                return 1;
            }
        }
        return 0;
    }
    else{
        return -1 ;
    }
}