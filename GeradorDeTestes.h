#include <stdlib.h>

//Gerando os valores aletórios de acordo com o parâmetro passado.
void GerarVetor(int * vetor, int tamanhoVetor){  

    for(int i = 0; i < tamanhoVetor; i++){
        vetor[i] = rand();
    }
    
}