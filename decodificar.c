#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "imagem.h"

void decodificarMensagem(Imagem img, char *saida){
	usleep(800000);
	printf("Decodificando sua mensagem...\n\n");

	int *byte_atual_binario; //vetor que armazenara uma lista de inteiros 0 ou 1 representando o byte atual do vetor pixel
	int *caractere_atual_binario; //vetor que armazenará os 8 LSB dos bytes do vetor pixel(tem novo valor a cada 8 interacoes)
	int caractere_atual_decimal, byte_atual = 1, contador = 0, i; //armazena o valor do vetor pixel

	FILE *arquivo;

	if(strcmp(saida, "-s") == 0){
		printf("Verifique a sua mensagem decodificada:\n\n");
	} else {
		printf("Verifique o arquivo %s e veja a mensagem codificada na imagem.\n", saida);
		arquivo = fopen(saida, "w+");
	}

	while(byte_atual != 0){
		caractere_atual_binario = (int *)calloc(8, sizeof(int));
		
		for(i = 0; i < 8; i++){
			byte_atual_binario = (int *)calloc(8, sizeof(int)); 
			//byte atual do vetor de pixel na posicao 'contador' que sera incrementada a cada laco do for
			byte_atual_binario = convertCharParaBinario(img.pixel[contador]);
			//atribui o LSB do byte atual ao caractere. serao 8 interacoes para criar 1 byte(1 caractere)
			caractere_atual_binario[i] = byte_atual_binario[7];

			contador++;
			free(byte_atual_binario);
		}
		//converte o caractere_atual_binario para decimal, assim teremos um valor utilizavel
		caractere_atual_decimal = convertBinarioParaDecimal(caractere_atual_binario);
		/*
		Atribui o valor do caractere_atual_decimal para o byte_atual.
		Essa atribuicao eh feita para que o while pare quando for encontrado um decimal igual a 0.
		Isso significa o fim da mensagem.
		*/
		byte_atual = caractere_atual_decimal;

		if(byte_atual != 0){
			if(strcmp(saida, "-s") == 0){
				//se a saida for a padrao, imprime na tela(ja convertido)
				printf("%c", caractere_atual_decimal);
			} else {
				//senao, imprime no arquivo
				fputc(caractere_atual_decimal, arquivo);
			}
		}
		free(caractere_atual_binario);
	}
	printf("\n");
}

int decodificar(char *imagem, char *saida){
	Imagem img;
	img = leitura(imagem);
	decodificarMensagem(img, saida);
	//gravar("testeleitura.txt", img);
	return 0;
}