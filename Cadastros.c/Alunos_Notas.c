#include <stdio.h>
typedef struct{
    char nome[50];
    int matricula;
    float notas[3];
} Aluno;

int main()
{
    char opcao;
    Aluno novoCadastro;
    Aluno calcularMedia;
    Aluno ordenarMediaFinal[100];
    Aluno maiorMedia;

    do{
        printf("--- Cadastro de Aluno ---\n");
        printf("--- MENU ---\n");
        printf("[1] - Cadastrar Aluno\n");
        printf("[2] - Media de cada aluno\n");
        printf("[3] - Ordenar alunos por media final\n");
        printf("[4] - Aluno com maior media\n");
        printf("[0] - Sair\n");
        scanf(" %c", &opcao);
    
        switch(opcao){
            case '1':
                printf("Digite o nome do aluno(a): ");
                scanf("%s", novoCadastro.nome);
                printf("Digite a matricula do aluno(a): ");
                scanf("%d", &novoCadastro.matricula);
                for(int i = 0; i < 3; i++){
                    printf("Digite a %d nota do aluno: ", i+1);
                    scanf("%f", &novoCadastro.notas[i]);
                }
                FILE *arquivo = fopen("alunos.bin", "ab");
                if(arquivo == NULL){
                printf("Erro ao abrir o arquivo!\n");
                return 1;
                }

                fwrite(&novoCadastro, sizeof(Aluno), 1, arquivo);
                fclose(arquivo);
                printf("Cadastro realizado com sucesso!\n");
                break;

            case '2':
                printf("--- Media de cada aluno ---\n");
                FILE *arquivoRead = fopen("alunos.bin", "rb");
                if(arquivoRead == NULL){
                    printf("Erro ao abrir o arquivo!\n");
                    return 1;
                }
                while(fread(&calcularMedia, sizeof(Aluno), 1, arquivoRead)){
                    float soma = 0;
                    for(int i = 0; i < 3; i++){
                        soma += calcularMedia.notas[i];
                    }
                    float media = soma / 3;
                    printf("Aluno: %s\n, Matricula: %d\n, Media: %.2f\n", calcularMedia.nome, calcularMedia.matricula, media);
                }
                fclose(arquivoRead);
                break;

            case '3':
                printf("--- Ordenar alunos por media final ---\n");
                FILE *arquivoOrdenar = fopen("alunos.bin", "rb");
                if(arquivoOrdenar == NULL){
                    printf("Erro ao abrir o arquivo!\n");
                    return 1;
                }
                int cont = 0;
                while(fread(&ordenarMediaFinal[cont], sizeof(Aluno), 1, arquivoOrdenar)){
                    cont++;
                }
                fclose(arquivoOrdenar);
                for(int i = 0; i < cont - 1; i++){
                    for(int j = i; j < cont; j++){
                        float mediaI = (ordenarMediaFinal[i].notas[0] + ordenarMediaFinal[i].notas[1] + ordenarMediaFinal[i].notas[2]) / 3;
                        float mediaJ = (ordenarMediaFinal[j].notas[0] + ordenarMediaFinal[j].notas[1] + ordenarMediaFinal[j].notas[2]) / 3;
                        if(mediaI < mediaJ){
                            Aluno temp = ordenarMediaFinal[i];
                            ordenarMediaFinal[i] = ordenarMediaFinal[j];
                            ordenarMediaFinal[j] = temp;
                        }
                    }
                }
                printf("Alunos ordenados por media final:\n");
                for(int i = 0; i < cont; i++){
                    float media = (ordenarMediaFinal[i].notas[0] + ordenarMediaFinal[i].notas[1] + ordenarMediaFinal[i].notas[2]) / 3;
                    printf("Aluno: %s, Matricula: %d, Media: %.2f\n", ordenarMediaFinal[i].nome, ordenarMediaFinal[i].matricula, media);
                }
                break;

            case '4':
                printf("--- Aluno com maior media ---\n");
                FILE *arquivoMaior = fopen("alunos.bin", "rb");
                if(arquivoMaior == NULL){
                    printf("Erro ao abrir o arquivo!\n");
                    return 1;
                }
                int primeiro = 1;
                while(fread(&maiorMedia, sizeof(Aluno), 1, arquivoMaior)){
                    float mediaAtual = (maiorMedia.notas[0] + maiorMedia.notas[1] + maiorMedia.notas[2]) / 3;
                    if(primeiro){
                        primeiro = 0;
                    } else {
                        float mediaMaior = (maiorMedia.notas[0] + maiorMedia.notas[1] + maiorMedia.notas[2]) / 3;
                        if(mediaAtual > mediaMaior){
                            maiorMedia = maiorMedia;
                        }
                    }
                }
                break;
            case '0':
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }
    } while(opcao != '0');
}
