#include <stdio.h>
#include <stdlib.h>

#include "opgrafo.h"
#include "entradaSaida.h"
#include "fordfulkerson.h"
#include "bellmannFord.h"

int main(int argc, char *argv[]){
	

	FILE *entrada;
	char *arquivo_entrada;
	arquivo_entrada = argv[1];
	entrada = fopen(arquivo_entrada, "r");
	
	Lista dados;
	Grafo grafo;
	int fluxo = 0;
	int custo = 0;
	int fonte = INFINITO;
	int sumidouro =0;
	
		
	
	if (entrada == NULL){
		printf("\nParametro incorreto!\n\n");		
		return 1;
	} else {
		contarMaiorArquivo (entrada, &fonte, &sumidouro);
		rewind(entrada);
		leituraArquivo (entrada, sumidouro, &grafo);
		dados = fordFulkerson(&grafo, fonte, sumidouro);
		
	
	printf("--------------------Cálculo do custo para um determinado valor de fluxo--------------------\n");
	printf("\nInforme o valor de fluxo: ");
	scanf("%d", &fluxo);

	custo = calcularCusto(fluxo, &dados);
	printf("\n\nO fluxo %d tem um custo de %d\n", fluxo, custo);
	return 0;
	}
	
}
