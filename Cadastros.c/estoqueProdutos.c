#include <stdio.h>
struct Produto{
    char nome[50];
    int codigo;
    float preco;
    int quantidade;
};
void cadastrarProduto(struct Produto *p1){
    printf("Digite o nome do produto: ");
    scanf("%s", p1->nome);
    printf("Digite o codigo do produto: ");
    scanf("%d", &p1->codigo);
    printf("Digite o preco do produto: ");
    scanf("%f", &p1->preco);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &p1->quantidade);       
    FILE *arquivo = fopen("produtos.txt", "a");
    if("arquivo" == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    fprintf(arquivo, "Nome: %s\n", p1->nome);
    fprintf(arquivo, "Codigo: %d\n", p1->codigo);
    fprintf(arquivo, "Preco: %.2f\n", p1->preco);
    fprintf(arquivo, "Quantidade: %d\n", p1->quantidade);
    printf("----------------------\n");
    fclose(arquivo);
}
void listarProduto(struct Produto *p1){
            FILE *arquivo = fopen("produtos.txt", "r");
            if(arquivo == NULL){
                printf("Erro ao abrir o arquivo!\n");
                return;
            }
            printf("--- Lista de Produtos ---\n");
            while(fscanf(arquivo, "Nome: %s\n", p1->nome) == 1) {
                if(fscanf(arquivo, "Codigo: %d\n", &p1->codigo) == 1) {
                    fscanf(arquivo, "Preco: %f\n", &p1->preco);
                    fscanf(arquivo, "Quantidade: %d\n", &p1->quantidade);
                    printf("Nome: %s\n", p1->nome);
                    printf("Codigo: %d\n", p1->codigo);
                    printf("Preco: %.2f\n", p1->preco);
                    printf("Quantidade: %d\n", p1->quantidade);
                    printf("----------------------\n");
                }
            }
            fclose(arquivo);
}
void atualizarEstoque(struct Produto *p1) {
    FILE *arquivo = fopen("produtos.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    int codigoBusca;
    int encontrado = 0;

    printf("Digite o codigo do produto para atualizar o estoque: ");
    scanf("%d", &codigoBusca);

    while (fscanf(arquivo,
                  "Nome: %[^\n]\nCodigo: %d\nPreco: %f\nQuantidade: %d\n",
                  p1->nome, &p1->codigo, &p1->preco, &p1->quantidade) == 4) {

        if (p1->codigo == codigoBusca) {
            printf("Produto encontrado: %s\n", p1->nome);
            printf("Quantidade atual: %d\n", p1->quantidade);
            printf("Digite a nova quantidade: ");
            scanf("%d", &p1->quantidade);
            encontrado = 1;
        }

        fprintf(temp, "Nome: %s\nCodigo: %d\nPreco: %.2f\nQuantidade: %d\n",
                p1->nome, p1->codigo, p1->preco, p1->quantidade);
    }

    fclose(arquivo);
    fclose(temp);

    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");

    if (encontrado)
        printf("Estoque atualizado com sucesso!\n");
    else
        printf("Produto com codigo %d não encontrado.\n", codigoBusca);
}
int main() {
    char op;
    struct Produto p1; 

    do {
        printf("--- MENU ---\n");
        printf("[1] - Cadastrar\n");
        printf("[2] - Listar\n");
        printf("[3] - Atualizar Estoques\n");
        printf("[0] - Sair\n");
        scanf(" %c", &op);

        switch (op){
            case '1':
               cadastrarProduto(&p1);
            break;
            case '2':
                listarProduto(&p1);
            break;
            case '3':
                atualizarEstoque(&p1);
            break;
            case '0':
               printf("Saindo...\n");
            break;
                
        }
    }while (op != '0');

    return 0;
}