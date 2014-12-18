#!/bin/bash

mkdir bin

make || exit 1

for i in testCProduit testCPalette testCMachine testTri; do
	make $i || exit 1
done
