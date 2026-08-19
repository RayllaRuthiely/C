#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Ponto.h"  //Inclue o arquivo de cabeçalho Ponto.h


struct ponto {
    float x;
    float y;
};

Ponto* ponto_criar(float x, float y){
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}
void ponto_Liberar(Ponto* p){
    free(p);
}

void ponto_acessar(Ponto* p, float* x, float* y){
    
    if (p != NULL && x != NULL && y != NULL) {
        *x = p->x;
        *y = p->y;
    }
}

float ponto_distancia(Ponto* p1, Ponto* p2){
    if (p1 == NULL || p2 == NULL) {
        return -1.0f; // Retorna -1.0f para indicar erro
    }
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrt(dx * dx + dy * dy);
}