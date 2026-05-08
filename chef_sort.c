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


#define QTD 6     // Quantidade de ingredientes
#define TAM 30    // Tamanho máximo de cada string

// ====================================================================
// FUNÇÃO PRINCIPAL
// ====================================================================
int main() {
    printf("=== BEM-VINDO AO CHEF SORT ===\n\n");

    // ---------------------------------------------------------
    // ÁREA DO NÍVEL NOVATO (Despensa / Bubble Sort)
    // ---------------------------------------------------------
    
   // Vetor bidimensional de strings com os ingredientes
    char ingredientes[QTD][TAM] = {
        "Tomate",
        "Cebola",
        "Alho",
        "Manjericao",
        "Azeite",
        "Sal"
    };

    char temp[TAM];     // Variável auxiliar para troca de strings
    int i, j;

    int comparacoes = 0; // Contador de comparações entre strings
    int trocas = 0;      // Contador de trocas realizadas


    printf("--- Nivel Novato: Organizando a Despensa ---\n");
    printf("Lista ANTES da ordenacao:\n");
    // Laco para imprimir ingredientes antes
    // ----------------------------
    // Exibição da lista ANTES da ordenação
    // ----------------------------
    printf("============================================\n");
    printf("  LISTA DE INGREDIENTES (ANTES DA ORDENACAO)\n");
    printf("============================================\n");

    for (i = 0; i < QTD; i++) {
        printf("- %s\n", ingredientes[i]);
    }
    // Chamada da funcao bubbleSortStrings(...)
    // ----------------------------
    // Algoritmo Bubble Sort
    // ----------------------------
    // Percorre o vetor várias vezes empurrando os maiores
    // elementos (em ordem alfabética) para o final
    for (i = 0; i < QTD - 1; i++) {

        for (j = 0; j < QTD - 1 - i; j++) {

            // Conta cada comparação realizada
            comparacoes++;

            // strcmp:
            // > 0 → primeira string vem depois alfabeticamente
            // < 0 → primeira string vem antes alfabeticamente
            // = 0 → strings iguais
            if (strcmp(ingredientes[j], ingredientes[j + 1]) > 0) {

                // Troca das strings usando uma variável temporária
                strcpy(temp, ingredientes[j]);
                strcpy(ingredientes[j], ingredientes[j + 1]);
                strcpy(ingredientes[j + 1], temp);

                // Conta a troca realizada
                trocas++;
            }
        }
    }

    printf("\nLista DEPOIS da ordenacao:\n");
    // Laco para imprimir ingredientes depois
    // Imprimir totais de comparacoes e trocas
    // ----------------------------
    // Exibição da lista APÓS a ordenação
    // ----------------------------
    printf("\n============================================\n");
    printf("  LISTA DE INGREDIENTES (APOS A ORDENACAO)\n");
    printf("============================================\n");

    for (i = 0; i < QTD; i++) {
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
    /*
    // Inicialize aqui o seu vetor de Pratos
    
    printf("\n--- Nivel Aventureiro: Organizando os Pratos ---\n");
    // Imprima antes, chame a funcao selectionSortPratos, imprima depois
    */


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
