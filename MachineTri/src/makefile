# Makefile du projet "Machine de tri"

# Chaque classe du projet doit être testée séparément (3 au total).
# Il y aura donc un lanceur (main) par classe à tester.

# Ce makefile doit permettre de faire :
#	- la compilation du lanceur associé à chaque classe à tester
#	- la compilation du projet final (c-à-d tri.cpp)

# Déclaration de quelques variables utiles au makefile
GPP = g++ -Wall
SRC = ./src
BIN = ./bin

# Test de la classe CProduit
# Compilation du lanceur testCProduit, pour cela (l'ordre de compilation est important en C++) :
#	- supprimer le contenu du répertoire "./bin" et
#	- d'abord compiler CProduitBase
#	- ensuite compiler CProduit
#	- finalement compiler testCProduit

# La cible "testCProduit" est exécutée en tapant la commande "make testCProduit"
testCProduit : deleteAll compilCProduitBase compilCProduit compilTestCProduit

# La cible "compilCProduitBase" est exécutée en tapant la commande "make compilCProduitBase"
compilCProduitBase :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CProduitBase
	$(GPP) $(SRC)/CProduitBase.cpp -o $(BIN)/CProduitBase.o -c

# La cible "compilCProduit" est exécutée en tapant la commande "make compilCProduit"
compilCProduit :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CProduit
	$(GPP) $(SRC)/CProduit.cpp -o $(BIN)/CProduit.o -c

# La cible "testCProduit" est exécutée en tapant la commande "make compilTestCProduit"
compilTestCProduit :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation testCProduit
	$(GPP) $(SRC)/testCProduit.cpp $(BIN)/CProduitBase.o $(BIN)/CProduit.o -o $(BIN)/testCProduit.exe

# La cible "deleteAll" est exécutée en tapant la commande "make deleteAll"
deleteAll :
	@# Précéder chaque commande d'une TABULATION
	@echo suppression du contenu du repertoire ./bin
	rm -f $(BIN)/*
