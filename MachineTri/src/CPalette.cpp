#include "CPalette.h"

/*
 * Constructeur de l'objet CPalette.
 * params:
 *	nbProd	Nombre de produits par palette
 *		Throws range_error si nbProd <= 0
 *	dest	Destination a affecter � la palette
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
		length_error e("Une destination doit �tre sp�cifi�e.");
		throw e;
	}
	
	m_NbProdParPalette = nbProd;
	m_pProdStockes = new CProduit*[nbProd];
	m_Dest = dest;
	m_NbProdActuels = 0;
}

/*
 * Supprime chaque produit du tableau de produit.
 * Affiche le code de la palette qui est d�truit.
 */
CPalette::~CPalette()
{
	for ( int i = 0 ; i < m_NbProdParPalette ; i++ )
	{
		(*m_pProdStockes[i]).~CProduit() ;
	}
	delete[] m_pProdStockes;
	cout << "[*] Palette " << m_CodePal << " d�truite." << endl;
}

/*
 * Construit le code de la palette.
 * Aucun contr�le n'est r�alis� sur NumPal.
 * param:
 *	NumPal	Le num�ro de la palette
 */
void CPalette::MakeCode( int NumPal )
{
	m_CodePal = "<Palette n� ";
	m_CodePal += NumPal;
	m_CodePal += " - Destination : ";
	m_CodePal += string(m_Dest);
	m_CodePal += " >" ;
}

/*
 * Ajoute un produit � la palette et incr�mente le 
 * nombre de produits pr�sents dans la palette.
 * Throws range_error si la palette est d�j� pleine.
 * params:
 *	pProduit	Une r�f�rence vers le produit a ajouter.
 			Throws invalid_argument si pProduit est �gal � null.
 */
void CPalette::AddProduit( CProduit * pProduit )
{
	if ( pProduit == NULL )
	{
		invalid_argument e("Le produit a ajouter ne peut pas �tre null.");
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
 * NOTE: si aucun produit n'existe � l'indice du tableau NULL sera retourn�.
 * param: 
 *	IndexTab	index du tableau qui dispose du produit
 *			Throws range_error si l'indice n'appartient pas au tableau.
 */
CProduit* CPalette::GetProduit( int IndexTab )
{
	if ( IndexTab < 0 || IndexTab >= m_NbProdParPalette )
	{
		range_error e("L'index n'appartient pas � la zone m�moire du tableau.");
		throw e;
	}
	return m_pProdStockes[IndexTab];
}
