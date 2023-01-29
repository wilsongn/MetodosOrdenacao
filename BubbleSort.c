#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Interface.h"

double bubbleSort(int * vetor, int tamanhoVetor)
{
    int max = 10000000;
    double tempoExecucao = 0;
    // Incia contagem de tempo de execução
    clock_t inicio = clock();

    for (int i = 0; i < tamanhoVetor - 1; i++)
    {
        for (int j = 0; j < tamanhoVetor - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    // Finaliza contagem de tempo de execução
    clock_t fim = clock();
    tempoExecucao += (double)(fim - inicio) / CLOCKS_PER_SEC;

    return tempoExecucao;

}