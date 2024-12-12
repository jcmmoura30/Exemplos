#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 200000

void merge(int *vetor, int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = vetor[inicio + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = vetor[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

int main() {
    clock_t t; 
    int vetor[TAM];

    srand((unsigned)time(NULL));

  
    for (int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM; 

    t = clock(); 
    mergeSort(vetor, 0, TAM - 1);
    t = clock() - t; 

   
    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000))); 

    return 0;
}
