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
CM=CMachine
tCM=testCMachine
t=tri
k=CKeyboard

# Test de la classe CProduit
# Compilation du lanceur testCProduit, pour cela (l'ordre de compilation est important en C++) :
#	- supprimer le contenu du répertoire "./bin" et
#	- d'abord compiler CProduitBase
#	- ensuite compiler CProduit
#	- finalement compiler testCProduit

default: deleteAll compilCProduitBase compilCProduit compilCPalette

testCProduit: deleteAll compilCProduitBase compilCProduit compilTestCProduit

testCPalette: deleteAll compilCProduitBase compilCProduit compilCPalette compilTestCPalette

testCMachine: deleteAll compilCMachine compilTestCMachine

testTri: deleteAll compilCProduitBase compilCProduit compilCPalette compilCMachine compilCKeyboard compilTestTri

compilCProduitBase:
	@echo Compilation $(CPB)
	$(GPP) $(SRC)/$(CPB).cpp -o $(BIN)/$(CPB).o -c
	
compilCKeyboard:
	@echo Compilation $(k)
	$(GPP) $(SRC)/$(k).cpp -o $(BIN)/$(k).o -c

compilCProduit:
	@echo Compilation $(CP)
	$(GPP) $(SRC)/$(CP).cpp -o $(BIN)/$(CP).o -c

compilTestCProduit:
	@echo Compilation $(tCP)
	$(GPP) $(SRC)/$(tCP).cpp $(BIN)/$(CPB).o $(BIN)/$(CP).o -o $(BIN)/$(tCP).bin

compilCPalette:
	@echo Compilation $(CPa)
	$(GPP) $(SRC)/$(CPa).cpp -o $(BIN)/$(CPa).o -c

compilTestCPalette:
	@echo Compilation $(tCPa)
	$(GPP) $(SRC)/$(tCPa).cpp $(BIN)/$(CPa).o $(BIN)/$(CP).o $(BIN)/$(CPB).o -o $(BIN)/$(tCPa).bin

compilCMachine: compilCProduitBase compilCProduit compilCPalette
	@echo Compilation $(CM)
	$(GPP) $(SRC)/$(CM).cpp -o $(BIN)/$(CM).o -c

compilTestCMachine:
	@echo Compilation $(tCM)
	$(GPP) $(SRC)/$(tCM).cpp $(BIN)/$(CPa).o $(BIN)/$(CP).o $(BIN)/$(CPB).o $(BIN)/$(CM).o -o $(BIN)/$(tCM).bin

compilTestTri:
	@echo Compilation $(t)
	$(GPP) $(SRC)/$(t).cpp $(BIN)/$(CPa).o $(BIN)/$(CP).o $(BIN)/$(CPB).o $(BIN)/$(CM).o $(BIN)/$(k).o -o $(BIN)/$(t).bin

deleteAll :
	@echo suppression du contenu du repertoire ./bin
	rm -f $(BIN)/*
