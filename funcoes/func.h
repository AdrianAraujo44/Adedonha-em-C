#ifndef FUNCOES
#define FUNCOES

struct jogadores {  
    char nome[12];
    int pontos[6];
    int totalscore;
    int tempo;
};


struct categoria categorias(int passada);

int *  sortearOrdemJogador(struct jogadores jogador[] ,int n, int *ordemAnterior);

int *criar_vetor(int n);

void respoder(struct jogadores jogador[],int *ordem, char letra, int n, char categoria[30], char **todasRespostas);

void pontuarJogadores(struct jogadores jogador[], char **todasRespostas, int n, int rodada);

char ** criaVetorString(int n);
void mostrarTabela(struct jogadores jogador[], int n, int rodada, char **titulosColunas);

#endif