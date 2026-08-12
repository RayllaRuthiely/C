#include <stdio.h>
#define MAX 10

int main(){

    int num[MAX];

    for(int i = 0; i < MAX; i++){
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &num[i]);

        int repetido = 1;
        while(repetido){

            repetido = 0;

            for(int j = 0; j < i; j++){

                if(num[i] == num[j]){
                    repetido = 1;
                    printf("Numero repetido, digite outro numero: ");
                    scanf("%d", &num[i]);
                    break;
                }
            }
        }
    }

    for(int i = 0; i < MAX; i++){
        printf("%d ", num[i]);
    }
    printf("\n");

}