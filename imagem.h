#ifndef IMAGEM_H
#define IMAGEM_H

typedef struct{
  
  char tipo[2];
  int width, height; //altura e largura
  int RGB; //escala
  unsigned char *pixel;

} Imagem;

Imagem leitura(char *nomeArquivo);

#endif
