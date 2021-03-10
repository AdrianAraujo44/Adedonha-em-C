#include "./funcoes/func.h"

char sortear_letra () {
  char letras[] = "ABCDEFGHIJLMNOPQRSTUVXZ";
  
  // srand(time(NULL));
  int random = rand() % (23);

  return letras[random];
};

char **criaVetorString(int n){
  char **letras_usadas;
    
    letras_usadas = (char **) malloc(n * sizeof(char *));
    for (int i =0; i < n ; i++) {
       letras_usadas[i] = (char *) malloc(30*sizeof(char));
    }
    return letras_usadas;
}
