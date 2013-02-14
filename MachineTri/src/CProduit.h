#ifndef CPRODUIT_H
#define CPRODUIT_H

#include "BiblioStd.h"
#include "CProduitBase.h"

#define DIM 20

class CProduit : public CProduitBase
{
	private:
		float m_Long;
		float m_Larg;
		float m_Haut;

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
