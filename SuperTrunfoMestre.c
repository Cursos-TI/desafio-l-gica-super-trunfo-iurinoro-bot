#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 2
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta* c) {
    printf("Digite o nome da carta: ");
    scanf(" %[^\n]", c->nome);

    printf("Digite o valor de Forca (0-100): ");
    scanf("%d", &c->forca);

    printf("Digite o valor de Velocidade (0-100): ");
    scanf("%d", &c->velocidade);

    printf("Digite o valor de Inteligencia (0-100): ");
    scanf("%d", &c->inteligencia);
}

// Função para exibir uma carta
void mostrarCarta(Carta c) {
    printf("\n=== Carta: %s ===\n", c.nome);
    printf("Forca: %d\n", c.forca);
    printf("Velocidade: %d\n", c.velocidade);
    printf("Inteligencia: %d\n", c.inteligencia);
    printf("======================\n");
}

// Função que retorna o valor de um atributo baseado na escolha
int obterValorAtributo(Carta c, int escolha) {
    switch (escolha) {
        case 1: return c.forca;
        case 2: return c.velocidade;
        case 3: return c.inteligencia;
        default: return -1;
    }
}

// Nome do atributo para exibição
const char* nomeAtributo(int escolha) {
    switch (escolha) {
        case 1: return "Forca";
        case 2: return "Velocidade";
        case 3: return "Inteligencia";
        default: return "Desconhecido";
    }
}

// Função de comparação com lógica avançada
void compararCartas(Carta c1, Carta c2, int atributo1, int atributo2) {
    int valor1_c1 = obterValorAtributo(c1, atributo1);
    int valor2_c1 = obterValorAtributo(c1, atributo2);

    int valor1_c2 = obterValorAtributo(c2, atributo1);
    int valor2_c2 = obterValorAtributo(c2, atributo2);

    int pontos_c1 = 0, pontos_c2 = 0;

    // Lógica de decisão composta com if-else
    pontos_c1 += (valor1_c1 > valor1_c2) ? 1 : (valor1_c1 < valor1_c2) ? 0 : 0;
    pontos_c2 += (valor1_c2 > valor1_c1) ? 1 : (valor1_c2 < valor1_c1) ? 0 : 0;

    pontos_c1 += (valor2_c1 > valor2_c2) ? 1 : (valor2_c1 < valor2_c2) ? 0 : 0;
    pontos_c2 += (valor2_c2 > valor2_c1) ? 1 : (valor2_c2 < valor2_c1) ? 0 : 0;

    printf("\n🔍 Comparando os atributos: %s e %s\n", nomeAtributo(atributo1), nomeAtributo(atributo2));
    printf("Resultado da Comparacao:\n");
    printf("%s: %d pontos\n", c1.nome, pontos_c1);
    printf("%s: %d pontos\n", c2.nome, pontos_c2);

    // Estrutura de decisão final
    if (pontos_c1 > pontos_c2) {
        printf("\n🏆 Vencedor: %s!\n", c1.nome);
    } else if (pontos_c2 > pontos_c1) {
        printf("\n🏆 Vencedor: %s!\n", c2.nome);
    } else {
        printf("\n⚔️ Empate! Nenhuma carta venceu.\n");
    }
}

void exibirMenuAtributos() {
    printf("Escolha um atributo:\n");
    printf("1 - Forca\n");
    printf("2 - Velocidade\n");
    printf("3 - Inteligencia\n");
    printf("Digite sua escolha: ");
}

int main() {
    Carta cartas[MAX_CARTAS];
    int continuar = 1;

    printf("=========== BATALHA DE CARTAS - NIVEL MESTRE ===========\n");

    // Cadastro das 2 cartas
    for (int i = 0; i < MAX_CARTAS; i++) {
        printf("\nCadastro da carta %d:\n", i + 1);
        cadastrarCarta(&cartas[i]);
    }

    while (continuar) {
        printf("\nCartas cadastradas:\n");
        for (int i = 0; i < MAX_CARTAS; i++) {
            mostrarCarta(cartas[i]);
        }

        int atributo1, atributo2;

        // Escolha dos dois atributos
        exibirMenuAtributos();
        scanf("%d", &atributo1);

        exibirMenuAtributos();
        scanf("%d", &atributo2);

        // Validação de entrada
        if ((atributo1 < 1 || atributo1 > 3) || (atributo2 < 1 || atributo2 > 3) || atributo1 == atributo2) {
            printf("❌ Atributos inválidos ou repetidos. Tente novamente.\n");
            continue;
        }

        // Comparação e resultado
        compararCartas(cartas[0], cartas[1], atributo1, atributo2);

        // Continuar?
        char resposta;
        printf("\nDeseja realizar outra comparacao? (s/n): ");
        scanf(" %c", &resposta);
        if (resposta != 's' && resposta != 'S') {
            continuar = 0;
            printf("👋 Encerrando o jogo. Obrigado por jogar!\n");
        }
    }

    return 0;
}
