#include "./funcoes/func.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

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

void respoder(struct jogadores jogador[],int *ordem, char letra, int n, char categoria[30]) {
    int c = 0;
    int segundos = (8 + 2 * n);
    char respostaJogador[250];
    char **todasRespostas;
    
    todasRespostas = (char **) malloc(n * sizeof(char *));
    for (int i =0; i< n ; i++) {
       todasRespostas[i] = (char *) malloc(30*sizeof(char));
    }

    int tempo = 0;
    int condicao = 0;
    int rodou = 0 ;
    time_t Ticks[2];
    while(c < n) {
        if(rodou == 0) {
            Ticks[0] = time(NULL);
        }
        printf("%s, você deve entrar um '%s' com a letra '%c' em %d segundos:\n", jogador[ordem[c]].nome,categoria,letra,segundos);
        scanf(" %s", respostaJogador);

        for(int i=0; i<strlen(respostaJogador); i++) {
            respostaJogador[i] = toupper (respostaJogador[i]); 
        }

        if( strlen(respostaJogador) <= 30) {
            if(respostaJogador[0] != letra){
                condicao = 1;
                rodou = 1;
            }
            if(condicao == 0) {
                Ticks[1] = time(NULL);
                tempo = tempo + difftime(Ticks[1], Ticks[0]);
                if(tempo <= segundos) {
                    printf("tempo: %d \n",tempo);
                    jogador[ordem[c]].tempo = tempo;
                    strcpy(todasRespostas[c],respostaJogador);
                }else {
                    printf("Passou do tempo %d \n",tempo);
                    strcpy(todasRespostas[c]," ");
                }
                c++;
                rodou = 0;
                segundos = segundos - 2;
                tempo = 0;
            }
            condicao = 0;
        }else{
            rodou = 1;
        }
    }
    for(int i = 0; i < n ; i++) {
        printf("respostas %s \n", todasRespostas[i]);
    }// aqui vem uma função para pontuar os jogadores
}