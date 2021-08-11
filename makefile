.DEFAULT_GOAL := check


clean: 
	rm -rf build/*.o
	rm -rf build/*.a

build:
	mkdir build


remove : dataBase/testDataBase/emptyFileRestaurateur.csv dataBase/testDataBase/emptyFileMenu.csv dataBase/testDataBase/emptyFileLivreur.csv dataBase/testDataBase/emptyFileClient.csv
	rm -rf dataBase/testDataBase/emptyFile*.csv
	touch dataBase/testDataBase/emptyFileRestaurateur.csv
	touch dataBase/testDataBase/emptyFileLivreur.csv
	touch dataBase/testDataBase/emptyFileClient.csv
	touch dataBase/testDataBase/emptyFileMenu.csv


build/client.o: lib/client.c lib/client.h | build
	gcc -c lib/client.c  -o build/client.o 

build/restaurateur.o: lib/restaurateur.c lib/restaurateur.h | build
	gcc -c lib/restaurateur.c  -o build/restaurateur.o 

build/livreur.o: lib/livreur.c lib/livreur.h | build
	gcc -c lib/livreur.c  -o build/livreur.o 

build/menu.o: lib/menu.c lib/menu.h | build
	gcc -c lib/menu.c  -o build/menu.o 


build/libluminyEat.a: lib/luminyEat.h build/client.o build/livreur.o build/restaurateur.o build/menu.o  | build
	ar crs build/libluminyEat.a build/client.o build/livreur.o build/restaurateur.o build/menu.o




build/test.o: test/test.c  | build
	gcc -Wall -Wno-macro-redefined -pedantic --debug -c test/test.c  -o build/test.o 

# test: build/test.o build/client.o build/restaurateur.o build/livreur.o  build/menu.o | build 
# 	gcc -o test build/test.o build/client.o  build/restaurateur.o build/livreur.o  build/menu.o


build/test: build/test.o build/libluminyEat.a  | build 
	gcc build/test.o -Lbuild -lluminyEat -o build/test


# Lance le programme de test.
check: build/test  remove | build
	./build/test


# main: build/main.o build/client.o build/restaurateur.o  build/livreur.o build/menu.o | build
# 	gcc -o main build/client.o build/restaurateur.o  build/livreur.o build/menu.o build/main.o


build/main: build/main.o build/libluminyEat.a | build
	gcc build/main.o -Lbuild -lluminyEat -o build/main 



	
build/main.o: main.c | build
	gcc -Wall -Wno-macro-redefined -pedantic --debug -c main.c  -o build/main.o 

lance : build/main | build
	./build/main

	

	
