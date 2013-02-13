#include "CProduit.h"

CProduit::CProduit()
{
	this->m_Long = rand() % DIM + 1;
	this->m_Haut = rand() % DIM + 1;
	this->m_Larg = rand() % DIM + 1;
}

void CProduit::MakeCode(int NumProd, int NumPal)
{
	string ret = "";	
}

ostream& CProduit::operator(ostream& os, CProduit& UnProd)
{

}
CProduit::~CProduit()
{

}
