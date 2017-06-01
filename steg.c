#include <stdio.h>
#include <string.h>
#include "imagem.h"

int main(){

  char file[100];
  Imagem img;

  printf("Nome do arquivo: "); //solicita entrada do nome do arquivo
  scanf("%s", file);
  printf("%s\n", file);
  img = leitura(file); //atribui o retorno da funcao de leitura para o struct do main

  return 0;
}
