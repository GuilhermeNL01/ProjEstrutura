#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRESTADORES 100
#define MAX_CONSUMIDORES 100
#define MAX_TIPOS_SERVICOS 10

// Estrutura para representar um prestador de serviço
typedef struct
{
    char nome[50];
    int idade;
    char email[50];
    char telefone[15];
    char endereco[100];
    char uf[3];
    char tipo_servico[50];
    double preco_servico;
} PrestadorServico;

// Estrutura para representar um consumidor
typedef struct
{
    char nome[50];
    int idade;
    char email[50];
    char telefone[15];
    char endereco[100];
    char uf[3];
} Consumidor;

// Estrutura para representar um tipo de serviço
typedef struct
{
    char nome[50];
    double valor;
} TipoServico;

// Função para verificar se um tipo de serviço já existe na lista
int existeTipoServico(TipoServico tiposServicos[], int numTiposServicos, char tipoServico[])
{
    for (int i = 0; i < numTiposServicos; i++)
    {
        if (strcmp(tiposServicos[i].nome, tipoServico) == 0)
        {
            return 1; // Retorna 1 se o tipo de serviço existe
        }
    }
    return 0; // Retorna 0 se o tipo de serviço não existe
}

// Função para cadastrar prestadores de serviço
void cadastrarPrestador(PrestadorServico prestadores[], int *numPrestadores, TipoServico tiposServicos[], int *numTiposServicos)
{
    if (*numPrestadores < MAX_PRESTADORES)
    {
        PrestadorServico novoPrestador;

        printf("Nome: ");
        scanf("%s", novoPrestador.nome);

        printf("Idade: ");
        scanf("%d", &novoPrestador.idade);

        printf("Email: ");
        scanf("%s", novoPrestador.email);

        printf("Telefone: ");
        scanf("%s", novoPrestador.telefone);

        printf("Endereço: ");
        scanf("%s", novoPrestador.endereco);

        printf("UF: ");
        scanf("%s", novoPrestador.uf);

        printf("Tipo de Serviço: ");
        scanf("%s", novoPrestador.tipo_servico);

        printf("Preço do Serviço: ");
        scanf("%lf", &novoPrestador.preco_servico);

        prestadores[*numPrestadores] = novoPrestador;
        (*numPrestadores)++;

        // Incrementar numTiposServicos somente se o tipo de serviço ainda não estiver cadastrado
        if (!existeTipoServico(tiposServicos, *numTiposServicos, novoPrestador.tipo_servico))
        {
            TipoServico novoTipoServico;
            strcpy(novoTipoServico.nome, novoPrestador.tipo_servico);
            novoTipoServico.valor = novoPrestador.preco_servico;
            tiposServicos[*numTiposServicos] = novoTipoServico;
            (*numTiposServicos)++;
        }

        printf("Prestador de serviço cadastrado com sucesso!\n");
    }
    else
    {
        printf("Limite de prestadores atingido!\n");
    }
}

// Função para cadastrar consumidores
void cadastrarConsumidor(Consumidor consumidores[], int *numConsumidores)
{
    if (*numConsumidores < MAX_CONSUMIDORES)
    {
        Consumidor novoConsumidor;

        printf("Nome: ");
        scanf("%s", novoConsumidor.nome);

        printf("Idade: ");
        scanf("%d", &novoConsumidor.idade);

        printf("Email: ");
        scanf("%s", novoConsumidor.email);

        printf("Telefone: ");
        scanf("%s", novoConsumidor.telefone);

        printf("Endereço: ");
        scanf("%s", novoConsumidor.endereco);

        printf("UF: ");
        scanf("%s", novoConsumidor.uf);

        consumidores[*numConsumidores] = novoConsumidor;
        (*numConsumidores)++;

        printf("Consumidor cadastrado com sucesso!\n");
    }
    else
    {
        printf("Limite de consumidores atingido!\n");
    }
}

// Função para listar tipos de serviços
void listarTiposServicos(TipoServico tiposServicos[], int numTiposServicos)
{
    printf("Lista de Tipos de Serviços:\n");
    for (int i = 0; i < numTiposServicos; i++)
    {
        printf("Nome: %s, Valor: %.2f\n", tiposServicos[i].nome, tiposServicos[i].valor);
    }
}

// Função para listar consumidores
void listarConsumidores(Consumidor consumidores[], int numConsumidores)
{
    if (numConsumidores > 0)
    {
        printf("Lista de Consumidores:\n");
        for (int i = 0; i < numConsumidores; i++)
        {
            printf("Nome: %s\n", consumidores[i].nome);
            printf("Idade: %d\n", consumidores[i].idade);
            printf("Email: %s\n", consumidores[i].email);
            printf("Telefone: %s\n", consumidores[i].telefone);
            printf("Endereço: %s\n", consumidores[i].endereco);
            printf("UF: %s\n", consumidores[i].uf);
            printf("------------------------------\n");
        }
    }
    else
    {
        printf("Nenhum consumidor cadastrado.\n");
    }
}

// Função para listar consumidores por estado
void listarConsumidoresPorEstado(Consumidor consumidores[], int numConsumidores, char estado[])
{
    printf("Lista de Consumidores em %s:\n", estado);
    for (int i = 0; i < numConsumidores; i++)
    {
        if (strcmp(consumidores[i].uf, estado) == 0)
        {
            printf("Nome: %s\n", consumidores[i].nome);
            printf("Idade: %d\n", consumidores[i].idade);
            printf("Email: %s\n", consumidores[i].email);
            printf("Telefone: %s\n", consumidores[i].telefone);
            printf("Endereço: %s\n", consumidores[i].endereco);
            printf("UF: %s\n", consumidores[i].uf);
            printf("------------------------------\n");
        }
    }
}

// Função para listar prestadores de serviço
void listarPrestadores(PrestadorServico prestadores[], int numPrestadores)
{
    if (numPrestadores > 0)
    {
        printf("Lista de Prestadores de Serviço:\n");
        for (int i = 0; i < numPrestadores; i++)
        {
            printf("Nome: %s\n", prestadores[i].nome);
            printf("Idade: %d\n", prestadores[i].idade);
            printf("Email: %s\n", prestadores[i].email);
            printf("Telefone: %s\n", prestadores[i].telefone);
            printf("Endereço: %s\n", prestadores[i].endereco);
            printf("UF: %s\n", prestadores[i].uf);
            printf("Tipo de Serviço: %s\n", prestadores[i].tipo_servico);
            printf("Preço do Serviço: %.2f\n", prestadores[i].preco_servico);
            printf("------------------------------\n");
        }
    }
    else
    {
        printf("Nenhum prestador de serviço cadastrado.\n");
    }
}

// Função para listar prestadores de serviço por tipo de serviço
void listarPrestadoresPorTipoServico(PrestadorServico prestadores[], int numPrestadores, char tipoServico[])
{
    printf("Lista de Prestadores de Serviço do tipo %s:\n", tipoServico);
    for (int i = 0; i < numPrestadores; i++)
    {
        if (strcmp(prestadores[i].tipo_servico, tipoServico) == 0)
        {
            printf("Nome: %s\n", prestadores[i].nome);
            printf("Idade: %d\n", prestadores[i].idade);
            printf("Email: %s\n", prestadores[i].email);
            printf("Telefone: %s\n", prestadores[i].telefone);
            printf("Endereço: %s\n", prestadores[i].endereco);
            printf("UF: %s\n", prestadores[i].uf);
            printf("Preço do Serviço: %.2f\n", prestadores[i].preco_servico);
            printf("------------------------------\n");
        }
    }
}

// Função para encontrar o(s) estado(s) do serviço mais caro
void encontrarEstadoServicoMaisCaro(PrestadorServico prestadores[], int numPrestadores)
{
    if (numPrestadores > 0)
    {
        double servicoMaisCaro = prestadores[0].preco_servico;
        printf("Estado(s) do Serviço mais Caro:\n");

        for (int i = 1; i < numPrestadores; i++)
        {
            if (prestadores[i].preco_servico > servicoMaisCaro)
            {
                servicoMaisCaro = prestadores[i].preco_servico;
            }
        }

        for (int i = 0; i < numPrestadores; i++)
        {
            if (prestadores[i].preco_servico == servicoMaisCaro)
            {
                printf("Estado: %s\n", prestadores[i].uf);
            }
        }
    }
    else
    {
        printf("Nenhum prestador de serviço cadastrado.\n");
    }
}

// Função para listar tipos de serviços por valor crescente
void listarTiposServicosPorValorCrescente(TipoServico tiposServicos[], int numTiposServicos)
{
    // Ordenar os tipos de serviços por valor crescente 
    for (int i = 0; i < numTiposServicos - 1; i++)
    {
        for (int j = 0; j < numTiposServicos - i - 1; j++)
        {
            if (tiposServicos[j].valor > tiposServicos[j + 1].valor)
            {
                // Trocar os elementos de posição
                TipoServico temp = tiposServicos[j];
                tiposServicos[j] = tiposServicos[j + 1];
                tiposServicos[j + 1] = temp;
            }
        }
    }

    printf("Lista de Tipos de Serviços por Valor Crescente:\n");
    for (int i = 0; i < numTiposServicos; i++)
    {
        printf("Nome: %s, Valor: %.2f\n", tiposServicos[i].nome, tiposServicos[i].valor);
    }
}

// Função para listar consumidores por nome crescente
void listarConsumidoresPorNomeCrescente(Consumidor consumidores[], int numConsumidores)
{
    // Ordenar os consumidores por nome crescente 
    for (int i = 0; i < numConsumidores - 1; i++)
    {
        for (int j = 0; j < numConsumidores - i - 1; j++)
        {
            if (strcmp(consumidores[j].nome, consumidores[j + 1].nome) > 0)
            {
                // Trocar os elementos de posição
                Consumidor temp = consumidores[j];
                consumidores[j] = consumidores[j + 1];
                consumidores[j + 1] = temp;
            }
        }
    }

    printf("Lista de Consumidores por Nome Crescente:\n");
    for (int i = 0; i < numConsumidores; i++)
    {
        printf("Nome: %s\n", consumidores[i].nome);
        printf("Idade: %d\n", consumidores[i].idade);
        printf("Email: %s\n", consumidores[i].email);
        printf("Telefone: %s\n", consumidores[i].telefone);
        printf("Endereço: %s\n", consumidores[i].endereco);
        printf("UF: %s\n", consumidores[i].uf);
        printf("------------------------------\n");
    }
}

int main()
{
    PrestadorServico prestadores[MAX_PRESTADORES];
    Consumidor consumidores[MAX_CONSUMIDORES];
    TipoServico tiposServicos[MAX_TIPOS_SERVICOS];
    int numPrestadores = 0;
    int numConsumidores = 0;
    int numTiposServicos = 0;
    int opcao;

    do
    {
        // Exibir menu e obter a escolha do usuário
        printf("\nMenu:\n");
        printf("1 - Cadastro de Prestadores de Serviço\n");
        printf("2 - Cadastro de Consumidores\n");
        printf("3 - Listagem de Tipos de Serviços\n");
        printf("4 - Listagem de Consumidores\n");
        printf("5 - Listagem de Prestadores de Serviço\n");
        printf("6 - Listagem de Consumidores por Estado\n");
        printf("7 - Listagem de Prestadores por Tipo de Serviço\n");
        printf("8 - Estado(s) do Serviço Mais Caro\n");
        printf("9 - Listagem de Tipos de Serviços por Valor Crescente\n");
        printf("10 - Listagem de Consumidores por Nome Crescente\n");
        printf("0 - Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Executar a função correspondente à escolha do usuário
        switch (opcao)
        {
        case 1:
            cadastrarPrestador(prestadores, &numPrestadores, tiposServicos, &numTiposServicos);
            break;

        case 2:
            cadastrarConsumidor(consumidores, &numConsumidores);
            break;
        case 3:
            listarTiposServicos(tiposServicos, numTiposServicos);
            break;
        case 4:
            listarConsumidores(consumidores, numConsumidores);
            break;
        case 5:
            listarPrestadores(prestadores, numPrestadores);
            break;
        case 6:
        {
            char estado[3];
            printf("Digite o UF do estado: ");
            scanf("%s", estado);
            listarConsumidoresPorEstado(consumidores, numConsumidores, estado);
        }
        break;
        case 7:
        {
            char tipoServico[50];
            printf("Digite o tipo de serviço: ");
            scanf("%s", tipoServico);
            listarPrestadoresPorTipoServico(prestadores, numPrestadores, tipoServico);
        }
        break;
        case 8:
            encontrarEstadoServicoMaisCaro(prestadores, numPrestadores);
            break;
        case 9:
            listarTiposServicosPorValorCrescente(tiposServicos, numTiposServicos);
            break;
        case 10:
            listarConsumidoresPorNomeCrescente(consumidores, numConsumidores);
            break;
        case 0:
            printf("Saindo do programa. Até logo!\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
