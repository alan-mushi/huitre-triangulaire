#include "CMachine.h"

CMachine::CMachine(int NbCateg, int NbProduitTotal, int NbProdParPalette, string* pLesDest)
{
	this->m_Marche = false;
	this->m_NbCateg = NbCateg;
	this->m_NbProduitTotal = NbProduitTotal;
	this->m_NbProdParPalette = NbProdParPalette;
	this->m_NbPaletteTotal = 1;
	this->m_NbPalProduites = 0;
	this->m_NumPalEnCour = 0;
	this->m_pNbProdParCateg = new int[NbCateg];
	this->m_pPaletteEnCour = new CPalette(NbProdParPalette, pLesDest[0]);
	this->m_pPalettes = new CPalette[1];
	this->m_pPalettes[0] = m_pPaletteEnCour;
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

}

CPalette* CMachine::GetPalette(int NumPalette)
{

}

CPalette* CMachine::GetPaletteEnCour ()
{

}

CProduit* CMachine::GetProduitEnCour()
{

}

void CMachine::SetMarche (bool Marche)
{
	this->m_Marche = Marche;
}

bool CMachine::InsertNewProduit ()
{
	bool ret = false;
	if(this->m_Marche) {
		ret = true;
		
	}
	
	return ret;
}

bool CMachine::Process()
{
	bool ret = false;
	if(this->m_Marche) {
		ret = true;
		
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

bool CMachine::AjoutPalette()
{
	bool ret = false;
	if(this->m_Marche) {
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

}
