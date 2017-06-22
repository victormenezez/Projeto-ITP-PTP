#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "imagem.h"

int main(int argc, char *argv[]){

	// char file[100], file2[100];

	// Imagem img;

	// printf("Nome da imagem: "); //solicita entrada do nome do arquivo
	// scanf("%s", file);
	// printf("Nome do arquivo com mensagem: "); //solicita entrada do nome do arquivo
	// scanf("%s", file2);

	// img = leitura(file);

	// gravar("testedeleitura.txt", img);


	//printf("%d %d %d %d\n", img.pixel[0], img.pixel[1], img.pixel[2], img.pixel[3]);
	  
	char *imagem, *mensagem;

	if(argc < 5){
		printf("Número de argumentos inválido. Verifique.\n");
	} else {
		if(strcmp(argv[1], "-e") == 0){
			usleep(500000);
			printf("MODO CODIFICADOR\n");
			if(strcmp(argv[2], "-i") == 0){
				mensagem = argv[3];
				imagem = argv[4];
				codificar(imagem, mensagem);
			} else {
				printf("Agumentos inválidos. Verifique.\n");
			}
		} else if(strcmp(argv[1], "-d") == 0){
			printf("MODO DECODIFICADOR\n");
		}

	}
	return 0;
}
