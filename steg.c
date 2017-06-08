#include <stdio.h>
#include <string.h>
#include "imagem.h"

int main(){

  char file[100];
  char *img_type; //variavel para armazenar retorno da funcão de leitura

  Imagem img;
  FILE *arquivo = fopen("teste.txt", "w");

  printf("Nome do arquivo: "); //solicita entrada do nome do arquivo
  scanf("%s", file);
  printf("%s\n", file);

  img = leitura(file);

  fwrite(img.pixel, sizeof(unsigned char), 3*img.width*img.height, arquivo);

  return 0;
}
