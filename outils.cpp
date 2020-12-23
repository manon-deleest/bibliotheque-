#include <iostream>
#include "outils.h"
using namespace std;

string maj(string maChaine)
{
	int i;
	string ch[50];
	string sortie;
	for (i = 0; i <= (maChaine.length() - 1); i++)
	{
		if ((maChaine[i] >= 'a') && (maChaine[i] <= 'z'))
		{
			ch[i] = maChaine[i] - 'a' + 'A';

		}
		else
		{
			ch[i] = maChaine[i];

		}
		sortie = sortie + ch[i];
	} return sortie;


}

//--------------------------------------------------------------------------------------------------------------------------------------------------

void verif(string& jour, string& mois, string& annee)
{
	//VERIF en version casté = on remplace var par stoi(var) pour la passer de chaine de caractères en entier.
	while ((stoi(jour) < 1) || (stoi(jour) > 31))
	{
		cout << " Veuillez saisir un jour compris entre 1 et 31 : ";
		cin >> jour;
	}

	while ((stoi(mois) < 1) || (stoi(mois) > 12))
	{
		cout << "Veuillez saisir un mois compris entre 1 et 12 : ";
		cin >> mois;
	}

	while (stoi(annee) < 0)
	{
		cout << " Veuillez saisir une annee superieure ou egale a 0 : ";
		cin >> annee;
	}

	if (stoi(mois) == 02) // Début annee bissextile
	{
		if (stoi(annee) % 4 == 0)
		{
			if ((stoi(annee) % 4 == 0 && stoi(annee) % 400 == 0) || (stoi(annee) % 100 != 0)) //cas bissextile
			{
				while ((stoi(jour) < 1) || (stoi(jour) > 29))
				{
					cout << " Date invalide : veuillez saisir un jour compris entre 1 et 29 : ";
					cin >> jour;
				}
			}
			else
				if (stoi(annee) % 100 == 0 && stoi(annee) % 400 != 0)
				{
					while ((stoi(jour) < 1) || (stoi(jour) > 28))
					{
						cout << "Date invalide : veuillez saisir un jour compris entre 1 et 28 :";
						cin >> jour;
					}
				}
		}
		else
		{
			while ((stoi(jour) < 1) || (stoi(jour) > 28))
			{
				cout << "Date invalide : veuillez saisir un jour compris entre 1 et 28 :";
				cin >> jour;
			}
		}
	} // fin annee bissextile
	else
	{
		if ((stoi(mois) == 1) || (stoi(mois) == 3) || (stoi(mois) == 5) || (stoi(mois) == 7) || (stoi(mois) == 8) || (stoi(mois) == 10 || stoi(mois) == 12))
		{
			while ((stoi(jour) < 1) || (stoi(jour) > 31))
			{
				cout << "Date invalide : veuillez saisir un jour compris entre 1 et 31 :";
				cin >> jour;
			}
		}
		else// si mois=4 ou mois=6 ou mois=9 ou 11
		{
			while ((stoi(jour) < 1) || (stoi(jour) > 30))
			{
				cout << "Date invalide : veuillez saisir un jour compris entre 1 et 30 : ";
				cin >> jour;
			}
		}
	}
	cout << "La date que vous avez saisi est le : " << jour << " / " << mois << " / " << annee << endl;



}

//---------------------------------------------------------------------------------------------------------------------------------------------

bool test_lettre(string& chaine)
{
	int i;
	i = 0;
	bool booltest;
	booltest = true;
	int var = 0;

	while (isdigit(chaine[i]) != 0)
	{
		i++;
		var++;
	}
	if (chaine.length() != var)
	{
		booltest = false;
	}
	return booltest;

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

void controle_chiffre(string& chaine)
{
	int i;
	i = 0;
	test_lettre(chaine);
	while (test_lettre(chaine) == 0)
	{
		cout << "ERREUR, merci de resaisir uniquement des chiffres :";
		cin >> chaine;
	}
}

// isdigit renvoie 0 si c'est un caractère autre que les chiffres, renvoie != 0 si c'est un chiffre.
// isalpha renvoie 0 si c'est un caractère autre qu'alphabétiques, renvoie != 0 si c'est une lettre.


//------------------------------------------------------------------------------------------------------------------------------------------------------

void taille_chaine_1(string& chaine)
{
	while (chaine.length() != 1)
	{
		cout << "ERREUR, merci de saisir uniquement 1 caractere ! ";
		cin >> chaine;
		cout << endl;
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------

bool test_tout_lettre(string& chaine)
{
	int i;
	i = 0;
	bool booltest;
	booltest = true;
	int var = 0;

	while (isalpha(chaine[i]) != 0)
	{
		i++;
		var++;
	}
	if (chaine.length() != var)
	{
		booltest = false;
	}
	return booltest;

}

//----------------------------------------------------------------------------------------------------------------------------------------------------------

void controle_lettre(string & chaine)
{
	int i;
	i = 0;
	test_tout_lettre(chaine);
	while (test_tout_lettre(chaine) == 0)
	{
		cout << "ERREUR, merci de resaisir uniquement des lettres :";
		cin >> chaine;
	}
}