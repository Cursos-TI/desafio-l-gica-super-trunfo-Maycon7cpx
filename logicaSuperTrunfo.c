#include <stdio.h>
#include <string.h>

// Estrutura para armazenar informações das cartas das cidades
typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} CartaCidade;

// Função para cadastrar uma carta de cidade
void cadastrarCarta(CartaCidade *carta) {
    printf("Digite o estado: ");
    scanf("%s", carta->estado);
    printf("Digite o código da carta: ");
    scanf("%d", &carta->codigo);
    printf("Digite o nome da cidade: ");
    scanf("%s", carta->nome);
    printf("Digite a população: ");
    scanf("%d", &carta->populacao);
    printf("Digite a área: ");
    scanf("%f", &carta->area);
    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

// Função para exibir informações de uma carta de cidade
void exibirCarta(CartaCidade carta) {
    printf("Estado: %s\n", carta.estado);
    printf("Código: %d\n", carta.codigo);
    printf("Cidade: %s\n", carta.nome);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
}

// Função para comparar dois atributos e determinar a carta vencedora
void compararCartas(CartaCidade carta1, CartaCidade carta2, int atributo) {
    switch (atributo) {
        case 1: // Comparar por população
            if (carta1.populacao > carta2.populacao) {
                printf("A carta vencedora é: %s (População: %d)\n", carta1.nome, carta1.populacao);
            } else if (carta1.populacao < carta2.populacao) {
                printf("A carta vencedora é: %s (População: %d)\n", carta2.nome, carta2.populacao);
            } else {
                printf("Empate! Ambas as cidades têm a mesma população.\n");
            }
            break;
        case 2: // Comparar por área
            if (carta1.area > carta2.area) {
                printf("A carta vencedora é: %s (Área: %.2f)\n", carta1.nome, carta1.area);
            } else if (carta1.area < carta2.area) {
                printf("A carta vencedora é: %s (Área: %.2f)\n", carta2.nome, carta2.area);
            } else {
                printf("Empate! Ambas as cidades têm a mesma área.\n");
            }
            break;
        case 3: // Comparar por PIB
            if (carta1.pib > carta2.pib) {
                printf("A carta vencedora é: %s (PIB: %.2f)\n", carta1.nome, carta1.pib);
            } else if (carta1.pib < carta2.pib) {
                printf("A carta vencedora é: %s (PIB: %.2f)\n", carta2.nome, carta2.pib);
            } else {
                printf("Empate! Ambas as cidades têm o mesmo PIB.\n");
            }
            break;
        case 4: // Comparar por pontos turísticos
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("A carta vencedora é: %s (Pontos Turísticos: %d)\n", carta1.nome, carta1.pontos_turisticos);
            } else if (carta1.pontos_turisticos < carta2.pontos_turisticos) {
                printf("A carta vencedora é: %s (Pontos Turísticos: %d)\n", carta2.nome, carta2.pontos_turisticos);
            } else {
                printf("Empate! Ambas as cidades têm o mesmo número de pontos turísticos.\n");
            }
            break;
        default:
            printf("Atributo inválido!\n");
            break;
    }
}

int main() {
    int opcao, atributo;
    CartaCidade carta1, carta2;

    while (1) {
        // Exibição do menu
        printf("\nMenu de Gerenciamento de Cartas de Cidades\n");
        printf("1. Cadastrar Carta 1\n");
        printf("2. Cadastrar Carta 2\n");
        printf("3. Exibir Carta 1\n");
        printf("4. Exibir Carta 2\n");
        printf("5. Comparar Cartas\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nCadastro da Carta 1\n");
                cadastrarCarta(&carta1);
                break;
            case 2:
                printf("\nCadastro da Carta 2\n");
                cadastrarCarta(&carta2);
                break;
            case 3:
                printf("\nExibição da Carta 1\n");
                exibirCarta(carta1);
                break;
            case 4:
                printf("\nExibição da Carta 2\n");
                exibirCarta(carta2);
                break;
            case 5:
                printf("\nEscolha o atributo para comparação:\n");
                printf("1. População\n");
                printf("2. Área\n");
                printf("3. PIB\n");
                printf("4. Pontos Turísticos\n");
                printf("Escolha uma opção: ");
                scanf("%d", &atributo);
                compararCartas(carta1, carta2, atributo);
                break;
            case 6:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}