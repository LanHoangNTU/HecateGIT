all:
	g++ -Isrc/include -Lsrc/lib -o HecateGIT main.cpp src/hecate/**/*.cpp -lmingw32 -lSDL2main -lSDL2