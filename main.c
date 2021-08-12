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
                    printf("Vous etes livreur\n");
                    do{
                        printf("[1].Pour supprimer \n[2].Pour modifier votre profile \n[3].Pour solde \n[q].Pour quitter \n[p].Pour precedent\n");
                        switch (choix_3){
                            case '1':
                                // TODO: fonction qui prend comme argument l'id et supprime la ligne de l'id
                                printf("Vous avez supprimer votre compte\n");
                                return 0;
                            case '2':
                                // TODO: fonction qui prend comme argument l'id et permet de modifier la ligne dans le fichier livreur.csv
                                printf("Vous avez modifier votre profile\n");
                                break;
                            case '3':
                                // TODO: fonction qui prend comme argument l'id du livreur et qui retourne son solde
                                printf("Votre solde\n");
                                break;
                            case 'q':
                                return 0;
                        }
                    }while(choix_3 != 'p');
                    break;
                case '3':
                    printf("Vous etes client\n");
                    do{
                        printf("[1].Pour supprimer \n[2].Pour modifier votre profile \n[3].Pour solde \n[4].Pour voir la liste des restaurants \n[5].Pour faire une commande \n[q].Pour quitter \n[p].Pour precedent\n");
                        switch (choix_3){
                            case '1':
                                // TODO: fonction qui prend comme argument l'id et supprime la ligne de l'id
                                printf("Vous avez supprimer votre compte\n");
                                return 0;
                            case '2':
                                // TODO: fonction qui prend comme argument l'id et permet de modifier la ligne dans le fichier livreur.csv
                                printf("Vous avez modifier votre profile\n");
                                break;
                            case '3':
                                // TODO: fonction qui prend comme argument l'id du livreur et qui retourne son solde
                                printf("Votre solde\n");
                                break;
                            case '4':
                                do{
                                    printf("[1].Pour voir qui peut me livrer \n[2].Pour voir les restaurants selon le type \n[3].Pour les deux \n[q].Pour quitter \n[p].Pour precedent\n");
                                    switch(choix_4){
                                        case '1':
                                            // TODO: fonction qui prend comme argument l'id de l'utilisateur et affiche les restaurants qui ont le meme code postal
                                            printf("Les restaurants dans votre secteur sont:\n");
                                            break;
                                        case '2':
                                            // TODO: fonction qui demande a l'utilisateur sont type de restaurant et affiche les restaurants avec ce type
                                            printf("Les restaurants avec votre type de restaurants\n");
                                            break;
                                        case '3':
                                            // TODO: fonction qui demande a l'utilisateur sont type de restaurant et affiche les restaurants avec ce type dans son secteur
                                            printf("Les restaurants combinés\n");
                                            break;
                                        case 'q':
                                            return 0;
                                    }
                                }while(choix_4 != 'p');
                                break;
                            case '5':
                                do{
                                    printf("[1].Pour voir la liste des items(pas compris le but)\n[2].Pour ajouter un item \n[3].Pour enlever un item \n[4].Pour passer la commande \n[q].Pour quitter \n[p].Pour precedent\n");
                                    switch(choix_4){
                                        // case '1': Pas compris a revoir
                                        case '2':
                                            // liste ListeItems; // On peut faire un structure qui enregistre le nom de l'item et son prix donc liste des structs
                                            // TODO: fonction qui retourn une liste avec les items
                                            printf("Vous avez ajouté un item\n");
                                            break;
                                        case '3':
                                            // TODO: fonction qui permet de supprimer un item de la liste des items (ajouter dans case 2)
                                            // if (list == NULL){
                                                // break; // puisque la liste est vide
                                            //}
                                            printf("Vous avez enlevé un item\n");
                                            break;
                                        case '4':
                                            // if (list == NULL){
                                                // break; // puisque la liste est vide
                                            //}
                                            // TODO: fonction qui permet de faire faire la somme des prix des elements de la liste, afficher cette somme (total), crediter le montant du profile du client et payer le restaurant et le livreur
                                            printf("Vous avez passer la commande\n");
                                            break;
                                        case 'q':
                                            return 0;
                                    }
                                }while(choix_4 != 'p');
                                break;
                            case 'q':
                                return 0;
                        }
                    }while(choix_3 != 'p');
                    break;
                case 'q':
                    return 0;
                }
            } while (choix_2 != 112);
            break;
        /************************/
        /* Pour créer un compte */
        /************************/
        case '2':
            break;
        }
    }while (choix_1 != 'q');
    return 0;
}