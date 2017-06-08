#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagem.h"

Imagem leitura(char *nomeArquivo){

  FILE *arq;
  Imagem img;
  unsigned char file_tipo[2];

  arq = fopen(nomeArquivo, "r");

  if(!arq)
    printf("Não foi possivel abrir o arquivo %s  \n", nomeArquivo);
  else{
    fscanf(arq, "%2s", file_tipo);
    file_tipo[2] = '\0';
    printf("%s\n", file_tipo);


    if(strcmp(file_tipo, "P6") == 0){
      
      printf("===== Imagem PPM P6 =====\n");
      Imagem img; //declaracao da struct de retorno
      strcpy(img.tipo, file_tipo);
      fscanf(arq, "%d %d %d", &img.width, &img.height, &img.RGB); //leitura das informacoes do cabecalho
      img.pixel = malloc(sizeof(unsigned char)*(3 * img.width * img.height)); //alocacao dos pixels

      fread(img.pixel, sizeof(unsigned char), 3 * img.width * img.height, arq); //leitura e armazenamento no vetor PIXEL
      printf("Tipo: %s / Altura: %d / Largura: %d / Escala: %d\n", img.tipo, img.width, img.height, img.RGB); //teste de confirmacao para leitura do cabecalho   
    
    }else if(strcmp(file_tipo, "BM") == 0){

      printf("==== Imagem BMP ====\n");
      int i, j;
      unsigned int offset; //variável para armazenar o offset
      fseek(arq, 10, SEEK_SET); //fseek para o offset
      fread(&offset, sizeof(int), 1, arq); //armazena offset na variavel local
      fseek(arq, 18, SEEK_SET); //fseek para largura da imagem
      fread(&img.width, sizeof(int), 1, arq); //armazena largura
      fread(&img.height, sizeof(int), 1, arq); //armazena altura
      printf("%d\n", img.width);
      printf("%d\n", img.height);
      fseek(arq, offset, SEEK_SET); //fseek para pixels da imagem

      img.pixel = malloc(sizeof(unsigned char)*(3 * img.width * img.height)); //alocacao dos pixels

      if((img.width*3) %4 == 0)
        fread(img.pixel, sizeof(unsigned char), 3 * img.width * img.height, arq); //leitura e armazenamento no vetor PIXEL
      else{
        for(i = 0; i < img.height; i++){
          for(j = 0; j < img.width*3; j++){
            fread(&img.pixel[i+j], sizeof(unsigned char), 1, arq);
          }
        }
      }
    }
  }

  fclose(arq);
  return img;
}
