#include "./funcoes/func.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

// Estruturas 
struct categoria {
    char nome[30];
    int chave;
};

struct categoria categorias(int passada) {
    int sorteado = -1 ;
    char result[30];
    
    while(sorteado == -1 || sorteado == passada) {
        srand( (unsigned)time(NULL) );
        sorteado =  rand() % 5;
    }
    if (sorteado == 0) 
        strcpy(result,"Nome de pessoa");
    if (sorteado == 1)
        strcpy(result,"Nome de cidades");
    if (sorteado == 2)
        strcpy(result,"Nome de animais");
    if (sorteado == 3)
        strcpy(result,"Nome de comidas");
    if (sorteado == 4)
        strcpy(result,"profissão");

    struct categoria categoriaAtual ;
    categoriaAtual.chave = sorteado;
    strcpy(categoriaAtual.nome ,result);
    return categoriaAtual;
}

int *criar_vetor(int tamanho) { 
   (int *) malloc(tamanho*sizeof(int));
}

int *  sortearOrdemJogador(struct jogadores jogador[], int n, int *ordemAnterior) {
    int * array = (int *) calloc (n, sizeof (int));
    int i = 0;
    int condicao = 0;
    int sorteado;

    for(int c = 0; c<n ; c++) {
        array[c] = ordemAnterior[c];
    }
    //srand( (unsigned)time(NULL) );
    while(i<n) {
		sorteado = rand() % n;
		int temp = array[i];
		array[i] = array[sorteado];
		array[sorteado] = temp;
        for(int c = 0; c< n; c++) {
            if(array[c] == ordemAnterior[c]){
                condicao ++;
            }
        }
        if(condicao != n) 
            i++;

        condicao = 0;
	}
    for(int b = 0; b<n ;b++) {
        printf("%d. %s\n",b+1,jogador[array[b]].nome);
    }
    return array;
   
}