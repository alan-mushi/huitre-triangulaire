#ifndef CPALETTE_H
#define CPALETTE_H

#include "BiblioStd.h"
#include "CProduit.h"

class CPalette {
	private:
		int m_NbProdParPalette;
		short m_NbProdActuels;
		string m_Dest;
		string m_CodePal;
		CProduit** m_pProdStockes;
		
	public:
		CPalette(short nbProd, const string dest);
		~CPalette();

		// Pour le moment on n'utilise pas les accesseurs
		//int GetNbProdParPalette();
		//short GetNbProdActuels();
		//string GetDest();
		//string GetCodePal();
		//CProduit** GetProdStockes();

		void MakeCode( int NumPal );
		void AddProduit( CProduit * pProduit );
		CProduit* GetProduit( int IndexTab );
};

#endif
