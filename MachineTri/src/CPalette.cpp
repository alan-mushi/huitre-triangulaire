#include "CPalette.h"

/*
 * Constructeur de l'objet CPalette.
 * params:
 *	nbProd	Nombre de produits par palette
 *		Throws range_error si nbProd <= 0
 *	dest	Destination a affecter à la palette
 *		Throws length_error si dest est une chaine vide
 */
CPalette::CPalette( short nbProd, const string dest )
{
	if ( nbProd <= 0 )
	{
		range_error e("Une palette doit contenir au moins une huitre.");
		throw e;
	}
	if ( dest.empty() )
	{
		length_error e("Une destination doit être spécifiée.");
		throw e;
	}
	
	m_NbProdParPalette = nbProd;
	m_pProdStockes = new CProduit*[nbProd];
	m_Dest = dest;
	m_NbProdActuels = 0;
	m_CodePal = "";
}

/*
 * Supprime chaque produit du tableau de produit.
 * Affiche le code de la palette qui est détruit.
 */
CPalette::~CPalette()
{
	for ( int i = 0 ; i < m_NbProdActuels-1 ; i++ )
	{
		(*m_pProdStockes[i]).~CProduit() ;
	}
	delete[] m_pProdStockes;
	cout << "[*] Palette " << m_CodePal << " détruite." << endl;
}

/*
 * Construit le code de la palette.
 * Aucun contrôle n'est réalisé sur NumPal.
 * param:
 *	NumPal	Le numéro de la palette
 */
void CPalette::MakeCode( int NumPal )
{
	stringstream tmp;
	tmp << "<Palette n# " << NumPal << " - Destination : " << m_Dest << " >" ;
	m_CodePal = tmp.str();
}

/*
 * Ajoute un produit à la palette et incrémente le 
 * nombre de produits présents dans la palette.
 * Throws range_error si la palette est déjà pleine.
 * params:
 *	pProduit	Une référence vers le produit a ajouter.
 			Throws invalid_argument si pProduit est égal à null.
 */
void CPalette::AddProduit( CProduit * pProduit )
{
	if ( pProduit == NULL )
	{
		invalid_argument e("Le produit a ajouter ne peut pas être null.");
		throw e;
	}
	if ( m_NbProdActuels == m_NbProdParPalette )
	{
		range_error e("La palette est pleine il n'est pas possible d'ajouter un autre produit.");
		throw e;
	}
	m_pProdStockes[m_NbProdActuels] = pProduit;
	m_NbProdActuels++;
}

/*
 * Retourne le produit dans le tableau.
 * NOTE: si aucun produit n'existe à l'indice du tableau NULL sera retourné.
 * param: 
 *	IndexTab	index du tableau qui dispose du produit
 *			Throws range_error si l'indice n'appartient pas au tableau.
 */
CProduit* CPalette::GetProduit( int IndexTab )
{
	if ( IndexTab < 0 || IndexTab >= m_NbProdParPalette )
	{
		range_error e("L'index n'appartient pas à la zone mémoire du tableau.");
		throw e;
	}
	return m_pProdStockes[IndexTab];
}

/*
 * Retourne le nombre de produit par palette.
 */
int CPalette::GetNbProdParPalette()
{
	return m_NbProdParPalette;
}

/*
 * Retourne le nombre de produit actuellement stockés dans la palette.
 */
short CPalette::GetNbProdActuels()
{
	return m_NbProdActuels;
}

/*
 * Retourne la destination à laquelle la palette est adressée.
 */
string CPalette::GetDest()
{
	return m_Dest;
}

/*
 * Retourne le code attribué à la palette.
 */
string CPalette::GetCodePal()
{
	return m_CodePal;
}
