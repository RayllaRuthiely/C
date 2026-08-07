#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"

int main()
{
    float d;
    Ponto *p, *q;

    p = ponto_criar(1.0, 2.0);
    q = ponto_criar(4.0, 6.0);
    d = ponto_distancia(p, q);

    printf("A distancia entre os pontos x e y e: %.2f\n", d);
    ponto_Liberar(p);
    ponto_Liberar(q);

    system("pause");
    return 0;
}