#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Gerando os valores aletórios de acordo com o parâmetro passado.
void GerarVetor(int * vetor, int tamanhoVetor, int max)
{  
    //Gera uma "semente" diferente de acordo com o horário da máquina
    srand(time(NULL)); 
    
    for(int i = 0; i < tamanhoVetor; i++)
    {
        vetor[i] = rand();
    }
}