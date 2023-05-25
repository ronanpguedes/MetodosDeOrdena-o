#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMES 1000 
#define MAX_CARACTER 100  

/*----------------------------------trocar----------------------------------------------------*/
void troca(char nomes[][MAX_CARACTER], int i, int j)
{
    char temp[MAX_CARACTER];
    strcpy(temp, nomes[i]);
    strcpy(nomes[i], nomes[j]);
    strcpy(nomes[j], temp);
}
/*----------------------------------bubble_sort----------------------------------------------------*/
void bubble_sort(char nomes[][MAX_CARACTER], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(nomes[j], nomes[j + 1]) > 0)
            {
                troca(nomes, j, j + 1);
            }
        }
    }
}
/*----------------------------------selection_sort----------------------------------------------------*/
void selection_sort(char nomes[][MAX_CARACTER], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(nomes[j], nomes[min]) < 0)
            {
                min = j;
            }
        }
        troca(nomes, i, min);
    }
}
/*----------------------------------insertion_sort----------------------------------------------------*/
void insertion_sort(char nomes[][MAX_CARACTER], int n)
{
    int i, j;
    char chave[MAX_CARACTER];
    for (i = 1; i < n; i++)
    {
        strcpy(chave, nomes[i]);
        j = i - 1;
        while (j >= 0 && strcmp(nomes[j], chave) > 0)
        {
            strcpy(nomes[j + 1], nomes[j]);
            j--;
        }
        strcpy(nomes[j + 1], chave);
    }
}
/*----------------------------------merge----------------------------------------------------*/
void merge(char nomes[][MAX_CARACTER], int inicio, int meio, int fim)
{
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // vetores auxiliares
    char esquerda[n1][MAX_CARACTER];
    char direita[n2][MAX_CARACTER];

    // copia os dados para os vetores auxiliares
    for (i = 0; i < n1; i++)
    {
        strcpy(esquerda[i], nomes[inicio + i]);
    }
    for (j = 0; j < n2; j++)
    {
        strcpy(direita[j], nomes[meio + 1 + j]);
    }

    // intercala os vetores auxiliares de volta ao vetor original
    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2)
    {
        if (strcmp(esquerda[i], direita[j]) <= 0)
        {
            strcpy(nomes[k], esquerda[i]);
            i++;
        }
        else
        {
            strcpy(nomes[k], direita[j]);
            j++;
        }
        k++;
    }

    // copia os elementos restantes do vetor esquerdo, se houver
    while (i < n1)
    {
        strcpy(nomes[k], esquerda[i]);
        i++;
        k++;
    }

    // copia os elementos restantes do vetor direito, se houver
    while (j < n2)
    {
        strcpy(nomes[k], direita[j]);
        j++;
        k++;
    }
}
/*----------------------------------merge_sort----------------------------------------------------*/
void merge_sort(char nomes[][MAX_CARACTER], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;

        // ordena as duas metades recursivamente
        merge_sort(nomes, inicio, meio);
        merge_sort(nomes, meio + 1, fim);

        // intercala as duas metades ordenadas
        merge(nomes, inicio, meio, fim);
    }
}
/*----------------------------------imprime_nomes----------------------------------------------------*/
void imprime_nomes(char nomes[][MAX_CARACTER], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s", nomes[i]);
    }
}
/*----------------------------------main----------------------------------------------------*/
int main()
{

    FILE *arquivo;                      
    char nome_arquivo[] = "nome_arquivo.txt"; 
    char nomes[MAX_NOMES][MAX_CARACTER];   
    int opcao;            
    int n = 0;                          

    // abre o arquivo em modo de leitura
    arquivo = fopen("nome_arquivo.txt", "r");

    // verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return -1;
    }

    // lista os nomes do arquivo que sao armazena no vetor de nomes
    while (!feof(arquivo))
    {
        fgets(nomes[n], MAX_CARACTER, arquivo);
        n++;
    }

    // fecha o arquivo
    fclose(arquivo);
    // mostrar menu 
    printf("Escolha um algoritmo de ordenacao:\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Selection Sort\n");
    printf("3 - Insertion Sort\n");
    printf("4 - Merge Sort\n");
    printf("5 - Sair\n");

    
    scanf("%d", &opcao);

    // verifica qual metodo de ordenacao foi escolhido para ordenar o vetor de nomes
    switch (opcao)
    {
    case 1:
        bubble_sort(nomes, n);
        break;
    case 2:
        selection_sort(nomes, n);
        break;
    case 3:
        insertion_sort(nomes, n);
        break;
    case 4:
        merge_sort(nomes, 0, n - 1);
        break;
    case 5:
        printf("Programa encerrado com sucesso.\n");
        return 0;
    default:
        printf("Opcao invalida.\n");
        return -1;
    }

    // imprime os nomes ordenados na tela
    imprime_nomes(nomes, n);

    return 0;
}
