#include "./funcoes/func.h"

char sortear_letra () {
  char letras[] = "ABCDEFGHIJLMNOPQRSTUVXZ";
  
  // srand(time(NULL));
  int random = rand() % (23);

  return letras[random];
};

int pedir_enter() {
  char ch;

	while(1)
	{
		printf("Digite [ enter ] para começar: ");
		ch=fgetc(stdin);
		
		if(ch==0x0A)
		{
			break;
		}
    while(getchar() != '\n'); 
  
	}
	return 0;
}

char **criaVetorString(int n){
  char **letras_usadas;
    
    letras_usadas = (char **) malloc(n * sizeof(char *));
    for (int i =0; i < n ; i++) {
       letras_usadas[i] = (char *) malloc(30*sizeof(char));
    }
    return letras_usadas;
}
