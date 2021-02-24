#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./funcoes/func.h"

int main (int nargs, char *argv[]) {
  char *categorias[5];

  categorias[0] = "nomes de Pessoas";
  categorias[1] = "nomes de cidades";
  categorias[2] = "nomes de animais";
  categorias[3] = "nomes de comidas";
  categorias[4] = "profissoes";


  int n; //representa o número de jogadores
  char jogadores[10][12];
  int ordemJogador = 0; // usado para ordenar o nome dos jogadores
  printf("*** JOGO ADEDONHA *** \n");
  printf("O número minimo de jogadores é 2 e o maximo é 10 \n");
    while( n > 10 || n < 2 ) {
      printf("Quantos Jogadores ? ");
      scanf("%d", &n);
  }
  
  while(ordemJogador < n) {
    printf("digite o nome do %d jogador: ", ordemJogador + 1);
    scanf("%s",jogadores[ordemJogador]);
    while (strlen(jogadores[ordemJogador]) > 12) {
      printf("Digite um nome com menos de 12 caracteres: ");
      scanf("%s",jogadores[ordemJogador]);
    }
    ordemJogador ++;
  }
}
