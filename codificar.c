#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "imagem.h"

int tamanhoMensagem(FILE *arquivo){
	fseek(arquivo, 0, SEEK_END); //ponteiro para fim do arquivo
	int tamanho = ftell(arquivo); //posicao atual do ponteiro
	rewind(arquivo); //retorno para inicio do arquivo

	return tamanho;
}

int *convertCharParaBinario(int indice){
	int i = 7;
	int *binario = (int *)calloc(8, sizeof(int));
	if(binario == 0){
		fprintf(stderr, "Não foi possível alocar a memória para o inteiro com os bits\n");
		exit(1);
	}
	while(indice > 0){
		binario[i] = indice%2;
		indice = indice/2;
		i--;
	}

	return binario;
}

int convertBinarioParaDecimal(int *indice){
	int decimal = 0, i, j = 7;
	for(i = 0; i < 8; i++){
		decimal += indice[i] * pow(2, j);
		j--;
	}
	return decimal;
}

void criarImagemCodificada(Imagem img){
	FILE *copia_imagem_ppm;

	copia_imagem_ppm = fopen("copias/imagem-codificada.ppm", "w+");
	fprintf(copia_imagem_ppm, "P6\n");
	fprintf(copia_imagem_ppm, "%d %d\n", img.width, img.height);
	fprintf(copia_imagem_ppm, "255\n");
	fwrite(img.pixel, sizeof(unsigned char), 3*img.width*img.height, copia_imagem_ppm);
	fclose(copia_imagem_ppm);
}

void codificarMensagem(FILE *arquivo, Imagem img){
	int tamanho_mensagem = tamanhoMensagem(arquivo); //atribui o tamanho, em bytes, da mensagem
	int tamanho_imagem = 3 * img.width * img.height; //atribui o tamanho, em bytes, da imagem
	usleep(800000);
	printf("Sua mensagem possui %d bytes\nA imagem utilizada possui %d bytes\n\n", tamanho_mensagem, tamanho_imagem);

	if(tamanho_mensagem * 8 > tamanho_imagem){
		fprintf(stderr, "Não é possível inserir a mensagem na imagem.\nEncerrando o programa...\n");
		exit(1);
	} else {
		int caracteres_codificados = 0, contador = 0;
		int caractere_atual, i, j, k;

		while(caracteres_codificados < tamanho_mensagem){
			int *caractere_atual_binario = (int *)calloc(8, sizeof(int));
			caractere_atual = fgetc(arquivo); //pegando o caractere da mensagem
			
			if(caractere_atual == EOF) //se for o final do arquivo, atribui o valor 3(correspondente a EOF na tabela ascii)
				caractere_atual = 0;

			//converte o caractere atual para binario. Para fins de comparação
			caractere_atual_binario = convertCharParaBinario(caractere_atual);
			
			for(i = 0; i < 8; i++){
				//alocacao do pixel com 8 espacos
				int *pixel_binario = (int *)calloc(8, sizeof(int));
				//converte e atribui o vetor de inteiro com os "bits"
				pixel_binario = convertCharParaBinario(img.pixel[contador]);
				//se o valor for diferente, ele altera o LSB para o bit da mensagem
				if(pixel_binario[7] != caractere_atual_binario[i]){
					pixel_binario[7] = caractere_atual_binario[i];
					//inserindo novo valor do pixel 
					img.pixel[contador] = convertBinarioParaDecimal(pixel_binario);
				}
				free(pixel_binario);
				contador++;
			}
			free(caractere_atual_binario);
			caracteres_codificados++;
		}
		for(i = 0; i < 8; i++){
			int *pixel_binario = (int *)calloc(8, sizeof(int));
			pixel_binario = convertCharParaBinario(img.pixel[contador]);
			pixel_binario[7] = 0;
			img.pixel[contador] = convertBinarioParaDecimal(pixel_binario);
			free(pixel_binario);
			contador++;
		}
	}
	criarImagemCodificada(img);
}

int codificar(char *imagem, char *mensagem){
	FILE *arq_mensagem;
	arq_mensagem = fopen(mensagem, "rb");
	Imagem img;
	if(arq_mensagem == NULL){
		fprintf(stderr, "\nErro na abertura dos arquivos. Verifique se o nome/caminho está correto, ou se os arquivos correspondem aos requisitos.\n");
		exit(1);
	} else {
		img = leitura(imagem);
		codificarMensagem(arq_mensagem, img);
		gravar("testeleitura.txt", img);
	}
	usleep(500000);
	printf("Codificação realizada com sucesso. Verifique a imagem 'imagem-codificada.ppm' dentro da pasta 'copias'.\n");
	fclose(arq_mensagem);
	return 0;
}