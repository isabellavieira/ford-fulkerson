#include "opgrafo.h"

/*--------------------------------------------------------------------------*/
/* Função responsável por criar o Grafo com o tamanho de vértices definido. */
/*--------------------------------------------------------------------------*/

void criarGrafo(Grafo *G1, int numVertices){
	int i;
	
	G1->hashSucessores = (ApontadorVertice) malloc(sizeof(Vertice)*(numVertices+1));
	G1->tam = numVertices;
	
	for (i = 0; i <=numVertices; i++){
		G1->hashSucessores[i].v = -1;
	}
}


/*--------------------------------------------------------------------------*/
/* Função responsável por desalocar o Grafo.                                 */
/*--------------------------------------------------------------------------*/

void desalocarGrafo(Grafo *G1) {
	int i;
	Vertice adjacentes;
		
	//Desalocando a lista de cada vértice
	for (i=0; i < G1->tam; i++){
		
		adjacentes = G1->hashAntecessores[i];
		desalocarLista(&adjacentes.L);
	}
	free(G1->hashSucessores);
	
}

/*--------------------------------------------------------------------------*/
/*Função responsável por imprimir o grafo na tela.  */
/*--------------------------------------------------------------------------*/

void mostrarGrafo (Grafo G1) {  
	int i;
		
	//Vertice adjacentes;
	for(i = 1; i <= (G1.tam); i++){
		if (G1.hashSucessores[i].v != -1){
			printf("\n");		
			printf("Aresta[%d] \n", G1.hashSucessores[i].v);
			printf("Antecessor[%d] \n", G1.hashSucessores[i].antecessor);
			printf("Distancia[%d] \n", G1.hashSucessores[i].distancia);			
			printf("Vertice[%d]-> Lista: ", i);
			mostrarLista(&(G1.hashSucessores[i].L));
		}
	}
	
}

/*--------------------------------------------------------------------------*/
/* Função responsável por inserir um vertice no Grafo.                       */
/*--------------------------------------------------------------------------*/

void inserirVertice(int n, Grafo *G1){

	G1->hashSucessores[n].v = n;
	criarLista(&G1->hashSucessores[n].L);
}

/*--------------------------------------------------------------------------*/
/* Função responsável por inserir uma aresta (v0->v1) no Grafo.      
 * inserirAresta(v0, v1, capacidade, custo).   				                 */
/*--------------------------------------------------------------------------*/

void inserirAresta(int v0, int v1, int capacidade, int custo, Grafo *G1){

	if (Tam(G1->hashSucessores[v0].L) >= 0){
		inserirElemento(v1, capacidade, custo, &G1->hashSucessores[v0].L);
	}else{
		printf("Erro: Lista não alocada!");
	}	
}

