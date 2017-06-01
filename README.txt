Compile o arquivo imagem.h: gcc imagem.h -c
Compile o arquivo steg.c: gcc steg.c imagem.o
Informe o arquivo com nome "imagem" para que o programa possa ler a imagem que estamos utilizando para testes.

A leitura da imagem ppm no formato P3 está sendo feita. Existe um teste na classe imagem.c para verificar se, realmente, os pixels foram adicionados ao vetor 'pixel'.