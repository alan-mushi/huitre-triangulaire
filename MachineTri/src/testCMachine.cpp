#include "CMachine.h"

int main()
{
	string* destination = new string[5];
	destination[0] = "Querrien";
	destination[1] = "Quimperlé";
	destination[2] = "Lorient";
	destination[3] = "Vannes";
	destination[4] = "Quiberon";

	CMachine *m1;
	
	cout << "[*] Test du constructeur" << endl;
	cout << "\t[*] Test avec paramètres valides ... ";
	try
	{
		m1 = new CMachine(2, 30, 15, destination);
		cout << "Test réussi" << endl;
	}
	catch(length_error e)
	{
		cout << "Test failed : " << e.what() << endl;
	}
	catch(runtime_error e)
	{
		cout << "Test failed : " << e.what() << endl;
	}
	
	cout << "\t[*] Test avec paramètres invalides (Categorie invalide) ... ";
	try
	{
		CMachine m2(-5, 10, 15, destination);
		cout << "Test failed : m2 a été créé..." << endl;
	}
	catch(length_error e)
	{
		cout << "Test réussi" << endl;
	}
	catch(runtime_error e)
	{
		cout << "Test failed : runtime_error émis au lieu de length_error : " << e.what() << endl;
	}
	
	cout << "\t[*] Test avec paramètres invalides (Nombre de produit total invalide) ... ";
	try
	{
		CMachine m3(12, -60, 5, destination);
		cout << "Test failed : m3 a été créé..." << endl;
	}
	catch(length_error e)
	{
		cout << "Test réussi" << endl;
	}
	catch(runtime_error e)
	{
		cout << "Test failed : runtime_error émis au lieu de length_error : " << e.what() << endl;
	}
	
	cout << "\t[*] Test avec paramètres invalides (Nombre de produits par palette invalide) ... ";
	try
	{
		CMachine m4(2, 30, -5, destination);
	}
	catch(length_error e)
	{
		cout << "Test réussi" << endl;
	}
	catch(runtime_error e)
	{
		cout << "Test failed : runtime_error émis au lieu de length_error : " << e.what() << endl;
	}
	cout << endl;
	
	cout << "[*] Test des Getters" << endl;
	cout << "\t[*] Test de GetNbCateg ... ";
	if((*m1).GetNbCateg() == 2)
		cout << "Test réussi" << endl;
	else
		cout << "Test Failed : le nombre de catégorie n'est pas correct" << endl;
		
	cout << "\t[*] Test de GetNbTotalProd ... ";
	if((*m1).GetNbTotalProd() == 30)
		cout << "Test réussi" << endl;
	else
		cout << "Test failed : le nombre total de produit n'est pas correct" << endl;
		
	cout << "\t[*] Test de GetNbProdParPalette ... ";
	if((*m1).GetNbProdParPalette() == 15)
		cout << "Test réussi" << endl;
	else
		cout << "Test failed : le nombre de produit par palette n'est pas correct" << endl;
		
	cout << "\t[*] Test de GetNbTotalPal ... ";
	if((*m1).GetNbTotalPal() == 2)
		cout << "Test réussi" << endl;
	else
		cout << "Test failed : le nombre total de palette n'est pas correct" << endl;
		
	cout << "\t[*] Test de GetNbPalProduites ... ";
	if((*m1).GetNbPalProduites() == 0)
		cout << "Test réussi" << endl;
	else
		cout << "Test failed : le nombre de palette produite n'est pas correct" << endl;
}
