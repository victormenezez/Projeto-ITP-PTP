O QUE FOI FEITO:

-CHECKPOINT 1

-Estrutra para leitura correta do tipo ppm (P6).
-Modularização externa do programa.
-Armazenamento da imagem em struct.

-CHECKPOINT 2

-Leitura e armazenagem de imagem BMP.

-CHECKPOINT 3

-Não houve entrega

-CHECKPOINT 4


O QUE NÃO FOI FEITO:

-Utilização do tipo de dado 'enum'.



COMPILAÇÃO:

-Execute o comando 'make'.
-Rode o executável './steg'.
-Informe como você irá executar o programa
	-e para modo de encodificação
		-i para informar o arquivo com a mensagem
		[nome do arquivo.txt]
		[nome da imagem.(bmp ou ppm)]
		exemplo: ./steg -e -i mensagem.txt imagem.ppm

	-d para modo de decodificação
		-s para saída no terminal
		-o para saída em arquivo com nome de sua escolha
		[nome do arquivo]
		[nome da imagem]
		exemplo: ./steg -d -s imagem.bmp
		exemplo: ./steg -d -o saida.txt imagem.bmp

-siga os passos informados pelo terminal e realize sua codificação/encodificação

DUPLA 

-Gabriel Paulo
-Victor Gomes

-Ambos os autores participaram do desenvolvimento. Não houve divisão de tarefas, todas os trechos de códigos e implementações foram feitas pelos dois integrantes com ajuda múltua.
