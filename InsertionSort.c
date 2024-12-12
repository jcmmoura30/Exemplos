#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 200000 

void insertionSort(int *vetor, int tamanho) {
    int i, j, key;
    for (i = 1; i < tamanho; i++) {
        key = vetor[i];
        j = i - 1;

      
        while (j >= 0 && vetor[j] > key) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = key;
    }
}

int main() {
    clock_t t; 
    int vetor[TAM];


    srand((unsigned)time(NULL)); 

  
    for(int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM; 

   
    t = clock();
    insertionSort(vetor, TAM); 
    t = clock() - t;


    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000))); 

    return 0;
}
