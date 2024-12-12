#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 200000

int partition(int *vetor, int inicio, int fim) {
    int pivo = vetor[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;
    return (i + 1);
}

void quickSort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pi = partition(vetor, inicio, fim);
        quickSort(vetor, inicio, pi - 1);
        quickSort(vetor, pi + 1, fim);
    }
}

int main() {
    clock_t t; 
    int vetor[TAM];

  
    srand((unsigned)time(NULL)); 

 
    for (int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

  
    t = clock(); 
    quickSort(vetor, 0, TAM - 1); 
    t = clock() - t; 


    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000))); 

    return 0;
}
