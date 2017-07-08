#include <stdio.h>
#include <stdlib.h>

#ifndef OPLISTA_H
#define OPLISTA_H


/*--------------------------------------------------------------------------*/
//					TAD - Lista
/*--------------------------------------------------------------------------*/
		typedef struct celula *Apontador;
		
		typedef struct celula {
			int vertice;
			int capacidade;
			int custo;
			Apontador prox;
		} celula;

		//Tipo abstrato Lista simplesmente encadeada
		typedef struct {
			Apontador primeiro, ultimo;
			int tam;
		} Lista;
  

void criarLista(Lista *L1);
void desalocarLista (Lista *L1);
void mostrarLista (Lista *L1) ;
void inserirElementoComeco(int n, int capacidade,int custo, Lista *L1);
void inserirElemento(int n, int capacidade, int custo, Lista *L1);
Apontador buscarElemento(int x, Lista *L1);
int Vazia(Lista *L1);
int Tam(Lista L1);
void removerDaLista (Lista *L1, int v0);

#endif
