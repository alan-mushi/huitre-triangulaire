#include "CMachine.h"

int main()
{
	string* destination = new string[5];
	destination[0] = "Querrien";
	destination[1] = "Quimperlé";
	destination[2] = "Lorient";
	destination[3] = "Vannes";
	destination[4] = "Quiberon";
	
	try
	{
		CMachine m1(2, 30, 15, destination);
		cout << "Test réussi." << endl;
	}
	catch(length_error e)
	{
		cout << "Test failed : " << e.what() << endl;
	}
	catch(runtime_error e)
	{
		cout << "Test failed : " << e.what() << endl;
	}
	
	try
	{
		CMachine m2(-5, 10, 15, destination);
		cout << "Test failed : m2 a été créé..." << endl;
	}
	catch(length_error e)
	{
		cout << "Test réussi." << endl;
	}
	catch(runtime_error e)
	{
		cout << "Test failed : runtime_error émis au lieu de length_error : " << e.what() << endl;
	}
	
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
	
	if(m1.GetNbCateg() == 2)
		cout << "Test réussi" << endl;
	else
		cout << "Test Failed : le nombre de catégorie n'est pas correct" << endl;
		
	if(m1.GetNbTotalProd() == 30)
		cout << "Test réussi" << endl;
	else
		cout << "Test failed : le nombre total de produit n'est pas correct" << endl;
		
	if(m1.GetNbProdParPalette() == 15)
		cout << "Test réussi" << endl;
	else
		cout << "Test failed : le nombre de produit par palette n'est pas correct" << end;
		
	if(m1.GetNbTotalPal() == 2)
		cout << "Test réussi" << endl;
	else
		cout << "Test failed : le nombre total de palette n'est pas correct" << endl;
		
	if(m1.GetNbPalProduites() == 0)
		cout << "Test réussi" << endl;
	else
		cout << "Test failed : le nombre de palette produite n'est pas correct" << endl;
}
