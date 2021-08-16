#include "../lib/luminyEat.h"


#include "test_harness.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>













// Valeurs pour le harnais de test spécifiques à ce programme.
int const tests_total = 105;
int const test_column_width = 80;

int main()
{   

        // tests pour les fonctions ajoutClient() , ajoutClientConstructeur() , chercherLigneIdClient() 

    {    
        int err2   , err1 ;
        char * ligne1 = chercherLigneIdClient(1 , "dataBase/tableClient.csv" , &err2);        
        TEST(strcmp(ligne1,  "1,Francoise Perrin,13005,0410203040,0\n" )==0);// voir si on a bien recupérer la ligne qu'on veut 
        char * ligne2 = chercherLigneIdClient(2 , "dataBase/tableClient.csv" , &err1);        
        TEST(strcmp(ligne2,  "2,Daffy Duck,13010,0690919293,50\n" )==0);// voir si on a bien recupérer la ligne qu'on veut 
        TEST( err1 == 0 );//  // voir si le fichier s'est ouvert correctement 
        TEST( err2 == 0); // voir si le fichier s'est ouvert correctement 
        err1 = 3 ;// voir si on a bien écrit la chose qu'on a voulu 

        pclient clientTest = (pclient)malloc(sizeof(client));
        clientTest = ajoutClientConstructeur("1" , "13005" , "0410203040" , "30" ,"Francoise Perrin" );
  
        TEST(0== strcmp(clientTest->id , "1") );
        TEST( 0==strcmp(clientTest->codePostal , "13005"));
        TEST( 0==strcmp(clientTest->telephone , "0410203040") );
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
        TEST(strcmp(ligne1,  "2,Le Veg,13005,0410111213,Vegetarien,2;3;4,24\n" )==0);// voir si on a bien recupérer la ligne qu'on veut       
        char * ligne2 = chercherLigneIdRestaurateur( 1 , "dataBase/tableRestaurants.csv" , &err1);        
        TEST(strcmp(ligne2,  "1,Chez Michel,13001,0413131313,Provencal,1;4;5,50\n" )==0);// voir si on a bien recupérer la ligne qu'on veut 
        TEST( err1 == 0 ); // voir si le fichier s'est ouvert correctement
        TEST( err2 == 0); // voir si le fichier s'est ouvert correctement
        
        prestaurateur RestaurateurTest = (prestaurateur)malloc(sizeof(restaurateur));
        RestaurateurTest = ajoutRestaurateurConstructeur( "3", "Joe's International House of Pancakes" , "13010" , "0422334455" , "Americain" , "6;7" , "44" );
  
        TEST(0== strcmp(RestaurateurTest->id , "3") );
        TEST( 0==strcmp(RestaurateurTest->nom , "Joe's International House of Pancakes"));
        TEST( 0==strcmp(RestaurateurTest->codePostal , "13010") );
        TEST( 0==strcmp(RestaurateurTest->telephone , "0422334455" ));
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
        TEST(strcmp(ligne1,  "1,Francois Pignon,0600000000,13001;13002;13003,1,20\n" )==0);// voir si on a bien recupérer la ligne qu'on veut       
        char * ligne2 = chercherLigneIdLivreur(3 , "dataBase/tableLivreurs.csv" , &err1);        
        TEST(strcmp(ligne2,  "3,Mickey Mouse,0611223344,13008;13009;13010;13011,0,0" )==0);// voir si on a bien recupérer la ligne qu'on veut       
        TEST( err1 == 0 ); // voir si le fichier s'est ouvert correctement
        TEST( err2 == 0); // voir si le fichier s'est ouvert correctement

        err1 = 3 ;// changer la valeur pour les  prochaines tests
        plivreur livreurTest = (plivreur)malloc(sizeof(livreur));
        livreurTest = ajoutLivreurConstructeur( "2", "Donald Duck" , "0601020304" ,"13001;13004;13005;13006;13009;13010", "0" , "25" );
  
        TEST(0== strcmp(livreurTest->id , "2") );
        TEST( 0==strcmp(livreurTest->nom , "Donald Duck"));
        TEST( 0==strcmp(livreurTest->telephone , "0601020304") );
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

    // TEST connexion
    {
        int *id_type ;
        // connexion restaurant
        id_type = connexion("0413131313") ;
        TEST(id_type[0] == 1) ;
        TEST(id_type[1] == 1) ;
        
        id_type = connexion("0410111213") ;
        TEST(id_type[0] == 2) ;
        TEST(id_type[1] == 1) ;
        
        id_type = connexion("0422334455") ;
        TEST(id_type[0] == 3) ;
        TEST(id_type[1] == 1) ;

        // connexion livreur
        id_type = connexion("0600000000") ;
        TEST(id_type[0] == 1) ;
        TEST(id_type[1] == 2) ;
        
        id_type = connexion("0601020304") ;
        TEST(id_type[0] == 2) ;
        TEST(id_type[1] == 2) ;
        
        id_type = connexion("0611223344") ;
        TEST(id_type[0] == 3) ;
        TEST(id_type[1] == 2) ;

        // connexion client
        id_type = connexion("0410203040") ;
        TEST(id_type[0] == 1) ;
        TEST(id_type[1] == 3) ;

        id_type = connexion("0690919293") ;
        TEST(id_type[0] == 2) ;
        TEST(id_type[1] == 3) ;

        id_type = connexion("0699887766") ;
        TEST(id_type[0] == 3) ;
        TEST(id_type[1] == 3) ;
    }

    // TEST afficher solde
    {
        // afficher solde restaurant
        TEST(afficherSoldeClient(1) == 1) ;
        TEST(afficherSoldeClient(2) == 1) ;
        TEST(afficherSoldeClient(3) == 1) ;
        TEST(afficherSoldeClient(4) == 0) ; // Pour un id client qui n'existe pas
        // afficher solde livreur
        TEST(afficherSoldeLivreur(1) == 1) ;
        TEST(afficherSoldeLivreur(2) == 1) ;
        TEST(afficherSoldeLivreur(3) == 1) ;
        TEST(afficherSoldeLivreur(4) == 0) ; // Pour un id livreur qui n'existe pas
        // afficher solde client
        TEST(afficherSoldeRestaurant(1) == 1) ;
        TEST(afficherSoldeRestaurant(2) == 1) ;
        TEST(afficherSoldeRestaurant(3) == 1) ;
        TEST(afficherSoldeRestaurant(4) == 0) ; // Pour un id restaurant qui n'existe pas

    }

    // TEST modifier solde
    {
        // modifier solde restaurant
        TEST(modifierSoldeClient(1, 0) == 1) ;
        TEST(modifierSoldeClient(2, 0) == 1) ;
        TEST(modifierSoldeClient(3, 0) == 1) ;
        TEST(modifierSoldeClient(4, 0) == 0) ; // Pour un id client qui n'existe pas
        // modifier solde livreur
        TEST(modifierSoldeLivreur(1, 0) == 1) ;
        TEST(modifierSoldeLivreur(2, 0) == 1) ;
        TEST(modifierSoldeLivreur(3, 0) == 1) ;
        TEST(modifierSoldeLivreur(4, 0) == 0) ; // Pour un id livreur qui n'existe pas
        // modifier solde client
        TEST(modifierSoldeRestaurant(1, 0) == 1) ;
        TEST(modifierSoldeRestaurant(2, 0) == 1) ;
        TEST(modifierSoldeRestaurant(3, 0) == 1) ;
        TEST(modifierSoldeRestaurant(4, 0) == 0) ; // Pour un id restaurant qui n'existe pas

    }

    // TEST Supprimer compte
    {   
        // supprimer restaurant
        TEST(supprimerCompte(1,1) == 1) ;
        TEST(supprimerCompte(2,1) == 1) ;
        TEST(supprimerCompte(3,1) == 1) ;
        // supprimer livreur
        TEST(supprimerCompte(1,2) == 1) ;
        TEST(supprimerCompte(2,2) == 1) ;
        TEST(supprimerCompte(3,2) == 1) ;
        // supprimer client
        TEST(supprimerCompte(1,3) == 1) ;
        TEST(supprimerCompte(2,3) == 1) ;
        TEST(supprimerCompte(3,3) == 1) ;
        // type n'existe pas
        TEST(supprimerCompte(1,4) == 0) ;
        TEST(supprimerCompte(2,4) == 0) ;
        TEST(supprimerCompte(3,4) == 0) ;
    }
    return tests_executed - tests_successful;
}





