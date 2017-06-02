all: steg

deco: steg.o imagem.o
	gcc steg.o imagem.o -o steg

steg.o: steg.c
	gcc -c steg.c

imagem.o: imagem.c
	gcc -c imagem.c

clean:
	rm -rf *o steg
