#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Interface.h"
//Parcialmente copiado: https://www.geeksforgeeks.org/counting-sort/
double counting_sort(int * vetor,int tamanhoVetor, int max) {
    double tempoExecucao = 0;
    int maior = 10000000;

    // Incia contagem de tempo de execução
    clock_t inicio = clock();

    // Cria um vetor de contagem de tamanho k+1 para armazenar as contagens de cada elemento
    int *count = (int*)malloc((maior+1) * sizeof(int));
    // Cria um vetor de saída de tamanho n para armazenar os elementos ordenados
    int *output = (int*)malloc(tamanhoVetor * sizeof(int));

    // Inicializa o vetor de contagem com 0
    for (int i = 0; i <= maior; i++) {
        count[i] = 0;
    }

    // Conta a ocorrência de cada elemento no vetor de entrada
    for (int i = 0; i < tamanhoVetor; i++) {
        count[vetor[i]]++;
    }

    // Modifica o vetor de contagem para que cada elemento contenha a soma dos elementos anteriores
    for (int i = 1; i <= maior; i++) {
        count[i] += count[i-1];
    }

    // Coloca cada elemento do vetor de entrada em sua posição no vetor de saída
    for (int i = tamanhoVetor-1; i >= 0; i--) {
        output[count[vetor[i]]-1] = vetor[i];
        count[vetor[i]]--;
    }

    // Copia os elementos do vetor de saída de volta para o vetor de entrada
    for (int i = 0; i < tamanhoVetor; i++) {
        vetor[i] = output[i];
    }

    // Libera a memória alocada para todos os vetores
    free(count);
    free(output);

    // Finaliza contagem de tempo de execução
    clock_t fim = clock();
    tempoExecucao += (double)(fim - inicio) / CLOCKS_PER_SEC;

    return tempoExecucao;
}