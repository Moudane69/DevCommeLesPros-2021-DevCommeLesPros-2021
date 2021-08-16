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

int modifierSoldeRestaurant(int id, int modification){
    FILE *fichier;
    int solde ;
    char line[1024] ;
    int indicateur = 0 ;
    fichier = fopen("dataBase/tableRestaurants.csv", "r") ;
    if(fichier != NULL){
        while (fgets(line, 1024, fichier) && indicateur == 0)
        {
            // On parcours l'ensemble des id de ligne
            char* tmp_1 = strdup(line);
            // Si on trouve l'id rechercher
            // On crée le tableau avec le meme id (en int) et le type de l'utilisateur
            // 1. Pour restaurateur
            if(atoi(getfield_2(tmp_1, 1)) == id){
                solde = atoi(getfield_2(line, 7)) ;
                solde = solde + modification ;
                indicateur = 1 ;
                fclose(fichier) ;
                FILE* fichier_temp ;
                fichier_temp = fopen("dataBase/restaurant_temp.csv", "w") ;
                fichier = fopen("dataBase/tableRestaurants.csv", "r") ;
                char ligneCopie[1024] ;
                while(fgets(ligneCopie, 1024, fichier)){
                    // free(tmp_1) ;
                    tmp_1 = strdup(ligneCopie) ;
                    char* tmp_2 = strdup(ligneCopie) ;
                    char* tmp_3 = strdup(ligneCopie) ;
                    char* tmp_4 = strdup(ligneCopie) ;
                    char* tmp_5 = strdup(ligneCopie) ;
                    char* tmp_6 = strdup(ligneCopie) ;
                    char* tmp_7 = strdup(ligneCopie) ;
                    char* id_restaurant = getfield_2(tmp_2, 1) ;
                    char* nom_restaurant = getfield_2(tmp_3, 2) ;
                    char* code_postal_restaurant = getfield_2(tmp_4, 3) ;
                    char* telephone_restaurant = getfield_2(tmp_5, 4) ;
                    char* type_restaurant = getfield_2(tmp_6, 5) ;
                    char* menu_restaurant = getfield_2(tmp_7, 6) ;
                    if(atoi(id_restaurant) != id){
                        fputs(ligneCopie, fichier_temp) ;
                    }
                    else{
                        fprintf(fichier_temp, "%s,%s,%s,%s,%s,%s,%d\n", id_restaurant, nom_restaurant, code_postal_restaurant, telephone_restaurant, type_restaurant, menu_restaurant, solde) ;
                    }
                }
                fclose(fichier) ;
                fclose(fichier_temp) ;
                remove("dataBase/tableRestaurants.csv");
                //rename the file replica.c to original name
                rename("dataBase/restaurant_temp.csv", "dataBase/tableRestaurants.csv");
                return 1 ;
            }
        }
        return 0;
    }
    else{
        return -1 ;
    }
}