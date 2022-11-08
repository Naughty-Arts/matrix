test: main.c lib/matrix.h
	gcc -std=c2x -o build/test.exe main.c -L./lib -I"C:\\libs" -L"C:\\libs"

lib/matrix.h: matrix.h
	cp matrix.h lib/matrix.h

install: lib/matrix.h
	cp lib/matrix.h "C:\\libs\\matrix.h"
