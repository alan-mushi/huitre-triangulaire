#include "CMachine.h"

CMachine::CMachine(int NbCateg, int NbProduitTotal, int NbProdParPalette, string* pLesDest)
{
	this->m_Marche = false;
	
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
	this->m_NumPalEnCour = 0;
	this->m_pNbProdParCateg = new int[NbCateg];
	for(int i=0; i<NbCateg; i++)
	{
		this->m_pNbProdParCateg[i] = 0;
	}
	this->m_pProdEnCour = NULL;
	if(p_LesDest == NULL)
	{
		runtime_error e("Les destinations n'ont pas étés correctement définies.");
		throw e;
	}
	this->m_pPaletteEnCour = new CPalette(NbProdParPalette, pLesDest[0]);
	this->m_pPalettes = new CPalette[NbProdParPalette];
	this->m_pPalettes[0] = m_pPaletteEnCour;
	for(int i=1; i < NbProdParPalette; i++)
	{
		this->m_pPalettes[i] = NULL;
	}
}

short CMachine::GetNbCateg()
{
	return this->m_NbCateg;
}

int CMachine::GetNbTotalProd()
{
	return this->m_NbProduitTotal;
}

short CMachine::GetNbProdParPalette()
{
	return this->m_NbProdParPalette;
}

int CMachine::GetNbTotalPal()
{
	return this->m_NbPaletteTotal;
}

int CMachine::GetNbPalProduites()
{
	return this->m_NbPalProduites;
}

int CMachine::GetNumPalEnCour()
{
	return this->m_NumPalEnCour;
}

int CMachine::GetNbProd(short Categ)
{
	int ret = -1;
	if((Categ > this->m_NbCateg) || (Categ < 0))
	{
		ret = this->m_pNbProdParCateg[Categ];
	}
	else
	{
		length_error e("Le numéro de catégorie n'est pas correct.");
		throw e;
	}
	
	return ret;
}

CPalette* CMachine::GetPalette(int NumPalette)
{
	CPalette* ret = NULL;
	
	if(NumPalette <= this->m_NbPaletteTotal && NumPalette > 0)
	{
		ret = m_pPalettes[NumPalette];
	}
	else
	{
		length_error e("Le numéro de palette n'est pas correct.");
		throw e;
	}
	
	return ret;
}

CPalette* CMachine::GetPaletteEnCour ()
{
	return m_pPaletteEnCour;
}

CProduit* CMachine::GetProduitEnCour()
{
	if(this->m_pProdEnCour == NULL)
	{
		runtime_error e("Il n'y a pas de produit en cours.");
		throw e;
	}
	
	return this->m_pProdEnCour;
}

void CMachine::SetMarche (bool Marche)
{
	this->m_Marche = Marche;
}

bool CMachine::InsertNewProduit ()
{
	bool ret = false;
	if(this->m_Marche) {
		int nbActuel = 0;
		for(int i=0; i<this->m_NbPaletteTotal; i++)
		{
			nbActuel += this->m_pPalettes[i]->GetNbProdActuels();
		}
		if(this->m_NbProduitTotal > nbActuel)
		{
			ret = true;
			if(this->m_NbProdParPalette < this->m_pPaletteEnCour->GetNbProdActuels())
			{
				CProduit* nouveauProduit = new CProduit();
				this->m_pProdEnCour = nouveauProduit;
			}
			else
			{
				this->AjoutPalette();
			}
		}
	}
	
	return ret;
}

bool CMachine::Process()
{
	bool ret = false;
	if(this->m_Marche) {
		ret = true;
		srand(time(NULL));
		this->m_pProdEnCour->setCateg((short)(rand() % (this->m_NbCateg - 1) + 1));
	}
	
	return ret;
}

bool CMachine::EjectionProduit()
{
	bool ret = false;
	if(this->m_Marche) {
		ret = true;
		
	}
	
	return ret;
}

bool CMachine::MarquageProduit()
{
	bool ret = false;
	if(this->m_Marche) {
		ret = true;
		
	}
	
	return ret;
}

//TODO : la méthode n'est peut être pas terminée : à vérifier
bool CMachine::AjoutPalette()
{
	bool ret = false;
	if(this->m_Marche) {
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

void CMachine::Affiche()
{
	cout << "\nNbre de palettes complètes : " << GetNbPalProduites() << endl;

	for (int i=0; i<=m_NumPalEnCour; i++) 
	{
		cout << "\n\rPalette --> " << i << "\tCode : " << m_pPalettes[i]->GetCode() << endl;

		for (int j=0; j<m_pPalettes[i]->GetNbProduitActuels(); j++) 
		{
			cout << "\r\tProduit -> " << j << endl;
			// Affiche les caractéristiques du produit
			cout << *( m_pPalettes[i]->GetProduit ( j ) );
		}
	}
}

CMachine::~CMachine()
{
	delete this->m_pProdEnCour;
	for(int i=0; i < NbProdParPalette; i++)
	{
		delete this->m_pPalettes[i];
	}
	delete this->m_pPalettes;
	delete this->m_pLesDest;
}
