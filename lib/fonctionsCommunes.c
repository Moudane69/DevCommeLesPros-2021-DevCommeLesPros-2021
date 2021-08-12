#include "fonctionsCommunes.h"

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
    // printf("%s\n", telephone) ;
    static int id_type[2] = {0, 0} ;
    char *listeFichier[3] = {"dataBase/tableRestaurants.csv", "dataBase/tableClient.csv", "dataBase/tableLivreurs.csv"} ; // A ajouter
    for(int i = 0; i < 3 ; i++){
        // FILE* stream = fopen(listeFichier[i], "r");
        FILE* stream = fopen(listeFichier[i], "r");
        if(stream != NULL){
            char line[1024];
            while (fgets(line, 1024, stream))
            {
                char* tmp_1 = strdup(line);
                if((strcmp(listeFichier[i],"dataBase/tableRestaurants.csv") == 0) && (strcmp(getfield(tmp_1, 4), telephone) == 0)){
                    char* tmp_2 = strdup(line);
                    // printf("%s", tmp_2) ;
                    id_type[0] = atoi(getfield(tmp_2, 1)) ;
                    id_type[1] = 1 ; // Pour type restaurant
                    // printf("Welcome restaurant %s\n", getfield(tmp_2, 2)) ;
                    free(tmp_2) ;
                    return id_type ;
                }
                else if((strcmp(listeFichier[i],"dataBase/tableLivreurs.csv") == 0) && (strcmp(getfield(tmp_1, 3), telephone) == 0) ){
                    char* tmp_2 = strdup(line);
                    // printf("%s", tmp_2) ;
                    id_type[0] = atoi(getfield(tmp_2, 1)) ;
                    id_type[1] = 2 ; // Pour type restaurant
                    // printf("Welcome restaurant %s\n", getfield(tmp_2, 2)) ;
                    free(tmp_2) ;
                    return id_type ;
                }
                else if((strcmp(listeFichier[i],"dataBase/tableClient.csv") == 0) && (strcmp(getfield(tmp_1, 4), telephone) == 0)){
                    char* tmp_2 = strdup(line);
                    // printf("%s", tmp_2) ;
                    id_type[0] = atoi(getfield(tmp_2, 1)) ;
                    id_type[1] = 3 ; // Pour type restaurant
                    // printf("Welcome client %s\n", getfield(tmp_2, 2)) ;
                    free(tmp_2) ;
                    return id_type;
                }
                // NOTE strtok clobbers tmp
                free(tmp_1);
            }
        }
        else{
            printf("Erreur d'ouverture du fichier\n");
        }
    }
    return id_type ;
}
