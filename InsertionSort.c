#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Interface.h"

double insertionSort(int * vetor, int tamanhoVetor) {
    int i, marcado, j;
    int max = 10000000;
    double tempoExecucao = 0;

    // Incia contagem de tempo de execução
    clock_t inicio = clock();

    for (i = 1; i < tamanhoVetor; i++) {
        marcado = vetor[i];
        j = i-1;
        while (j >= 0 && vetor[j] > marcado) {
            vetor[j+1] = vetor[j];
            j = j-1;
        }
        vetor[j+1] = marcado;
    }

    // Finaliza contagem de tempo de execução
    clock_t fim = clock();
    tempoExecucao += (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    return tempoExecucao;
}
