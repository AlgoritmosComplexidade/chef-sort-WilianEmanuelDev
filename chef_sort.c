#include <stdio.h>
#include <string.h>

// ANÁLISE DE ALGORITMO - Desafio Chef Sort
// Este é o arquivo inicial para o desafio. 
// Dependendo do nível escolhido (Novato, Aventureiro ou Mestre), 
// descomente e utilize as estruturas e funções correspondentes.

// ====================================================================
// ESTRUTURAS DE DADOS (Para Níveis Aventureiro e Mestre)
// ====================================================================

// Struct para o Nível Aventureiro
/*
typedef struct {
    char nome[50];
    int qtd_ingredientes;
} Prato;
*/

// Struct para o Nível Mestre
/*
typedef struct {
    char nome_prato[50];
    int numero_comanda;
} Comanda;
*/

// ====================================================================
// PROTÓTIPOS DAS FUNÇÕES DE ORDENAÇÃO
// ====================================================================

// Nível Novato: Bubble Sort para strings
// Dica: Use strcmp() da biblioteca <string.h> para comparar strings.
// Dica: Passe ponteiros para contadores de comparações e trocas se quiser alterá-los dentro da função.
void bubbleSortStrings(char arr[][50], int n, int *comparacoes, int *trocas) {
    // Sua lógica do Bubble Sort aqui
}

// Nível Aventureiro: Selection Sort para array de structs (Prato)
/*
void selectionSortPratos(Prato arr[], int n) {
    // Sua lógica do Selection Sort aqui buscando a menor qtd_ingredientes
}
*/

// Nível Mestre: Recursive Insertion Sort para array de structs (Comanda)
// Dica: Lembre-se de definir o "caso base" (n <= 1) para parar a recursão!
/*
void recursiveInsertionSort(Comanda arr[], int n) {
    // Sua lógica do Insertion Sort Recursivo aqui
}
*/

// ====================================================================
// FUNÇÃO PRINCIPAL
// ====================================================================

typedef struct {
    char nome[40];              // Nome do prato
    int quantidadeIngredientes; // Quantidade de ingredientes
} Prato;

int main() {

    printf("=== BEM-VINDO AO CHEF SORT ===\n\n");

    #define QTD_INGREDIENTES 6   // Quantidade de ingredientes
    #define TAM 30               // Tamanho máximo de cada string
    #define QTD_PRATOS 5

    int i, j;

    // ---------------------------------------------------------
    // ÁREA DO NÍVEL NOVATO (Despensa / Bubble Sort)
    // ---------------------------------------------------------

    // Vetor bidimensional de strings com os ingredientes
    char ingredientes[QTD_INGREDIENTES][TAM] = {
        "Tomate",
        "Cebola",
        "Alho",
        "Manjericao",
        "Azeite",
        "Sal"
    };

    char tempStr[TAM];     // Variável auxiliar para troca de strings
    int comparacoes = 0;   // Contador de comparações entre strings
    int trocas = 0;        // Contador de trocas realizadas

    printf("--- Nivel Novato: Organizando a Despensa ---\n");
    //printf("Lista ANTES da ordenacao:\n");

    // ----------------------------
    // Exibição da lista ANTES da ordenação
    // ----------------------------
    printf("============================================\n");
    printf("  LISTA DE INGREDIENTES (ANTES DA ORDENACAO)\n");
    printf("============================================\n");

    for (i = 0; i < QTD_INGREDIENTES; i++) {
        printf("- %s\n", ingredientes[i]);
    }

    // Chamada da funcao bubbleSortStrings(...)
    // ----------------------------
    // Algoritmo Bubble Sort
    // ----------------------------
    // Percorre o vetor várias vezes empurrando os maiores
    // elementos (em ordem alfabética) para o final
    for (i = 0; i < QTD_INGREDIENTES - 1; i++) {
        for (j = 0; j < QTD_INGREDIENTES - 1 - i; j++) {

            // Conta cada comparação realizada
            comparacoes++;

            // strcmp:
            // > 0 → primeira string vem depois alfabeticamente
            // < 0 → primeira string vem antes alfabeticamente
            // = 0 → strings iguais
            if (strcmp(ingredientes[j], ingredientes[j + 1]) > 0) {

                // Troca das strings usando uma variável temporária
                strcpy(tempStr, ingredientes[j]);
                strcpy(ingredientes[j], ingredientes[j + 1]);
                strcpy(ingredientes[j + 1], tempStr);

                // Conta a troca realizada
                trocas++;
            }
        }
    }

    //printf("\nLista DEPOIS da ordenacao:\n");

    // ----------------------------
    // Exibição da lista APÓS a ordenação
    // ----------------------------
    printf("============================================\n");
    printf("  LISTA DE INGREDIENTES (APOS A ORDENACAO)\n");
    printf("============================================\n");

    for (i = 0; i < QTD_INGREDIENTES; i++) {
        printf("- %s\n", ingredientes[i]);
    }

    // ----------------------------
    // Exibição das métricas do algoritmo
    // ----------------------------
    printf("\n============================================\n");
    printf("  METRICAS DO BUBBLE SORT\n");
    printf("============================================\n");
    printf("Comparacoes realizadas: %d\n", comparacoes);
    printf("Trocas realizadas:      %d\n", trocas);

    // ---------------------------------------------------------
    // ÁREA DO NÍVEL AVENTUREIRO (Pratos / Selection Sort)
    // ---------------------------------------------------------

    // Inicialize aqui o seu vetor de Pratos
    // Vetor fixo de pratos com diferentes complexidades
    Prato pratos[QTD_PRATOS] = {
        {"Arroz Branco", 3},
        {"Feijoada", 10},
        {"Macarrao Alho e Oleo", 5},
        {"Omelete", 4},
        {"Lasanha", 8}
    };

    int menor;
    Prato tempPrato;

    /*
    printf("\n--- Nivel Aventureiro: Organizando os Pratos ---\n");
    // Imprima antes, chame a funcao selectionSortPratos, imprima depois
    */

    // ----------------------------
    // Impressão ANTES da ordenação
    // ----------------------------
    printf("\n============================================\n");
    printf("  LISTA DE PRATOS (ANTES DA ORDENACAO)\n");
    printf("============================================\n");

    for (i = 0; i < QTD_PRATOS; i++) {
        printf("Prato: %-22s | Ingredientes: %d\n",
               pratos[i].nome,
               pratos[i].quantidadeIngredientes);
    }

    // ----------------------------
    // Algoritmo Selection Sort
    // ----------------------------
    // A cada iteração, seleciona o prato com menor
    // quantidade de ingredientes e o posiciona corretamente
    for (i = 0; i < QTD_PRATOS - 1; i++) {

        // Assume que o menor elemento está na posição atual
        menor = i;

        // Procura o menor valor no restante do vetor
        for (j = i + 1; j < QTD_PRATOS; j++) {
            if (pratos[j].quantidadeIngredientes <
                pratos[menor].quantidadeIngredientes) {
                menor = j;
            }
        }

        // Realiza a troca apenas se necessário
        if (menor != i) {
            tempPrato = pratos[i];
            pratos[i] = pratos[menor];
            pratos[menor] = tempPrato;
        }
    }

    // ----------------------------
    // Impressão APÓS a ordenação
    // ----------------------------
    printf("\n============================================\n");
    printf("  LISTA DE PRATOS (APOS A ORDENACAO)\n");
    printf("============================================\n");

    for (i = 0; i < QTD_PRATOS; i++) {
        printf("Prato: %-22s | Ingredientes: %d\n",
               pratos[i].nome,
               pratos[i].quantidadeIngredientes);
    }

    // ---------------------------------------------------------
    // ÁREA DO NÍVEL MESTRE (Comandas / Recursive Insertion Sort)
    // ---------------------------------------------------------
    /*
    // Inicialize aqui o seu vetor de Comandas
    
    printf("\n--- Nivel Mestre: Organizando as Comandas ---\n");
    // Imprima antes, chame a funcao recursiveInsertionSort, imprima depois
    */

    return 0;
}
