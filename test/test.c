#include "../lib/client.h"
#include "../lib/restaurateur.h"
#include "../lib/livreur.h"
#include "../lib/menu.h"

#include "test_harness.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>













// Valeurs pour le harnais de test spécifiques à ce programme.
int const tests_total = 50;
int const test_column_width = 80;

int main()
{   

        // tests pour les fonctions ajoutClient() , ajoutClientConstructeur() , chercherLigneIdClient() 

    {    
        int err2   , err1 ;
        char * ligne1 = chercherLigneIdClient(1 , "dataBase/tableClient.csv" , &err2);        
        TEST(strcmp(ligne1,  "1,Francoise Perrin,13005,04 10 20 30 40,0\n" )==0);// voir si on a bien recupérer la ligne qu'on veut 
        char * ligne2 = chercherLigneIdClient(2 , "dataBase/tableClient.csv" , &err1);        
        TEST(strcmp(ligne2,  "2,Daffy Duck,13010,06 90 91 92 93,50\n" )==0);// voir si on a bien recupérer la ligne qu'on veut 
        TEST( err1 == 0 );// voir si le fichier s'est ouvert correctement // voir si le fichier s'est ouvert correctement // voir si le fichier s'est ouvert correctement 
        TEST( err2 == 0);// voir si le fichier s'est ouvert correctement // voir si le fichier s'est ouvert correctement 
        err1 = 3 ;// changer la valeur pour les  prochaines tests

        pclient clientTest = (pclient)malloc(sizeof(client));
        clientTest = ajoutClientConstructeur("1" , "13005" , "04 10 20 30 40" , "30" ,"Francoise Perrin" );
  
        TEST(0== strcmp(clientTest->id , "1") );
        TEST( 0==strcmp(clientTest->codePostal , "13005"));
        TEST( 0==strcmp(clientTest->telephone , "04 10 20 30 40") );
        TEST( 0==strcmp(clientTest->solde , "30" ));
        TEST( 0==strcmp(clientTest->nom , "Francoise Perrin") );
        ajoutClient(clientTest , &err1 , "fichierQuiNexistePas.csv");
        TEST( err1 == 1 );// voir si le fichier s'est ouvert correctement // voir si le fichier s'est ouvert correctement // voir si le fichier s'est ouvert correctement // voir si le fichier s'est ouvert correctement 
        err1 = 3 ;// changer la valeur pour les  prochaines tests

        ajoutClient(clientTest , &err1 , "dataBase/testDataBase/emptyFileClient.csv");
        TEST_FILE( "dataBase/testDataBase/emptyFileClient.csv" , "dataBase/testDataBase/testEmptyFileClient.csv"  ); // voir si on a bien écrit la chose qu'on a voulu 
        TEST(err1 ==0 ) ; // voir si le fichier s'est ouvert correctement 



    }

    return tests_executed - tests_successful;
}





