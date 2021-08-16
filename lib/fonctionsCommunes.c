#include "fonctionsCommunes.h"

void viderBuffer()
{
    int c ;
    while ((c = getchar()) != '\n' && c != EOF)
    {}
}

// Pour plus d'information
// https://stackoverflow.com/questions/60686644/issue-when-using-pointer-to-line-tokens-in-c
const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ","))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int* connexion(char* telephone)
{
    // Initialisation de la variable qui va contenir l'id et le type
    static int id_type[2] = {0, 0} ;
    // Tableau des chemins relatives pour acceder au fichier de la base de données
    char *listeFichier[3] = {"dataBase/tableRestaurants.csv", "dataBase/tableClient.csv", "dataBase/tableLivreurs.csv"} ; // A ajouter
    for(int i = 0; i < 3 ; i++){
        // Pour chaque fichier qu'on ouvre
        FILE* stream = fopen(listeFichier[i], "r");
        if(stream != NULL){
            char line[1024];
            while (fgets(line, 1024, stream))
            {
                // On parcours l'ensemble des id de ligne
                char* tmp_1 = strdup(line);
                // Si on trouve l'id rechercher
                // On crée le tableau avec le meme id (en int) et le type de l'utilisateur
                // 1. Pour restaurateur
                if((strcmp(listeFichier[i],"dataBase/tableRestaurants.csv") == 0) && (strcmp(getfield(tmp_1, 4), telephone) == 0)){
                    char* tmp_2 = strdup(line);
                    // printf("%s", tmp_2) ;
                    id_type[0] = atoi(getfield(tmp_2, 1)) ;
                    id_type[1] = 1 ; 
                    free(tmp_2) ;
                    return id_type ;
                }
                //2. Pour livreur
                else if((strcmp(listeFichier[i],"dataBase/tableLivreurs.csv") == 0) && (strcmp(getfield(tmp_1, 3), telephone) == 0) ){
                    char* tmp_2 = strdup(line);
                    // printf("%s", tmp_2) ;
                    id_type[0] = atoi(getfield(tmp_2, 1)) ;
                    id_type[1] = 2 ;
                    free(tmp_2) ;
                    return id_type ;
                }
                //3. Pour client
                else if((strcmp(listeFichier[i],"dataBase/tableClient.csv") == 0) && (strcmp(getfield(tmp_1, 4), telephone) == 0)){
                    char* tmp_2 = strdup(line);
                    // printf("%s", tmp_2) ;
                    id_type[0] = atoi(getfield(tmp_2, 1)) ;
                    id_type[1] = 3 ;
                    free(tmp_2) ;
                    return id_type;
                }
                // NOTE strtok clobbers tmp
                free(tmp_1);
            }
        }
        else{
            printf("Erreur d'ouverture du fichier\n");
            id_type[0] = -1 ;
            id_type[1] = -1 ;
        }
    }
    // On retourne l'id et le type
    // Si le fichier n'existe pas ou probleme d'ouverture On retourne {-1, -1}
    // Si le numero du telephone n'existe pas on retourn {0, 0}
    return id_type ;
}

char* getfield_2(char* line, int num)
{
    char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ","))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int supprimerCompte(int id, int type){
    // La fonction se base sur la recherche de la ligne de l'utilisateur par type
    // Elle copie le fichier sans la ligne en question dans un nouveau fichier temporaire
    // Elle supprime le fichier et renome le nouveau fichier temporaire
    FILE* fichierLecture ;
    // Switch permet de designe quel fichier utiliser al 'aide du type
    switch(type){
        case 1:
                fichierLecture = fopen("dataBase/tableRestaurants.csv", "r") ;
                if(fichierLecture != NULL){
                    char line[1024];
                    char* idfichierLecture ;
                    while (fgets(line, 1024, fichierLecture)){
                        char copieLigne[1024] ;
                        strcpy(copieLigne ,line) ;
                        // printf("%s",line) ;
                        idfichierLecture = getfield_2(line, 1) ;
                        if(atoi(idfichierLecture) != id){
                            // int tailleLigne = strlen(line) ;
                            FILE* fichierEcriture ;
                            fichierEcriture = fopen("dataBase/tablerestaurants_2.csv", "a") ;
                            fputs(copieLigne, fichierEcriture) ;
                            fclose(fichierEcriture) ;
                        }
                        // Pour laisser la ligne vide
                        // else{
                        //     FILE* fichierEcriture ;
                        //     fichierEcriture = fopen("dataBase/tablerestaurants_2.csv", "a") ;
                        //     fputs("\n", fichierEcriture) ;
                        //     fclose(fichierEcriture) ;
                        // }
                    }
                    fclose(fichierLecture) ;
                    remove("dataBase/tableRestaurants.csv");
                    //rename the file replica.c to original name
                    rename("dataBase/tablerestaurants_2.csv", "dataBase/tableRestaurants.csv");
                    return 1 ;
                }
                else{
                    return -1 ;
                }
            break;
        case 2:
                fichierLecture = fopen("dataBase/tableLivreurs.csv", "r") ;
                if(fichierLecture != NULL){
                    char line[1024];
                    char* idfichierLecture ;
                    while (fgets(line, 1024, fichierLecture)){
                        char copieLigne[1024] ;
                        strcpy(copieLigne ,line) ;
                        // printf("%s",line) ;
                        idfichierLecture = getfield_2(line, 1) ;
                        if(atoi(idfichierLecture) != id){
                            // int tailleLigne = strlen(line) ;
                            FILE* fichierEcriture ;
                            fichierEcriture = fopen("dataBase/tablelivreur_2.csv", "a") ;
                            fputs(copieLigne, fichierEcriture) ;
                            fclose(fichierEcriture) ;
                        }
                        // Pour laisser la ligne vide
                        // else{
                        //     FILE* fichierEcriture ;
                        //     fichierEcriture = fopen("dataBase/tablerestaurants_2.csv", "a") ;
                        //     fputs("\n", fichierEcriture) ;
                        //     fclose(fichierEcriture) ;
                        // }
                    }
                    fclose(fichierLecture) ;
                    remove("dataBase/tableLivreurs.csv");
                    //rename the file replica.c to original name
                    rename("dataBase/tablelivreur_2.csv", "dataBase/tableLivreurs.csv");
                    return 1 ;
                }
                else{
                    return -1 ;
                }
            break;
        case 3:
                fichierLecture = fopen("dataBase/tableClient.csv", "r") ;
                if(fichierLecture != NULL){
                    char line[1024];
                    char* idfichierLecture ;
                    while (fgets(line, 1024, fichierLecture)){
                        char copieLigne[1024] ;
                        strcpy(copieLigne ,line) ;
                        // printf("%s",line) ;
                        idfichierLecture = getfield_2(line, 1) ;
                        if(atoi(idfichierLecture) != id){
                            // int tailleLigne = strlen(line) ;
                            FILE* fichierEcriture ;
                            fichierEcriture = fopen("dataBase/tableClient_2.csv", "a") ;
                            fputs(copieLigne, fichierEcriture) ;
                            fclose(fichierEcriture) ;
                        }
                        // Pour laisser la ligne vide
                        // else{
                        //     FILE* fichierEcriture ;
                        //     fichierEcriture = fopen("dataBase/tablerestaurants_2.csv", "a") ;
                        //     fputs("\n", fichierEcriture) ;
                        //     fclose(fichierEcriture) ;
                        // }
                    }
                    fclose(fichierLecture) ;
                    remove("dataBase/tableClient.csv");
                    //rename the file replica.c to original name
                    rename("dataBase/tableClient_2.csv", "dataBase/tableClient.csv");
                    return 1 ;
                }
                else{
                    return -1 ;
                }
            break;
    }
    return 0 ;
}

int ajoutHistorique(int id, int type , char* manipulation){
    FILE *stream ;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char* choix ;
    if(type == 1){
        choix = malloc(sizeof(char)*12) ;
        strcpy(choix, "restaurateur") ;
    }
    else if(type == 2){
        choix = malloc(sizeof(char)*7) ;
        strcpy(choix, "livreur") ;
    }
    else if(type == 3){
        choix = malloc(sizeof(char)*6) ;
        strcpy(choix, "client") ;
    }
    stream = fopen("historique.txt", "a") ;
    if(stream != NULL){
        fprintf(stream, "DATE: %d-%02d-%02d %02d:%02d:%02d par le %s d'id %d: %s\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, choix, id, manipulation) ;
        fclose(stream) ;
        return 1; 
    }
    else{
        // printf("Erreur d'ouverture du fichier historique\n");
        return 0 ;
    }
}
