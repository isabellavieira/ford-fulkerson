#include <stdio.h>
#include <stdlib.h>
#include "opgrafo.h"
#include "oplista.h"

#ifndef FORDFULKERSON_H
#define FORDFULKERSON_H

void construirGrafoFolga(Grafo *grafo, int fluxo, Lista caminho);
int adjacente(int vertice0, int vertice1, Grafo *grafo);
Lista fordFulkerson (Grafo *grafo, int vertice0, int vertice1);
int calcularCusto (int fluxo, Lista *dados);

#endif
