#ifndef IMAGEM_H
#define IMAGEM_H

typedef struct{

	unsigned short int bfType; //caracteres BM
	unsigned long int  bfSize; //tamanho do arquivo em bytes
	unsigned short int bfReserved1; //reservado
	unsigned short int bfReserved2; //reservado
	unsigned long int brOffbits; 

} BMPFileHeader;

typedef struct{

	unsigned long int biSize; //espaço em bytes ocupado pela estrutura de dados(40 bytes)
	unsigned long int biWidth; //Largura da imagem
	unsigned long int biHeight; //Altura da imagem
	unsigned short int biPlanes; //numero de planos
	unsigned short int biBitCount; //numero de bits por pixel
	unsigned long int biCompression; //tipo de compressão
	unsigned long int biSizeImage; //tamanho em bytes
	unsigned long int biXPelsPerMeter; //resolução horizontal
	unsigned long int biYPelsPerMeter; //resolução vertical
	unsigned long int biClrUsed; //numero de cores do mapa de cores
	unsigned long int biClrImportant; //numero de cores do mapa de cores consideradas importantes

} BMPInfoHeader;



typedef struct{
  
  char tipo[2];
  int width, height; //altura e largura
  int RGB; //escala
  unsigned char *pixel; //vetor para os pixels alocado dinamicamente no imagem.c

} Imagem;

Imagem leitura(char *nomeArquivo); //funcao de leitura

#endif
