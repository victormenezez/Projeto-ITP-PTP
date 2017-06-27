#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "imagem.h"

int main(int argc, char *argv[]){
	char *imagem, *mensagem, *saida, c;

	int eflag = 0;
	int iflag = 0;
	int dflag = 0;
	int sflag = 0;
	int oflag = 0;


	while ((c = getopt (argc, argv, "ei:dso:")) != -1){
	    switch (c){
	    	case 'e':
	      		eflag = 1;
	        	break;
	      	case 'i':
	        	iflag = 1;
	        	if(eflag)
	        		mensagem = optarg;
	        	else if(dflag)
	        		imagem = optarg;
	        	break;
	      	case 'd':
	      		dflag = 1;
	        	break;
	      	case 's':
	      		sflag = 1;
	      		saida = "-s";
	        	break;
	        case 'o':
	        	oflag = 1;
	        	saida = optarg;
	        	break;
		    // case '?':
		    //     if (optopt == 'c')
		    //     	fprintf (stderr, "Option -%c requires an argument.\n", optopt);
		    //     else if (isprint (optopt))
		    //     	fprintf (stderr, "Unknown option `-%c'.\n", optopt);
		    //     else
		    //     	fprintf (stderr,
		    //                "Unknown option character `\\x%x'.\n",
		    //                optopt);
	     	//    	return 1;
	    	default:
	    		abort ();
    	}
  	}


	// if(argc < 4){
	// 	printf("Número de argumentos inválido. Verifique.\n");
	// } else {
	// 	if(strcmp(argv[1], "-e") == 0){
	// 		usleep(500000);
	// 		printf("MODO CODIFICADOR\n");
	// 		if(strcmp(argv[2], "-i") == 0){
	// 			mensagem = argv[3];
	// 			imagem = argv[4];
	// 			codificar(imagem, mensagem);
	// 		} else {
	// 			printf("Argumentos inválidos. Verifique.\n");
	// 		}
	// 	} else if(strcmp(argv[1], "-d") == 0){
	// 		printf("MODO DECODIFICADOR\n");
	// 		if(strcmp(argv[2], "-s") == 0){
	// 			saida = argv[2];
	// 			if(strcmp(argv[3], "-f") == 0){
	// 				imagem = argv[5];
	// 			} else {
	// 				imagem = argv[3];
	// 			}
	// 			decodificar(imagem, saida);
	// 		} else if(strcmp(argv[2], "-o") == 0){
	// 			saida = argv[3];
	// 			if(strcmp(argv[4], "-f") == 0){
	// 				imagem = argv[6];
	// 			} else {
	// 				imagem = argv[4];
	// 			}
	// 			decodificar(imagem, saida);
	// 		} else {
	// 			printf("ARGUMENTOS INVÁLIDOS\n");
	// 			exit(1);
	// 		}
	// 	} else {
	// 		printf("ARGUMENTOS INVÁLIDOS\n");
	// 		exit(1);
	// 	}

	// }
	return 0;
}
