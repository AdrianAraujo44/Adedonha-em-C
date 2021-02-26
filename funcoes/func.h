#ifndef FUNCOES
#define FUNCOES

struct jogadores {  
    char nome[12];
    int pontos;
};


struct categoria categorias(int passada);
int * sortearOrdemJogador(struct jogadores jogador[] ,int n);

#endif