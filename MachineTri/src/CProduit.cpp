#include "CProduit.h"

CProduit::CProduit()
{
	this->m_Long = rand() % DIM + 1;
	this->m_Haut = rand() % DIM + 1;
	this->m_Larg = rand() % DIM + 1;
}

void CProduit::MakeCode(int NumProd, int NumPal)
{
	ostringstream tmp;
	tmp << NumProd << this->getCateg() << NumPal;
	this->setCode(tmp.str());
}

ostream& operator<<(ostream& os, CProduit& UnProd)
{
	os << "Longueur :" << UnProd.getLong() << endl;
	os << "Largeur :" << UnProd.getLarg() << endl;
	os << "Hauteur :" << UnProd.getHaut() << endl;
	os << "Catégorie :" << UnProd.getCateg() << endl;
	os << "Code :" << UnProd.getCode() << endl;
	
	return os;
}

float CProduit::getLong()
{
	return this->m_Long;
}

float CProduit::getLarg()
{
	return this->m_Haut;
}

float CProduit::getHaut()
{
	return this->m_Larg;
}

CProduit::~CProduit()
{
	cout << "Adresse du produit détruit : " << this << endl;
}
