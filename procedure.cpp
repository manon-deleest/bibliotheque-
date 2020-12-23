#include <iostream>
#include "include1.h"
#include "outils.h"
using namespace std;


void afficheLivre(t_livre monLivre[], t_auteur monAuteur[], int& nbElem) // nbElem est le nombre de livres de la base
{
	int ind;
	ind = nbElem + 1;
	//cout << "	Position : ";
	cout << "	Titre : ";
	cout << monLivre[ind - 1].titre << endl;
	cout << "	Auteur :";
	cout << monAuteur[ind - 1].nom_auteur << " " << monAuteur[ind - 1].prenom_auteur << endl;
	cout << "	Genre : ";
	cout << monLivre[ind - 1].genre << endl;
	cout << "	Nombre de pages : ";
	cout << monLivre[ind - 1].nbr_pages << endl;
	cout << "	Date de publication : " << monLivre[ind - 1].date.jj << " / " << monLivre[ind - 1].date.mm << " / " << monLivre[ind - 1].date.aa << endl;
}
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void afficheLivres(int nbElem, t_livre listeLivre[], t_auteur monAuteur[],int nbaut)
{
	int i;
	for (i = 0; i <= nbElem - 1; i++)
	{
		afficheLivre(listeLivre, monAuteur, i);
	}
}
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void RechercheLivre(t_biblio & maBiblio, string titreRech, t_livre livre[], t_liste_auteur tauteur)
{
	int pos;
	bool trouve;
	string saisie_operateur;
	char operateur;
	string recherche;
	int pos_recherche;
	trouve = false;
	pos = 0;
	
	cout << endl;
	cout << "Rechercher : " << endl;
	cout << "1 - Rechercher par titre " << endl;
	cout << "2 - Rechercher par le genre du livre" << endl;
	cout << "3 - Rechercher par annee de publication " << endl;
	cout << "4 - Rechercher par auteur " << endl;
	cout << "Entrer le nombre ";
	cin >> saisie_operateur;

	controle_chiffre(saisie_operateur);
	taille_chaine_1(saisie_operateur);
	if (saisie_operateur >= "1" && saisie_operateur <= "4")
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
	}
	else
	{
		cout << "ATTENTION ! Aucune option est prevu pour cette saisie . " << endl;
		operateur = 'r';
	} 

	switch (operateur)
	{
	case '1': 
		cout << "Entrer le titre du livre : ";
		cin >> recherche;
		cout << endl;
		RechercheLivre_titre(maBiblio, recherche, tauteur);
		// la procédure fonctionne

		
		break;
	case '2':
		cout << "Entrer le genre du livre : ";
		cin >> recherche;
		cout << endl;
		RechercheLivre_genre(maBiblio, recherche, tauteur);
		break;
	case '3':
		cout << "Entrer l'annee de publication du livre : ";
		cin >> recherche;
		controle_chiffre(recherche);
		cout << endl;
		RechercheLivre_annee(maBiblio, recherche, tauteur);
		
		break;
	case '4':
		cout << "Entrer l'auteur  : ";
		cin >> recherche;
		cout << endl;
		RechercheLivre_auteur(maBiblio, recherche, tauteur);
		break;
	default:
		break;
	}
	

}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RechercheLivre_titre(t_biblio maBiblio, string titreRech, t_liste_auteur LISTEAUTEUR )
{
	int i;
	i = 0;
	int pos;
	pos = 0;
	for (pos = 0; pos <= maBiblio.nbLivre - 1; pos++)
	{
		if (maBiblio.tableauLivre[pos].titre == titreRech)
		{
			afficheLivre(maBiblio.tableauLivre, LISTEAUTEUR.liste_auteur, pos);
			i++;
		}
	}
	if (i == 0)
	{
		cout << "Aucun livre ne correspond a votre recherche" << endl;
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RechercheLivre_genre(t_biblio maBiblio, string titreRech, t_liste_auteur LISTEAUTEUR)
{
	int i;
	i = 0;
	int pos;
	pos = 0;
	for (pos = 0; pos <= maBiblio.nbLivre - 1; pos++)
	{
		if (maBiblio.tableauLivre[pos].genre == titreRech)
		{
			afficheLivre(maBiblio.tableauLivre, LISTEAUTEUR.liste_auteur, pos);
			i++;
		}
	}
	if (i == 0)
	{
		cout << "Aucun livre ne correspond a votre recherche"<<endl;
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RechercheLivre_annee(t_biblio maBiblio, string titreRech, t_liste_auteur LISTEAUTEUR)
{
	int i;
	i = 0;
	int pos;
	pos = 0;
	for (pos = 0; pos <= maBiblio.nbLivre - 1; pos++)
	{
		if (maBiblio.tableauLivre[pos].date.aa == titreRech)
		{
			afficheLivre(maBiblio.tableauLivre, LISTEAUTEUR.liste_auteur, pos);
			i++;
		}
	}
	if (i == 0)
	{
		cout << "Aucun livre ne correspond a votre recherche" << endl;
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RechercheLivre_auteur(t_biblio maBiblio, string titreRech, t_liste_auteur LISTEAUTEUR)
{
	int i;
	i = 0;
	int pos;
	pos = 0;
	for (pos = 0; pos <= maBiblio.nbLivre - 1; pos++)
	{
		if (LISTEAUTEUR.liste_auteur[pos].nom_auteur == titreRech)
		{
			afficheLivre(maBiblio.tableauLivre, LISTEAUTEUR.liste_auteur, pos);
			i++;
		}
	}
	if (i == 0)
	{
		cout << "Aucun livre ne correspond a votre recherche" << endl;
	}
}
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void AfficheAuteur(int& nombreauteur, t_auteur liste_auteur[])
{
	int ind;
	ind = nombreauteur+1;
	cout << "	Auteur n : " << liste_auteur[ind - 1].idAuteur << endl;
	cout << "	Nom de l'auteur : " << liste_auteur[ind - 1].nom_auteur << endl;
	cout << "	Prenom de l'auteur : " << liste_auteur[ind - 1].prenom_auteur << endl;
	cout << "	Genre : " << liste_auteur[ind - 1].genre << endl;
	cout << "	Nationalite : " << liste_auteur[ind - 1].nat << endl;
	cout << "	Date de naissance : " << liste_auteur[ind - 1].naissance.jj << " / " << liste_auteur[ind - 1].naissance.mm << " / " << liste_auteur[ind - 1].naissance.aa << endl;
	if (liste_auteur[ind - 1].mort.jj != "0")
	{
		cout << "	Date de deces : " << liste_auteur[ind - 1].mort.jj << " / " << liste_auteur[ind - 1].mort.mm << " / " << liste_auteur[ind - 1].mort.aa << endl;
	}
	cout << endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void AfficheAuteurs(int & nbauteur, t_auteur listeauteur[])
{
	int i;
	for (i = 0; i <= nbauteur - 1; i++)
	{
		AfficheAuteur(i, listeauteur);
		cout << endl;
	}
}


/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void Ajoutlivre(t_livre listeLivre[], int& nbElem, int MAXLIVRE, t_auteur liste_auteur[], int MAXAUTEUR, t_liste_auteur&TLISTEAUTEUR, t_date DATE)
{
	string operateur;
	string verif_saisie;
	bool boolean;
	char ope_verif;
	boolean = false;
	if (MAXLIVRE == nbElem || MAXAUTEUR == nbElem)
	{
		cout << "IMPOSSIBLE, le nombre maximum de livres ou d'auteurs est atteint" << endl;
	}
	else
	{
		cout << "	Titre : ";
		cin >> listeLivre[nbElem].titre;
		cout << "	Genre du livre : ";
		cin >> listeLivre[nbElem].genre;
		cout << "Ajout de l'auteur : ";
		cout << endl;
		AjoutAuteur(TLISTEAUTEUR, DATE, TLISTEAUTEUR.nbauteur, MAXAUTEUR);
		cout << endl;
		cout << "	Jour de publication : ";
		cin >> listeLivre[nbElem].date.jj;
		controle_chiffre(listeLivre[nbElem].date.jj);
		cout <<	"	Mois de publication : ";
		cin >> listeLivre[nbElem].date.mm;
		controle_chiffre(listeLivre[nbElem].date.mm);
		cout << "	Annee de publication : ";
		cin >> listeLivre[nbElem].date.aa;
		controle_chiffre(listeLivre[nbElem].date.aa);
		verif(listeLivre[nbElem].date.jj, listeLivre[nbElem].date.mm, listeLivre[nbElem].date.aa);

		while (listeLivre[nbElem].date.aa <= TLISTEAUTEUR.liste_auteur[nbElem].naissance.aa) //contrôle de publication post-naissance
		{
			cout << "ERREUR, le livre aurait ete publie avant la naissance de l'auteur ! ";
			cout << "Merci de resaisir la date de publication : ";
			cout << endl;
			cout << "	Jour de publication : ";
			cin >> listeLivre[nbElem].date.jj;
			controle_chiffre(listeLivre[nbElem].date.jj);
			cout << "	Mois de publication : ";
			cin >> listeLivre[nbElem].date.mm;
			controle_chiffre(listeLivre[nbElem].date.mm);
			cout << "	Annee de publication : ";
			cin >> listeLivre[nbElem].date.aa;
			controle_chiffre(listeLivre[nbElem].date.aa);
			verif(listeLivre[nbElem].date.jj, listeLivre[nbElem].date.mm, listeLivre[nbElem].date.aa);
		}
		cout << "	Nombre de pages : ";
		cin >> listeLivre[nbElem].nbr_pages;
		controle_chiffre(listeLivre[nbElem].nbr_pages);
		cout << endl;
		cout << "	Recapitulatif : " << endl;
		afficheLivre(listeLivre, liste_auteur, nbElem);

		do
		{
			// Verification de la saisie, création de verif_saisie et controle sur la saisie, switch si modif à faire 
			cout << "	Voulez-vous valider la saisie O/N ?";
			cin >> verif_saisie;
			verif_saisie = maj(verif_saisie);
			while ((verif_saisie != "O") && (verif_saisie != "N"))
			{
				cout << "ERREUR, merci de saisir o(oui) ou n(non). ";
				cin >> verif_saisie;
				verif_saisie = maj(verif_saisie);
			}
			if (verif_saisie == "O")
			{
				boolean = true;
				cout << "	Livre enregistre ! " << endl;
				nbElem = nbElem + 1; // MESSAGE DE VALIDATION, INCREMENTATION DU NOMBRE DE LIVRES
				
			}
			else // Debut de la modification de la saisie 
			{
				cout << endl;
				cout << "Modification de la saisie : " << endl;
				cout << "1 - Modifier le titre" << endl;
				cout << "2 - Modifier le genre du livre" << endl;
				cout << "3 - Modifier le nombre de pages" << endl;
				cout << "4 - Modifier la date de publication" << endl;
				cout << "Entrer le nombre ";
				cin >> ope_verif;
				

				switch (ope_verif)
				{
				case '1':
					cout << "	Modification du titre :" << endl;
					cout << "	Saisie : "<<listeLivre[nbElem].titre;
					cout << "	Nouvelle saisie : ";
					cin>> listeLivre[nbElem].titre;
					break;
				case '2':
					cout << "	Modification du genre du livre :" << endl;
					cout << "	Saisie : " << listeLivre[nbElem].genre << endl;
					cout << "	Nouvelle saisie : ";
					cin >> listeLivre[nbElem].genre;
					break;
				case '3':
					cout << "	Modification du nombre de pages :" << endl;
					cout << "	Saisie : " << listeLivre[nbElem].nbr_pages << endl;
					cout << "	Nouvelle saisie : ";
					cin >> listeLivre[nbElem].nbr_pages;
					controle_chiffre(listeLivre[nbElem].nbr_pages);
					break;
				case '4':
					cout << "	Modification de la date de publication :" << endl;
					cout << "	Saisie : " << listeLivre[nbElem].date.jj << " / " << listeLivre[nbElem].date.mm << " / " << listeLivre[nbElem].date.aa << endl;
					cout << "	Nouvelle saisie : " << endl;
					cout << "		Jour de publication : ";
					cin >> listeLivre[nbElem].date.jj;
					controle_chiffre(listeLivre[nbElem].date.jj);
					cout << "		Mois de publication : ";
					cin >> listeLivre[nbElem].date.mm;
					controle_chiffre(listeLivre[nbElem].date.mm);
					cout << "		Annee de publication : ";
					cin >> listeLivre[nbElem].date.aa;
					controle_chiffre(listeLivre[nbElem].date.aa);
					verif(listeLivre[nbElem].date.jj, listeLivre[nbElem].date.mm, listeLivre[nbElem].date.aa);
					break;
				default:
					cout << "Vous avez saisi un chiffre du menu inexistant ! ";
					break;

				}
				cout << endl;
				afficheLivre(listeLivre,liste_auteur,nbElem);// Affichage du livre, vérification par l'utilisateur
				cout << endl;
			}
		} while (boolean == false);
		
		
	}
	
}
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void AjoutAuteur(t_liste_auteur& TLISTEAUTEUR, t_date DATE, int& NBAUTEUR, int MAXAUTEUR) //AVANCEMENT : Presque terminé, manque identifiant de l'auteur, int & NBAUTEUR ne sert à rien car il est dans le type t_liste_auteur
{

	string verif_saisie; // saisie de "Voulez vous faire une modification ?"
	char ope_verif;// operateur du switch de la modif (case 2)
	ope_verif = 'a';
	string saisie_ope_verif;
	bool boolean;
	boolean = false;
	char ope_dcd; // operateur de saisie de la date de deces
	string saisie_ope_dcd;


	if (MAXAUTEUR == TLISTEAUTEUR.nbauteur)
	{
		cout << "Le nombre d'auteurs maximum est atteint, vous ne pouvez plus saisir de nouveaux auteurs.";
	}
	else
	{
		TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].idAuteur = TLISTEAUTEUR.nbauteur;
		cout << "	ID de l'auteur : " << TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].idAuteur<<endl;
		cout << "	Nom de l'auteur : ";
		cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].nom_auteur;
		cout << "	Prenom de l'auteur : ";
		cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].prenom_auteur;
		cout << "	Genre de l'auteur (Masculin/Feminin : M/F ) :  ";
		cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre;
		TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre = maj(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre);
		// CONTROLE du bon caractere genre M ou F
		while ( (TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre != "M") && (TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre != "F"))
		{
			cout << "ERREUR, merci de saisir M ou F ";
			cout << "	Genre de l'auteur (Masculin/Feminin : M/F ) :  ";
			cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre;
			TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre = maj(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre);
		}
		//Traitement qui transforme l'initiale en le mot complet
		if (TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre == "M")
		{
			TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre = "MASCULIN";
		}
		else
		{
			TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre = "FEMININ";
		}
		cout << "	Nationalite de l'auteur (ex : FR, USA...) : "; 
		cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].nat;
		controle_lettre(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].nat);
		TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].nat = maj(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].nat);
		cout << "	Date de naissance de l'auteur : "<<endl;
		
		cout << "		Jour de naissance : ";
		cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.jj;
		controle_chiffre(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.jj);
		cout << "		Mois de naissance : ";
		cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.mm;
		controle_chiffre(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.mm);
		cout << "		Annee de naissance : ";
		cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.aa;
		controle_chiffre(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.aa);
		verif(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.jj, TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.mm, TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.aa); //VERIF MARCHE ! :) 
		cout << "	Est ce que l'auteur est decede Oui(o) / Non(n) ? ";

		cin >> saisie_ope_dcd;

		//TEST CONTROLE LETTRE CF LIGNE 430
		taille_chaine_1(saisie_ope_dcd);
		saisie_ope_dcd =  maj(saisie_ope_dcd);
		if (saisie_ope_dcd == "O" || saisie_ope_dcd <= "N")
		{
			if (saisie_ope_dcd == "O")
			{
				ope_dcd = 'O';
			}
			if (saisie_ope_dcd == "N")
			{
				ope_dcd = 'N';
			}

		}
		else
		{
			cout << "ATTENTION ! Aucune option est prevu pour cette saisie . " << endl;
			ope_dcd = 'r';
		}

		switch (ope_dcd)
		{
		case 'O': 
			cout << "		Jour de deces : ";
			cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.jj;
			controle_chiffre(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.jj);
			cout << "		Mois de deces : ";
			cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.mm;
			controle_chiffre(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.mm);
			cout << "		Annee de deces : ";
			cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.aa;
			controle_chiffre(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.aa);
			verif(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.jj, TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.mm, TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.aa);
			verif_deces(TLISTEAUTEUR, TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.aa, TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.aa);
			break;
		case 'N':
			TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.jj = "INCONNU";
			TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.mm = "INCONNU";
			TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.aa = "INCONNU";
			break;
		default:
			break;
		}
																																																			
																																																			
				
		
		cout << endl;
		cout << "	Resume de la saisie : " << endl;
		AfficheAuteur(TLISTEAUTEUR.nbauteur, TLISTEAUTEUR.liste_auteur);
		do
		{
			// Verification de la saisie, création de verif_saisie et controle sur la saisie, switch si modif à faire 
			cout << "	Voulez-vous valider la saisie O/N ?";
			cin >> verif_saisie;
			verif_saisie = maj(verif_saisie);
			while ((verif_saisie != "O") && (verif_saisie != "N"))
			{
				cout << "ERREUR, merci de saisir, o(oui) ou n(non). ";
				cin >> verif_saisie;
				verif_saisie = maj(verif_saisie);
			}
			if (verif_saisie == "O")
			{
				boolean = true;
				cout << "	Auteur enregistre ! " << endl;
				TLISTEAUTEUR.nbauteur++; //MESSAGE DE VALIDATION, INCREMENTATION, FIN DE LA PROCEDURE 
			}
			else // Debut de la modification de la saisie 
			{
				cout << endl;
				cout << "Modification de la saisie : " << endl;
				cout << "1 - Modifier le nom " << endl;
				cout << "2 - Modifier le prenom " << endl;
				cout << "3 - Modifier le genre" << endl;
				cout << "4 - Modifier la nationalite " << endl;
				cout << "5 - Modifier la date de naissance" << endl;
				cout << "6 - Modifier la date de deces" << endl;
				cout << "Entrer le nombre ";
				cin >> saisie_ope_verif;

				controle_chiffre(saisie_ope_verif);
				taille_chaine_1(saisie_ope_verif);
				
				if (saisie_ope_verif >= "1" && saisie_ope_verif <= "6")
				{
					if (saisie_ope_verif == "1")
					{
						ope_verif = '1';
					}
					if (saisie_ope_verif == "2")
					{
						ope_verif = '2';
					}
					if (saisie_ope_verif == "3")
					{
						ope_verif = '3';
					}
					if (saisie_ope_verif == "4")
					{
						ope_verif = '4';
					}
					if (saisie_ope_verif == "5")
					{
						ope_verif = '5';
					}
					if (saisie_ope_verif == "6")
					{
						ope_verif = '6';
					}
					
				}
				else
				{
					cout << "ATTENTION ! Aucune option est prevu pour cette saisie . " << endl;
					ope_verif = 'r';
				}

				switch (ope_verif)
				{
				case '1':
					cout << "	Modification du nom : "<<endl;
					cout <<	"	Saisie : " << TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].nom_auteur << endl;
					cout << "	Nouvelle saisie : ";
					cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].nom_auteur;
					break;
				case '2':
					cout <<	"	Modification du prenom : " << endl;
					cout << "	Saisie : " << TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].prenom_auteur << endl;
					cout << "	Nouvelle saisie : ";
					cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].prenom_auteur;
					break;
				case '3':
					cout << "	Modification du genre : " << endl;
					cout << "	Saisie : " << TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre << endl;
					cout << "	Nouvelle saisie : ";
					cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre;
					TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre = maj(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre);
					// CONTROLE du bon caractere genre M ou F
					while ((TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre != "M") && (TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre != "F"))
					{
						cout << "ERREUR, merci de saisir M ou F ";
						cout << "	Genre de l'auteur (Masculin/Feminin : M/F ) :  ";
						cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre;
						TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre = maj(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre);
					}
					//Traitement qui transforme l'initiale en le mot complet
					if (TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre == "M")
					{
						TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre = "MASCULIN";
					}
					else
					{
						TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].genre = "FEMININ";
					}
					break;
				case '4':
					cout << "	Modification de la nationalite : " << endl;
					cout << "	Saisie : " << TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].nat << endl;
					cout << "	Nouvelle saisie : ";
					cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].nat;
					//TEST A FAIRE 
					TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].nat = maj(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].nat);
					break;
				case '5':
					cout << "	Modification de la date de naissance : " << endl;
					cout << "	Saisie : " << TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.jj << " / " << TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.mm << " / " << TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.aa << endl;
					cout << "	Nouvelle saisie : "<<endl;
					cout << "		Jour de naissance : ";
					cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.jj;
					controle_chiffre(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.jj);
					cout << "		Mois de naissance : ";
					cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.mm;
					controle_chiffre(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.mm);
					cout << "		Annee de naissance : ";
					cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.aa;
					controle_chiffre(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.aa);
					verif(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.jj, TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.mm, TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.aa);
					break;
				case '6':
					cout << "	Modification de la date de deces :" << endl;
					cout << "	Saisie : " << TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.jj << " / " << TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur ].mort.mm << " / " << TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.aa << endl;
					cout << "	Nouvelle saisie : "<<endl;
					cout << "		Jour de deces : ";
					cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.jj;
					controle_chiffre(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.jj);
					cout << "		Mois de deces : ";
					cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.mm;
					controle_chiffre(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.mm);
					cout << "		Annee de deces : ";
					cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.aa;
					controle_chiffre(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.aa);
					verif(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.jj, TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.mm, TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.aa);
					verif_deces(TLISTEAUTEUR, TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].naissance.aa, TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.aa);
					break;
				default:
					cout << "Vous avez saisi un chifrre du menu inexistant ! ";
					break;

				}
				cout << endl;
				AfficheAuteur(TLISTEAUTEUR.nbauteur, TLISTEAUTEUR.liste_auteur); // Affichage de l'auteur , vérification par l'utilisateur
				cout << endl;
			}
		} while (boolean == false);

		
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
void trie(t_livre tab[], int taille, t_auteur tab_aut[]) // taille = taille du tableau actuelle
{
	int p;
	bool change;
	t_livre tempo;
	int i = 0; //compteur
	char choix;
	string saisie_choix;

	cout << endl;
	cout << "Trier : " << endl;
	cout << "1 - Trier par le nom de l'auteur " << endl;
	cout << "2 - Trier par la date de publication" << endl;
	cout << "3 - Trier par le titre" << endl;
	cout << "Entrer le nombre ";
	cin >> saisie_choix;

	controle_chiffre(saisie_choix); //Fonction de traitement et de controle
	taille_chaine_1(saisie_choix); //Fonction de traitement et de controle

	if (saisie_choix >= "1" && saisie_choix <= "3")
	{
		if (saisie_choix == "1")
		{
			choix = '1';
		}
		if (saisie_choix == "2")
		{
			choix = '2';
		}
		if (saisie_choix == "3")
		{
			choix = '3';
		}
	}
	else
	{
		cout << "ATTENTION ! Aucune option est prevu pour cette saisie . " << endl;
		choix = 'r';
	}


	switch (choix)
	{
	case '1': // Trie par nom
		p = taille - 1;
		change = true;
		while (change == true && p > 0)
		{
			change = false;
			for (i = 0; i <= p - 1; i++)
			{
				if (tab_aut[i].nom_auteur < tab_aut[i+1].nom_auteur)
				{
					tempo = tab[i];
					tab[i] = tab[i + 1];
					tab[i + 1] = tempo;
				}
			}
		}
		break;
	case '2': // Trie par date de publication
		p = taille - 1;
		change = true;
		while (change == true && p > 0)
		{
			change = false;
			for (i = 0; i <= p - 1; i++)
			{
				if (tab[i].date.aa > tab[i + 1].date.aa) //MODIF ICI car je pense que c'est > au lieu de < (modif 19/12/19)
				{
					tempo = tab[i];
					tab[i] = tab[i + 1];
					tab[i + 1] = tempo;
				}
			}
		}
		break;
	case '3': // Trie par titre
		p = taille - 1;
		change = true;
		while (change == true && p > 0)
		{
			change = false;
			for (i = 0; i <= p - 1; i++)
			{
				if (tab[i].titre < tab[i + 1].titre)
				{
					tempo = tab[i];
					tab[i] = tab[i + 1];
					tab[i + 1] = tempo;
				}
			}
		}
		break;
	default:
		cout << "Vous avez saisi un chiffre du menu inexistant ! ";
		break;
	}
	cout << "Livres trie !"<<endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void verif_deces(t_liste_auteur & TLISTEAUTEUR, string annee1, string & annee2) 
{
	while (stoi(annee1) >= stoi(annee2))
	{
		cout << endl;
		cout << "ERREUR, l'auteur serait mort avant d'etre ne ,IMPOSSIBLE ! "<<endl;
		cout << "		Jour de deces : ";
		cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.jj;
		cout << "		Mois de deces : ";
		cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.mm;
		cout << "		Annee de deces : ";
		cin >> TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.aa;
		annee2 = TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.aa;
		verif(TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.jj, TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.mm, TLISTEAUTEUR.liste_auteur[TLISTEAUTEUR.nbauteur].mort.aa);
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

void modif(t_biblio biblio, t_liste_auteur listeauteur, int & compteur)
{
	
	string titre_recherche;

	while (compteur > 2)
	{
		cout << "ERREUR, merci de resaisir 1 ou 2 ";
		cin >> compteur;
	}

	if (compteur == 1)
	{
		cout << "Modification d'un livre : "<<endl;
		RechercheLivre(biblio, titre_recherche, biblio.tableauLivre, listeauteur);

	}
	else 
	if (compteur == 2)
	{
		cout << "Modification d'un auteur : ";
		Recherche_Auteur(titre_recherche, listeauteur);
	}
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Recherche_Auteur_nom(t_liste_auteur & tlisteauteur, string titreRech)
{
	int i;
	i = 0;
	int pos;
	pos = 0;

	for (pos = 0; pos <= tlisteauteur.nbauteur - 1; pos++)
	{
		if (tlisteauteur.liste_auteur[pos].nom_auteur == titreRech)
		{
			AfficheAuteur(pos, tlisteauteur.liste_auteur);
			i++;
		}
	}
	if (i == 0)
	{
		cout << "Aucun auteur ne correspond a votre recherche" << endl;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Recherche_Auteur_prenom(t_liste_auteur& tlisteauteur, string titreRech)
{
	int i;
	i = 0;
	int pos;
	pos = 0;

	for (pos = 0; pos <= tlisteauteur.nbauteur - 1; pos++)
	{
		if (tlisteauteur.liste_auteur[pos].prenom_auteur == titreRech)
		{
			AfficheAuteur(pos, tlisteauteur.liste_auteur);
			i++;
		}
	}
	if (i == 0)
	{
		cout << "Aucun auteur ne correspond a votre recherche" << endl;
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------

void Recherche_Auteur_nat(t_liste_auteur& tlisteauteur, string titreRech)
{
	int i;
	i = 0;
	int pos;
	pos = 0;

	for (pos = 0; pos <= tlisteauteur.nbauteur - 1; pos++)
	{
		if (tlisteauteur.liste_auteur[pos].nat == titreRech)
		{
			AfficheAuteur(pos, tlisteauteur.liste_auteur);
			i++;
		}
		
	}
	if (i == 0)
	{
		cout << "Aucun auteur ne correspond a votre recherche" << endl;
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------

void Recherche_Auteur( string titreRech, t_liste_auteur tauteur)
{
	int pos;
	bool trouve;
	string saisie_operateur;
	char operateur;
	string recherche;
	int pos_recherche;
	trouve = false;
	pos = 0;

	cout << endl;
	cout << "Rechercher : " << endl;
	cout << "1 - Rechercher par nom " << endl;
	cout << "2 - Rechercher par prenom" << endl;
	cout << "3 - Rechercher par nationalite " << endl;
	cout << "Entrer le nombre ";
	cin >> saisie_operateur;

	controle_chiffre(saisie_operateur);
	taille_chaine_1(saisie_operateur);
	if (saisie_operateur >= "1" && saisie_operateur <= "3")
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
	}
	else
	{
		cout << "ATTENTION ! Aucune option est prevu pour cette saisie . " << endl;
		operateur = 'r';
	}

	switch (operateur)
	{
	case '1':
		cout << "	Entrer le nom de l'auteur : ";
		cin >> recherche;
		cout << endl;
		Recherche_Auteur_nom(tauteur, recherche);
		
		break;
	case '2':
		cout << "	Entrer le prenom de l'auteur : ";
		cin >> recherche;
		cout << endl;
		Recherche_Auteur_prenom(tauteur, recherche);
		break;
	case '3':
		cout << "	Entrer la nationalite de l'auteur : ";
		cin >> recherche;
		controle_lettre(recherche);
		recherche = maj(recherche);
		Recherche_Auteur_nat(tauteur, recherche);
		cout << endl;

		break;
	default:
		break;
	}


}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void supp(t_biblio& maBiblio, string titreRech, t_livre livre[], t_liste_auteur tauteur)
{
	int position;
	int i;
	cout << "ATTENTION, pour son bon fonctionnement, le tableau sera trie a la fin de la suppression";
	RechercheLivre(maBiblio, titreRech, livre, tauteur);
	cout << "	Entrer la position du livre que vous souhaitez supprimer: ";
	cin >> position;

	livre[position] = livre[maBiblio.nbLivre];
	maBiblio.nbLivre--;

	trie(maBiblio.tableauLivre, maBiblio.nbLivre, tauteur.liste_auteur);
	cout << "Livre supprime !";
	cout << endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

void supp_auteur(t_biblio& maBiblio, int &nbauteur, t_livre livre[], t_liste_auteur tauteur)
{
	int position;
	int i;
	AfficheAuteurs(nbauteur, tauteur.liste_auteur);	//affichage pour faciliter le choix de l'utilisateur
	cout << "	Entrer le numero de l'auteur que vous souhaitez supprimer: ";
	cin >> position; //choix de l'utilisateur

	tauteur.liste_auteur[position] = tauteur.liste_auteur[nbauteur];
	nbauteur--;
	cout << "Auteur supprime !";
	cout << endl;
}
