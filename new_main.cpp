#include <iostream>
#include "include1.h"
#include "outils.h"
using namespace std;
// stoi(date.aa) convertit le string en int


int main()
{
	int compteur_menu;
	bool boolean;
	char operateur;// MENU GLOBAL
	char operateur2; // MENU LIVRE
	char operateur3; // MENU AUTEUR
	string saisie_operateur;
	string saisie_operateur2;
	string saisie_operateur3;
	string recherche_titre;
	t_biblio bib; //contient nbLivres et tableauLivre[MAXLIVRE]
	t_date date; // Est de type jour, mois, année
	t_liste_auteur struc_lauteur;

	bib.nbLivre = 0; //Déclaration nombre de Livres
	boolean = true;
	struc_lauteur.nbauteur = 0; //Déclaration nombre d'auteurs
	date.jj = "0";
	date.mm = "0";
	date.aa = "0";
	operateur == 'a';
	operateur2 == 'a';
	operateur3 == 'a';
	compteur_menu = 0;

	cout << endl << endl << endl;
	cout << "							///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "							//				  BIENVENUE DANS NOTRE BIBLIOTHEQUE !				 //" << endl;
	cout << "							//								Manon DELEEST / Valentin ROUGIER //" << endl;

	do
	{


		cout << "							///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << "							// " << "1 - Ajouter un livre 			  // 2 - Ajouter un auteur			 //" << endl;
		cout << "							// " << "3 - Afficher le tableau des livres	  	  // 4 - Afficher la liste des auteurs  	 //" << endl;
		cout << "							// " << "5 - Menu Livre				  // 6 - Menu Auteur				 //" << endl;
		cout << "							// " << "					7 - Quitter						 // " << endl;
		cout << "							///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << "												Saisir un nombre : ";
		cin >> saisie_operateur;

		controle_chiffre(saisie_operateur);
		taille_chaine_1(saisie_operateur);
		if (saisie_operateur >= "1" && saisie_operateur <= "7")
		{
			if (saisie_operateur == "1")
			{
				operateur = '1';
			}
			if (saisie_operateur == "2")
			{
				operateur = '2';
			}
			if (saisie_operateur == "3")
			{
				operateur = '3';
			}
			if (saisie_operateur == "4")
			{
				operateur = '4';
			}
			if (saisie_operateur == "5")
			{
				operateur = '5';
			}
			if (saisie_operateur == "6")
			{
				operateur = '6';
			}
			if (saisie_operateur == "7")
			{
				operateur = '7';
			}
		}
		else
		{
			cout << "ATTENTION ! Aucune option est prevu pour cette saisie . "<<endl;
			operateur = 'r';
		}

		switch(operateur)
		{
		case '1':
			cout << "Ajout d'un livre : " << endl;
			Ajoutlivre(bib.tableauLivre, bib.nbLivre, MAXLIVRE, struc_lauteur.liste_auteur, MAXAUTEUR, struc_lauteur, date);
			cout << endl;
			break;
		case '2':
			cout << "Ajout d'un auteur : " << endl;
			AjoutAuteur(struc_lauteur, date, struc_lauteur.nbauteur, MAXAUTEUR);
			break;

		case '3':
			if (bib.nbLivre != 0)
			{
				cout << "Affichage de l'ensemble des livres de la bibliotheque : " << endl<<endl;
				afficheLivres(bib.nbLivre, bib.tableauLivre, struc_lauteur.liste_auteur, struc_lauteur.nbauteur);
			}
			else
			{
				cout << "ERREUR, la base ne contient aucun livre ! Faire la touche 1 pour ajouter un livre ! " << endl;
			}

			break;
		case '4':
			if (struc_lauteur.nbauteur != 0)
			{
				cout << "Affichage des auteurs : " << endl<<endl;
				AfficheAuteurs(struc_lauteur.nbauteur, struc_lauteur.liste_auteur);
			}
			else
			{
				cout << "ERREUR, la base ne contient aucun auteur ! Faire la touche 1 pour ajouter un livre ou ajouter simplement un auteur avec la touche 2 ! " << endl;
			}
			break;
		case '5': 
			if (bib.nbLivre > 0) //  A modifier à la fin des test : bib.nbLivre != 0
			{
				cout << "									Voici le menu Livre, choisissez une option parmi celles disponibles : " << endl<<endl;
				cout << "												///////////////////////////////"<<endl;
				cout << "												// 1 - Modifier un livre X   //" << endl;
				cout << "												// 2 - Rechercher un livre   //" << endl;
				cout << "												// 3 - Trier les livres	     //" << endl;
				cout << "												// 4 - Supprimer un livre    //" << endl;
				cout << "												///////////////////////////////"<<endl;
				cout << "												Choisir un nombre : ";
				cin >> saisie_operateur2;

				controle_chiffre(saisie_operateur2); //Fonction de traitement et de controle
				taille_chaine_1(saisie_operateur2); //Fonction de traitement et de controle

				if (saisie_operateur2 >= "1" && saisie_operateur2 <= "4")
				{
					if (saisie_operateur2 == "1")
					{
						operateur2 = '1';
					}
					if (saisie_operateur2 == "2")
					{
						operateur2 = '2';
					}
					if (saisie_operateur2 == "3")
					{
						operateur2 = '3';
					}
					if (saisie_operateur2 == "4")
					{
						operateur2 = '4';
					}
				}
				else
				{
					cout << "ATTENTION ! Aucune option est prevu pour cette saisie . " << endl;
					operateur2 = 'r';
				}
				switch (operateur2)
				{
				case '1':
						compteur_menu = 1;
						modif(bib, struc_lauteur, compteur_menu);
						// Procédure de la modif d'un livre : Recherche puis modification
						// Procedure a finir 
					break;
				case '2': // OK !
						cout << "Recherche de livres : " << endl;
						RechercheLivre(bib, recherche_titre, bib.tableauLivre, struc_lauteur);
					break;
				case '3':
						cout << "Trie des livres " << endl;
						trie(bib.tableauLivre, bib.nbLivre, struc_lauteur.liste_auteur);
						
						// A voir comment on décide de trier, peut-être avec plusieurs tris -> sous-menu
					break;
				case '4':
						cout << "Suppression de livres : " << endl;
						supp(bib, recherche_titre, bib.tableauLivre, struc_lauteur);
						// On sait faire la suppression de livres dans un tab non trié , mais trié -/0\- !
					break;
				default:
					break;
				}

			}
			else
			{
				cout << "IMPOSSIBLE d'acceder au menu Livre, la base ne contient aucun livre ! Faire la touche 1 pour ajouter un livre ! " << endl;
			}
				break;
		case '6':
			if (struc_lauteur.nbauteur > 0) // modifié que pour les tests
			{
				cout << "									Voici le menu Auteur, choisissez une option parmi celles disponibles : " << endl;
				cout << "												///////////////////////////////" << endl;
				cout << "												// 1 - Modifier un auteur X  //" << endl;
				cout << "												// 2 - Rechercher un auteur  //" << endl;
				cout << "												// 3 - Suppression d'auteur  //" << endl;
				cout << "												///////////////////////////////" << endl;
				cout << "												Choisir un nombre : ";
				cin >> saisie_operateur3;

				controle_chiffre(saisie_operateur3); //Fonction de traitement et de controle
				taille_chaine_1(saisie_operateur3); //Fonction de traitement et de controle

				if (saisie_operateur3 >= "1" && saisie_operateur3 <= "3")
				{
					if (saisie_operateur3 == "1")
					{
						operateur3 = '1';
					}
					if (saisie_operateur3 == "2")
					{
						operateur3 = '2';
					}
					if (saisie_operateur3 == "3")
					{
						operateur3 = '3';
					}
				}
				else
				{
					cout << "ATTENTION ! Aucune option est prevu pour cette saisie . " << endl;
					operateur3 = 'r';
				}

				switch (operateur3)
				{
				case '1':
					compteur_menu = 2;
					modif(bib, struc_lauteur, compteur_menu);
					// Procedure a finir 
					break;
				case '2': 
					cout << "Recherche d'un auteur : "<<endl;
					cout << endl;
					Recherche_Auteur(recherche_titre, struc_lauteur);
					
					break;
				case '3':
					cout << "Suppression d'auteur : " << endl;
					supp_auteur(bib, struc_lauteur.nbauteur, bib.tableauLivre, struc_lauteur);
				default:
					break;
				}
			}
			else
			{
				cout << "ERREUR, la base ne contient aucun auteur ! Faire la touche 1 pour ajouter un livre ou ajouter simplement un auteur avec la touche 2 ! " << endl;
			}
			break;
		case '7': 
			cout << "Merci de votre visite, bonne journee et a bientot ! ";
			boolean = false;
			system("pause");
			break;
		default:
			break;
		}
	} while (boolean == true);


}
