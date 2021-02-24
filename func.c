#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./func.h"

int main (int nargs, char*argv[]) {
    char letras_usadas[23];
    int i = 1, j = 3;
    char indice_letras; // iterar sobre a lista de usadas
    int n = 0; //representa o número de jogadores
    char jogadores[10][12];
    int ordemJogador = 0; // usado para ordenar o nome dos jogadores
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
            scanf("%s",jogadores[ordemJogador]);
        //}
        ordemJogador ++;
    }
    
    
}