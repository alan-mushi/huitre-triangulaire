# Makefile du projet "Machine de tri"

# Ce makefile doit permettre de faire :
#	- la compilation du lanceur associé à chaque classe à tester
#	- la compilation du projet final (c-à-d tri.cpp)

GPP=g++ -Wall -ggdb
SRC=./src
BIN=./bin
CP=CProduit
tCP=testCProduit
CPB=CProduitBase
CPa=CPalette
tCPa=testCPalette

# Test de la classe CProduit
# Compilation du lanceur testCProduit, pour cela (l'ordre de compilation est important en C++) :
#	- supprimer le contenu du répertoire "./bin" et
#	- d'abord compiler CProduitBase
#	- ensuite compiler CProduit
#	- finalement compiler testCProduit

default: deleteAll compilCProduitBase compilCProduit compilCPalette

testCProduit : deleteAll compilCProduitBase compilCProduit compilTestCProduit

testCPalette : deleteAll compilCProduitBase compilCProduit compilCPalette compilTestCPalette

compilCProduitBase :
	@echo Compilation $(CPB)
	$(GPP) $(SRC)/$(CPB).cpp -o $(BIN)/$(CPB).o -c

compilCProduit :
	@echo Compilation $(CP)
	$(GPP) $(SRC)/$(CP).cpp -o $(BIN)/$(CP).o -c

compilTestCProduit :
	@echo Compilation $(tCP)
	$(GPP) $(SRC)/$(tCP).cpp $(BIN)/$(CPB).o $(BIN)/$(CP).o -o $(BIN)/$(tCP).exe

compilCPalette:
	@echo Compilation $(CPa)
	$(GPP) $(SRC)/$(CPa).cpp -o $(BIN)/$(CPa).o -c

compilTestCPalette:
	@echo Compilation $(tCPa)
	$(GPP) $(SRC)/$(tCPa).cpp $(BIN)/$(CPa).o $(BIN)/$(CP).o $(BIN)/$(CPB).o -o $(BIN)/$(tCPa).bin

deleteAll :
	@echo suppression du contenu du repertoire ./bin
	rm -f $(BIN)/*
