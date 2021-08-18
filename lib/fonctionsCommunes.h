#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void viderBuffer() ;
const char* getfield(char* line, int num); // Fonction permet la manipulation des fichier CSV (extraction de cellules dans un fichier CSV)
int* connexion(char* telephone); // Fonction qui return un tableau composé d'id et du type de l'utilisateur avec le numero du telephone de l'utilisateur mit en argument
char* getfield_2(char* line, int num); // Meme fonction que la premiere avec quelque modification
int supprimerCompte(int id, int type); // Fonction qui permet de supprimer le compte a l'aide de l'id et le type de l'utilisateur
int ajoutHistorique(int id, int type , char* manipulation); // Fonction qui créer un fichier historique (si inexistant) et qui trace l'ensemble des manipulations faites par les utilisateurs
char *strremove(char *str, char *sub) ; // fonction intermediaire
char *remove_white_spaces(char *str) ; // fonction intermediaire
int generateId(char* path); // fonction qui génere le prochiane Id dans chaque table 
