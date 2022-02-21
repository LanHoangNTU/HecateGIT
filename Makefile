all:
	g++ -Isrc/Include -Lsrc/lib -o HecateGIT main.cpp -lmingw32 -lSDL2main -lSDL2