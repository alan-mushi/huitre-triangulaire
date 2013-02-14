#ifndef CPRODUIT_H
#define CPRODUIT_H

#include "BiblioStd.h"
#include "CProduitBase.h"

#define DIM 20

class CProduit : public CProduitBase
{
	private:
		float m_Long; //longueur du produit
		float m_Larg; //largeur du produit
		float m_Haut; //hauteur du produit

	public:
		CProduit();
		void MakeCode(int NumProd, int NumPal);
		friend ostream& operator<<(ostream& os, CProduit& UnProd);
		float getLong();
		float getLarg();
		float getHaut();
		~CProduit();
};

#endif
