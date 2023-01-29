#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Interface.h"

int ValidaOrdenacao(int * vetor, int tamanhoVetor)
{
    int i;
    for (i = 0; i < tamanhoVetor - 1; i++) 
    {
        if (vetor[i] > vetor[i + 1]) 
        {
            return 0;
        }
    }
    return 1;
}

int count_digito(int n) 
{
    int count = 0;
    while (n != 0) 
    {
        n /= 10;
        count++;
    }
    return count;
}

int count_digitoDouble(double num) 
{
    int count = 0;
    int int_num = (int)num;
    if(num > 0 && num < 1) count++;
    while (int_num != 0) 
    {
        int_num /= 10;
        count++;
    }
    return count;
}

void printaLinhaArquivo(double media, int tamanhoVetor)
{
    int tamanhoLinha = 20;
    FILE * file;
    file = fopen("tabela.txt", "a");

    fprintf(file, "|40                   |");
    fprintf(file, "%d", tamanhoVetor);
    while((tamanhoLinha-count_digito(tamanhoVetor)))
    {
        fprintf(file, " ");
        tamanhoLinha--;
    }
    tamanhoLinha = 9;
    fprintf(file, "|%.10lf", media*1000);
    while ((tamanhoLinha-count_digitoDouble(media*1000)))
    {
        fprintf(file, " ");
        tamanhoLinha--;
    }
    
    fprintf(file, "|\n");
    fprintf(file, "+---------------------------------------------------------------+\n");
    fclose(file);
}

void IniciaTesteCounting(int numeroTestes, int tamanhoVetor, int max, int numeroGrupos)
{   
    if(numeroGrupos == 8)
    {
        FILE * file;
        file = fopen("tabela.txt", "a");
        fprintf(file, "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        fprintf(file, "\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fprintf(file, "|Counting Sort                                                  |\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fprintf(file, "|Numero de vetores    |Tamanho dos vetores |Tempo (ms)          |\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fclose(file);
    }
    if(numeroGrupos != 0)
    {
        double mediaTempoExecucao;
        double total = 0;
        int count;
        int aux = numeroTestes;
        double tempoExecucaoCounting;
        while(numeroTestes)
        {
            int * vetor;
            vetor = (int*) malloc(tamanhoVetor * sizeof(int));

            GerarVetor(vetor, tamanhoVetor, max);
            tempoExecucaoCounting = counting_sort(vetor, tamanhoVetor, max);
            free(vetor);
            total += tempoExecucaoCounting;
            
            numeroTestes--;
        }
        mediaTempoExecucao = total / 40;
        printaLinhaArquivo(mediaTempoExecucao, tamanhoVetor);
        IniciaTesteCounting(aux, tamanhoVetor*5, max, numeroGrupos-1);
    }
}

void IniciaTesteSelectionSort(int numeroTestes, int tamanhoVetor, int max, int numeroGrupos)
{
    double tempoExecucao;
    double total = 0;
    int i = 0;
    int * vetor;
    int aux = numeroTestes;
    double mediaTempoExecucao;
    if(numeroGrupos == 8)
    {
        FILE * file;
        file = fopen("tabela.txt", "a");
        fprintf(file, "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        fprintf(file, "\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fprintf(file, "|Selection Sort                                                 |\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fprintf(file, "|Numero de vetores    |Tamanho dos vetores |Tempo (ms)          |\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fclose(file);
    }
    if(numeroGrupos != 0)
    {
        while (numeroTestes)
        {
            int * vetor;
            vetor = (int*) malloc(tamanhoVetor * sizeof(int));
            GerarVetor(vetor, tamanhoVetor, max);
            tempoExecucao = selectionSort(vetor, tamanhoVetor);
            if(!ValidaOrdenacao(vetor, tamanhoVetor)) printf("Falha na ordenação\n");
            free(vetor);
            total += tempoExecucao;
            numeroTestes--;
        }
        mediaTempoExecucao = total / 40;
        printaLinhaArquivo(mediaTempoExecucao, tamanhoVetor);
        IniciaTesteSelectionSort(aux, tamanhoVetor*5, max, numeroGrupos-1);
    }
}

void IniciaTesteBubbleSort(int numeroTestes, int tamanhoVetor, int max, int numeroGrupos)
{
    double tempoExecucao;
    double total = 0;
    int i = 0;
    int * vetor;
    int aux = numeroTestes;
    double mediaTempoExecucao;
    if(numeroGrupos == 8)
    {
        FILE * file;
        file = fopen("tabela.txt", "a");
        fprintf(file, "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        fprintf(file, "\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fprintf(file, "|Bubble Sort                                                    |\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fprintf(file, "|Numero de vetores    |Tamanho dos vetores |Tempo (ms)          |\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fclose(file);
    }
    if(numeroGrupos != 0)
    {
        while (numeroTestes)
        {
            vetor = (int*) malloc(tamanhoVetor * sizeof(int));
            GerarVetor(vetor, tamanhoVetor, max);
            tempoExecucao = bubbleSort(vetor, tamanhoVetor);
            if(!ValidaOrdenacao(vetor, tamanhoVetor)) printf("Falha na ordenação\n");
            free(vetor);
            total += tempoExecucao;
            numeroTestes--;
        }
        mediaTempoExecucao = total / 40;
        printaLinhaArquivo(mediaTempoExecucao, tamanhoVetor);
        IniciaTesteBubbleSort(aux, tamanhoVetor*5, max, numeroGrupos-1);
    }
}

void IniciaTesteInsertionSort(int numeroTestes, int tamanhoVetor, int max, int numeroGrupos)
{
    double tempoExecucao;
    double total = 0;
    int i = 0;
    int * vetor;
    int aux = numeroTestes;
    double mediaTempoExecucao;
    if(numeroGrupos == 8)
    {
        FILE * file;
        file = fopen("tabela.txt", "a");
        fprintf(file, "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        fprintf(file, "\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fprintf(file, "|Insertion Sort                                                 |\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fprintf(file, "|Numero de vetores    |Tamanho dos vetores |Tempo (ms)          |\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fclose(file);
    }
    if(numeroGrupos != 0)
    {
        while (numeroTestes)
        {
            vetor = (int*) malloc(tamanhoVetor * sizeof(int));
            GerarVetor(vetor, tamanhoVetor, max);
            tempoExecucao = insertionSort(vetor, tamanhoVetor);
            if(!ValidaOrdenacao(vetor, tamanhoVetor)) printf("Falha na ordenação\n");
            free(vetor);
            total += tempoExecucao;
            numeroTestes--;
        }
        mediaTempoExecucao = total / 40;
        printaLinhaArquivo(mediaTempoExecucao, tamanhoVetor);
        IniciaTesteInsertionSort(aux, tamanhoVetor*5, max, numeroGrupos-1);
    }
}

void IniciaTesteQuickSort(int numeroTestes, int tamanhoVetor, int max, int numeroGrupos)
{
    double tempoExecucao = 0;
    double total = 0;
    int * vetor;
    int aux = numeroTestes;
    double mediaTempoExecucao;
    if(numeroGrupos == 8)
    {
        FILE * file;
        file = fopen("tabela.txt", "a");
        fprintf(file, "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        fprintf(file, "\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fprintf(file, "|Quick Sort                                                     |\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fprintf(file, "|Numero de vetores    |Tamanho dos vetores |Tempo (ms)          |\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fclose(file);
    }
    if(numeroGrupos != 0)
    {
        while (numeroTestes)
        {
            vetor = (int*) malloc(tamanhoVetor * sizeof(int));
            GerarVetor(vetor, tamanhoVetor, max);
            tempoExecucao = quickSort(vetor, 0, tamanhoVetor-1, tamanhoVetor);
            if(!ValidaOrdenacao(vetor, tamanhoVetor)) printf("Falha na ordenação\n");
            total += tempoExecucao;
            numeroTestes--;
            free(vetor);
        }
        mediaTempoExecucao = total / 40;
        printaLinhaArquivo(mediaTempoExecucao, tamanhoVetor);
        IniciaTesteQuickSort(aux, tamanhoVetor*5, max, numeroGrupos-1);
    }
}

void IniciaTesteMergeSort(int numeroTestes, int tamanhoVetor, int max, int numeroGrupos)
{
    double tempoExecucao = 0;
    double total = 0;
    int aux = numeroTestes;
    double mediaTempoExecucao;
    if(numeroGrupos == 8)
    {
        FILE * file;
        file = fopen("tabela.txt", "a");
        fprintf(file, "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        fprintf(file, "\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fprintf(file, "|Merge Sort                                                     |\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fprintf(file, "|Numero de vetores    |Tamanho dos vetores |Tempo (ms)          |\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fclose(file);
    }
    if(numeroGrupos != 0)
    {
        while (numeroTestes)
        {
            int * vetor;
            vetor = (int*) malloc(tamanhoVetor * sizeof(int));
            GerarVetor(vetor, tamanhoVetor, max);
            tempoExecucao = merge_Sort(vetor, tamanhoVetor);
            printf("%d\n", numeroGrupos);
            if(!ValidaOrdenacao(vetor, tamanhoVetor)) printf("Falha na ordenação\n");
            total += tempoExecucao;
            numeroTestes--;
            free(vetor);
        }
        mediaTempoExecucao = total / 40;
        printaLinhaArquivo(mediaTempoExecucao, tamanhoVetor);
        IniciaTesteMergeSort(aux, tamanhoVetor*5, max, numeroGrupos-1);
    }
}

void IniciaTesteBucketSort(int numeroTestes, int tamanhoVetor, int max, int numeroGrupos)
{
    double tempoExecucao = 0;
    double total = 0;
    int * vetor;
    int aux = numeroTestes;
    double mediaTempoExecucao;
    if(numeroGrupos == 8)
    {   
        FILE * file;
        file = fopen("tabela.txt", "a");
        fprintf(file, "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        fprintf(file, "\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fprintf(file, "|Bucket Sort                                                    |\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fprintf(file, "|Numero de vetores    |Tamanho dos vetores |Tempo (ms)          |\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fclose(file);
    }
    if(numeroGrupos != 0)
    {
        while (numeroTestes)
        {
            vetor = (int*) malloc(tamanhoVetor * sizeof(int));
            GerarVetor(vetor, tamanhoVetor, max);
            tempoExecucao = BucketSort(vetor, tamanhoVetor);
            if(!ValidaOrdenacao(vetor, tamanhoVetor)) printf("Falha na ordenação\n");
            total += tempoExecucao;
            numeroTestes--;
            free(vetor);
        }
        mediaTempoExecucao = total / 40;
        printaLinhaArquivo(mediaTempoExecucao, tamanhoVetor);
        IniciaTesteBucketSort(aux, tamanhoVetor*5, max, numeroGrupos-1);
    }
}

void IniciaTesteRadixSort(int numeroTestes, int tamanhoVetor, int max, int numeroGrupos)
{
    double tempoExecucao = 0;
    double total = 0;
    int * vetor;
    int aux = numeroTestes;
    double mediaTempoExecucao;
    if(numeroGrupos == 8)
    {
        FILE * file;
        file = fopen("tabela.txt", "a");
        fprintf(file, "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        fprintf(file, "\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fprintf(file, "|Radix Sort                                                     |\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fprintf(file, "|Numero de vetores    |Tamanho dos vetores |Tempo (ms)          |\n");
        fprintf(file, "+---------------------------------------------------------------+\n");
        fclose(file);
    }
    if(numeroGrupos != 0)
    {
        while (numeroTestes)
        {
            vetor = (int*) malloc(tamanhoVetor * sizeof(int));
            GerarVetor(vetor, tamanhoVetor, max);
            tempoExecucao = radixSort(vetor, tamanhoVetor);
            if(!ValidaOrdenacao(vetor, tamanhoVetor)) printf("Falha na ordenação\n");
            total += tempoExecucao;
            numeroTestes--;
            free(vetor);
        }
        mediaTempoExecucao = total / 40;
        printaLinhaArquivo(mediaTempoExecucao, tamanhoVetor);
        IniciaTesteRadixSort(aux, tamanhoVetor*5, max, numeroGrupos-1);
    }
}

void IniciaTeste()
{
    IniciaTesteSelectionSort(40, 50, 10000000, 8);

    IniciaTesteInsertionSort(40, 50, 10000000, 8);

    IniciaTesteBubbleSort(40, 50, 10000000, 8);

    IniciaTesteCounting(40, 50, 10000000, 8);

    IniciaTesteQuickSort(40, 50, 10000000, 8);

    IniciaTesteMergeSort(40, 50, 10000000, 8);

    IniciaTesteRadixSort(40, 50, 10000000, 8);

    IniciaTesteBucketSort(40, 50, 10000000, 8);
}