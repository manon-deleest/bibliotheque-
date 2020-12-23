

#pragma once
#include <string>
#include <ctype.h>
#include <iostream>
using namespace std;

#ifndef _INCLUDE_
#define _INCLUDE_

const int MAXLIVRE = 100;
const int MAXAUTEUR = 100;

// déclaration type t_date
typedef struct
{
	string jj;
	string mm;
	string aa;
}t_date;

// déclaration type t_auteur
typedef struct
{
	int	idAuteur;
	string prenom_auteur;
	string nom_auteur;
	string genre;
	string nat;
	t_date naissance;
	t_date mort;
}t_auteur;

// déclaration type t_livre
typedef struct
{
	string titre;
	int auteur;
	string nbr_pages;
	t_date date;
	string genre;
	
}t_livre;


// Déclaration type t_biblio, contient le tableau de livre[MAXLIVRE]
// et le nombre de livres de la base
typedef struct
{
	int nbLivre;
	t_livre tableauLivre[MAXLIVRE];
}t_biblio; 


// t_liste_auteur 
typedef struct
{
	t_auteur liste_auteur[MAXAUTEUR];
	int nbauteur;
}t_liste_auteur;
/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////
// Procédure qui permet d'afficher un seul et unique livre,
// utile pour l'affichage de la bibli entière
//Entree : tableau de livre, tableau d'auteur
//Sortie: tableau de livre, tableau d'auteur, nombre d'auteurs
////////////////////////////////////////////////////////////////
void afficheLivre(t_livre monLivre[], t_auteur monAuteur[], int& nbElem);

/////////////////////////////////////////////////////////////////
// Procédure qui permet d'afficher des livres (bibliothèques de livres)
//Entree : nombre de livres, nombre d'auteurs 
//Sortie: 
////////////////////////////////////////////////////////////////
void afficheLivres(int nbElem, t_livre listeLivre[], t_auteur monAuteur[], int nbaut);

/////////////////////////////////////////////////////////////////
// Procédure qui permet d'ajouter un livre dans la bibliothèque
//Entree : MAXLIVRE, MAXAUTEUR, DATES
//Sortie: tableau de livres, tableau d'auteurs, nbElem, TYPE LISTEAUTEUR
////////////////////////////////////////////////////////////////
void Ajoutlivre(t_livre listeLivre[], int& nbElem, int MAXLIVRE, t_auteur liste_auteur[], int MAXAUTEUR, t_liste_auteur &TLISTEAUTEUR, t_date DATE);

/////////////////////////////////////////////////////////////////
// Procedure globale qui reprend les autres procedures de recherches
//Entree : la liste contenant les livres, la structure contenant les auteurs
//Sortie: affichage des livres de la bibliothèque
////////////////////////////////////////////////////////////////
void RechercheLivre(t_biblio& maBiblio, string titreRech, t_livre livre[], t_liste_auteur tauteur);

/////////////////////////////////////////////////////////////////
// Permet d'ajouter un auteur 
//Entree : la liste d'auteur avant l'ajout
//		   la date 
//		   nombre d'auteur avant l'ajout
//		   nombre maximum d'auteur que l'on peut avoir dans la liste
//Sortie: listes auteur modifié, 
//		  nombre d'auteur aprés l'ajout
////////////////////////////////////////////////////////////////
void AjoutAuteur(t_liste_auteur& TLISTEAUTEUR, t_date DATE, int& NBAUTEUR, int MAXAUTEUR);

/////////////////////////////////////////////////////////////////
// Permet de trier la liste de livre par nom d'auteur, par date de 
// publication ou par titre.
//Entree : la liste de livre
//		   la taille de la liste
//		   la liste des auteur
//Sortie: listes des livres dans l'ordre
////////////////////////////////////////////////////////////////
void trie(t_livre tab[], int taille, t_auteur tab_aut[]);

/////////////////////////////////////////////////////////////////
// Permet d'afficher un auteur 
//Entree : la liste d'auteur 
//		   nombre d'auteur 
//Sortie: affichage d'un auteur
////////////////////////////////////////////////////////////////
void AfficheAuteur(int& nombreauteur, t_auteur liste_auteur[]);

/////////////////////////////////////////////////////////////////
// Permet de vérifier si la date de deces est supérieur a la date 
//de naissance
//Entree : la liste d'auteur 
//		   l'année de naissance
//		   l'année de deces 
//Sortie: message et ressaisie si la date n'est pas bonne 
////////////////////////////////////////////////////////////////
void verif_deces(t_liste_auteur& TLISTEAUTEUR, string annee1, string& annee2);

/////////////////////////////////////////////////////////////////
// Permet d'afficher la liste des auteurs
//Entree : la liste d'auteur
//		   nombre d'auteur 
//Sortie: 
////////////////////////////////////////////////////////////////
void AfficheAuteurs(int& nbauteur, t_auteur listeauteur[]);

/////////////////////////////////////////////////////////////////
// Permet de rechercher un livre par titre et de l'afficher
//Entree : Structure t_biblio, structure t_liste_auteur,
//		   saisie de la recherche
//Sortie: affichage du/des livre(s) ou message si la 
//		  recherche n'a pas abouti
////////////////////////////////////////////////////////////////
void RechercheLivre_titre(t_biblio maBiblio, string titreRech, t_liste_auteur LISTEAUTEUR);

/////////////////////////////////////////////////////////////////
// Permet de rechercher un livre par genre et de l'afficher
//Entree : Structure t_biblio, structure t_liste_auteur,
//		   saisie de la recherche
//Sortie: affichage du/des livre(s) ou message si la 
//		  recherche n'a pas abouti
////////////////////////////////////////////////////////////////
void RechercheLivre_genre(t_biblio maBiblio, string titreRech, t_liste_auteur LISTEAUTEUR);

/////////////////////////////////////////////////////////////////
// Permet de rechercher un livre par annee de publication et de l'afficher
//Entree : Structure t_biblio, structure t_liste_auteur,
//		   saisie de la recherche
//Sortie: affichage du/des livre(s) ou message si la 
//		  recherche n'a pas abouti
////////////////////////////////////////////////////////////////
void RechercheLivre_annee(t_biblio maBiblio, string titreRech, t_liste_auteur LISTEAUTEUR);

/////////////////////////////////////////////////////////////////
// Permet de rechercher un livre par auteur et de l'afficher
//Entree : Structure t_biblio, structure t_liste_auteur,
//		   saisie de la recherche
//Sortie: affichage du/des livre(s) ou message si la 
//		  recherche n'a pas abouti
////////////////////////////////////////////////////////////////
void RechercheLivre_auteur(t_biblio maBiblio, string titreRech, t_liste_auteur LISTEAUTEUR);

/////////////////////////////////////////////////////////////////
// Permet de modifier d'un livre ou d'un auteur 
//Entree : la bibliothèque
//		   la liste auteur
//		   un compteur
//Sortie: le livre ou auteur modifié
////////////////////////////////////////////////////////////////
void modif(t_biblio biblio, t_liste_auteur listeauteur, int& compteur);

/////////////////////////////////////////////////////////////////
// Procedure qui recherche l'auteur par son nom et l'affiche
//
//Entree : saisi de la recherche, structure t_liste_auteur
//Sortie: Affichage de l'auteur ou message et ressaisie si la date n'est pas bonne 
////////////////////////////////////////////////////////////////
void Recherche_Auteur_nom(t_liste_auteur& tlisteauteur, string titreRech);

/////////////////////////////////////////////////////////////////
// Procedure qui recherche l'auteur par son prenom et l'affiche
//
//Entree : saisi de la recherche, structure t_liste_auteur
//Sortie: Affichage de l'auteur ou message et ressaisie si la date n'est pas bonne 
////////////////////////////////////////////////////////////////
void Recherche_Auteur_prenom(t_liste_auteur& tlisteauteur, string titreRech);

/////////////////////////////////////////////////////////////////
// Procedure qui recherche l'auteur par sa nationalite et l'affiche
//
//Entree : saisi de la recherche, structure t_liste_auteur
//Sortie: Affichage de l'auteur ou message et ressaisie si la date n'est pas bonne 
////////////////////////////////////////////////////////////////
void Recherche_Auteur_nat(t_liste_auteur& tlisteauteur, string titreRech);

/////////////////////////////////////////////////////////////////
// Procedure qui globale qui recherche un auteur et l'affiche
//
//Entree : saisi de la recherche, structure t_liste_auteur
//Sortie: Affichage de l'auteur ou message et ressaisie si la date n'est pas bonne 
////////////////////////////////////////////////////////////////
void Recherche_Auteur(string titreRech, t_liste_auteur tauteur);

/////////////////////////////////////////////////////////////////
// Procedure qui supprime un livre, necessite d'etre trié
// avant la fin de l execution
//
//Entree : saisie, livre à supprimer, strcuture t_liste_auteur, structure t_biblio
//Sortie:  maBiblio
////////////////////////////////////////////////////////////////
void supp(t_biblio& maBiblio, string titreRech, t_livre livre[], t_liste_auteur tauteur);

/////////////////////////////////////////////////////////////////
// Procedure qui supprime un auteur
//
//Entree : saisie, livre à supprimer, strcuture t_liste_auteur, structure t_biblio
//Sortie:  Nombre auteur
////////////////////////////////////////////////////////////////
void supp_auteur(t_biblio& maBiblio, int &nbauteur, t_livre livre[], t_liste_auteur tauteur);

#endif
