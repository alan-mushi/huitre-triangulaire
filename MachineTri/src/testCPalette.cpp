#include "BiblioStd.h"
#include "CPalette.h"

int main()
{
	string dest1 = "Pentagone";
	string dest2 = "Iran";
	short nbProdPal1 = 13, nbProdPal2 = 7;

	/*******************************************************/
	cout << endl << "[*] Test du constructeur de CPalette." << endl;
	cout << "\t[*] test : param nbProd invalid (=0) ... ";
	try {
		CPalette nbProdInvalide1( 0, dest1 );
		cout << "FAIL";
	} catch ( range_error& e ) {
		cout << "GOOD : " << e.what();
	}
	cout << endl;

	cout << "\t[*] test : param nbProd invalid (=-4) ... ";
	try {
		CPalette nbProdInvalide2( -4, dest1 );
		cout << "FAIL";
	} catch ( range_error& e ) {
		cout << "GOOD : " << e.what();
	}
	cout << endl;

	cout << "\t[*] test : param dest invalid (='') ... ";
	try {
		CPalette nbProdInvalide3( nbProdPal1, "" );
		cout << "FAIL";
	} catch ( length_error& e ) {
		cout << "GOOD : " << e.what();
	}
	cout << endl;

	cout << "\t[*] test : paramètres valides ... ";
	CPalette *paletteValide = NULL;
	try {
		paletteValide = new CPalette( nbProdPal2, dest2 );
		cout << "GOOD";
	} catch ( ... ) {
		cout << "FAIL";
		cout << endl << "[-] Creation de CPalette FAILED ... aborting." << endl;
		return -1;
	}
	cout << endl << endl;

	/*******************************************************/
	cout << "[*] Test d'ajout d'un produit." << endl;
	cout << "\t[*] test d'ajout avec un produit = null ... ";
	try {
		(*paletteValide).AddProduit( NULL );
		cout << "FAIL (une exception aurait du être lancée)";
	} catch ( range_error& e ) {
		cout << "FAIL (exception non attendue) : " << e.what();
	} catch ( invalid_argument& e ) {
		cout << "GOOD : " << e.what();
	}
	cout << endl;

	cout << "\t[*] test d'ajout avec un produit valide ... ";
	try {
		(*paletteValide).AddProduit( new CProduit() );
		cout << "GOOD";
	} catch ( range_error& e ) {
		cout << "FAIL (exception non attendue) : " << e.what();
	} catch ( invalid_argument& e ) {
		cout << "FAIL : " << e.what();
	}
	if ( (*paletteValide).GetNbProdActuels() != 1 )
	{
		cout << "[-] Insertion FAILED ... abording." << endl;
		return -1; // Sinon la suite va afficher être problématique...
	}
	cout << endl;

	cout << "\t[*] test d'ajout avec maximum de produits atteints ... ";
	for ( int i = 0 ; i < nbProdPal2 ; i++ )
	{
		try {
			(*paletteValide).AddProduit( new CProduit() );
			if ( i >= nbProdPal2 )
				cout << "FAIL (le maximum aurait du être atteint)";
		} catch ( range_error& e ) {
			if ( i == nbProdPal2-1 )
				cout << "GOOD : " << e.what();
			else
				cout << " FAIL (le maximum a été atteint trop tôt)";
		}
	}
	cout << endl << endl;

	/*******************************************************/
	cout << "[*] Test de GetNbProdParPalette." << endl;

	cout << "\t[*] test sur l'objet déjà construit ... ";
	if ( nbProdPal2 == (*paletteValide).GetNbProdParPalette() )
		cout << "GOOD";
	else
		cout << "FAIL (le nombre retourné est [" << (*paletteValide).GetNbProdParPalette() << "] et le nombre attendu était le [" << nbProdPal2 << "])";
	cout << endl;

	cout << "\t[*] test sur un nouvel objet ... ";
	// Il n'y aura aucune exception ici : celà simplifie la synthaxe
	CPalette anotherPaletteValide( nbProdPal1, dest1 );
	if ( nbProdPal1 == anotherPaletteValide.GetNbProdParPalette() )
		cout << "GOOD";
	else
		cout << "FAIL (le nombre retourné est [" << (*paletteValide).GetNbProdParPalette() << "] et le nombre attendu était le [" << nbProdPal2 << "])";
	cout << endl << endl;

	/*******************************************************/
	cout << "[*] Test de GetDest." << endl;
	cout << "\t[*] test sur le premier objet crée ... ";
	if ( dest2 == (*paletteValide).GetDest() )
		cout << "GOOD";
	else
		cout << "FAIL (la destination n'est pas valide: attendu '" << dest2 << "' retourné '" << (*paletteValide).GetDest() << "' )";
	cout << endl;

	cout << "\t[*] test sur le deuxième objet crée ... ";
	if ( dest1 == anotherPaletteValide.GetDest() )
		cout << "GOOD";
	else
		cout << "FAIL (la destination n'est pas valide: attendu '" << dest1 << "' retourné '" << anotherPaletteValide.GetDest() << "' )";
	cout << endl << endl;

	/*******************************************************/
	cout << "[*] Test de GetNbProdActuels." << endl;
	cout << "\t[*] test sur le premier objet crée ... ";
	if ( nbProdPal2 == (*paletteValide).GetNbProdActuels() )
		cout << "GOOD";
	else
		cout << "FAIL (le nombre attendu n'est pas celui renvoyé : attendu [" << nbProdPal2 << "] renvoyé [" << (*paletteValide).GetNbProdActuels() << "] )";
	cout << endl;

	cout << "\t[*] test sur le deuxième objet crée (insertion de " << nbProdPal1-3 <<" éléments) ... ";
	for (int i = 0 ; i < nbProdPal1-3 ; i++ )
	{
		try {
			anotherPaletteValide.AddProduit( new CProduit() );
		} catch ( invalid_argument& e ) {
			cout << "FAIL (le produit crée vaut NULL) ... abording." << endl;
			return -1;
		} catch ( range_error& e ) {
			cout << "FAIL (la limite a été atteinte trop tôt) ... abording." << endl;
			return -1;
		}
	}
		
	if ( nbProdPal1-3 == anotherPaletteValide.GetNbProdActuels() )
		cout << "GOOD";
	else
		cout << "FAIL (le nombre attendu n'est pas celui renvoyé : attendu [" << nbProdPal1-3 << "] renvoyé [" << anotherPaletteValide.GetNbProdActuels() << "] )";
	cout << endl << endl;

	/*******************************************************/
	cout << "[*] Test de GetCodePal." << endl;
	cout << "\t[*] test sur le deuxième objet crée (code vide) ... " ;
	if ( (anotherPaletteValide.GetCodePal()).empty() )
		cout << "GOOD";
	else
		cout << "FAIL (code retourné '" << anotherPaletteValide.GetCodePal() << "' code attendu '')";
	cout << endl;
	
	cout << "\t[*] test une fois le code généré ... ";
	int codePal = 6;
	anotherPaletteValide.MakeCode( codePal );
	stringstream tmp;
	tmp << "<Palette n# " << codePal << " - Destination : " << anotherPaletteValide.GetDest() << " >" ;
	string codeAttendu = tmp.str();
	if ( codeAttendu == anotherPaletteValide.GetCodePal() )
		cout << "GOOD";
	else
		cout << "FAIL (code retourné '" << anotherPaletteValide.GetCodePal() << "' code attendu '" << codeAttendu << "')";
	cout << endl << endl;

	/*******************************************************/
	cout << "[*] Test de GetProduit." << endl;
	cout << "\t[*] test avec un index hors bornes (<0) ... ";
	try {
		anotherPaletteValide.GetProduit( -2 );
		cout << "FAIL (une exception range_error aurait du être levée)";
	} catch ( range_error& e ) {
		cout << "GOOD : " << e.what();
	}
	cout << endl;

	cout << "\t[*] test avec un index hors bornes (>nbProdPal1) ... ";
	try {
		anotherPaletteValide.GetProduit( nbProdPal1+2 );
		cout << "FAIL (une exception range_error aurait du être levée)";
	} catch ( range_error& e ) {
		cout << "GOOD : " << e.what();
	}
	cout << endl;

	cout << "\t[*] test avec un index valide ... ";
	try {
		CProduit* tmp = anotherPaletteValide.GetProduit( anotherPaletteValide.GetNbProdActuels()-1 );
		cout << "GOOD :" << endl << *tmp;
	} catch ( range_error& e ) {
		cout << "FAIL : " << e.what();
	}
	cout << endl << endl;

	/*******************************************************/
	cout << "[*] Place aux destructeurs..." << endl;
	// On n'oublie pas de détruire ce qui doit l'être
	delete paletteValide;
}
