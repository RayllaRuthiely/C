#include <stdio.h>
int main()
{
    int num;
    char op;

    do{
        printf("Digite o numero para multiplicacao: ");
        scanf("%d", &num);
        printf("---TABUADA---\n");

        for(int i = 0; i <= 10; i++){
        printf("%d X %d= %d\n", num, i, num * i);
        }
        printf("Desejar digitar outro numero?: (s/n)");
        scanf(" %c", &op);
    }while(op == 's' || op == 'S');

    return 0;
    
}