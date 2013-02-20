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
	
	cout << "\t[*] Test de GetNumPalEnCour ... ";
	if((*m1).GetNumPalEnCour() == 0)
		cout << "Test réussi" << endl;
	else
		cout << "Test failed : le numéro de la palette en cours n'est pas correct" << endl;
		
	cout << "\t[*] Test de GetNbProd ... ";
	try
	{
		if((*m1).GetNbProd(1) == 1 || (*m1).GetNbProd(1) == 0)
			cout << "Test réussi" << endl;
		else
			cout << "Test failed : le nombre de produit n'est pas correct dans la 1ere catégorie" << endl;
	}
	catch(length_error e)
	{
		cout << "Test failed : borne non respectée : " << e.what() << endl;
	}
		
	cout << "\t[*] Test de GetPalette ... ";
	try
	{
		if((*m1).GetPalette(1) != NULL)
			cout << "Test réussi" << endl;
		else
			cout << "Test failed : la méthode a renvoyé NULL" << endl;
	}
	catch(length_error e)
	{
		cout << "Test failed : borne non respectée : " << e.what() << endl;
	}
	
	cout << "\t[*] Test de GetPaletteEnCour ... ";
	if((*m1).GetPaletteEnCour() != NULL)
		cout << "Test réussi" << endl;
	else
		cout << "Test failed : la palette en cour vaut NULL" << endl;
		
	cout << "\t[*] Test de GetProduitEnCour ... ";
	try
	{
		CProduit* prod = (*m1).GetProduitEnCour();
		cout << "Test failed : un produit est en cours alors qu'il ne devrait pas y en avoir : " << prod << endl;
	}
	catch(runtime_error e)
	{
		cout << "Test réussi" << endl;
	}
	
	(*m1).SetMarche(true);
	cout << "[*] Insertion d'un produit : test de InsertNewProduit ... ";
	if((*m1).InsertNewProduit())
		cout << "Test réussi" << endl;
	else
		cout << "Test failed : la machine n'est pas en fonctionnement" << endl;
		
	cout << "[*] Test de Process ... ";
	if((*m1).Process())
		cout << "Test réussi" << endl;
	else
		cout << "Test failed : l'assignation d'une catégorie a échouée" << endl;
		
	cout << "[*] Test de EjectionProduit ... ";
	if((*m1).EjectionProduit())
		cout << "Test réussi" << endl;
	else
		cout << "Test failed : le produit en cour n'a pas été éjecté" << endl;
		
	cout << "[*] Test de MarquageProduit ... ";
	if((*m1).MarquageProduit())
	cout << "Test réussi" << endl;
	else
		cout << "Test failed : le marquage n'a pas été fait." << endl;
		
	cout << "[*] Test de AjoutPalette ... ";
	try
	{
		if((*m1).AjoutPalette())
			cout << "Test réussi" << endl;
		else
			cout << "Test failed : La palette n'a pas été ajoutée" << endl;
	}
	catch(invalid_argument e)
	{
		cout << "Test failed : " << e.what() << endl;
	}
	catch(range_error e)
	{
		cout << "Test failed : " << e.what() << endl;
	}
	
	(*m1).Affiche();
}
