#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* getfield(char* line, int num); // Fonction permet la manipulation des fichier CSV (extraction de cellules dans un fichier CSV)
int* connexion(char* telephone); // Fonction qui return un tableau composé d'id et du type de l'utilisateur avec le numero du telephone de l'utilisateur mit en argument
char* getfield_2(char* line, int num); // Meme fonction que la premiere avec quelque modification