#include <stdlib.h>
#include <time.h>
#include "Interface.h"

//Partialmente copiado: https://www.geeksforgeeks.org/quick-sort/
double quickSort(int * vetor, int esquerda, int direita, int tamanhoVetor) {
    int i = esquerda;
    int j = direita;
    double tempoExecucao = 0;

    // Incia contagem de tempo de execução
    clock_t inicio = clock();
    
    // Escolhendo o elemento do meio do subvetor como o pivô
    int pivo = vetor[(esquerda + direita) / 2];

    while (i <= j) {
        // Movendo o ponteiro i para o próximo elemento maior que o pivô
        while (vetor[i] < pivo) {
            i++;
        }
        // Movendo o ponteiro j para o próximo elemento menor que o pivô
        while (vetor[j] > pivo) {
            j--;
        }
        // Se i é menor ou igual a j, troca os elementos de lugar
        if (i <= j) {
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
            i++;
            j--;
        }
    }
    // Se a esquerda é menor que j, chama a função novamente para o subvetor da esquerda
    if (esquerda < j) {
        quickSort(vetor, esquerda, j, tamanhoVetor);
    }
    // Se i é menor que a direita, chama a função novamente para o subvetor da direita
    if (i < direita) {
        quickSort(vetor, i, direita, tamanhoVetor);
    }
    
    // Finaliza contagem de tempo de execução
    clock_t fim = clock();
    tempoExecucao += (double)(fim - inicio) / CLOCKS_PER_SEC;

    return tempoExecucao;
}
