#include <stdio.h>
#include <stdlib.h>

int main(){
    char choix_1 ;
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