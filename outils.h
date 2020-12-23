#pragma once
#include <string>
#include <iostream>
#include <ctype.h>
using namespace std;

#ifndef _OUTILS_
#define _OUTILS_


/////////////////////////////////////////////////////////////////
// Procédure qui permet de mettre en majuscule la chaine de 
// caractère entrée en paramètre
// Entree : maChaine : chaine
// Sortie: /
////////////////////////////////////////////////////////////////
string maj(string maChaine);

/////////////////////////////////////////////////////////////////
// Fonction retournant un booléen. La fonction vérifie si la
// chaine entrée en paramètre comporte uniquement des lettres
// Entree : chaine : chaine
// Sortie:  chaine : chaine
////////////////////////////////////////////////////////////////
bool test_tout_lettre(string& chaine);

/////////////////////////////////////////////////////////////////
// Procédure qui permet de vérifier la saisie d'une date 
// (jour/mois/année)
// Entree : jour, mois, annee : entier
// Sortie: jour, mois, annee : entier
////////////////////////////////////////////////////////////////
void verif(string& jour, string& mois, string& annee);

/////////////////////////////////////////////////////////////////
// Fonction retournant un booléen. La fonction vérifie si la
// chaine entrée en paramètre comporte uniquement des chiffres
// Entree : chaine : chaine
// Sortie:  chaine : chaine
////////////////////////////////////////////////////////////////
bool test_lettre(string& chaine);

/////////////////////////////////////////////////////////////////
// Procédure qui permet de traiter la fonction test_lettre , 
// qui affiche une erreur si la saisie n'est pas uniquement 
// des chiffres et redemande la saisie.
// Entree : chaine : chaine
// Sortie: chaine : chaine
////////////////////////////////////////////////////////////////
void controle_chiffre(string& chaine);

/////////////////////////////////////////////////////////////////
// Procédure qui controle si la chaine saisie ne comporte 
// bien qu'un seul caractere. Dans le cas échéant,  
// une resaisie est demandée
// Entree : chaine : chaine
// Sortie: chaine : chaine
////////////////////////////////////////////////////////////////
void taille_chaine_1(string& chaine);

/////////////////////////////////////////////////////////////////
// Procédure qui permet de traiter la fonction test_tout_lettre , 
// qui affiche une erreur si la saisie n'est pas uniquement 
// des lettres et redemande la saisie.
// Entree : chaine : chaine
// Sortie: chaine : chaine
////////////////////////////////////////////////////////////////
void controle_lettre(string& chaine);



#endif
