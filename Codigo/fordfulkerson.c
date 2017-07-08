#include "fordfulkerson.h"

/*-------------------------------------------------------------------------------------*/
/* Função para a construção do Grafo de folga a partir um fluxo e um caminho.		    */
/*--------------------------------------------------------------------------------------*/		
void construirGrafoFolga(Grafo *grafo, int fluxo, Lista caminho){
	
	//O caminho precisa ter pelo menos UM Vértice - Primeiro é celula cabeça
	Apontador aux1 = caminho.primeiro->prox;
	Apontador aux2 = aux1->prox;
	Apontador aresta = NULL;
	Apontador retorno = NULL;
	int i = 1;
	
	if (aux2 == NULL) printf("Erro: sem caminho.");
	
	while(aux2 != NULL){
		
		aresta = NULL;
		retorno = NULL;		
		i++;
				
		if (grafo->hashSucessores[aux1->vertice].v == -1){
			inserirVertice(aux1->vertice, &(*grafo));
		
		}

		if (grafo->hashSucessores[aux2->vertice].v == -1){
			inserirVertice(aux2->vertice, &(*grafo));
		}

		aresta = buscarElemento(aux2->vertice, &(grafo->hashSucessores[aux1->vertice].L));
		retorno = buscarElemento(aux1->vertice, &(grafo->hashSucessores[aux2->vertice].L));
		
		if (aresta->capacidade > fluxo){
			aresta->capacidade = aresta->capacidade - fluxo;							 /*Atualizando a folga!*/
			
			if (retorno == NULL){
	
				inserirAresta(aux2->vertice, aux1->vertice, fluxo, ((-1)*aresta->custo), &(*grafo)); 

			} else{

				retorno->capacidade = retorno->capacidade + fluxo;
			}
			
		/*Se a capacidade for igual ao fluxo*/	
		}else if (aresta->capacidade == fluxo){ 

			removerDaLista(&grafo->hashSucessores[aux1->vertice].L, aux2->vertice);
				
			if (retorno == NULL){
				inserirAresta(aux2->vertice, aux1->vertice, fluxo, ((-1)*aresta->custo), &(*grafo));
			} else{
				retorno->capacidade = retorno->capacidade + fluxo;
			}
		}else{	
			printf("Erro: não tem capacidade para passar fluxo na aresta (%d, %d).", aux1->vertice, aux2->vertice);
			return;
				
		}	
		
		aux1 = aux2;
		aux2 = aux2->prox;
	}

}
/*-------------------------------------------------------------------------------------*/
/* Função que verifica se o vertice1, ou seja, o sumidouro (T) está presente na lista
 * de adjacencia da fonte (S).									 					    */
/*--------------------------------------------------------------------------------------*/
int adjacente(int vertice0, int vertice1, Grafo *grafo){
	
	int gargaloInsaturado;
	Apontador p;
	
	//Busca o elemento vertice1(sumidouro), na lista de adjacentes do vertice0 (fonte), ou seja, verificar se o sumiouro é alcançável a partir da fonte
	p = buscarElemento(vertice1, &(grafo->hashSucessores[vertice0].L));
	
	if (p == NULL) return(gargaloInsaturado = 0);						/*Se não for alcançável a partir da fonte */
	else return(gargaloInsaturado = 1);									/*Se for alcançável a partir da fonte  */
	
}

/*--------------------------------------------------------------------------*/
/* Algoritmo ford-fulkerson - Fluxo máximo com custo.						*/
/* A pertir do algoritmo de caminho mínimo: Bellmann-ford.				    */
/*--------------------------------------------------------------------------*/

Lista fordFulkerson (Grafo *grafo, int vertice0, int vertice1){
	
	int fluxo = 0;				//fluxo para cada iteração
	int fluxoMaximo = 0;		//Fluxo máximo do grafo
	int custoCaminho = 0;		//Custo total de um caminho de custo mínimo
	int custoTotal = 0;			//Custo total para a passagem do fluxoTotal no grafo
	int capacidadeMinima = 0;	//Capacidade mínima do caminho de custo mínimo 
	int gargaloInsaturado = 1;	//Flag para marcar verificar quando o gargalo já está saturado
	int existe = 0;
	Lista caminho;				//Lista para armazenar o caminho de custo mínimo de cada iteração
	Lista lista; 				// Lista com os fluxos de cada caminho com seus respectivos custos
	int i = 1;
	criarLista(&lista);
	
	//Testando a saturação
	while (gargaloInsaturado){
			
		//Obter caminho de custo mínimo - retornando o caminho mínimo, a capacidade mínima e a soma dos custos do caminho
		bellmannFord(&(*grafo), &caminho, &custoCaminho, &capacidadeMinima,&existe);				
		
		//Se não o sumidouro nao esta presente no caminho, ou seja, se ele nao for alcançável - FIM
		if (existe == -1){
			break;
		}
		
		fluxo = capacidadeMinima;
		//Construindo o grafo de folga
		construirGrafoFolga(&(*grafo), fluxo, caminho);
		
		//Contabilizando o FluxoTotal do grafo
		fluxoMaximo = fluxoMaximo + fluxo;
		
		//Contabilizando o custoTotal para a passagem do fluxoTotal
		custoTotal = custoTotal + (fluxo * custoCaminho);
			
		//Inserindo o fluxo com seu respectivo custo em uma lista para pesquisa posterior
		inserirElemento(fluxo, 0, custoCaminho, &lista);
		
	}
	
	//A ultima celula guarda o fluxo total e seu custo
	inserirElemento(fluxoMaximo, 0, custoTotal, &lista);
	
	printf("\n--> O Fluxo máximo do grafo é %d com o custo de %d\n", fluxoMaximo, custoTotal);
	
	return lista;
}


/*--------------------------------------------------------------------------*/
/* Função que calcula o custo para determinado valor de custo.			    */
/*--------------------------------------------------------------------------*/
int calcularCusto (int fluxo, Lista *dados ){
	int custo = 0;
	int restante = fluxo;
	int somaCusto = 0;
	Apontador aux = dados->primeiro->prox;

	// verifica se o fluxo informado é maior que o fluxo digitado
	if (dados->ultimo->vertice < fluxo){
		printf("O fluxo informado é maior que o fluxo máximo suportado pelo grafo!\n");
		return 0;
	}
	
	while(aux != NULL){
		if (aux->vertice >= restante){
			somaCusto = somaCusto + (aux->custo*restante);
			restante = 0;
		}else/* if(aux->vertice < fluxo)*/{
			restante = restante - aux->vertice;
			somaCusto = somaCusto + (aux->custo*aux->vertice);
		}
		
		if (restante == 0) break;
		
		aux = aux->prox;
	}
	
	return somaCusto;
}
