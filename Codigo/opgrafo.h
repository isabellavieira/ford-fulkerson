#include <stdio.h>
#include <stdlib.h>
#include "oplista.h"

#ifndef OPGRAFO_H
#define OPGRAFO_H

/*--------------------------------------------------------------------------*/
//					TAD - Grafo
/*--------------------------------------------------------------------------*/
		typedef struct Vertice *ApontadorVertice;
		
		typedef struct Vertice{
			int v;
			int antecessor;					// BelmannFord
			int distancia;					// BelmannFord
			Lista L;
			
		}Vertice;
		
		//Tipo abstrato Grafo a partir de lista de adjacência
		typedef struct {
			ApontadorVertice hashSucessores;
			ApontadorVertice hashAntecessores;
			int tam;
		} Grafo;
  
/*--------------------------------------------------------------------------*/ 


void criarGrafo(Grafo *G1, int numVertices);
void desalocarGrafo(Grafo *G1);
void mostrarGrafo (Grafo G1);
void inserirVertice(int n, Grafo *G1);
void inserirAresta(int v0, int v1, int capacidade, int custo, Grafo *G1);

#endif
