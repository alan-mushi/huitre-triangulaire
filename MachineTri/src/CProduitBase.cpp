#include "CProduitBase.h"

short CProduitBase::getCateg()
{
	return m_Categ;
}

string CProduitBase::getCode()
{
	return m_Code;
}

/*
 * Change la catégorie de l'attribut m_Categ.
 * Throw range_error si la cat n'est pas dans les bornes ]0;NbCat]
 */
void CProduitBase::setCateg( short cat )
{
	if ( cat > 0 && cat <= NBCATEG )
		m_Code = cat;
	else
	{
		range_error e("Catégorie hors limites.");
		throw e;
	}
}
