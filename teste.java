package teste;

import java.util.*;

class Servico {
    String nome;
    double valor;
    String tipo;

    public Servico(String nome, double valor, String tipo) {
        this.nome = nome;
        this.valor = valor;
        this.tipo = tipo;
    }
}

class Pessoa {
    String nome;
    String estado;

    public Pessoa(String nome, String estado) {
        this.nome = nome;
        this.estado = estado;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Pessoa> prestadores = new ArrayList<>();
        List<Pessoa> consumidores = new ArrayList<>();
        List<Servico> servicos = new ArrayList<>();

        while (true) {
            System.out.println("Escolha uma opção:");
            System.out.println("1. Cadastro de Prestadores de Serviço");
            System.out.println("2. Cadastro de Consumidores");
            System.out.println("3. Cadastro de Serviços");
            System.out.println("4. Listagem de Tipos de Serviços");
            System.out.println("5. Listagem de Consumidores");
            System.out.println("6. Listagem de Prestadores de Serviço");
            System.out.println("7. Listagem de Consumidores por Estado");
            System.out.println("8. Listagem de Prestadores por Tipo de Serviço");
            System.out.println("9. Estado(s) do Serviço Mais Caro");
            System.out.println("10. Listagem de Serviços por Valor Crescente");
            System.out.println("11. Listagem de Consumidores por Nome Crescente");
            System.out.println("12. Sair");
            int opcao = scanner.nextInt();

            switch (opcao) {
                case 1:
                    System.out.println("Digite o nome do prestador de serviço:");
                    String nomePrestador = scanner.next();
                    System.out.println("Digite o estado do prestador de serviço:");
                    String estadoPrestador = scanner.next();
                    prestadores.add(new Pessoa(nomePrestador, estadoPrestador));
                    break;
                case 2:
                    System.out.println("Digite o nome do consumidor:");
                    String nomeConsumidor = scanner.next();
                    System.out.println("Digite o estado do consumidor:");
                    String estadoConsumidor = scanner.next();
                    consumidores.add(new Pessoa(nomeConsumidor, estadoConsumidor));
                    break;
                case 3:
                    System.out.println("Digite o nome do serviço:");
                    String nomeServico = scanner.next();
                    System.out.println("Digite o valor do serviço:");
                    double valorServico = scanner.nextDouble();
                    System.out.println("Digite o tipo do serviço:");
                    String tipoServico = scanner.next();
                    servicos.add(new Servico(nomeServico, valorServico, tipoServico));
                    break;
                case 4:
                    Set<String> tiposServicos = new HashSet<>();
                    for (Servico servico : servicos) {
                        tiposServicos.add(servico.tipo);
                    }
                    System.out.println("Tipos de Serviços Disponíveis:");
                    for (String tipo : tiposServicos) {
                        System.out.println(tipo);
                    }
                    break;
                case 5:
                    System.out.println("Lista de Consumidores:");
                    for (Pessoa consumidor : consumidores) {
                        System.out.println(consumidor.nome + " - " + consumidor.estado);
                    }
                    break;
                case 6:
                    System.out.println("Lista de Prestadores de Serviço:");
                    for (Pessoa prestador : prestadores) {
                        System.out.println(prestador.nome + " - " + prestador.estado);
                    }
                    break;
                case 7:
                    System.out.println("Digite o estado para listar os consumidores:");
                    String estadoListaConsumidores = scanner.next();
                    System.out.println("Consumidores no estado de " + estadoListaConsumidores + ":");
                    for (Pessoa consumidor : consumidores) {
                        if (consumidor.estado.equals(estadoListaConsumidores)) {
                            System.out.println(consumidor.nome);
                        }
                    }
                    break;
                case 8:
                    System.out.println("Digite o tipo de serviço para listar os prestadores:");
                    String tipoListaPrestadores = scanner.next();
                    System.out.println("Prestadores de serviço do tipo " + tipoListaPrestadores + ":");
                    for (Pessoa prestador : prestadores) {
                        for (Servico servico : servicos) {
                            if (prestador.estado.equals(servico.tipo)) {
                                System.out.println(prestador.nome);
                            }
                        }
                    }
                    break;
                case 9:
                    double maiorValor = 0;
                    Set<String> estadosMaisCaros = new HashSet<>();
                    for (Servico servico : servicos) {
                        if (servico.valor > maiorValor) {
                            maiorValor = servico.valor;
                            estadosMaisCaros.clear();
                            estadosMaisCaros.add(servico.tipo);
                        } else if (servico.valor == maiorValor) {
                            estadosMaisCaros.add(servico.tipo);
                        }
                    }
                    System.out.println("Estado(s) do Serviço Mais Caro:");
                    for (String estado : estadosMaisCaros) {
                        System.out.println(estado);
                    }
                    break;
                case 10:
                    Collections.sort(servicos, (s1, s2) -> Double.compare(s1.valor, s2.valor));
                    System.out.println("Listagem de Serviços por Valor Crescente:");
                    for (Servico servico : servicos) {
                        System.out.println(servico.nome + " - " + servico.valor);
                    }
                    break;
                case 11:
                    Collections.sort(consumidores, (c1, c2) -> c1.nome.compareTo(c2.nome));
                    System.out.println("Listagem de Consumidores por Nome Crescente:");
                    for (Pessoa consumidor : consumidores) {
                        System.out.println(consumidor.nome + " - " + consumidor.estado);
                    }
                    break;
                case 12:
                    System.out.println("Encerrando o programa.");
                    System.exit(0);
                    break;
                default:
                    System.out.println("Opção inválida. Por favor, escolha uma opção válida.");
                    break;
            }
        }
    }
}

