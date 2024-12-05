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
    clock_t t; //variável para armazenar tempo
    int vetor[TAM];

    //semente de aleatoriedade
    srand((unsigned)time(NULL)); //o algoritmo tem como semente a hora atual que o código é executado

    //geração aleatório dos valores do vetor
    for (int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM; //função rand retorna um número aleatório

    //Verificando tempo de execução do bubble sort=> t2
    t = clock(); //armazena tempo, antes de executar a função
    quickSort(vetor, 0, TAM - 1); //chama a função
    t = clock() - t; //tempo final - tempo inicial

    //imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double

    return 0;
}
