#include <stdio.h>
#include <stdlib.h>

int main(){

    int *v = malloc(sizeof(int));

    *v = 10;
    printf("Endereco: %p | Valor: %d\n", v, *v);
    free(v);

}