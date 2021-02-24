#include "./funcoes/func.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char sortear_letra() {
  // srand(time(NULL));
  char letra = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 26];
  return letra;
}