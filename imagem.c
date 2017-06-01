#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagem.h"

Imagem leitura(char *nomeArquivo){

  FILE *arq;
  Imagem img;

  arq = fopen(nomeArquivo, "r");

  if(!arq)
    printf("Não foi possivel abrir o arquivo %s  \n", nomeArquivo);
  else{
    fscanf(arq, "%s %d %d %d", img.tipo, &img.width, &img.height, &img.RGB);
    img.pixel = malloc(sizeof(unsigned char)*(3 * img.width * img.height)); //alocacao dos pixels
    fread(img.pixel, sizeof(unsigned char), 3 * img.width * img.height, arq); //leitura e armazenamento no vetor PIXEL
    printf("Tipo: %s / Altura: %d / Largura: %d / Escala: %d\n", img.tipo, img.width, img.height, img.RGB); //teste de confirmacao para leitura do cabecalho
  }

  fclose(arq);
  return img;
}
