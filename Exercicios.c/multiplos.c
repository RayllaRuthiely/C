#include <stdio.h>
#define MAX 10

int main(){

    int vetor[MAX];
    int x;

    for(int i = 0; i < MAX; i++){
       vetor[i] = i + 1;
    }
    for (int i = 0; i < MAX; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Digite o valor de x: ");
    scanf("%d", &x);

    if(x <= 0){
        printf("O valor de x deve ser maior que zero.\n");
    } else {
        printf("Multiplos de %d: ", x);
        for (int i = 0; i < MAX; i++) {
            if (vetor[i] % x == 0) {
                printf("%d ", vetor[i]);
            }
        }
        printf("\n");

    }
}