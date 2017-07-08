#include "bellmannFord.h"

/*----------------------------------------------------------------------*/
/* Bellmann Ford														*/
/*----------------------------------------------------------------------*/
void bellmannFord (Grafo *grafo,Lista *lista,int *custoMax,int *fluxo,int *existe) {
	
	int i,k,j;
	Apontador aux;
	*custoMax = 0;
	*fluxo = INFINITO;
	int vetor[grafo->tam+1];
	int continua = 1;
	
	
	// inicializando todos os antecessores com -1
	for (i=0; i<(grafo->tam); i++) {
		grafo->hashSucessores[i].antecessor = -1;
	}
	
	// distancia do vertice inicial = 0
	grafo->hashSucessores[1].distancia = 0;
	
	// inicializando todos as distancias (exceto a primeira) com infinito
	for (i=2; i<=(grafo->tam); i++) {
		grafo->hashSucessores[i].distancia = INFINITO;
	}
			 
	// Verificando qual o caminho de custo mínimo
	for (k=1; k<=(grafo->tam);k++) {
		for (i=1; i<=(grafo->tam);i++) {
			
			if (grafo->hashSucessores[i].v != -1) {
				aux = grafo->hashSucessores[i].L.primeiro->prox;			// lista da hash

					while (aux != NULL) {
												
						if ((grafo->hashSucessores[i].distancia +  aux->custo) < grafo->hashSucessores[aux->vertice].distancia) {
						
							grafo->hashSucessores[aux->vertice].distancia = grafo->hashSucessores[i].distancia + aux->custo;
							grafo->hashSucessores[aux->vertice].antecessor = i;
						
						}
						aux = aux->prox;
					}
			}
		}
	}
	
	// Verificando se tem ciclo negativo
	for (i=1; i<=(grafo->tam);i++) {
		if (grafo->hashSucessores[i].v != -1) {
			aux = grafo->hashSucessores[i].L.primeiro->prox;
			while(aux != NULL){
				if ((grafo->hashSucessores[i].distancia +  aux->custo) < grafo->hashSucessores[aux->vertice].distancia) {
					printf("\n\nCiclo negativo no grafo!\n\n");
					break;
				}
				aux = aux->prox;
			}
		}
	}
	
	// lista de menor caminho sera do tamanho do grafo
	int menorCaminho[grafo->tam+1];
	
	for (i=1; i<=(grafo->tam);i++) {
		menorCaminho[i] = -1;
	}
	
	for (i = (grafo->tam); i>0; i--) {
		menorCaminho[i] =grafo->hashSucessores[i].antecessor;
		
	}
	
	criarLista(&(*lista));
	i = grafo->tam;
	inserirElementoComeco(i,0,0,&(*lista));

	while(menorCaminho[i] != -1){
		inserirElementoComeco(menorCaminho[i],0,0,&(*lista));
		i = menorCaminho[i];
	}
	aux = (*lista).primeiro->prox;
	
	while(aux!=NULL){	
		aux = aux->prox;
	}
		
	i = grafo->tam;
	j = menorCaminho[i];
	
	while(j != -1){
		aux = grafo->hashSucessores[j].L.primeiro->prox;
		while(aux != NULL){
			if(aux->vertice == i){
				if(*fluxo > aux->capacidade) *fluxo = aux->capacidade;
				*custoMax += aux->custo;
				
			}
			aux = aux->prox;
		}
		i = j;
		j = menorCaminho[i];
	}	
	 
	for(i=1;i<=grafo->tam;i++){
		vetor[i] = -1;
	}
	 
	vetor[grafo->tam] = grafo->tam;
	i = grafo->tam;
	while(continua){
		
		
		if( vetor[grafo->hashSucessores[i].antecessor] == -1) vetor[grafo->hashSucessores[i].antecessor]  = grafo->hashSucessores[i].antecessor;
		else {
			
			*existe = -1;
			continua = 0;
		}	
		i =  grafo->hashSucessores[i].antecessor;
		if(i==1)	continua = 0;
	}
	
	
	
	if(vetor[1] == -1){
		 
		 *existe = -1;
	}
	
}
