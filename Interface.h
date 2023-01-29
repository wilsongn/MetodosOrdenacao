//Essa interface contém funções de todos os métodos de ordenação e do gerador de teste
#include <stdio.h>
#include <stdlib.h>

//Comando que da início a todos os testes
void IniciaTeste();

//Inicia os testes do método CountingSort
void IniciaTesteCounting(int numeroTestes, int tamanhoVetor, int max, int numeroGrupos);

//Inicia os testes do método BucketSort
void IniciaTesteBucketSort(int numeroTestes, int tamanhoVetor, int max, int numeroGrupos);

//Inicia os testes do método QuickSort
void IniciaTesteQuickSort(int numeroTestes, int tamanhoVetor, int maxi, int numeroGrupos);

//Inicia os testes do método SelectionSort
void IniciaTesteSelectionSort(int numeroTestes, int tamanhoVetor, int max, int numeroGrupos);

//Inicia os testes do método InsertionSort
void IniciaTesteInsertionSort(int numeroTestes, int tamanhoVetor, int max, int numeroGrupos);

//Inicia os testes do método BubbleSort
void IniciaTesteBubbleSort(int numeroTestes, int tamanhoVetor, int max, int numeroGrupos);

//Inicia os testes do método MergeSort
void IniciaTesteMergeSort(int numeroTestes, int tamanhoVetor, int max, int numeroGrupos);

//Gera os valores aletórios para um vetor de acordo com o parâmetro passado.
void GerarVetor(int * vetor, int tamanhoVetor, int max);

//Printa uma linha da tabela para um arquivo txt
void printaLinhaArquivo(double media, int tamanhoVetor);

//Função que ordena o vetor pelo método counting sort
double counting_sort(int* vetor, int tamanhoVetor, int max);

//Função que ordena o vetor pelo método QuickSort
double quickSort(int * vetor, int esquerda, int direita, int tamanhoVetor);

//Função que ordena o vetor pelo método Selection Sort
double selectionSort(int * vetor, int tamanhoVetor);

//Função que ordena o vetor pelo método Insertion Sort
double insertionSort(int * vetor,int tamanhoVetor);

//Função que ordena o vetor pelo método bubble Sort
double bubbleSort(int * vetor,int tamanhoVetor);

//Função que ordena o vetor pelo método merge Sort
double merge_Sort(int * vetor, int tamanhoVetor);

//Função que ordena o vetor pelo método Radix Sort
double radixSort(int *vetor, int tamanhoVetor);

//Função que ordena o vetor pelo método Bucket Sort
double BucketSort(int* vetor, int tamanhoVetor);

//Função para validar a ordenação, retorna 1 se tiver ordenado de forma crescente e 0 se não estiver ordenado
int ValidaOrdenacao(int * vetor, int tamanhoVetor);