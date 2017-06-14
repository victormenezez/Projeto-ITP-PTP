#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "imagem.h"

int main(){

  char file[100];

  Imagem img;

  printf("Nome do arquivo: "); //solicita entrada do nome do arquivo
  scanf("%s", file);

  img = leitura(file);

  gravar("asdasdasd.txt", img);

  printf("%d %d %d %d\n", img.pixel[0], img.pixel[1], img.pixel[2], img.pixel[3]);
  return 0;
}
