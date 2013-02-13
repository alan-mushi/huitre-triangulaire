/*
    Auteur          :   Serge Dubois & JF. Kamp
    Date            :   février 2013

    Sujet           :   Cours C++ deuxième année IUT informatique VANNES
*/

#ifndef CMACHINE_H
#define CMACHINE_H

#include "CPalette.h"
#include "CProduit.h"
#include "BiblioStd.h"

// Défintion de la classe Machine
class CMachine {

 	// Données privées
	private:

	bool 		m_Marche; 		// booléen de marche/arrêt
  	short 		m_NbCateg;		// nombre de catégories pour le tri des produits, 
						// la catégorie d'un produit est comprise entre 1 et m_NbCateg
  	int 		m_NbProduitTotal;	// nombre total de produits à trier
  	short 		m_NbProdParPalette;	// nombre de produits que peut contenir une palette
	int		m_NbPaletteTotal;	// nombre total de palettes nécessaires
	int		m_NbPalProduites;	// nombre de palettes actuelles complètement remplies
  	int		m_NumProdEnCour;	// numéro du produit en cours de traitement (le premier prend le numéro zéro)
  	int		m_NumPalEnCour;		// numéro de la palette en cours de chargement (la première prend le numéro zéro)
  	int*		m_pNbProdParCateg;	// tableau contenant le nombre de produits associé à chaque catégorie
  	CProduit*  	m_pProdEnCour;		// pointeur sur le produit en cours de traitement
  	CPalette*  	m_pPaletteEnCour;	// pointeur sur la palette en cours de chargement
  	CPalette** 	m_pPalettes;		// tableau de pointeurs sur les palettes déjà produites + la palette en cours de chargement
  	string*         m_pLesDest;            	// tableau des destinations de chaque palette

 	public:

	// Ce constructeur DOIT initialiser tous les attributs SAUF le produit en cours 
	// qui n'est pas encore connu. Une toute première palette (numéro zéro) vide en cours est créée avec une
	// première destination. Au départ, la machine est à l'arrêt.
	CMachine ( int NbCateg, int NbProduitTotal, int NbProdParPalette, string* pLesDest );
  
	// Destructeur nécessaire à la libération des zones mémoires dynamiques.
	// Attention, dans ce destructeur, ne détruire une palette et un produit qu'une seule 
	// fois sinon il y aura plantage (double free...).
	~CMachine ();
  
	/** Accesseurs **/
  	/****************/
  	bool   GetMarche ();
  	short  GetNbCateg ();
  	int    GetNbTotalProd ();
  	short  GetNbProdParPalette ();
  	int    GetNbTotalPal ();
  	int    GetNbPalProduites ();
  	int    GetNumPalEnCour ();
  
  	// Renvoie le nombre de produits associés à la catégorie "Categ"	
  	int    GetNbProd ( short Categ );
  
  	// Renvoie un pointeur sur la palette dont le numéro est passé en paramètre
  	// ce numéro correspond à l'index dans le tableau des palettes (m_pPalettes)
  	CPalette*    GetPalette ( int NumPalette );
  
  	// Renvoie un pointeur sur la palette en cours de chargement
  	CPalette*    GetPaletteEnCour ();
  
  	// Renvoie un pointeur sur le produit en cours de traitement
  	CProduit*    GetProduitEnCour ();
  
  	/** Modificateurs **/
  	/*******************/
  	void   SetMarche ( bool Marche );
  
	/** Chaque méthode dans la suite renvoie vrai si la machine est bien en marche. **/
	/** Si la machine n'est pas en marche, l'opération ne se fait pas et la méthode renvoie faux **/

	// Création et insertion d'un nouveau produit dans la machine qui devient le produit en cours.
	// Si le nbre total de produits à traiter est atteind, la méthode ne fait rien et renvoie faux.
	// Si ce nouveau produit nécessite un stockage sur une nouvelle palette (la précédente étant pleine), 
	// une nouvelle palette est créée avec sa nouvelle destination.
	bool   InsertNewProduit ();

	// La machine attribue une catégorie au produit en cours.
	// Pour simplifier, l'attribution de la catégorie (1...m_NbCateg) se fait aléatoirement avec 
	// la fonction "rand()" (sachant que rand() renvoie un entier aléatoire i telle que 0 <= i < RAND_MAX et
	// que RAND_MAX est une constante déjà déclarée et connue).
	bool Process ();
	  
	// Met à jour le tableau des catégories m_NbProdParCateg suivant la catégorie à laquelle appartient 
	// le nouveau produit.
	bool EjectionProduit ();
	  
	// Une fois connus :
	//	- la catégorie du produit
	//	- le numéro de la palette en cours sur laquelle est stocké le produit en cours
	// => le produit est marqué avec le code suivant : "<Produit NumProd - Cat xx - Pal NumPal>"
	bool MarquageProduit ();
	  
	// Ajoute le produit courant sur la palette en cours de chargement.
	bool AjoutPalette ();
	  
	// Pour chaque palette, on affiche à l'écran le code de chaque produit
	// y compris pour la dernière palette éventuellement incomplète.
	// Le code de cette méthode est le suivant :
	/*******/
	//	void CMachine::Affiche() {
	
	//		cout << "\nNbre de palettes complètes : " << GetNbPalProduites() << endl;
	
	//		for (int i=0; i<=m_NumPalEnCour; i++) {
	
	//			cout << "\n\rPalette --> " << i << "\tCode : " << m_pPalettes[i]->GetCode() << endl;
	
	//			for (int j=0; j<m_pPalettes[i]->GetNbProduitActuels(); j++) {
	
	//				cout << "\r\tProduit -> " << j << endl;
					// Affiche les caractéristiques du produit
	//				cout << *( m_pPalettes[i]->GetProduit ( j ) );
	//			}
	//		}
	//	}	
	/*******/
  
  	void Affiche ();
};

#endif
