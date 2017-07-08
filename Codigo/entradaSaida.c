#include "entradaSaida.h"

/*----------------------------------------------------------------------*/
/* Converte string para inteiro											*/
/*----------------------------------------------------------------------*/
int converterStringToInt (FILE *entrada, char *caractere){  

	char palavra[5]; 
	int result;
	int i = 0;
	
	while ((*caractere) != ' ' && (*caractere) != '\n'){
		palavra[i] = (*caractere);
		i++;
		fscanf(entrada, "%c" , &(*caractere));			
	}
	
	palavra[i] = '\0';

	result = (atoi(palavra));
	return result;
}

/*----------------------------------------------------------------------*/
/* Função que verifica qual o maior vértice do grafo para alocar a hash */
/*----------------------------------------------------------------------*/
void contarMaiorArquivo (FILE *entrada, int *menorVertice, int *maiorVertice) {
	
	int de;
	int para;
	int caractere;
	
	while (!feof(entrada)) {
		
		// lendo o caractere DE
		fscanf(entrada, "%d" , &de);
			
		// lendo o caractere PARA
		fscanf(entrada, "%d" , &para);
		
		// Pegando o maior vértice
		if (de > *maiorVertice) {
			*maiorVertice = de;
		}
		
		if (para > *maiorVertice) {
			*maiorVertice = para;
		}
		
		if (de < *menorVertice) {
			*menorVertice = de;
		}
		
		if (para < *menorVertice) {
			*menorVertice = para;
		}
		
		fscanf(entrada, "%d" , &caractere);
		fscanf(entrada, "%d" , &caractere);

	}
		
}

/*----------------------------------------------------------------------*/
/* Leitura do arquivo e alocacao do grafo								*/
/*----------------------------------------------------------------------*/
void leituraArquivo (FILE *entrada, int numVertices, Grafo *grafo) {
	
	int de;
	int para;
	int capacidade;
	int custo;
	
	// Criando grafo (hash)
	criarGrafo (&(*grafo), numVertices);
			
	while (!feof(entrada)) {
				
		// lendo o caractere DE
		fscanf(entrada, "%d" , &de);
	
		// lendo o caractere PARA
		fscanf(entrada, "%d" , &para);
		
		// lendo o caractere CAPACIDADE
		fscanf(entrada, "%d" , &capacidade);
		
		// lendo o caractere CUSTO
		fscanf(entrada, "%d" , &custo);	
		
		// inserindo vertices
		if (grafo->hashSucessores[de].v != de) {		// se não existe na hash o vertice de, eu o insiro
			inserirVertice(de, &(*grafo));
		} 
	
		// inserindo arestas ("listas") na hash
		inserirAresta(de, para, capacidade, custo, &(*grafo));
			
		
	
	}

}
