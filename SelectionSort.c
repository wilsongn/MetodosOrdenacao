#include <stdio.h>
#include <time.h>
#include "Interface.h"

double selectionSort(int * vetor, int tamanhoVetor) {
    int i, j, menor, temp;
    int max = 10000000;
    double tempoExecucao = 0; 

    // Incia contagem de tempo de execução
    clock_t inicio = clock();

    for (i = 0; i < tamanhoVetor-1; i++) {
        menor = i;
        for (j = i+1; j < tamanhoVetor; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }
        temp = vetor[menor];
        vetor[menor] = vetor[i];
        vetor[i] = temp;
    }

    // Finaliza contagem de tempo de execução
    clock_t fim = clock();
    tempoExecucao += (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    return tempoExecucao;
}