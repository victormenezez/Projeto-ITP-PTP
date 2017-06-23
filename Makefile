all: steg

steg: steg.o imagem.o codificar.o decodificar.o
	gcc steg.o imagem.o codificar.o decodificar.o -lm -o steg

steg.o: steg.c
	gcc -c steg.c

imagem.o: imagem.c
	gcc -c imagem.c

codificar.o: codificar.c
	gcc -c codificar.c

decodificar.o: decodificar.c
	gcc -c decodificar.c

clean:
	rm -rf *o steg
