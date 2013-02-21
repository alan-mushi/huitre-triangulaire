#include "CMachine.h"

/**
* Constructeur 
* @param NbCateg Le nombre de catégorie
* @param NbProduitTotal Le nombre de produit total à enregistrer
* @param NbProdParPalette Le nombre de produit par palette
* @param pLesDest Un tableau de string contenant les destinations des différentes palettes
* @throw length_error length_error est émis si <code>NbCateg</code>, <code>NbProduitTotal</code> ou <code>NbProdParPalette</code> est inférieur à 0. Emis aussi si le nombre de produit total est < que le nombre de produit par palette
* @throw runtime_error Emis si les destinatations sont égal à NULL
*/
CMachine::CMachine(int NbCateg, int NbProduitTotal, int NbProdParPalette, string* pLesDest)
{
	this->m_Marche = false;
	m_NbPalProduites = 0;
	
	if(NbProdParPalette > NbProduitTotal)
	{
		length_error e("Le nombre de produit par palette ne peut pas être supérieur au nombre de produit total");
		throw e;
	}
	
	if(NbCateg > 0)
		this->m_NbCateg = NbCateg;
	else
	{
		length_error e("Le nombre de catégorie doit être suppérieur à 0.");
		throw e;
	}
	if(NbProduitTotal > 0)
		this->m_NbProduitTotal = NbProduitTotal;
	else
	{
		length_error e("Le nombre de produit total doit être supérieur à 0.");
		throw e;
	}
	if(NbProdParPalette > 0)
		this->m_NbProdParPalette = NbProdParPalette;
	else
	{
		length_error e("Le nombre de produit par palette doit être supérieur à 0.");
		throw e;	
	}
	this->m_NbPaletteTotal = NbProduitTotal / NbProdParPalette;
	if((NbProduitTotal % NbProdParPalette) > 0)
		this->m_NbPaletteTotal++;
		
	this->m_NumPalEnCour = 0;
	this->m_pNbProdParCateg = new int[NbCateg];
	for(int i=0; i<NbCateg; i++)
	{
		this->m_pNbProdParCateg[i] = 0;
	}
	this->m_pProdEnCour = NULL;
	if(pLesDest == NULL)
	{
		runtime_error e("Les destinations n'ont pas étés correctement définies.");
		throw e;
	}
	// DEBUG
	// CPalette( short nbProd = NbProdParPalette , const string dest = pLesDest[0]);
	// DEBUG
	try
	{
		this->m_pPaletteEnCour = new CPalette(NbProdParPalette, pLesDest[0]);
	}
	catch(range_error e)
	{
		cout << "Erreur d'initialisation pour this->m_pPaletteEnCour : " << e.what() << endl;
	}
	catch(length_error e)
	{
		cout << "Erreur d'initialisation pour this->m_pPaletteEnCour : " << e.what() << endl;
	}
	this->m_pPalettes = new CPalette*[this->m_NbPaletteTotal];
	this->m_pPalettes[0] = m_pPaletteEnCour;
	for(int i=1; i < this->m_NbPaletteTotal; i++)
	{
		this->m_pPalettes[i] = NULL;
	}
}

/**
* Retourne le nombre de catégorie pour la machine
* @return Le nombre de catégorie
*/
short CMachine::GetNbCateg()
{
	return this->m_NbCateg;
}

/**
* Retourne le nombre total de produit
* @return Le nombre total de produit
*/
int CMachine::GetNbTotalProd()
{
	return this->m_NbProduitTotal;
}

/**
* Retourne le nombre de produit par palette
* @return Le nombre de produit par palette
*/
short CMachine::GetNbProdParPalette()
{
	return this->m_NbProdParPalette;
}

/**
* Retourne le nombre total de palette
* @return Le nombre total de palette
*/
int CMachine::GetNbTotalPal()
{
	return this->m_NbPaletteTotal;
}

/**
* Retourne le nombre de palettes produite actuellement
* @return Le nombre de palette produite
*/
int CMachine::GetNbPalProduites()
{
	return this->m_NbPalProduites;
}

/**
* Retourne le numéro de la palette en cours
* @return Le numéro de la palette en cours
*/
int CMachine::GetNumPalEnCour()
{
	return this->m_NumPalEnCour;
}

/**
* Retourne le nombre de produit par catégorie
* @param Categ Le numéro de la catégorie pour laquelle il faut compter le nombre de produit
* @return Le nombre de produit pour la catégorie passée en paramètre
* @throw length_error Emis si <code>Categ</code> n'est pas entre 0 et <code>m_NbCateg</code>
*/
int CMachine::GetNbProd(short Categ)
{
	int ret = -1;
	if(!(Categ > this->m_NbCateg) && !(Categ < 0))
	{
		// -1 pour aligner sur le tableau (comme il commence a l'indice 0)
		ret = this->m_pNbProdParCateg[Categ-1];
	}
	else
	{
		length_error e("Le numéro de catégorie n'est pas correct.");
		throw e;
	}
	
	return ret;
}

/**
* Retourne un pointeur vers une palette en fonction de son numéro de palette
* @param NumPalette Le numéro de la palette à sélectionner
* @return La palette sélectionnée
* @throw length_error Emis si NumPalette n'est pas compris entre 0 et le nombre de palette totale
*/
CPalette* CMachine::GetPalette(int NumPalette)
{
	CPalette* ret = NULL;
	
	if(NumPalette <= this->m_NbPaletteTotal && NumPalette > 0)
	{
		ret = m_pPalettes[NumPalette-1];
	}
	else
	{
		length_error e("Le numéro de palette n'est pas correct.");
		throw e;
	}
	
	return ret;
}

/**
* Retourne un pointeur vers la palette en cours
* @return Un pointeur vers la palette en cours
*/
CPalette* CMachine::GetPaletteEnCour ()
{
	return m_pPaletteEnCour;
}

/**
* Retourne un pointeur vers le produit en cours
* @return Le pointeur vers le produit en cours
* @throw runtime_error Emis si il n'y a pas de produit en cours (<code>this->m_pProdEnCour == NULL</code>)
*/
CProduit* CMachine::GetProduitEnCour()
{
	if(this->m_pProdEnCour == NULL)
	{
		runtime_error e("Il n'y a pas de produit en cours.");
		throw e;
	}
	
	return this->m_pProdEnCour;
}

/**
* Met en marche ou arrête la machine
* @param Marche Mettre à true pour mettre en marche et false pour arrêter la machine
*/
void CMachine::SetMarche (bool Marche)
{
	this->m_Marche = Marche;
}

/**
* Insère un nouveau produit
* @return True si l'insertion a fonctionné, false sinon. Renvoie false si la machine est arrêtée
*/
bool CMachine::InsertNewProduit ()
{
	bool ret = false;
	if(this->m_Marche) {
		int nbActuel = 0;
		for(int i=0; i<this->m_NbPaletteTotal-1; i++)
		{
			nbActuel += this->m_pPalettes[i]->GetNbProdActuels();
		}
		if(this->m_NbProduitTotal > nbActuel)
		{
			ret = true;
			CProduit* nouveauProduit = new CProduit();
			this->m_pProdEnCour = nouveauProduit;
			this->Process();
			
			if(this->m_NbProdParPalette < this->m_pPaletteEnCour->GetNbProdActuels())
				this->m_pPaletteEnCour->AddProduit(nouveauProduit);
			else
				this->AjoutPalette();
		}
	}
	
	return ret;
}

/**
* Assigne une catégorie aléatoirement au produit en cours
* @return Retourne false si la machine n'est pas en marche
*/
bool CMachine::Process()
{
	bool ret = false;
	if(this->m_Marche) {
		ret = true;
		try
		{
			srand(time(NULL));
			int alea = (rand() % (this->m_NbCateg - 1) + 1);
			this->m_pProdEnCour->setCateg(alea);
			this->m_pNbProdParCateg[this->m_pProdEnCour->getCateg()]++;
		}
		catch(range_error e)
		{
			cout << "Erreur : " << e.what() << endl;
		}
	}
	
	return ret;
}

/**
* Permet d'éjecter le produit en cours
* @return Retourne false si la machine n'est pas en marche
*/
bool CMachine::EjectionProduit()
{
	bool ret = false;
	if(this->m_Marche) {
		ret = true;
		short currentProdCateg = (*m_pProdEnCour).getCateg();
		// -1 pour aligner sur le tableau
		currentProdCateg--;
		m_pNbProdParCateg[currentProdCateg]--;
	}
	
	return ret;
}

/**
* Définit le code du produit une fois la catégorie et le numero de palette connue
* @return Retourne false si la machine n'est pas en marche
*/
bool CMachine::MarquageProduit()
{
	bool ret = false;
	if(this->m_Marche) {
		ret = true;
		(*m_pProdEnCour).MakeCode( m_NumProdEnCour, m_NumPalEnCour );
	}
	
	return ret;
}

/**
* Permet d'ajouter une palette
* @return Retourne false si la machine n'est pas en marche
*/
bool CMachine::AjoutPalette()
{
	bool ret = false;
	if(this->m_Marche) 
	{
		try
		{	
			this->m_pPaletteEnCour->AddProduit(this->m_pProdEnCour);
			this->m_NumProdEnCour++;
		}
		catch(invalid_argument e)
		{
			cout << "Erreur : " << e.what() << endl;
		}
		catch(range_error e)
		{
			cout << "Erreur : " << e.what() << endl;
		}
		
		ret = true;
	}
	
	return ret;
}

/**
* Affiche l'état des éléments de la machine
*/
void CMachine::Affiche()
{
	cout << "\nNbre de palettes complètes : " << GetNbPalProduites() << endl;

	for (int i=0; i<=m_NumPalEnCour; i++) 
	{
		cout << "\n\rPalette --> " << i << "\tCode : " << m_pPalettes[i]->GetCodePal() << endl;

		for (int j=0; j<m_pPalettes[i]->GetNbProdActuels(); j++) 
		{
			cout << "\r\tProduit -> " << j << endl;
			// Affiche les caractéristiques du produit
			cout << *( m_pPalettes[i]->GetProduit ( j ) );
		}
	}
}

/**
* Destructeur
*/
CMachine::~CMachine()
{
	delete this->m_pProdEnCour;
	for(int i=0; i < m_NbProdParPalette; i++)
	{
		delete this->m_pPalettes[i];
	}
	delete this->m_pPalettes;
	delete this->m_pLesDest;
}
