#include <stdio.h>
#include <stdlib.h>
#include "opgrafo.h"

#ifndef ENTRADASAIDA_H
#define ENTRADASAIDA_H

int converterStringToInt (FILE *entrada, char *caractere);
void contarMaiorArquivo (FILE *entrada, int *menorVertice, int *maiorVertice);
void leituraArquivo (FILE *entrada, int numVertices, Grafo *grafo);

#endif
