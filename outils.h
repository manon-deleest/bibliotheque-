#pragma once
#include <string>
#include <iostream>
#include <ctype.h>
using namespace std;

#ifndef _OUTILS_
#define _OUTILS_


/////////////////////////////////////////////////////////////////
// Proc�dure qui permet de mettre en majuscule la chaine de 
// caract�re entr�e en param�tre
// Entree : maChaine : chaine
// Sortie: /
////////////////////////////////////////////////////////////////
string maj(string maChaine);

/////////////////////////////////////////////////////////////////
// Fonction retournant un bool�en. La fonction v�rifie si la
// chaine entr�e en param�tre comporte uniquement des lettres
// Entree : chaine : chaine
// Sortie:  chaine : chaine
////////////////////////////////////////////////////////////////
bool test_tout_lettre(string& chaine);

/////////////////////////////////////////////////////////////////
// Proc�dure qui permet de v�rifier la saisie d'une date 
// (jour/mois/ann�e)
// Entree : jour, mois, annee : entier
// Sortie: jour, mois, annee : entier
////////////////////////////////////////////////////////////////
void verif(string& jour, string& mois, string& annee);

/////////////////////////////////////////////////////////////////
// Fonction retournant un bool�en. La fonction v�rifie si la
// chaine entr�e en param�tre comporte uniquement des chiffres
// Entree : chaine : chaine
// Sortie:  chaine : chaine
////////////////////////////////////////////////////////////////
bool test_lettre(string& chaine);

/////////////////////////////////////////////////////////////////
// Proc�dure qui permet de traiter la fonction test_lettre , 
// qui affiche une erreur si la saisie n'est pas uniquement 
// des chiffres et redemande la saisie.
// Entree : chaine : chaine
// Sortie: chaine : chaine
////////////////////////////////////////////////////////////////
void controle_chiffre(string& chaine);

/////////////////////////////////////////////////////////////////
// Proc�dure qui controle si la chaine saisie ne comporte 
// bien qu'un seul caractere. Dans le cas �ch�ant,  
// une resaisie est demand�e
// Entree : chaine : chaine
// Sortie: chaine : chaine
////////////////////////////////////////////////////////////////
void taille_chaine_1(string& chaine);

/////////////////////////////////////////////////////////////////
// Proc�dure qui permet de traiter la fonction test_tout_lettre , 
// qui affiche une erreur si la saisie n'est pas uniquement 
// des lettres et redemande la saisie.
// Entree : chaine : chaine
// Sortie: chaine : chaine
////////////////////////////////////////////////////////////////
void controle_lettre(string& chaine);



#endif
