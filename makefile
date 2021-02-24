all: funcoes.o
	gcc func.o main.c -o main

funcoes.o: ./funcoes/func.h
	gcc -c func.c

clean:
	rm -rf *.o