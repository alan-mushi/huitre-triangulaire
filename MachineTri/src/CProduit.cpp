#include "CProduit.h"

/**
*	Constructeur initialisant à des nombre aléatoire compris entre
*	1 et DIM les attributs de la classe
*/
CProduit::CProduit()
{
	srand(time(NULL));
	this->m_Long = rand() % (DIM - 1) + 1;
	this->m_Haut = rand() % (DIM - 1) + 1;
	this->m_Larg = rand() % (DIM - 1) + 1;
}

/**
*	Génére le code du produit
*	@NumProd Le numéro du produit
	@NumPal Le numéro de la palette
*/
void CProduit::MakeCode(int NumProd, int NumPal)
{
	ostringstream tmp;
	tmp << NumProd << this->getCateg() << NumPal;
	this->setCode(tmp.str());
}

/**
*	Permet d'afficher avec cout << unProduit;
*/
ostream& operator<<(ostream& os, CProduit& UnProd)
{
	os << "Longueur :" << UnProd.getLong() << endl;
	os << "Largeur :" << UnProd.getLarg() << endl;
	os << "Hauteur :" << UnProd.getHaut() << endl;
	os << "Catégorie :" << UnProd.getCateg() << endl;
	os << "Code :" << UnProd.getCode() << endl;
	
	return os;
}

/**
*	Retourne la longueur du produit
*	@return la longueur du produit
*/
float CProduit::getLong()
{
	return this->m_Long;
}

/**
*	Retourne la largeur du produit
*	@return la largeur du produit
*/
float CProduit::getLarg()
{
	return this->m_Haut;
}

/**
*	Retourne la hauteur du produit
*	@return la hauteur du produit
*/
float CProduit::getHaut()
{
	return this->m_Larg;
}

/**
*	Destructeur
*/
CProduit::~CProduit()
{
	cout << "Adresse du produit détruit : " << this << endl;
}
