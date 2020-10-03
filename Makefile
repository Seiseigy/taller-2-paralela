CXX = g++
CXXFLAGS = -g3 -Wall
MKDIR = mkdir -p

LIBS = -lm

clean:
	rm -fr *.o a.out core programa dist build

directorios:
	$(MKDIR) build dist

producto.o: directorios src/producto.cpp include/producto.h
	$(CXX) $(CXXFLAGS) -c src/producto.cpp -o build/producto.o

funciones.o: directorios src/funciones.cpp
	$(CXX) $(CXXFLAGS) -c src/funciones.cpp -o build/funciones.o

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

all: clean main.o funciones.o producto.o
	$(CXX) $(CXXFLAGS) -o dist/programa build/main.o build/producto.o build/funciones.o $(LIBS)
	rm -fr build

clean:
	rm -fr *.o a.out core dist build

.DEFAULT_GOAL := all