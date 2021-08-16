#include "livreur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "fonctionsCommunes.h"


 
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


void  ajoutLivreur(plivreur livreur , int * err , char * path  ){
    
    FILE * tablelivreur ;



    if( access( path, F_OK ) == 0 ) { // regarder si le fichier exist avec la fonction access de <unistd.h> car le parametre a ou a+ crée toujours le fichier s'il n'existe pas 
        
        *err = 0;// s'il n'y a pas une erreur d'ouverture alors err va prendre la valeur 0
        tablelivreur = fopen(path, "a+" );
        fprintf(tablelivreur, "%s,%s,%s,%s,%s,%s%s", livreur->id, livreur->nom ,livreur->telephone,  livreur->deplacements, livreur->restaurant , livreur->solde,  "\n");
        fclose(tablelivreur);
        return ;  

    }else {


        *err = 1; // s'il y a une erreur d'ouverture alors err va prendre la valeur 1
        printf("fichier non trouvé dans 'ajoutlivreur' function \n");
        return;


    }


}

char * chercherLigneIdLivreur(int i , char * path, int* err  ){
    int boucle, line = i+1 ;
    char chaine[100];
    char* ligne= malloc(sizeof(char)*100);
    if( access( path, F_OK ) != 0 ) { // regarder si le fichier exist avec la fonction access de <unistd.h> car le parametre a ou a+ crée toujours le fichier s'il n'existe pas
   
    
        *err = 1 ;// s'il y a une erreur d'ouverture alors err va prendre la valeur 1
        printf("erreur dans l'ouverture du fichier CSV.. exit\n");
        return NULL;

    } 

    FILE *fichierCsv = fopen(path, "r");
    *err = 0 ;// s'il n'y a pas une erreur d'ouverture alors err va prendre la valeur 0
    for(boucle = 0; boucle<line;++boucle){
        

        if(0==fgets(chaine, sizeof(chaine), fichierCsv)){

            break;
        }
    }
    fclose(fichierCsv);
    ligne= &chaine[0];
    return ligne;


}

int afficherSoldeLivreur(int id){
    FILE *fichier;
    int solde ;
    char line[1024] ;
    fichier = fopen("dataBase/tableLivreurs.csv", "r") ;
    if(fichier != NULL){
        while (fgets(line, 1024, fichier))
        {
            // On parcours l'ensemble des id de ligne
            char* tmp_1 = strdup(line);
            // Si on trouve l'id rechercher
            // On crée le tableau avec le meme id (en int) et le type de l'utilisateur
            // 1. Pour restaurateur
            if(atoi(getfield_2(tmp_1, 1)) == id){
                solde = atoi(getfield_2(line, 6)) ;
                printf("%d\n", solde);
                // Je peut return le solde direct
                return 1;
            }
        }
        return 0;
    }
    else{
        return -1 ;
    }
}






