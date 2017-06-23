#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "imagem.h"

void decodificarMensagem(Imagem img, char *saida){
	//int tamanho_mensagem = tamanhoMensagem(arquivo); //atribui o tamanho, em bytes, da mensagem
	//int tamanho_imagem = 3 * img.width * img.height; //atribui o tamanho, em bytes, da imagem
	usleep(800000);
	printf("Decodificando sua mensagem...\n\n");

	int *byte_atual_binario; //vetor que armazenara uma lista de inteiros 0 ou 1 representando o byte atual do vetor pixel
	int *caractere_atual_binario; //vetor que armazenará os 8 LSB dos bytes do vetor pixel(tem novo valor a cada 8 interacoes)
	int caractere_atual_decimal, byte_atual = 0, contador = 0, i; //armazena o valor do vetor pixel

	FILE *arquivo;

	printf("%s\n", saida);
	if(strcmp(saida, "-s") == 0){
		printf("Mensagem decodificada: %s\n", saida);
	} else {
		printf("Verifique o arquivo %s e veja a mensagem codificada na imagem.\n", saida);
		arquivo = fopen(saida, "w+");
	}

	while(byte_atual != 3){
		caractere_atual_binario = (int *)calloc(8, sizeof(int)); 
		
		for(i = 0; i < 8; i++){
			byte_atual_binario = (int *)calloc(8, sizeof(int)); 
			byte_atual_binario = convertCharParaBinario(img.pixel[contador]);
			
			caractere_atual_binario[i] = byte_atual_binario[7];

			contador++;
			free(byte_atual_binario);
		}

		caractere_atual_decimal = convertBinarioParaDecimal(caractere_atual_binario);
		byte_atual = caractere_atual_decimal;

		if(byte_atual != 3){
			if(strcmp(saida, "-s") == 0){
				printf("%c", caractere_atual_decimal);
			} else {
				fputc(caractere_atual_decimal, arquivo);
			}
		}
		free(caractere_atual_binario);
	}
}

int decodificarPPM(char *imagem, char *saida){
	// FILE *arq_imagem;
	// arq_imagem = fopen(imagem, "rb");
	Imagem img;
	// if(arq_mensagem == NULL){
	// 	printf("\nErro na abertura dos arquivos. Verifique se o nome está correto, ou se os arquivos correspondem aos requisitos.\n");
	// 	exit(1);
	// } else {
		img = leitura(imagem);
		decodificarMensagem(img, saida);
		gravar("testeleitura.txt", img);
	// }
	return 0;
}