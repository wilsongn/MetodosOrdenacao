#include <stdio.h>
#include<limits.h>
#include<time.h>
#include "Interface.h"

//Copiada de: https://www.sanfoundry.com/c-program-sorts-array-using-bucket-sort/
//Função para achar o maior elemento do vetor
int max_element(int vetor[], int tamanhoVetor) 
{  
    // Inicializa a váriavel max com o menor valor possível
    int max = INT_MIN;  
    for (int i = 0; i < tamanhoVetor; i++)
    {
        //Quando encontrar um valor maior que o contido na varíavel max, troca
        if (vetor[i] > max)  
        max = vetor[i];  
    }
    //return the max element
    return max;  
}

//Copiada de: https://www.sanfoundry.com/c-program-sorts-array-using-bucket-sort/
double BucketSort(int * vetor, int tamanhoVetor) 
{  
    double tempoExecucao = 0;

    // Incia contagem de tempo de execução
    clock_t inicio = clock();

    // Função para achar o maior elemento do vetor
    int max = max_element(vetor, tamanhoVetor); 

    // Criando os baldes
    int bucket[max+1];  
 
    // Iniciando o balde com o valor zero
    for (int i = 0; i <= max; i++)  
    bucket[i] = 0;  
 
    // Separando elementos nos baldes correspondentes
    for (int i = 0; i < tamanhoVetor; i++)  
    bucket[vetor[i]]++;
 
    // Juntando os baldes
    int j=0; 
    for (int i = 0; i <= max; i++)  
    { 
        while (bucket[i] > 0)  
        {        
            vetor[j++] = i;  
            bucket[i]--;   
        }  
    }
    // Finaliza contagem de tempo de execução
    clock_t fim = clock();

    tempoExecucao += (double)(fim - inicio) / CLOCKS_PER_SEC;

    return tempoExecucao;
}