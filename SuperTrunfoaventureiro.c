
#include <stdio.h>

int main() {
    // Variáveis para armazenar dados da Carta 1
    char estado1[3];
    char codigo1[4];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // Variáveis para armazenar dados da Carta 2
    char estado2[3];
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // Entrada dos dados da Carta 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (letra de A a H): ");
    scanf("%2s", estado1);

    printf("Código da carta (ex: A01): ");
    scanf("%3s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("População: ");
    scanf("%d", &populacao1);

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Entrada dos dados da Carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (letra de A a H): ");
    scanf("%2s", estado2);

    printf("Código da carta (ex: B02): ");
    scanf("%3s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("População: ");
    scanf("%d", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo das propriedades calculadas
    float densidade1 = populacao1 / area1;
    float pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;

    float densidade2 = populacao2 / area2;
    float pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;

    // Exibir dados completos da Carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    // Exibir dados completos da Carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    // Menu interativo para escolher o atributo de comparação
    int escolha;

    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per Capita\n");
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &escolha);

    float valor1, valor2;
    int menorVence = 0; // Para densidade populacional o menor vence

    switch (escolha) {
        case 1:
            printf("\nComparando por População:\n");
            valor1 = (float)populacao1;
            valor2 = (float)populacao2;
            menorVence = 0;
            break;
        case 2:
            printf("\nComparando por Área:\n");
            valor1 = area1;
            valor2 = area2;
            menorVence = 0;
            break;
        case 3:
            printf("\nComparando por PIB:\n");
            valor1 = pib1;
            valor2 = pib2;
            menorVence = 0;
            break;
        case 4:
            printf("\nComparando por Densidade Populacional:\n");
            valor1 = densidade1;
            valor2 = densidade2;
            menorVence = 1;
            break;
        case 5:
            printf("\nComparando por PIB per Capita:\n");
            valor1 = pibPerCapita1;
            valor2 = pibPerCapita2;
            menorVence = 0;
            break;
        default:
            printf("Escolha inválida!\n");
            return 1;
    }

    printf("Carta 1 - %s (%s): %.2f\n", nomeCidade1, estado1, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", nomeCidade2, estado2, valor2);

    // Comparação aninhada para determinar o vencedor
    if (menorVence) {
        if (valor1 < valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        }
        else if (valor2 < valor1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        }
        else {
            printf("Resultado: Empate!\n");
        }
    }
    else {
        if (valor1 > valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        }
        else if (valor2 > valor1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        }
        else {
            printf("Resultado: Empate!\n");
        }
    }

    return 0;
}
