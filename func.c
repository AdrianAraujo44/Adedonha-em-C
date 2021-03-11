#include "./funcoes/func.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>  
#include <time.h> 
#include <ctype.h>
#include <math.h>

// Estruturas 
struct categoria {
    char nome[30];
    int chave;
};

//função categoria -> responsavel por retornar uma categoria nova diferente da categoria passada, passada em uma struct
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
        strcpy(result,"profissao");

    struct categoria categoriaAtual ;
    categoriaAtual.chave = sorteado;
    strcpy(categoriaAtual.nome ,result);
    return categoriaAtual;
}

int *criar_vetor(int tamanho) { 
   return (int *) malloc(tamanho*sizeof(int));
}

//sortear jogadores em sua ordem de resposta
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

void pontuarJogadores(struct jogadores jogador[], char **todasRespostas, int n, int rodada){

  float repeticoes;
    int ts;
    float pontuacao;

    for(int i = 0; i < n; i++){

      repeticoes = 0;

      for(int j = 0; j < n; j++){
        
          if( !(strcmp(todasRespostas[i], todasRespostas[j])) ){
            repeticoes++;
          }
       
      }
        
       ts = strlen(todasRespostas[i]);
       pontuacao = ts / repeticoes;
       jogador[i].pontos[rodada] = round(pontuacao);
       jogador[i].totalscore += round(pontuacao);
       jogador[i].pontos[rodada+1] = jogador[i].totalscore;
    }

}

char ** criaVetorString(int n){
  char **todasRespostas;
    
    todasRespostas = (char **) malloc(n * sizeof(char *));
    for (int i =0; i< n ; i++) {
       todasRespostas[i] = (char *) malloc(30*sizeof(char));
    }
    return todasRespostas;
}

void respoder(struct jogadores jogador[],int *ordem, char letra, int n, char categoria[30], char **todasRespostas) {
  
    int c = 0;
    int segundos = (8 + 2 * n);
    char respostaJogador[250];

    int tempo = 0;
    int condicao = 0;
    int rodou = 0 ;
    time_t Ticks[2];
    while(c < n) {

        if(rodou == 0) {
            Ticks[0] = time(NULL);
        }
        printf("\33[H\33[2J");
        printf("%s, '%s' com a letra '%c' em %d segundos:\n", jogador[ordem[c]].nome,categoria, letra, segundos);
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
                    //printf("tempo: %d \n",tempo);
                    jogador[ordem[c]].tempo = tempo;
                    strcpy(todasRespostas[c], respostaJogador);
                }else {
                    printf("Passou do tempo\n");
                    strcpy(todasRespostas[c],"");
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
        printf("resposta de %s : %s \n", jogador[i].nome,todasRespostas[i]);
    }
}
 
void mostrarTabela(struct jogadores jogador[], int n, int rodada, char **titulosColunas){
  int beauty;
  int k;
  int pontos;
  char* ponts;
  
  printf("\n\n");
  
  printf("|JOGADORES |");
  
  if(rodada == 5)
  titulosColunas[rodada+1] = "Total final";
  else
  titulosColunas[rodada+1] = "Total parcial";
  for(k = 0; k <= rodada+1; k++){
    printf("%s|", titulosColunas[k]);
  }

  for(int i = 0;  i < n; i++){

    printf("\n|%s", jogador[i].nome);
  
    beauty = 10 - strlen(jogador[i].nome);
    for(k = 1; k <= beauty; k++)
    printf(" ");
    printf(":");

    for(int j = 0; j <= rodada+1; j++) {
        pontos = jogador[i].pontos[j];

        if(pontos == 0)
        beauty = strlen(titulosColunas[j]) - 1;
        else
        beauty = strlen(titulosColunas[j]) - floor(log10(pontos)) -1;

      for(k = 1; k <= beauty; k++)
        printf(" ");
        
      printf("%d",  jogador[i].pontos[j]);
      
       printf("|");
    }
    
  }
}

char sortear_letra () {
  char letras[] = "ABCDEFGHIJLMNOPQRSTUVXZ";
  int random = rand() % (23);

  return letras[random];
};

int pedir_enter() {
  char ch;

	while(1){
        getchar();
		printf("Digite [ enter ] para começar: \n");
		ch=fgetc(stdin);
		
		if(ch==0x0A){
			break;
		}
    while(getchar() != '\n'); 
  
	}
	return 0;
}

char **criaVetorStringLetras(int n){
  char **letras_usadas;
    
    letras_usadas = (char **) malloc(n * sizeof(char *));
    for (int i =0; i < n ; i++) {
       letras_usadas[i] = (char *) malloc(30*sizeof(char));
    }
    return letras_usadas;
}

struct jogadores vencedor(struct jogadores jogador[], int n){

    int pontuacao;
    int i;
    
    int maior = jogador[0].totalscore - jogador[0].tempo;
    int ganhador = 0;

    for(i = 1; i < n; i++){
     pontuacao = jogador[i].totalscore - jogador[i].tempo;
      if(pontuacao > maior){
      maior = pontuacao;
      ganhador = i;
      }
    }

  return jogador[ganhador];
  }