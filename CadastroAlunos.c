#include <stdio.h>
#include <string.h>
struct Alunos{
    char nome[50];
    int idade;
    float nota;
};

float media(struct Alunos aluno[], int qtd){
    float soma = 0;
    for(int i = 0; i < qtd; i++){
        soma += aluno[i].nota;
    }
    return soma / qtd;
}
void nomes(struct Alunos aluno[], int qtd){
    char encontrado = 0;
    char busca[50];
    printf("Digite o nome do aluno que deseja encontrar: ");
    scanf("%s", busca);
    for(int i = 0; i < qtd; i++){
        if(strcmp(aluno[i].nome, busca) == 0){
            printf("Aluno %s encontrada!\n", busca);
            encontrado = 1;
        }
    }
    if(!encontrado){
        printf("Aluno %s nao encontrado!\n", busca);
    }
}
void cadastro(struct Alunos aluno[], int qtd){
    printf("\n LISTA DE ALUNOS CADASTRADOS \n");
    for(int i = 0; i < qtd; i++){
        printf("Aluno %d: \n", i + 1);
        printf("Nome: %s\n", aluno[i].nome);
        printf("Idade: %d\n", aluno[i].idade);
        printf("Nota: %.2f\n", aluno[i].nota);
    }
}
int main()
{
    struct Alunos aluno[3];

    for(int i = 0; i < 3; i++){
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", aluno[i].nome);
        printf("Digite a idade do aluno %d: ", i +1);
        scanf("%d", &aluno[i].idade);
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &aluno[i].nota);
    }
    printf("\n MENU DE OPCOES \n");
    printf("[1] - Media das notas dos alunos\n");
    printf("[2] - Encontrar aluno \n");
    printf("[3] - Lista de alunos cadastrados\n");
    printf("[4] - Sair \n");
    int opcao;
    do{
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Media dos alunos: %.2f\n", media(aluno, 3));
                break;
            case 2:
                nomes(aluno, 3);
                break;
            case 3: 
                cadastro(aluno, 3);
                break;    
            case 4:
                printf("Saindo...\n");      
        }
    }while(opcao != 4);
    return 0;
    
}