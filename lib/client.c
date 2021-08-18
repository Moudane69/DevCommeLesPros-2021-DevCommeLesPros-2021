#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "fonctionsCommunes.h"


pclient ajoutClientConstructeur(char * id , char * codePostal , char* telephone , char * solde ,char * nom){
    
    
    pclient nouveauClient ;
    nouveauClient = malloc(sizeof(char*)*6);
    nouveauClient->id=id;
    nouveauClient->telephone=telephone;
    nouveauClient->solde=solde;
    nouveauClient->codePostal=codePostal;
    nouveauClient->nom=nom;
    
    return nouveauClient;
    

}



void  ajoutClient(pclient client , int * err , char * path  ){
    
    FILE * tableClient ;



    if( access( path, F_OK ) == 0 ) { // regarder si le fichier exist avec la fonction access de <unistd.h> car le parametre a ou a+ crée toujours le fichier s'il n'existe pas 
        *err = 0; // s'il n'y a pas une erreur d'ouverture alors err va prendre la valeur 0
        tableClient = fopen(path, "a+" );
        fprintf(tableClient, "%s%s%s%s%s%s%s%s%s%s", client->id, "," , client->nom, "," ,client->codePostal, "," , client->telephone,"," , client->solde , "\n");
        fclose(tableClient);
        return ;  

    }else {


        *err = 1; // s'il y a une erreur d'ouverture du fichier alors err va prendre la valeur 1
        printf("fichier non trouvé dans 'ajoutClient' function \n");
        return;


    }


}



char * chercherLigneIdClient(int i , char * path, int* err  ){ 
    int boucle, line = i+1 ;
    char chaine[100];
    char* ligne= malloc(sizeof(char)*100);
    if( access( path, F_OK ) != 0 ) { // regarder si le fichier exist avec la fonction access de <unistd.h> car le parametre a ou a+ crée toujours le fichier s'il n'existe pas
   
    
        *err = 1 ;// s'il y a une erreur d'ouverture du fichier alors err va prendre la valeur 1
        printf("erreur dans l'ouverture du fichier CSV.. exit\n");
        return NULL;

    } 
    FILE *fichierCsv = fopen(path, "r");
    *err = 0 ;//s'il n'y a pas une erreur d'ouverture alors err va prendre la valeur 1
    for(boucle = 0;boucle<line;++boucle){
        

        if(0==fgets(chaine, sizeof(chaine), fichierCsv)){
            break;
        }
    }
    fclose(fichierCsv);
    ligne= &chaine[0]; 
    return ligne;


}


int afficherSoldeClient(int id){
    FILE *fichier;
    int solde ;
    char line[1024] ;
    fichier = fopen("dataBase/tableClient.csv", "r") ;
    if(fichier != NULL){
        while (fgets(line, 1024, fichier))
        {
            // On parcours l'ensemble des id de ligne
            char* tmp_1 = strdup(line);
            // Si on trouve l'id rechercher
            // On crée le tableau avec le meme id (en int) et le type de l'utilisateur
            // 1. Pour restaurateur
            if(atoi(getfield_2(tmp_1, 1)) == id){
                solde = atoi(getfield_2(line, 5)) ;
                printf("%d\n", solde);
                // Je peux return solde direct
                return 1;
            }
        }
        return 0;
    }
    else{
        return -1 ;
    }
}

int modifierSoldeClient(int id, int modification){
    FILE *fichier;
    int solde ;
    char line[1024] ;
    int indicateur = 0 ;
    fichier = fopen("dataBase/tableClient.csv", "r") ;
    if(fichier != NULL){
        while (fgets(line, 1024, fichier) && indicateur == 0)
        {
            // On parcours l'ensemble des id de ligne
            char* tmp_1 = strdup(line);
            // Si on trouve l'id rechercher
            // On crée le tableau avec le meme id (en int) et le type de l'utilisateur
            // 1. Pour restaurateur
            if(atoi(getfield_2(tmp_1, 1)) == id){
                solde = atoi(getfield_2(line, 5)) ;
                solde = solde + modification ;
                indicateur = 1 ;
                fclose(fichier) ;
                FILE* fichier_temp ;
                fichier_temp = fopen("dataBase/client_temp.csv", "w") ;
                fichier = fopen("dataBase/tableClient.csv", "r") ;
                char ligneCopie[1024] ;
                while(fgets(ligneCopie, 1024, fichier)){
                    // free(tmp_1) ;
                    tmp_1 = strdup(ligneCopie) ;
                    char* tmp_2 = strdup(ligneCopie) ;
                    char* tmp_3 = strdup(ligneCopie) ;
                    char* tmp_4 = strdup(ligneCopie) ;
                    char* tmp_5 = strdup(ligneCopie) ;
                    char* id_client = getfield_2(tmp_2, 1) ;
                    char* nom_client = getfield_2(tmp_3, 2) ;
                    char* code_postal_client = getfield_2(tmp_4, 3) ;
                    char* telephone_client = getfield_2(tmp_5, 4) ;
                    // char* solde_client = getfield_2(tmp_6, 5) ;
                    if(atoi(id_client) != id){
                        fputs(ligneCopie, fichier_temp) ;
                    }
                    else{
                        fprintf(fichier_temp, "%s,%s,%s,%s,%d\n", id_client, nom_client, code_postal_client, telephone_client, solde) ;
                    }
                }
                fclose(fichier) ;
                fclose(fichier_temp) ;
                remove("dataBase/tableClient.csv");
                //rename the file replica.c to original name
                rename("dataBase/client_temp.csv", "dataBase/tableClient.csv");
                return 1 ;
            }
        }
        return 0;
    }
    else{
        return -1 ;
    }
}

int afficherRestaurantCodePostal(int id_client){

    FILE *fichierClient ;
    fichierClient = fopen("dataBase/tableClient.csv", "r") ;
    if(fichierClient != NULL){
        char line[1024] ;
        while (fgets(line, 1024, fichierClient)){

            char* temp_1 = strdup(line) ;
            if(atoi(getfield_2(temp_1, 1)) == id_client){
                char* temp_2 = strdup(line);
                char* cpClient = getfield_2(temp_2, 3) ;
                fclose(fichierClient) ;
                FILE *fichierRestaurant ;
                fichierRestaurant = fopen("dataBase/tableRestaurants.csv", "r") ;
                if(fichierRestaurant != NULL){
                    char line_2[1024] ;
                    int indicateur = 0 ;
                    while(fgets(line_2, 1024, fichierRestaurant)){
                        char* temp_4 = strdup(line_2);
                        char* temp_5 = strdup(line_2);
                        char* cpRestaurant = getfield_2(temp_4, 3) ;
                        if(strcmp(cpRestaurant,cpClient) == 0){
                            printf("%s peut vous livrer\n", getfield_2(temp_5, 2)) ;
                            indicateur ++ ;
                        }
                    }
                    // Un restaurant de le meme code postal existe
                    if(indicateur > 0){
                        return 2 ;
                    }
                }
                else{
                    // Erreur d'ouverture du fichier fichierRestaurant
                    return -2 ;
                }
                // Aucun restaurant peut livrer
                printf("Aucun restaurant proche de vous \n");
                return 1 ;
            }
        }
        // L'idClient n'existe pas
        return 0 ;
    }
    else{
        // Erreur d'ouverture du fichier fichierClient
        return -1 ;
    }
}

int afficherRestaurantType(char* typeClient){
    FILE *fichierRestaurant ;
    fichierRestaurant = fopen("dataBase/tableRestaurants.csv", "r") ;
    if(fichierRestaurant != NULL){
        char line_2[1024] ;
        int indicateur = 0 ;
        while(fgets(line_2, 1024, fichierRestaurant)){
            // char* temp_3 = strdup(line_2) ;
            char* temp_4 = strdup(line_2);
            char* temp_5 = strdup(line_2);
            char* typeRestaurant = getfield_2(temp_4, 5) ;
            if(strcmp(typeRestaurant,typeClient) == 0){
                printf("%s peut vous livrer\n", getfield_2(temp_5, 2)) ;
                indicateur ++ ;
            }
        }
        // Un restaurant de le meme code postal existe
        if(indicateur > 0){
            return 2 ;
        }
    }
    else{
        // Erreur d'ouverture du fichier fichierRestaurant
        return -1 ;
    }
    // Aucun restaurant peut livrer
    printf("Aucun restaurant correspond a votre type de recherche \n");
    return 0 ;
}

int afficherRestaurantCodePostalType(int id_client, char *typeClient){

    FILE *fichierClient ;
    fichierClient = fopen("dataBase/tableClient.csv", "r") ;
    if(fichierClient != NULL){
        char line[1024] ;
        while (fgets(line, 1024, fichierClient)){

            char* temp_1 = strdup(line) ;
            if(atoi(getfield_2(temp_1, 1)) == id_client){
                char* temp_2 = strdup(line);
                char* cpClient = getfield_2(temp_2, 3) ;
                fclose(fichierClient) ;
                FILE *fichierRestaurant ;
                fichierRestaurant = fopen("dataBase/tableRestaurants.csv", "r") ;
                if(fichierRestaurant != NULL){
                    char line_2[1024] ;
                    int indicateur = 0 ;
                    while(fgets(line_2, 1024, fichierRestaurant)){
                        // char* temp_3 = strdup(line_2) ;
                        char* temp_4 = strdup(line_2);
                        char* temp_5 = strdup(line_2);
                        char* temp_6 = strdup(line_2);
                        char* typeRestaurant = getfield_2(temp_6, 5) ;
                        char* cpRestaurant = getfield_2(temp_4, 3) ;
                        if((strcmp(cpRestaurant,cpClient) == 0) && (strcmp(typeClient, typeRestaurant) == 0)){
                            printf("%s peut vous livrer\n", getfield_2(temp_5, 2)) ;
                            indicateur ++ ;
                        }
                    }
                    // Un restaurant de le meme code postal existe
                    if(indicateur > 0){
                        return 2 ;
                    }
                }
                else{
                    // Erreur d'ouverture du fichier fichierRestaurant
                    return -2 ;
                }
                // Aucun restaurant peut livrer
                printf("Aucun restaurant correspond a votre recherche\n");
                return 1 ;
            }
        }
        // L'idClient n'existe pas
        return 0 ;
    }
    else{
        // Erreur d'ouverture du fichier fichierClient
        return -1 ;
    }
}