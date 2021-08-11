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


void  ajoutMenu(pmenu menu , int * err , char * path  ){
    
    FILE * tablemenu ;


c
    if( access( path, F_OK ) == 0 ) {// regarder si le fichier exist avec la fonction access( ) de <unistd.h> car le parametre a ou a+ crée toujours le fichier s'il n'existe pas c
        *err = 0;//s'il n'y a pas une erreur d'ouverture alors err va prendre la valeur 0
        tablemenu = fopen(path, "a+" );
        fprintf(tablemenu, "%s,%s,%s,%s%s", menu->id, menu->nom, menu->ingredients, menu->prix, "\n");
        fclose(tablemenu);
        return ;  

    }else {


        *err = 1; // s'il y a une erreur d'ouverture alors err va prendre la valeur 1
        printf("fichier non trouvé dans 'ajoutmenu' function \n");
        return;


    }


}



char * chercherLigneIdMenu(int i , char * path, int* err  ){
    int boucle, line = i+1 ;
    char chaine[100];
    char* ligne= malloc(sizeof(char)*100);
    if( access( path, F_OK ) != 0 ) { // regarder si le fichier exist avec la fonction access( ) de <unistd.h> car le parametre a ou a+ crée toujours le fichier s'il n'existe pas c
   
    
        *err = 1 ; // s'il y a une erreur d'ouverture alors err va prendre la valeur 1
        printf("erreur dans l'ouverture du fichier CSV.. exit\n");
        return NULL;

    } 
    FILE *fichierCsv = fopen(path, "r");
    *err = 0 ;//s'il n'y a pas une erreur d'ouverture alors err va prendre la valeur 0
    for(boucle = 0;boucle<line;++boucle){
        

        if(0==fgets(chaine, sizeof(chaine), fichierCsv)){
            break;
        }
    }
    fclose(fichierCsv);
    ligne= &chaine[0];
    return ligne;


}


