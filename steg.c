#include <stdio.h>
#include <string.h>
#include "imagem.h"

int main(){

  char file[100];
  Imagem img;

  printf("arquivo: ");
  scanf("%s", file);
  printf("%s\n", file);
  img = leitura(file);

  int i;
  
  return 0;
}
