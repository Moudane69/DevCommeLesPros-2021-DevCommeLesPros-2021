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


void  ajoutLivreur(plivreur livreur , int * err , char * path  ){
    
    FILE * tablelivreur ;



    if( access( path, F_OK ) == 0 ) { // regarder si le fichier exist avec la fonction access de <unistd.h> car le parametre a ou a+ crée toujours le fichier s'il n'existe pas 
        
        *err = 0;// s'il n'y a pas une erreur d'ouverture alors err va prendre la valeur 0
        tablelivreur = fopen(path, "a+" );
        fprintf(tablelivreur, "%s,%s,%s,%s,%s,%s%s", livreur->id, livreur->nom ,livreur->telephone,  livreur->deplacements, livreur->restaurant , livreur->solde,  "\n");
        fclose(tablelivreur);
        return ;  

    }else {


        *err = 1;// s'il y a une erreur d'ouverture alors err va prendre la valeur 1
        printf("fichier non trouvé dans 'ajoutlivreur' function \n");
        return;


    }


}







