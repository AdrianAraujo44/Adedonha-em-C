#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./funcoes/func.h"

int main (int nargs, char *argv[]) {
  char **letra = criaVetorString(10);
  bool b;
  char aux;
  int indice = 0;
  int i = 0;

  // int n; //representa o número de jogadores
  // char jogadores[10][12];
  // int ordemJogador = 0; // usado para ordenar o nome dos jogadores
  // printf("*** JOGO ADEDONHA *** \n");
  // printf("O número minimo de jogadores é 2 e o maximo é 10 \n");
  //   while( n > 10 || n < 2 ) {
  //     printf("Quantos Jogadores ? ");
  //     scanf("%d", &n);
  // }
  
  // while(ordemJogador < n) {
  //   printf("digite o nome do %d jogador: ", ordemJogador + 1);
  //   scanf("%s",jogadores[ordemJogador]);
  //   while (strlen(jogadores[ordemJogador]) > 12) {
  //     printf("Digite um nome com menos de 12 caracteres: ");
  //     scanf("%s",jogadores[ordemJogador]);
  //   }
  //   ordemJogador ++;
  // }

  srand(time(NULL));
  do {
    aux = sortear_letra();
    b = false;
    for (int j = 0; j < indice; j++) {
      if (aux == *letra[j]) {
        b = true;
      }
    }
  } while (b == true);

  *letra[indice] = aux;

  printf("%c\n", aux);

  indice++;

 


  return EXIT_SUCCESS;
}
