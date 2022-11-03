test: main.c lib/matrix.h lib/libmatrix.a
	gcc -std=c2x -o build/test.exe main.c -L./lib -lmatrix -I"C:\\libs" -L"C:\\libs" -lvector

lib/matrix.h: matrix.h
	cp matrix.h lib/matrix.h

lib/libmatrix.a: matrix.c matrix.h
	gcc -std=c2x -c matrix.c -o bin/matrix.o -I"C:\\libs" -L"C:\\libs" -lvector
	ar rcs lib/libmatrix.a bin/matrix.o

install: lib/matrix.h lib/libmatrix.a
	cp lib/matrix.h "C:\\libs\\matrix.h"
	cp lib/libmatrix.a "C:\\libs\\libmatrix.a"
