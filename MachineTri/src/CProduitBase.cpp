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

/*
 * Change le code du produit.
 *	dest	Destination a affecter à la palette
 *		Throws length_error si dest est une chaine vide
 */
void CProduitBase::setCode( string code )
{
	if ( code.empty() )
	{
		length_error e("Le code ne doit pas être une chaine vide.");
		throw e;
	}
	m_Code = code;
}
