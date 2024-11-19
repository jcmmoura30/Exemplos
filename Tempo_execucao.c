#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 200000; //constante para tamanho do vetor

void bubbleSort (int v[TAM]) { //função de ordenação de um vetor
    int a, b, aux;
    for (a=TAM-1; a>=1; a--) {
        for (b=0; b<a; b++) {
            if (v[b]>v[b+1]) {
                aux = v[b];
                v[b] = v[b+1];
                v[b+1] = aux;
            }
        }
    }
}

int main(){
    clock_t t; //variável para armazenar tempo
    int vetor[TAM];

    //semente de aleatoriedade
    srand((unsigned)time(NULL)); //o algoritmo tem como semente a hora atual que o código é executado

    //geração aleatório dos valores do vetor
    for(int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM; //função rand retorna um número aleatório

    //Verificando tempo de execução do bubble sort=> t2
    t = clock(); //armazena tempo, antes de executar a função
    bubbleSort(vetor); //chama a função
    t = clock() - t; //tempo final - tempo inicial

    //imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double

    return 0;
}
