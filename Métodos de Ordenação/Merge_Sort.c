#include <stdio.h>
#include <stdlib.h>

int contadorMerge = 0;  // Contador de Operações

// Função que faz a Intercalação (Merge)
// O(n)
void merge(int vetor[], int esquerda, int meio, int direita) {
    int i, j, k;
    int tamanho = direita - esquerda + 1;

    // Aloca Dinamicamente o Vetor Auxiliar
    int *AuxiliarMerge = (int *) malloc(tamanho * sizeof(int));
    if (AuxiliarMerge == NULL) {
        fprintf(stderr, "Erro: falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    // Copia os Dois Subvetores (Esquerda e Direita) para o Auxiliar
    i = esquerda;
    j = meio + 1;
    k = 0;

    // Intercala os Dois Subvetores no Vetor Auxiliar
    while (i <= meio && j <= direita) {
        if (vetor[i] <= vetor[j])
            AuxiliarMerge[k++] = vetor[i++];
        else
            AuxiliarMerge[k++] = vetor[j++];
        contadorMerge++;
    }

    // Copia o Restante da Metade Esquerda, Se houver
    while (i <= meio)
        AuxiliarMerge[k++] = vetor[i++];

    // Copia o Restante da Metade Direita, Se houver
    while (j <= direita)
        AuxiliarMerge[k++] = vetor[j++];

    // Copia de Volta para o Vetor Original
    for (k = 0; k < tamanho; k++)
        vetor[esquerda + k] = AuxiliarMerge[k];

    // Libera a Memória Alocada
    free(AuxiliarMerge);
}

// Função Recursiva do Merge Sort
// O(log n)
void mergeSort(int vetor[], int esquerda, int direita) {
    if (esquerda >= direita)
        return;

    int meio = (esquerda + direita) / 2;

    mergeSort(vetor, esquerda, meio);
    mergeSort(vetor, meio + 1, direita);
    merge(vetor, esquerda, meio, direita);
}

// Imprime o Vetor Ordenado
void print_vetor(int vetor[],int n){
    for(int i = 0; i < n; i++){
        printf("%d ",vetor[i]);
    }
}

// Leitura do Vetor de Tamanho N Via Teclado
int main() {

    int N;
    scanf("%d",&N);
    int vetor[N];
    for(int i = 0; i < N; i++){
        scanf("%d",&vetor[i]);
    }

    printf("\nVetor Original V = ");
    print_vetor(vetor,N);

    mergeSort(vetor,0,N-1);
    printf("\nVetor Ordenado: V = ");
    print_vetor(vetor,N);

    printf("\nNúmero de Comparações: %d",contadorMerge);
  
    return 0;
}
