all: steg

steg: steg.o imagem.o codificar.o
	gcc steg.o imagem.o codificar.o -lm -o steg

steg.o: steg.c
	gcc -c steg.c

imagem.o: imagem.c
	gcc -c imagem.c

codificar.o: codificar.c
	gcc -c codificar.c

clean:
	rm -rf *o steg
