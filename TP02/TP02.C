/*Aluna: Beatriz Rocha de Araújo 
Matéria: Estrutura de Dados */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//funções necessárias para o código 
void swap(char **x, char **y);
void quicksort(char *array[], int low, int high, int *trocas, int *comparacoes);
int partition(char *array[], int low, int high, int *trocas, int *comparacoes);

//função troca as duas strings apontadas pelos ponteiros
void swap(char **x, char **y) {
    char *temp = *x;
    *x = *y;
    *y = temp;
}

//função principal para a ordenação do array utilizando o quicksort
void quicksort(char *array[], int low, int high, int *trocas, int *comparacoes) {
    srand(time(NULL));
    if (low < high) {
        int pivot_index = partition(array, low, high, trocas, comparacoes);
        quicksort(array, low, pivot_index - 1, trocas, comparacoes);
        quicksort(array, pivot_index + 1, high, trocas, comparacoes);
    }
}

//escolha um pivot aleatório e reorganiza os elementos do arrya 
int partition(char *array[], int low, int high, int *trocas, int *comparacoes) {
    int pivot_index = low + rand() % (high - low + 1);

    if (pivot_index != high) {
        swap(&array[pivot_index], &array[high]);
    }

    char *pivot_value = array[high];
    int i = low;

    for (int j = low; j < high; j++) {
        (*comparacoes)++;
        if (strcmp(array[j], pivot_value) <= 0) {
            swap(&array[i], &array[j]);
            i++;
            (*trocas)++;
        }
    }

    swap(&array[i], &array[high]);

    return i;
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi",
        "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };
    //variaveis definidas para acompanhar o comprimento do array e a contagem das trocas e comparações feitas
    int length = 20;
    int trocas = 0;
    int comparacoes = 0;

    //função chamada para ordenar o array
    quicksort(arr, 0, length - 1, &trocas, &comparacoes);

    printf("Vetor ordenado: \n");
    for (int i = 0; i < length; i++)
        printf("\n%s", arr[i]);
    printf("\n");

    //gerando o arquivo de saída  
    FILE *saida = fopen("C://Users//Beatriz//Desktop//estruturadedados//ArquivoSaida.txt", "w");
    if (saida != NULL)
    {
        fprintf(saida, "Numero de trocas: %d\n", trocas);
        fprintf(saida, "Numero de comparacoes: %d\n", comparacoes);
        fprintf(saida, "Vetor ordenado: \n");
        for (int i = 0; i < length; i++)
        {
            fprintf(saida, "%s\n", arr[i]);
        }
        fclose(saida);
        printf("\nArquivo 'ArquivoSaida.txt' gerado com sucesso.\n");
    } else {
        printf("\nErro ao criar o arquivo de saída.\n");
    }

    printf("------------------------------------------------------------");

    //Calculando a Mediana
    char *mediana;
    if (length % 2 == 1){
        mediana = arr[length/2];
       printf("\nMediana: %s", mediana);
    } else {
        mediana = arr[length/2 - 1];
        printf("\nMediana: %s e %s", arr[length / 2], mediana);
    }

    

    return 0;
}
