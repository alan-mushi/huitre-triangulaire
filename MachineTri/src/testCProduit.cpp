#include "CProduit.h"

int main()
{
	CProduit test;
	test.MakeCode(10, 2);
	cout << test << endl;
	
	cout << "Longueur" << test.getLong() << endl;
	cout << "Largeur" << test.getLarg() << endl;
	cout << "Hauteur" << test.getHaut() << endl;
	cout << "Catégorie" << test.getCateg() << endl;
	
	try 
	{
		test.setCateg(2);
		cout << "Test réussi : Définition d'une catégorie ok." << endl;
	}
	catch(range_error e)
	{
		cout << "Test failed :Définition d'une catégorie pas ok :" << e.what() << endl;
	}
	
	CProduit test2;
	
	try
	{
		test2.setCateg(602);
		cout << "Test failed : Borne non respectée" << endl;
	}
	catch(range_error e)
	{
		cout << "Test réussie" << endl;
	}
	
	try
	{
		test2.setCode("test");
	}
	catch(length_error e)
	{
		cout << "Test failed : " << e.what() << endl;
	}
	
	try
	{
		test2.setCode("");
	}
	catch(length_error e)
	{
		cout << "Test réussi" << endl;
	}
	
	cout << "Code " << test2.getCode() << endl;
}
