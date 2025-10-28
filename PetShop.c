#include <stdio.h>
#include <string.h>

struct PET {
    int idade;
    char especie[100];
};

void cadastrar(struct PET animal[], int *qtd) {
    int n;
    printf("Quantos pets deseja cadastrar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nDigite a especie do pet %d (cachorro / gato / coelho): ", *qtd + 1);
        scanf(" %[^\n]", animal[*qtd].especie);
        printf("Digite a idade do pet: ");
        scanf("%d", &animal[*qtd].idade);
        (*qtd)++;
    }
}

void buscar(struct PET animal[], int qtd) {
    int encontrado = 0;
    char busca[100];
    int ano;

    printf("Digite a especie do pet que deseja buscar: ");
    scanf(" %[^\n]", busca);
    printf("Digite a idade: ");
    scanf("%d", &ano);

    for (int i = 0; i < qtd; i++) {
        if (strcmp(animal[i].especie, busca) == 0 && animal[i].idade == ano) {
            printf("-- PET ENCONTRADO --\n");
            printf("Especie: %s | Idade: %d\n", animal[i].especie, animal[i].idade);
            encontrado = 1;
        }
    }

    if (!encontrado)
        printf("Nenhum pet encontrado com esses dados!\n");
}

void adicionar(struct PET animal[], int *qtd) {
    printf("\n=== Adicionar Novo Pet ===\n");
    printf("Especie do pet: ");
    scanf(" %[^\n]", animal[*qtd].especie);
    printf("Idade do pet: ");
    scanf("%d", &animal[*qtd].idade);
    (*qtd)++;
    printf("Pet adicionado com sucesso!\n");
}

void relatorio(struct PET animal[], int qtd) {
    if (qtd == 0) {
        printf("\nNenhum pet cadastrado ainda!\n");
        return;
    }

    printf("\n--- RELATORIO ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("Pet %d: Especie: %s | Idade: %d\n", i + 1, animal[i].especie, animal[i].idade);
    }
}


int main() {
    char op;
    struct PET animal[100];
    int qtd = 0;

    do {
        printf("[1] - Cadastrar pet\n");
        printf("[2] - Buscar pet\n");
        printf("[3] - Adicionar pet\n");
        printf("[4] - Relatorio\n");
        printf("[5] - Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &op);

        switch (op) {
            case '1':
                cadastrar(animal, &qtd);
                break;
            case '2':
                buscar(animal, qtd);
                break;
            case '3':
                adicionar(animal, &qtd);
                break;
            case '4':
                relatorio(animal, qtd);
                break;
            case '5':
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (op != '5');

    return 0;
}