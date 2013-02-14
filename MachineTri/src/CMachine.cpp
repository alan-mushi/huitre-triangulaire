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
	//m_pNbProdParCateg = new int[];
}

bool CMachine::GetMarche()
{
	return this->m_Marche;
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

}

bool CMachine::Process()
{

}

bool CMachine::EjectionProduit()
{

}

bool CMachine::MarquageProduit()
{

}

bool CMachine::AjoutPalette()
{

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
