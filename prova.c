#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------gerarVetor------------------------------*/
void gerarVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
    }
}
/*-----------------------insertionSort------------------------------*/
void insertionSort(int vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}
/*-----------------------merge------------------------------*/
void merge(int vetor[], int inicio, int meio, int fim) {
    int i, j, aux;
    int tamanhoEsq = meio - inicio + 1;
    int tamanhoDir = fim - meio;

    int vetorEsq[tamanhoEsq], vetorDir[tamanhoDir];

    for (i = 0; i < tamanhoEsq; i++) {
        vetorEsq[i] = vetor[inicio + i];
    }
    for (j = 0; j < tamanhoDir; j++) {
        vetorDir[j] = vetor[meio + 1 + j];
    }

    i = 0;
    j = 0;
    aux = inicio;

    while (i < tamanhoEsq && j < tamanhoDir) {
        if (vetorEsq[i] <= vetorDir[j]) {
            vetor[aux] = vetorEsq[i];
            i++;
        } else {
            vetor[aux] = vetorDir[j];
            j++;
        }
        aux++;
    }

    while (i < tamanhoEsq) {
        vetor[aux] = vetorEsq[i];
        i++;
        aux++;
    }

    while (j < tamanhoDir) {
        vetor[aux] = vetorDir[j];
        j++;
        aux++;
    }
}
/*------------------------mergeSort-----------------------------*/
void mergeSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}
/*---------------------BuscaSeguencial--------------------------------*/
int buscaSequencial(int vetor[], int tamanho, int numero) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == numero) {
            return i;
        }
    }
    return -1;
}
/*-----------------------buscaBinaria------------------------------*/
int buscaBinaria(int vetor[], int tamanho, int numero) {
    int inicio = 0;
    int fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (vetor[meio] == numero) {
            return meio;
        }
        if (vetor[meio] < numero) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}
/*-----------------------exibirVetor------------------------------*/
void exibirVetor(int vetor[], int tamanho) {
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
/*-----------------------------------------------------*/
int main() {
    int vetor[100];
    int tamanho = 0;
    char opcao;

    do {
        printf("\n     Menu:     \n");
        printf("\n");
        printf("a. Gerar vetor\n");
        printf("b. Ordenar vetor\n");
        printf("c. Busca sequencial\n");
        printf("d. Busca binaria\n");
        printf("e. Sair\n");
        printf("\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'a':
                printf("Digite o tamanho do vetor: ");
                scanf("%d", &tamanho);
                gerarVetor(vetor, tamanho);
                printf("Vetor gerado com sucesso!\n");
                break;
            case 'b':
                if (tamanho > 0) {
                    char letra;
                    printf("Digite a letra para ordenar (I para Insertion Sort, M para Merge Sort): ");
                    scanf(" %c", &letra);
                    if (letra == 'I' || letra == 'i') {
                        insertionSort(vetor, tamanho);
                        printf("Vetor ordenado usando Insertion Sort.\n");
                        exibirVetor(vetor, tamanho);
                    } else if (letra == 'M' || letra == 'm') {
                        mergeSort(vetor, 0, tamanho - 1);
                        printf("Vetor ordenado usando Merge Sort.\n");
                        exibirVetor(vetor, tamanho);
                    } else {
                        printf("Opcao invalida!\n");
                    }
                } else {
                    printf("E necessario gerar o vetor primeiro!\n");
                }
                break;
            case 'c':
                if (tamanho > 0) {
                    int numero;
                    printf("Digite o numero a ser buscado: ");
                    scanf("%d", &numero);
                    int posicao = buscaSequencial(vetor, tamanho, numero);
                    if (posicao != -1) {
                        printf("Numero encontrado na posicao %d.\n", posicao);
                    } else {
                        printf("Numero nao encontrado no vetor.\n");
                    }
                } else {
                    printf("E necessario gerar o vetor primeiro!\n");
                }
                break;
            case 'd':
                if (tamanho > 0) {
                    int numero;
                    printf("Digite o numero a ser buscado: ");
                    scanf("%d", &numero);
                    int posicao = buscaBinaria(vetor, tamanho, numero);
                    if (posicao != -1) {
                        printf("Numero encontrado na posicao %d.\n", posicao);
                    } else {
                        printf("Numero nao encontrado no vetor.\n");
                    }
                } else {
                    printf("E necessario gerar o vetor para ser ordenado primeiro!\n");
                }
                break;
            case 'e':
                printf("Programa finalizado !!! \n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 'e');

    return 0;
}
