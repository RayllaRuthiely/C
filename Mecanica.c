#include <stdio.h>

typedef struct {
    char servico[50];
    char proprietario[50];
    char veiculo[50];
    char data[9];
} Agendamento;
int main()
{
    int op = 0;
    Agendamento novoAgendamento;
    Agendamento listarAgendamento;

    do{
        printf("--- MENU --- \n");
        printf("[1] - Agendar Servico\n");
        printf("[2] - Listar Agendamentos\n");
        printf("[3] - opcao 3\n");
        printf("[4] - opcao 4\n");
        printf("[0] - sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Qual servico deseja agendar? (Troca de Oleo, Balanceamento, Alinhamento, Revisao): ");
                scanf(" %[^\n]", novoAgendamento.servico);
                printf("Qual o nome do proprietario? ");
                scanf(" %[^\n]", novoAgendamento.proprietario);
                printf("Qual o modelo do veiculo? ");
                scanf(" %[^\n]", novoAgendamento.veiculo);
                printf("Qual a data do agendamento? (dd/mm/aaaa) ");
                scanf(" %[^\n]", novoAgendamento.data);
                printf("Agendamento criado com sucesso!\n");

                FILE *arquivo = fopen("agendamentos.txt", "a");

                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo!\n");
                    return 1;
                }

                fprintf(arquivo, "Servico: %s\n", novoAgendamento.servico);
                fprintf(arquivo, "Proprietario: %s\n", novoAgendamento.proprietario);
                fprintf(arquivo, "Veiculo: %s\n", novoAgendamento.veiculo);
                fprintf(arquivo, "Data: %s\n\n", novoAgendamento.data);
                fclose(arquivo);
                break;
            case 2:
                printf("--- Listando agendamentos ---\n");
                FILE *arquivoRead = fopen("agendamentos.txt", "r+");
                if (arquivoRead == NULL) {
                    printf("Erro ao abrir o arquivo!\n");
                    return 1;
                }
                while(fscanf(arquivoRead, "Servico: %[^\n]\n", listarAgendamento.servico) == 1) {
                    if(fscanf(arquivoRead, "Proprietario: %[^\n]\n", listarAgendamento.proprietario) == 1) {
                        fscanf(arquivoRead, "Veiculo: %[^\n]\n", listarAgendamento.veiculo);
                        fscanf(arquivoRead, "Data: %[^\n]\n\n", listarAgendamento.data);
                        printf("Servico: %s\n", listarAgendamento.servico);
                        printf("Proprietario: %s\n", listarAgendamento.proprietario);
                        printf("Veiculo: %s\n", listarAgendamento.veiculo);
                        printf("Data: %s\n", listarAgendamento.data);
                        printf("-------------------------\n");
                    }
                }
                fclose(arquivoRead);
                break;
            case 3:
                printf("Voce escolheu a opcao 3\n");
                break;
            case 4:
                printf("Voce escolheu a opcao 4\n");
                break;
            case 0:
                printf("Saindo...\n");
                break;    
        }

    }while(op != 0);
    return 0;
} 