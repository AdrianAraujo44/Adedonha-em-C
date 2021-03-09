#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./funcoes/func.h"

struct categoria {
    char nome[30];
    int chave;
};

int main () {
    int rodadas = 5;
    int n, ordemJogador = 0; 
    struct jogadores jogadores[10];
    char **respostas;
    char **titulosColunas;
    char **categ = criaVetorString(5);

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
        // int numerosJogadores = (int)strlen(jogadores[ordemJogador]);
        // while(numerosJogadores > 0 & numerosJogadores < 13) {
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
        result = categorias(result.chave);
        titulosColunas[cont] = categ[result.chave];
        printf("\n");
        printf("--------------------------------------------\n");
        printf("A categoria desta rodada é: %s \n",result.nome);
        printf("A ordem desta jogada será: \n");
        ordem = sortearOrdemJogador(jogadores, n, ordem); 
        printf("--------------------------------------------\n");
        respoder(jogadores, ordem ,'A', n, result.nome, respostas);
        pontuarJogadores(jogadores, respostas, n, cont);
        mostrarTabela(jogadores, n, cont, titulosColunas);
        cont ++;
    }

return 0;
}
