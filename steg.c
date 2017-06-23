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
	  
	char *imagem, *mensagem, *saida;

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
			if(strcmp(argv[2], "-s") == 0){
				saida = argv[2];
				if(strcmp(argv[3], "-f") == 0){
					if(strcmp(argv[4], "ppm") == 0){
						imagem = argv[5];
						decodificarPPM(imagem, saida);
					} else if(strcmp(argv[4], "bmp") == 0){
						printf("DECODIFICADOR DE BMP\n");
						exit(1);
					}
				} else {
					printf("FORMATO DE IMAGEM NÃO INFORMADO!\n");
					exit(1);
				}
			} else if(strcmp(argv[2], "-o") == 0){
				if(strcmp(argv[4], "-f") == 0){
					saida = argv[3];
					if(strcmp(argv[5], "ppm") == 0){
						imagem = argv[6];
						decodificarPPM(imagem, saida);
					} else if(strcmp(argv[5], "bmp") == 0){
						printf("DECODIFICADOR DE BMP\n");
						exit(1);
					}
				} else {
					printf("FORMATO DE IMAGEM NÃO INFORMADO!\n");
					exit(1);
				}
			} else {
				printf("ARGUMENTOS INVÁLIDOS\n");
				exit(1);
			}
		} else {
			printf("ARGUMENTOS INVÁLIDOS\n");
			exit(1);
		}

	}
	return 0;
}
