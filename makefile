all: funcoes.o
	gcc func.o main.c -o main -lm

funcoes.o: ./funcoes/func.h
	gcc -c func.c

clean:
	rm -rf *.o