#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./funcoes/func.h"

struct categoria {
    char nome[30];
    int chave;
};

void main () {
    int rodadas = 5;
    int n, ordemJogador = 0; 
    struct jogadores jogadores[10];
    
    printf("*** JOGO ADEDONHA *** \n");
    printf("O número minimo de jogadores é 2 e o maximo é 10 \n");
    while( n > 10 || n < 2 ) {
        printf("Quantos Jogadores ? ");
        scanf("%d", &n);
    }
    
    while(ordemJogador < n) {
        // int numerosJogadores = (int)strlen(jogadores[ordemJogador]);
        // while(numerosJogadores > 0 & numerosJogadores < 13) {
            printf("digite o nome do %d jogador: ", ordemJogador + 1);
            scanf("%s",jogadores[ordemJogador].nome);
        //}
        ordemJogador ++;
    }

    int cont = 0 ;
    int *ordem;
    ordem = criar_vetor(n);
    for(int i =0; i<n ; i++) {
        ordem[i] = i;
    }
    struct categoria result;
    result.chave = 1;
    while(cont < rodadas) {
        result = categorias(result.chave);
        printf("\n");
        printf("--------------------------------------------\n");
        printf("A categoria desta rodada é: %s \n",result.nome);
        ordem = sortearOrdemJogador(jogadores,n,ordem); 
        printf("--------------------------------------------\n");
        cont ++;
    }
}
