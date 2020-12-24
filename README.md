# Bibliothèque

## Préambule 

  Lors du module M1103 intitulé « Structure de données & Algorithmes fondamentaux » j'ai appris à manipuler les tableaux, les structures ainsi que les fichiers. J'ai eu à réaliser sur plusieurs séances de TP puis en autonomie, un projet autour d’une bibliothèque codée en C/C++ , langage appris lors du premier semestre. J'ai réalisé ce projet en binôme avec l'un de mes camarades. C’était un projet plus long et plus concret que les précédents, qui m’a appris à m’organiser et me fixer des objectifs à réaliser en un temps donné. 

***
## Explication

  Le programme débute avec un menu. Sur ce menu se trouve la partie centrale du programme : l’ajout de livre, d’auteurs, l’affichage des auteurs … mais aussi la possibilité de choisir un nouveau menu, le « Menu Livre » ou le « Menu Auteur ». L’utilisateur a aussi le choix de quitter le programme en appuyant sur la touche 7.

![alt text](https://github.com/manon-deleest/blibliotheque-/blob/master/image/screen1.png)


Ce type de programme est basé sur les menus (switch) car le menu est le moyen le plus simple d’illustrer les interactions entre l’utilisateur et le programme. En C++, les menus réagissent suivant un opérateur qui est obligatoirement de type entier ou caractère. Le problème avec ces types, c’est que sans contrôle de saisies, sur une saisie erronée, le programme peut arrêter l’exécution, donc il a fallu contourner le problème et rendre le menu infaillible. 
Ainsi, l’utilisateur doit saisir une chaine de caractères au lieu saisir un caractère, pour l’utilisateur il n’ y a aucun changement si ce n’est que cela évite beaucoup de bug. 
De plus, le menu demande un chiffre pour choisir sa destination, il a donc fallu créer la procédure « contrôle_chiffre » qui prend en entrée une chaine de caractères, et vérifie grâce à la fonction « isdigit» si la chaine saisie comporte uniquement des chiffres, le cas échéant, l’utilisateur reçoit un message d’erreur et peut ressaisir cette chaine.
La chaine devait comporter un seul caractère, une procédure contrôlant la taille de la chaine était donc nécessaire. Une fois la taille de la chaine contrôlée, la saisie de l’utilisateur devait correspondre à une option du menu. 
Enfin le caractère saisit par l’utilisateur est attribué à une variable de type caractère. Cette variable est l’opérateur demandé par le menu. 
Concrètement, ce travail de contrôle permet de fiabiliser le programme.
Quelques exemples de saisies habituellement problématiques, résolus grâce aux contrôles.

![alt text](https://github.com/manon-deleest/blibliotheque-/blob/master/image/screen2.png)

![alt text](https://github.com/manon-deleest/blibliotheque-/blob/master/image/screen3.png)

En saisissant « 1 » soit « Ajouter un livre », on accède à la création d’un livre, une multitude d’informations est demandée à l’utilisateur afin de remplir le tableau de données consacré aux livres en arrière-plan. On peut y retrouver le genre du livre, la date de publication du livre ou encore le nombre de pages …

![alt text](https://github.com/manon-deleest/blibliotheque-/blob/master/image/screen4.png)

Les contrôles sur les saisies ont été réalisés pour que la date de décès d’un auteur ne puisse pas être antérieur à sa date de naissance ainsi il ne peut pas publier de livres avant sa naissance. Néanmoins il peut publier un livre post-mortem, ceci est notre volonté pour rester réaliste car il peut y avoir une réédition des dizaines d’années plus tard (ex : Misérables, Victor Hugo).

Pour continuer, l’utilisateur à la possibilité d’ajouter simplement un auteur sans passer par l’ajout de livre :

![alt text](https://github.com/manon-deleest/blibliotheque-/blob/master/image/screen5.png)

L’utilisateur saisit tous les champs et découvre un résumé de ses saisies. Après avoir relu il se rend compte qu’il s’est trompé d’année de décès ! Pas de panique, il a été prévu une option permettant de demander à l’utilisateur s’il est d’accord avec sa saisie. Dans ce cas-là, il va saisir « n » et va découvrir le nouveau menu qui se présente à lui :

![alt text](https://github.com/manon-deleest/blibliotheque-/blob/master/image/screen6.png)

Il va pouvoir choisir parmi tous les champs disponibles saisis au préalable. Ici il pourra donc ressaisir la date de décès et pourra une nouvelle fois vérifier l’ensemble des données. Après avoir vérifié, il recevra un message de validation « Auteur enregistré ! » avant de retrouver le menu principal. Avec l’option « 3 »  et « 4 » du menu principal, l’utilisateur peut trouver tous ses livres/auteurs saisis : 

![alt text](https://github.com/manon-deleest/blibliotheque-/blob/master/image/screen7.png)

Pour terminer la présentation, il faut mentionner les 2 menus « Livre/Auteur » restants. A travers ces deux menus, on retrouve des options relatives à ceux-ci. Pour le « menu livre », la saisie « 5 » entraîne son ouverture. Celui-ci propose de nouvelles options relatives aux livres comme la modification de livre, le tri, la recherche ou encore la suppression de livre. 

![alt text](https://github.com/manon-deleest/blibliotheque-/blob/master/image/screen8.png)


Il est aussi possible de trier par nom d’auteur, par date de publication et par titre.

![alt text](https://github.com/manon-deleest/blibliotheque-/blob/master/image/screen10.png)

Pour une question pratique, il est imposé à l’utilisateur le tri après la suppression d’un livre. Dans le « menu auteur », les mêmes options existent sauf le tri des auteurs. La recherche se fait de la même façon et le programme affiche l’auteur avec sa fiche informative.

![alt text](https://github.com/manon-deleest/blibliotheque-/blob/master/image/screen11.png)


***
## Document mis à disposition

-	new_main.cpp : programme principal
-	procedure.cpp : ensemble des procédures nécessaires
-	outils.cpp : ensemble des procédures ‘universelles’, que l’on pourrait utiliser plusieurs fois
-	include1.h : ensemble des déclarations du « procedure.cpp » + déclaration des structures, constantes…
-	outils.h : ensemble des déclarations du « outils.cpp »

***







