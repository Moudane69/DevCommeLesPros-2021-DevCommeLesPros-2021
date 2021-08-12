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
