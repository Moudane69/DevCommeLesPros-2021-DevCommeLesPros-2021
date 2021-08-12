#include <stdio.h>
#include <stdlib.h>

int main(){
    char choix_1 ;
    char choix_2 ;
    printf("Bienvenue dans le menu principale de LuminyEats Application\n") ;
    do
    {
        printf("[1].Pour vous connecté\n[2].Pour créer un compte\n[q].Pour quitter\n");
        scanf("%c", &choix_1) ;
        // viderBuffer() ;
        switch (choix_1)
        {

        /***********************/
        /* Pour vous connecter */
        /***********************/
        case '1':
            do
            {
                // TODO: connexion: prend comme argument le numero de telephone et return id et type
                // printf("Pour vous connecter, entrez votre numero de telephone: ");

                // Choix entre differents type d'utilisateur
                switch(choix_2){
                case '1':
                    printf("Vous etes restaurateur\n");
                    do{
                        printf("[1].Pour supprimer \n[2].Pour item \n[3].Pour solde \n[q].Pour quitter \n[p].Pour precedent\n");
                        switch (choix_3){
                            case 49:
                                // TODO: fonction qui prend comme argument l'id et supprime la ligne de l'id
                                printf("Vous avez supprimer votre compte\n");
                                return 0;
                            case 50:
                                // TODO: fonction qui prend comme argument l'id de l'item et permet de le modifier
                                printf("Vous avez ajouter un item\n");
                                break;
                            case 51:
                                // TODO: fonction qui prend comme argument l'id du restaurateur et qui retourne son solde
                                printf("Votre solde\n");
                                break;
                            case 113:
                                return 0;
                        }
                    }while(choix_3 != 'p');
                    break;
                case '2':
        /************************/
        /* Pour créer un compte */
        /************************/
        case '2':
            break;
        }
    }while (choix_1 != 'q');
    return 0;
}