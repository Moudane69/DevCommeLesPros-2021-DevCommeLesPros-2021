#include "lib/luminyEat.h"

int main()
{
    char choix_1;
    char choix_2;
    char choix_3;
    char choix_4;
    char choix_5;
    int id_item;
    printf("Bienvenue dans le menu pricipale de LuminyEats\n") ;
    do
    {
        printf("[1].Pour vous connecté\n[2].Pour créer un compte\n[q].Pour quitter\n");
        scanf("%c", &choix_1);
        viderBuffer();
        switch (choix_1)
        {

        /***********************/
        /* Pour vous connecter */
        /***********************/

        case '1':
            do
            {
                // type permet de faire le choix dans la switch suivante, id permet d'identifier la ligne dans le fichier CSV
                printf("Pour vous connecter, entrez votre numero de telephone: ");
                char *numeroTelephone ;
                numeroTelephone = malloc(sizeof(char)*10) ;
                scanf("%s" , numeroTelephone) ;
                int* id_type = connexion(numeroTelephone) ;
                viderBuffer();
                if(id_type[1] == 1){
                     choix_2 = '1' ;
                }
                else if(id_type[1] == 2){
                    choix_2 = '2' ;
                }
                else if(id_type[1] == 3){
                    choix_2 = '3' ;
                }
                switch (choix_2)
                {
                case '1':
                    // system("clear");
                    printf("Vous etes restaurateur\n");
                    ajoutHistorique(id_type[0], id_type[1] , "Connexion") ;
                    do{
                        printf("[1].Pour supprimer \n[2].Pour item \n[3].Pour solde \n[q].Pour quitter \n[p].Pour precedent\n");
                        scanf("%c", &choix_3);
                        viderBuffer();
                        switch (choix_3){
                            case 49:
                                supprimerCompte(id_type[0], id_type[1]) ;
                                ajoutHistorique(id_type[0], id_type[1] , "SupprimerCompte") ;
                                printf("Vous avez supprimer votre compte\n");
                                return 0;
                            case 50:
                                printf("[1].Pour ajouter un item dans votre menu\n[2].Pour supprimer un item deja existant\n");
                                scanf("%c", &choix_5) ;
                                switch (choix_5){
                                    case '1':
                                        printf("Entrez l'id du item que vous voulez ajouter: \n") ;
                                        scanf("%d", &id_item) ;
                                        ajouterItem(id_type[0], id_item) ;
                                        viderBuffer();
                                        printf("Vous avez ajouter un item\n");
                                        break;
                                    case '2':
                                        printf("Entrez l'id du item que vous voulez supprimer (Attention il faut au moins un item qui reste dans votre menu): \n") ;
                                        scanf("%d", &id_item) ;
                                        supprimerItem(id_type[0], id_item) ;
                                        viderBuffer();
                                        printf("Vous avez supprimer un item\n");
                                        break;
                                }
                                break;
                            case 51:
                                afficherSoldeRestaurant(id_type[0]) ;
                                printf("Votre solde\n");
                                break;
                            case 'q':
                                return 0;
                        }
                    }while(choix_3 != 'p');
                    break;
                case '2':
                    // system("clear");
                    printf("Vous etes livreur\n");
                    ajoutHistorique(id_type[0], id_type[1] , "Connexion") ;
                    do{
                        printf("[1].Pour supprimer \n[2].Pour modifier votre profile \n[3].Pour solde \n[q].Pour quitter \n[p].Pour precedent\n");
                        scanf("%c", &choix_3);
                        viderBuffer();
                        switch (choix_3){
                            case '1':
                                supprimerCompte(id_type[0], id_type[1]) ;
                                ajoutHistorique(id_type[0], id_type[1] , "SupprimerCompte") ;
                                printf("Vous avez supprimer votre compte\n");
                                return 0;
                            case '2':
                                // TODO: fonction qui prend comme argument l'id et permet de modifier la ligne dans le fichier livreur.csv
                                printf("Vous avez modifier votre profile\n");
                                break;
                            case '3':
                                afficherSoldeLivreur(id_type[0]) ;
                                printf("Votre solde\n");
                                break;
                            case 'q':
                                return 0;
                        }
                    }while(choix_3 != 'p');
                    break;
                case '3':
                    // system("clear");
                    printf("Vous etes client\n");
                    ajoutHistorique(id_type[0], id_type[1] , "Connexion") ;
                    do{
                        printf("[1].Pour supprimer \n[2].Pour modifier votre profile \n[3].Pour solde \n[4].Pour voir la liste des restaurants \n[5].Pour faire une commande \n[q].Pour quitter \n[p].Pour precedent\n");
                        scanf("%c", &choix_3);
                        viderBuffer();
                        switch (choix_3){
                            case '1':
                                supprimerCompte(id_type[0], id_type[1]) ;
                                ajoutHistorique(id_type[0], id_type[1] , "SupprimerCompte") ;
                                printf("Vous avez supprimer votre compte\n");
                                return 0;
                            case '2':
                                // TODO: fonction qui prend comme argument l'id et permet de modifier la ligne dans le fichier livreur.csv
                                printf("Vous avez modifier votre profile\n");
                                break;
                            case '3':
                                printf("Votre solde\n");
                                afficherSoldeClient(id_type[0]) ;
                                printf("\n") ;
                                break;
                            case '4':
                                do{
                                    printf("[1].Pour voir qui peut me livrer dans mon secteur\n[2].Pour voir les restaurants selon le type \n[3].Pour les deux \n[q].Pour quitter \n[p].Pour precedent\n");
                                    scanf("%c", &choix_4);
                                    viderBuffer();
                                    switch(choix_4){
                                        case '1':
                                            afficherRestaurantCodePostal(id_type[0]) ;
                                            break;
                                        case '2':
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
                                    scanf("%c", &choix_4);
                                    viderBuffer();
                                    switch(choix_4){
                                        // case '1': Pas compris a voir
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
        case '2':
        /************************/
        /* Pour créer un compte */
        /************************/
            do{
                // To Delete
                printf("[1].Pour restaurateur \n[2].Pour livreur \n[3].Pour client \n[q].Pour quitter \n[p].Pour precedent\n");
                scanf("%c", &choix_2);
                viderBuffer();
                // int id = 0 ;
                switch(choix_2){
                    case '1':
                        // TODO: fonction qui permet de demander les champs de la structure restaurateur et les mettre dans le fichier restaurant.csv
                        // id = genererId("./db/restaurant.csv") ;
                        // printf("Votre Id: %d\n", id) ;
                        printf("Vous avez creer un compte pour un restaurateur\n");
                        break;
                    case '2':
                        // TODO: fonction qui permet de demander les champs de la structure restaurateur et les mettre dans le fichier livreur.csv
                        printf("Vous avez creer un compte pour un livreur\n");
                        break;
                    case '3':
                        // TODO: fonction qui permet de demander les champs de la structure restaurateur et les mettre dans le fichier client.csv
                        printf("Vous avez creer un compte pour un client\n");
                        break;
                    case 'q':
                        return 0;
                }
            }while(choix_2 != 'p');
            break;
        }
    }while (choix_1 != 'q');
    return 0;
}