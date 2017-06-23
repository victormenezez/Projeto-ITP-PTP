#ifndef IMAGEM_H
#define IMAGEM_H

typedef struct{
  
  char tipo[2];
  int width, height; //altura e largura
  int RGB; //escala
  unsigned char *pixel; //vetor para os pixels alocado dinamicamente no imagem.c

} Imagem;

Imagem leitura(char *nomeArquivo); //funcao de leitura

int *convertCharParaBinario(int indice); //retorna o binario de um char(8 bits)

int convertBinarioParaDecimal(int *indice); //retorna um inteiro decimal de um vetor inteiro de bits

int tamanhoMensagem(FILE *arquivo); //retorna um inteiro que indica o tamanho da mensagem em bytes

void criarImagemCodificada(Imagem img); //realiza a copia da imagem codificada

void codificarMensagem(FILE *arquivo, Imagem img); //realiza a codificacao da mensagem na imagem

int codificar(char *imagem, char *mensagem); //realiza a leitura e a codificacao da mensagem

void gravar(char *nomeArquivo, Imagem img); //grava os pixels e um novo arquivo(atualmente para testes)

void decodificarMensagem(Imagem img, char *saida); //decodifica a mensagem em uma imagem

int decodificarPPM(char *imagem, char *saida); //realiza a chamada da funcao de decodificacao

#endif
