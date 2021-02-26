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

int * sortearOrdemJogador(struct jogadores jogador[], int n) {
    int * array = (int *) calloc (n, sizeof (int));
    int result = 0;
    int cont = 0;
    int sorteado;
    srand( (unsigned)time(NULL) );
    printf("A ordem desta jogada será: \n");
    while(cont < n) {
        sorteado = rand() % 3;
        for(int i = 0; i < n ; i++) {
            if(array[i] == sorteado) {
                result = 1;
                printf(" %d. %s \n",cont + 1 , jogador[cont].nome);
            }
        }
        if(result) {
            array[cont] = sorteado;
        }
        cont ++;

        // if(array[0] != sorteado & array[1] != sorteado & array[2] != sorteado) {
        //     array[cont] = sorteado;
        //     printf(" %d. %s \n",cont + 1 , jogador[cont].nome);
        // }
        //  cont ++;
    }
    printf("---------------------------------------- \n");
    return array;
}