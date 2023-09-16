#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura para representar um serviço
typedef struct {
    char nome[100];
    double valor;
    char tipo[100];
} Servico;

// Definindo a estrutura para representar uma pessoa
typedef struct {
    char nome[100];
    char estado[100];
} Pessoa;

int main() {
    int opcao;
    char buffer[100];
    double maiorValor = 0;

    // Arrays para armazenar prestadores, consumidores e serviços
    Pessoa prestadores[100];
    Pessoa consumidores[100];
    Servico servicos[100];

    int numPrestadores = 0;
    int numConsumidores = 0;
    int numServicos = 0;

    // Loop principal do programa
    while (1) {
        printf("Escolha uma opção:\n");
        printf("1. Cadastro de Prestadores de Serviço\n");
        printf("2. Cadastro de Consumidores\n");
        printf("3. Cadastro de Serviços\n");
        printf("4. Listagem de Tipos de Serviços\n");
        printf("5. Listagem de Consumidores\n");
        printf("6. Listagem de Prestadores de Serviço\n");
        printf("7. Listagem de Consumidores por Estado\n");
        printf("8. Listagem de Prestadores por Tipo de Serviço\n");
        printf("9. Estado(s) do Serviço Mais Caro\n");
        printf("10. Listagem de Serviços por Valor Crescente\n");
        printf("11. Listagem de Consumidores por Nome Crescente\n");
        printf("12. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Cadastro de Prestadores de Serviço
                printf("Digite o nome do prestador de serviço:\n");
                scanf("%s", buffer);
                strcpy(prestadores[numPrestadores].nome, buffer);
                printf("Digite o estado do prestador de serviço:\n");
                scanf("%s", buffer);
                strcpy(prestadores[numPrestadores].estado, buffer);
                numPrestadores++;
                break;
            case 2:
                // Cadastro de Consumidores
                printf("Digite o nome do consumidor:\n");
                scanf("%s", buffer);
                strcpy(consumidores[numConsumidores].nome, buffer);
                printf("Digite o estado do consumidor:\n");
                scanf("%s", buffer);
                strcpy(consumidores[numConsumidores].estado, buffer);
                numConsumidores++;
                break;
            case 3:
                // Cadastro de Serviços
                printf("Digite o nome do serviço:\n");
                scanf("%s", buffer);
                strcpy(servicos[numServicos].nome, buffer);
                printf("Digite o valor do serviço:\n");
                scanf("%lf", &servicos[numServicos].valor);
                printf("Digite o tipo do serviço:\n");
                scanf("%s", buffer);
                strcpy(servicos[numServicos].tipo, buffer);
                numServicos++;
                break;
            case 4:
                // Listagem de Tipos de Serviços
                printf("Tipos de Serviços Disponíveis:\n");
                for (int i = 0; i < numServicos; i++) {
                    int tipoJaListado = 0;
                    for (int j = 0; j < i; j++) {
                        if (strcmp(servicos[i].tipo, servicos[j].tipo) == 0) {
                            tipoJaListado = 1;
                            break;
                        }
                    }
                    if (!tipoJaListado) {
                        printf("%s\n", servicos[i].tipo);
                    }
                }
                break;
            case 5:
                // Listagem de Consumidores
                printf("Lista de Consumidores:\n");
                for (int i = 0; i < numConsumidores; i++) {
                    printf("%s - %s\n", consumidores[i].nome, consumidores[i].estado);
                }
                break;
            case 6:
                // Listagem de Prestadores de Serviço
                printf("Lista de Prestadores de Serviço:\n");
                for (int i = 0; i < numPrestadores; i++) {
                    printf("%s - %s\n", prestadores[i].nome, prestadores[i].estado);
                }
                break;
            case 7:
                // Listagem de Consumidores por Estado
                printf("Digite o estado para listar os consumidores:\n");
                scanf("%s", buffer);
                printf("Consumidores no estado de %s:\n", buffer);
                for (int i = 0; i < numConsumidores; i++) {
                    if (strcmp(consumidores[i].estado, buffer) == 0) {
                        printf("%s\n", consumidores[i].nome);
                    }
                }
                break;
            case 8:
                // Listagem de Prestadores por Tipo de Serviço
                printf("Digite o tipo de serviço para listar os prestadores:\n");
                scanf("%s", buffer);
                printf("Prestadores de serviço do tipo %s:\n", buffer);
                for (int i = 0; i < numPrestadores; i++) {
                    for (int j = 0; j < numServicos; j++) {
                        if (strcmp(prestadores[i].estado, servicos[j].tipo) == 0) {
                            printf("%s\n", prestadores[i].nome);
                            break;
                        }
                    }
                }
                break;
            case 9:
                // Estado(s) do Serviço Mais Caro
                for (int i = 0; i < numServicos; i++) {
                    if (servicos[i].valor > maiorValor) {
                        maiorValor = servicos[i].valor;
                    }
                }
                printf("Estado(s) do Serviço Mais Caro:\n");
                for (int i = 0; i < numServicos; i++) {
                    if (servicos[i].valor == maiorValor) {
                        int estadoJaListado = 0;
                        for (int j = 0; j < i; j++) {
                            if (strcmp(servicos[i].tipo, servicos[j].tipo) == 0) {
                                estadoJaListado = 1;
                                break;
                            }
                        }
                        if (!estadoJaListado) {
                            printf("%s\n", servicos[i].tipo);
                        }
                    }
                }
                break;
            case 10:
                // Listagem de Serviços por Valor Crescente
                for (int i = 0; i < numServicos - 1; i++) {
                    for (int j = 0; j < numServicos - i - 1; j++) {
                        if (servicos[j].valor > servicos[j + 1].valor) {
                            // Trocar os serviços de lugar
                            Servico temp = servicos[j];
                            servicos[j] = servicos[j + 1];
                            servicos[j + 1] = temp;
                        }
                    }
                }
                printf("Listagem de Serviços por Valor Crescente:\n");
                for (int i = 0; i < numServicos; i++) {
                    printf("%s - %.2lf\n", servicos[i].nome, servicos[i].valor);
                }
                break;
            case 11:
                // Listagem de Consumidores por Nome Crescente
                for (int i = 0; i < numConsumidores - 1; i++) {
                    for (int j = 0; j < numConsumidores - i - 1; j++) {
                        if (strcmp(consumidores[j].nome, consumidores[j + 1].nome) > 0) {
                            // Trocar os consumidores de lugar
                            Pessoa temp = consumidores[j];
                            consumidores[j] = consumidores[j + 1];
                            consumidores[j + 1] = temp;
                        }
                    }
                }
                printf("Listagem de Consumidores por Nome Crescente:\n");
                for (int i = 0; i < numConsumidores; i++) {
                    printf("%s - %s\n", consumidores[i].nome, consumidores[i].estado);
                }
                break;
            case 12:
                printf("Encerrando o programa.\n");
                exit(0);
                break;
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
    }

    return 0;
}
