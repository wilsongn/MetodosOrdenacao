#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Interface.h"

/* Função para obter o dígito mais significativo de um número */
int getMax(int *vetor, int tamanhoVetor) {
    int max = vetor[0];
    for (int i = 1; i < tamanhoVetor; i++)
        if (vetor[i] > max)
            max = vetor[i];
    return max;
}

/* Função de ordenação radix */
double radixSort(int *vetor, int tamanhoVetor) {
    int exp, m = getMax(vetor, tamanhoVetor);
    double tempoExecucao = 0;

    // Incia contagem de tempo de execução
    clock_t inicio = clock();
    /* Loop para percorrer cada dígito */
    for (exp = 1; m/exp > 0; exp *= 10)
        counting_sort(vetor, tamanhoVetor, exp);
    // Finaliza contagem de tempo de execução
    clock_t fim = clock();
    tempoExecucao += (double)(fim - inicio) / CLOCKS_PER_SEC;

    return tempoExecucao;
}
