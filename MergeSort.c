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
    clock_t t; //variável para armazenar tempo
    int vetor[TAM];

    //semente de aleatoriedade
    srand((unsigned)time(NULL)); //o algoritmo tem como semente a hora atual que o código é executado

    //geração aleatório dos valores do vetor
    for (int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM; //função rand retorna um número aleatório

    //Verificando tempo de execução do bubble sort=> t2
    t = clock(); //armazena tempo, antes de executar a função
    mergeSort(vetor, 0, TAM - 1); //chama a função
    t = clock() - t; //tempo final - tempo inicial

    //imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double

    return 0;
}
