#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "opgrafo.h"

#define INFINITO INT_MAX

#ifndef BELLMANNFORD_H
#define BELLMANNFORD_H

void bellmannFord (Grafo *grafo,Lista *lista,int *custoMax,int *fluxo,int* existe);

#endif
