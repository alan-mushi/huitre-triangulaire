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
	this->m_code = tmp;
}

ostream& CProduit::operator<<(ostream& os, CProduit& UnProd)
{
	os << "Longueur :" << this->m_Long << endl;
	os << "Largeur :" << this->m_Larg << endl;
	os << "Hauteur :" << this->m_Haut << endl;
	os << "Catégorie :" << this->getCateg() << endl;
	os << "Code :" << this->getCode() << endl;
}
CProduit::~CProduit()
{
	cout << "Adresse du produit détruit" << this << endl;
}
