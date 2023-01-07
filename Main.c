#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GeradorDeTestes.h"

int main(void){
    int teste = 10;
    int * vetor;

    vetor = (int*)malloc(teste * sizeof(int));
    
    srand(time(NULL)); //Gera uma "semente" diferente de acordo com o horário da máquina
    GerarVetor(vetor, teste);

    for(int i = 0; i < teste; i++){
        printf("%d\n", vetor[i]);
    }

    free(vetor);

    return 0;
}