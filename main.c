#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./funcoes/func.h"

void main () {
    int n, ordemJogador = 0; 
    struct jogadores {  
        char nome[12];
        int pontos;
    };
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
}
