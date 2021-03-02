#ifndef FUNCOES
#define FUNCOES

struct jogadores {  
    char nome[12];
    int pontos;
    int tempo;
};


struct categoria categorias(int passada);
int *  sortearOrdemJogador(struct jogadores jogador[] ,int n, int *ordemAnterior);
int *criar_vetor(int n);
void respoder(struct jogadores jogador[],int *ordem, char letra, int n, char categoria[30]);
#endif