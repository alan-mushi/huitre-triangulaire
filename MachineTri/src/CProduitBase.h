#ifndef CPRODUITBASE_H
#define CPRODUITBASE_H

#include "BiblioStd.h"

class CProduitBase {

	private:
		string m_Code;
		short m_Categ;

	public:
		virtual void MakeCode( int NumProd, int NumPal ) = 0 ;
		short getCateg();
		void setCateg( short cat );
		string getCode();
	
	private:
		void setCode( string code );
};

#endif
