#include "./funcoes/func.h"

char sortear_letra () {
  char letras[] = "ABCDEFGHIJLMNOPQRSTUVXZ";
  
  srand(time(NULL));
  int random = rand() % (23);

  return letras[random];
};

char pedir_enter() {
  char enter;

  printf("Digite [ Enter ] para iniciar a rodada: ");
  scanf("%c", &enter);

  return enter;
}

void limpar_tela() {
  system("clear"); // linux
}