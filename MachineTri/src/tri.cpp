/*
	Auteur          :   Serge Dubois & JF. Kamp
	Date            :   février 2013

	Sujet           :   Cours C++ deuxième année IUT informatique VANNES

	Commentaires    :   Ce projet propose la modélisation simple d'une
						machine permettant de trier des produits et de
						les regrouper par palette après leur avoir
						attribué un code unique.

	Fonctionnement  :   Créer un Objet de Type CMachine en lui passant en
						paramètres respectivement :
							Le nombre de catégorie de la machine.
							Le nombre total de produit à trier.
							Le nombre de produits par palette.

						Utiliser ensuite la méthode InsertNewProduit() pour
						introduire un nouveau produit dans la machine.
						Pour chaque produit, appeler la méthode Process().
						Cette dernière définit la catégorie, le code et assure
						la mise en palette du produit.
*/

#include "tri.h"

/** LANCEUR FINAL DE L'APPLICATION **/

int main () {

	char c = '\0';
	bool Fin = false;

	// Compteur du nombre de produits
	// !! Le premier produit a le numéro zéro
	int cpt = 0;

	CMachine* M1;
	CKeyboard Clavier;	// Gestion du clavier sous Linux
	int NbCateg;
	int NbProduitTotal;
	int NbProdParPalette;
	int NbTotPal;		// Nbre total de palettes nécessaires
	string* pDest;          // Le tableau des destinations de taille NbTotPal
	div_t tmp;

	cout << "\t\tModelisation du fonctionnement d'une machine de tri\n\r"
		 << "\t\t\t\tet de palettisation\n\n\r" << endl;
	cout << "Commandes :\n\r\tLancement de la production : < g >\n\r"
		 << "\tArret de la production (pause)     : < p >\n\r"
		 << "\tFin de la production       : < f >\n\r" << endl;
		 
	NbCateg = 5;			// nbre de catégories
	NbProduitTotal = 13;		// nbre total de produits à trier
	NbProdParPalette = 5;		// nbre de produits par palette
	
	tmp = div ( NbProduitTotal, NbProdParPalette );
	if ( tmp.rem == 0 ) NbTotPal = tmp.quot;
	else NbTotPal = tmp.quot + 1;
	
	cout << "Nbre tot palettes = " << NbTotPal << endl;

	// Liste des destinations pour les palettes
	pDest = new string[NbTotPal];

	// Fonction permettant d'entrer la liste des destinations
	SetDestination ( pDest, NbTotPal );

	// Création de l'objet CMachine
	M1 = new CMachine ( NbCateg, NbProduitTotal, NbProdParPalette, pDest );

	Clavier.Initialisation();

	// Boucle de simulation de la machine de tri
	// Frapper au clavier :
	//	- la touche 'g' pour lancer le tri
	//	- la touche 'p' pour effectuer une pause
	//	- la touche 'f' pour mettre fin au tri
	do {

		if (Clavier.kbhit()) { c = Clavier.getch(); }

		switch(c) {

			case 'g' :
				cout << "\nGO" << endl;
				M1->SetMarche ( true );   	// Lancement du tri
				break;

			case 'p' :
				cout << "\nPAUSE" << endl;
				M1->SetMarche ( false );  	// Arrêt momentané (pause) du tri
				break;

			case 'f' :
				cout << "\nARRET" << endl;
				M1->SetMarche ( false );  	// Fin du tri
				Fin = true;
				break;

			default :

				// Boucle de tri qui commence par l'insertion du produit dans la machine
				if ( M1->GetMarche() ) {

					// Entrer un nouveau produit
					if ( !M1->InsertNewProduit() ) cout << "Machine en pause" <<endl;

					// Lancer le process
					if ( !M1->Process() ) cout << "Machine en pause" << endl;

					// Ejection du Produit
					if ( !M1->EjectionProduit() ) cout << "Machine en pause" << endl;

					// Marquage du produit
					if ( !M1->MarquageProduit() ) cout << "Machine en pause" << endl;

					// Stockage du produit sur la palette
					if ( M1->AjoutPalette() ) {
						cpt++;
					}
					else cout << "Machine en pause" << endl;

					// Pause système pendant 2.000.000 microsecondes
					usleep(2000000);

					cout << "\nProduction en cours... Produit numero : " << cpt << "\n\r" << endl;

					// Affichage des résultats du tri (nbre de produits par catégorie)
					for (int i=0; i<M1->GetNbCateg(); i++) {
						
						cout << "\r\tCatégorie " << (i+1) << " : " << M1->GetNbProd(i) << endl;
					}
				}

				break;
		}

		// Test fin de production
		// Si la fin n'est pas atteinte, on met le caractère "c" à une valeur différente de 'g', 'p' ou 'f'
		if ( cpt < M1->GetNbTotalProd() ) c='w';
		// Sinon on arrête
		else {
			M1->SetMarche ( false );
			Fin = true;
		}

	} while ( !Fin );

	// Afficher les résultats de production
	M1->Affiche();
	cout << "\n\rPour sortir :\n\r\tAppuyer sur une touche." << endl;
	c = Clavier.getch();

	// Libération obligatoire de l'espace mémoire utilisé par la machine
	delete M1;

	// Libération obligatoire du tableau des destinations
	delete[] pDest;

	Clavier.Arret();

}

/****************************/

// Cette fonction remplit le tableau des destinations pour chaque palette
void SetDestination ( string* pDest, int NbTotPalette ) {

	string tmp;

	for ( int i=0; i < NbTotPalette; i++ ) {

		cout << "Destination de la palette N°" << i << " - ";
		getline(cin, tmp);
		*(pDest + i) = tmp;
		cout << endl;
	}
}
