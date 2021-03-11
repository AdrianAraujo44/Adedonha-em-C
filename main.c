#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h> 
#include "./funcoes/func.h"

struct categoria {
    char nome[30];
    int chave;
};

int main () {
    int rodadas = 5;
    int n, ordemJogador = 0; 
    struct jogadores jogadores[10];
    struct jogadores winner;
    char **respostas;
    char **titulosColunas;
    char **categ = criaVetorString(5);
    char **letra = criaVetorStringLetras(10);
    bool b;
    char aux;
    int indice = 0;

    categ[0] = "Nome de pessoas";
    categ[1] = "Nome de cidades";
    categ[2] = "Nome de animais";
    categ[3] = "Nome de comidas";
    categ[4] = "profissao";
    
    int caracteres;
    printf("*** JOGO ADEDONHA *** \n");
    printf("O número minimo de jogadores é 2 e o maximo é 10 \n");
    while( n > 10 || n < 2 ) {
        printf("Quantos Jogadores ? ");
        scanf("%d", &n);
    }
    for(int i = 0; i < n; i++){
      jogadores[i].totalscore = 0;
    }

    while(ordemJogador < n || caracteres > 12 ) {
          do{
            printf("digite o nome do %d jogador: ", ordemJogador + 1);
            scanf("%s",jogadores[ordemJogador].nome);
            caracteres = strlen(jogadores[ordemJogador].nome);
          }while(caracteres > 12);

        ordemJogador ++;
    }

    int cont = 0 ;
    int *ordem;
    ordem = criar_vetor(n);
    respostas = criaVetorString(n);
    titulosColunas = criaVetorString(6);

    for(int i =0; i < n ; i++) {
        ordem[i] = i;
    }
    struct categoria result;
    result.chave = 1;

    while(cont < rodadas) {
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
        indice++;
        printf("\n\nA letra da rodada é %c \n",aux);
        result = categorias(result.chave);
        titulosColunas[cont] = categ[result.chave];
        printf("\n");
        printf("--------------------------------------------\n");
        printf("A categoria desta rodada é: %s \n",result.nome);
        printf("A ordem desta jogada será: \n");
        ordem = sortearOrdemJogador(jogadores, n, ordem); 
        printf("--------------------------------------------\n");
        pedir_enter();
        printf("\33[H\33[2J");
        respoder(jogadores, ordem ,aux, n, result.nome, respostas);
        pontuarJogadores(jogadores, respostas, n, cont);
        mostrarTabela(jogadores, n, cont, titulosColunas);
        cont ++;
    }
    winner = vencedor(jogadores, n);
    printf("\n\nGanhador: %s\n", winner.nome);

return 0;
}
