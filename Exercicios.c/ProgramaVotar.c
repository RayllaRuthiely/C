#include <stdio.h>


int main()
{
    int idade;
    char op;

    do{
        printf("Digite seu ano de nascimento: ");
        scanf("%d", &idade);
        int calc = (2026 - idade);

        if(calc < 16){
            printf("Voce nao pode votar\n");
        }else if(calc == 16 || calc < 18 || calc > 70){
            printf("Voto opcional\n");

        }else{
            printf("Voto obrigatorio\n");
        }
        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &op);
        if(op == 'N' || op == 'n') {
				printf("Saindo...\n");
		}

    }while(op == 's' || op == 'S');
}