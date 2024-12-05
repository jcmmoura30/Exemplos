#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 200000 

void insertionSort(int *vetor, int tamanho) {
    int i, j, key;
    for (i = 1; i < tamanho; i++) {
        key = vetor[i];
        j = i - 1;

        // Move elements of vetor[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && vetor[j] > key) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = key;
    }
}

int main() {
    clock_t t; //variável para armazenar tempo
    int vetor[TAM];

    //semente de aleatoriedade
    srand((unsigned)time(NULL)); //o algoritmo tem como semente a hora atual que o código é executado

    //geração aleatório dos valores do vetor
    for(int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM; //função rand retorna um número aleatório

    //Verificando tempo de execução do bubble sort=> t2
    t = clock(); //armazena tempo, antes de executar a função
    insertionSort(vetor, TAM); //chama a função
    t = clock() - t; //tempo final - tempo inicial

    //imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double

    return 0;
}
