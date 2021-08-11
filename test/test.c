#include "../lib/luminyEat.h"


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
        TEST( err1 == 0 );//  // voir si le fichier s'est ouvert correctement 
        TEST( err2 == 0); // voir si le fichier s'est ouvert correctement 
        err1 = 3 ;// voir si on a bien écrit la chose qu'on a voulu 

        pclient clientTest = (pclient)malloc(sizeof(client));
        clientTest = ajoutClientConstructeur("1" , "13005" , "04 10 20 30 40" , "30" ,"Francoise Perrin" );
  
        TEST(0== strcmp(clientTest->id , "1") );
        TEST( 0==strcmp(clientTest->codePostal , "13005"));
        TEST( 0==strcmp(clientTest->telephone , "04 10 20 30 40") );
        TEST( 0==strcmp(clientTest->solde , "30" ));
        TEST( 0==strcmp(clientTest->nom , "Francoise Perrin") );
        ajoutClient(clientTest , &err1 , "fichierQuiNexistePas.csv");
        TEST( err1 == 1 );// voir si le fichier s'est ouvert correctement 
        err1 = 3 ;// changer la valeur pour les  prochaines tests

        ajoutClient(clientTest , &err1 , "dataBase/testDataBase/emptyFileClient.csv");
        TEST_FILE( "dataBase/testDataBase/emptyFileClient.csv" , "dataBase/testDataBase/testEmptyFileClient.csv"  ); // voir si on a bien écrit la chose qu'on a voulu 
        TEST(err1 ==0 ) ; // voir si le fichier s'est ouvert correctement 



    }
        
        
                             // test pour des fonctions dans Restaurateur.c ( ajoutRestaurateur() , ajoutrestaurateurConstructeur() , chercherLigneIdRestaurateur() )
   {   



        int err2   , err1 ;
        char * ligne1 = chercherLigneIdRestaurateur( 2 , "dataBase/tableRestaurants.csv" , &err2);  
        TEST(strcmp(ligne1,  "2,Le Veg,13005,04 10 11 12 13,Vegetarien,2;3;4,24\n" )==0);// voir si on a bien recupérer la ligne qu'on veut       
        char * ligne2 = chercherLigneIdRestaurateur( 1 , "dataBase/tableRestaurants.csv" , &err1);        
        TEST(strcmp(ligne2,  "1,Chez Michel,13001,04 13 13 13 13,Provencal,1;4;5,50\n" )==0);// voir si on a bien recupérer la ligne qu'on veut 
        TEST( err1 == 0 ); // voir si le fichier s'est ouvert correctement
        TEST( err2 == 0); // voir si le fichier s'est ouvert correctement
        
        prestaurateur RestaurateurTest = (prestaurateur)malloc(sizeof(restaurateur));
        RestaurateurTest = ajoutRestaurateurConstructeur( "3", "Joe's International House of Pancakes" , "13010" , "04 22 33 44 55" , "Americain" , "6;7" , "44" );
  
        TEST(0== strcmp(RestaurateurTest->id , "3") );
        TEST( 0==strcmp(RestaurateurTest->nom , "Joe's International House of Pancakes"));
        TEST( 0==strcmp(RestaurateurTest->codePostal , "13010") );
        TEST( 0==strcmp(RestaurateurTest->telephone , "04 22 33 44 55" ));
        TEST( 0==strcmp(RestaurateurTest->type , "Americain" ));
        TEST( 0==strcmp(RestaurateurTest->menu , "6;7" ));
        TEST( 0==strcmp(RestaurateurTest->solde , "44" ));

        err1=3;// changer la valeur pour les  prochaines tests

        ajoutRestaurateur(RestaurateurTest , &err1 , "fichierQuiNexistePas.csv");
        TEST( err1 == 1 );  // voir si le fichier s'est ouvert correctement       
        err1=3;// changer la valeur pour les  prochaines tests
        ajoutRestaurateur(RestaurateurTest , &err1 , "dataBase/testDataBase/emptyFileRestaurateur.csv");
        TEST_FILE( "dataBase/testDataBase/emptyFileRestaurateur.csv" , "dataBase/testDataBase/testEmptyFileRestaurateur.csv"  );// voir si on a bien écrit la chose qu'on a voulu 
        TEST(err1 ==0 ) ; // voir si le fichier s'est ouvert correctement





    }
        
         // test pour des fonctions dans livreur.c ( ajoutLIvreur() , ajoutLivreurConstructeur() , chercherLigneIdLivreur() )
    {

        int err2   , err1 ;
        char * ligne1 = chercherLigneIdLivreur(1 , "dataBase/tableLivreurs.csv" , &err2);        
        TEST(strcmp(ligne1,  "1,Francois Pignon,06 00 00 00 00,13001;13002;13003,1,20\n" )==0);// voir si on a bien recupérer la ligne qu'on veut       
        char * ligne2 = chercherLigneIdLivreur(3 , "dataBase/tableLivreurs.csv" , &err1);        
        TEST(strcmp(ligne2,  "3,Mickey Mouse,06 11 22 33 44,13008;13009;13010;13011,0,0" )==0);// voir si on a bien recupérer la ligne qu'on veut       
        TEST( err1 == 0 ); // voir si le fichier s'est ouvert correctement
        TEST( err2 == 0); // voir si le fichier s'est ouvert correctement

        err1 = 3 ;// changer la valeur pour les  prochaines tests
        plivreur livreurTest = (plivreur)malloc(sizeof(livreur));
        livreurTest = ajoutLivreurConstructeur( "2", "Donald Duck" , "06 01 02 03 04" ,"13001;13004;13005;13006;13009;13010", "0" , "25" );
  
        TEST(0== strcmp(livreurTest->id , "2") );
        TEST( 0==strcmp(livreurTest->nom , "Donald Duck"));
        TEST( 0==strcmp(livreurTest->telephone , "06 01 02 03 04") );
        TEST( 0==strcmp(livreurTest->solde , "25" ));
        TEST( 0==strcmp(livreurTest->deplacements , "13001;13004;13005;13006;13009;13010") );
        TEST( 0 == strcmp(livreurTest->restaurant , "0" ) );
        ajoutLivreur(livreurTest , &err1 , "fichierQuiNexistePas.csv");
        TEST( err1 == 1 ); // voir si le fichier s'est ouvert correctement

        err1 = 3 ; // changer la valeur pour les  prochaines tests
        ajoutLivreur(livreurTest , &err1 , "dataBase/testDataBase/emptyFileLivreur.csv");
        TEST_FILE( "dataBase/testDataBase/testEmptyFileLivreur.csv" , "dataBase/testDataBase/testEmptyFileLivreur.csv"  );// voir si on a bien écrit la chose qu'on a voulu 
        TEST(err1 ==0 ) ; // voir si le fichier s'est ouvert correctement
        TEST(err1 ==0 ) ; // voir si le fichier s'est ouvert correctement



    }
         // test des fonctions pour menu
    {

        int err2   , err1 ;
        char * ligne1 = chercherLigneIdMenu(5 , "dataBase/tableItemsMenus.csv" , &err2);        
        TEST(strcmp(ligne1,  "5,salade nicoise,oeuf;thon;olive;huile,10\n" )==0);// voir si on a bien recupérer la ligne qu'on veut
        char * ligne2 = chercherLigneIdMenu(6 , "dataBase/tableItemsMenus.csv" , &err1);        
        TEST(strcmp(ligne2,  "6,pancakes aux myrtilles,farine;lait;oeuf;myrtille,8\n" )==0);// voir si on a bien recupérer la ligne qu'on veut
        TEST( err1 == 0 );// voir si le fichier s'est ouvert correctement
        TEST( err2 == 0);// voir si le fichier s'est ouvert correctement
        pmenu menuTest = (pmenu)malloc(sizeof(menu));
        menuTest = ajoutMenuConstructeur( "5", "salade nicoise" , "oeuf;thon;olive;huile" , "10" );
  
        TEST(0== strcmp(menuTest->id , "5") );
        TEST( 0==strcmp(menuTest->nom , "salade nicoise"));
        TEST( 0==strcmp(menuTest->prix , "10") );
        TEST( 0==strcmp(menuTest->ingredients , "oeuf;thon;olive;huile" ));
        err1=3;

        ajoutMenu(menuTest , &err1 , "fichierQuiNexistePas.csv");
        TEST( err1 == 1 );  // voir si le fichier s'est ouvert correctement      
        err1=3;
        ajoutMenu(menuTest , &err1 , "dataBase/testDataBase/emptyFileMenu.csv");
        TEST_FILE( "dataBase/testDataBase/testEmptyFileMenu.csv" , "dataBase/testDataBase/testEmptyFileMenu.csv"  );// voir si on a bien écrit la chose qu'on a voulu 
        TEST(err1 ==0 ) ;// voir si le fichier s'est ouvert correctement


    }
  
        
        

    return tests_executed - tests_successful;
}





