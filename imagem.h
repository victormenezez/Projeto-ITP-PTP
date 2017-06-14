#ifndef IMAGEM_H
#define IMAGEM_H

typedef struct{
  
  char tipo[2];
  int width, height; //altura e largura
  int RGB; //escala
  unsigned char *pixel; //vetor para os pixels alocado dinamicamente no imagem.c

} Imagem;

Imagem leitura(char *nomeArquivo); //funcao de leitura

void gravar(char *nomeArquivo, Imagem img);

#endif
