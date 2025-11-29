#include <stdio.h>

int compara = 0, troca = 0;

// Leitura do Vetor de Tamanho N Via Teclado
void leitura_vetor(int Vetor[],int N){
    for(int i = 0; i < N; i++){
        scanf("%d",&Vetor[i]);
    }
}

// Algoritmo de Bubble-Sort
// Eficiência: O(n^2)
void bubble_sort(int Vetor[],int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - i - 1; j++){
            compara++;
            if(Vetor[j] > Vetor[j + 1]){
                int temp = Vetor[j + 1];
                Vetor[j+1] = Vetor[j];
                Vetor[j] = temp;
                troca++;
            }
        }
    }
}

// Impressão de Resultado
void print_vetor(int Vetor[],int N){
    for(int i = 0; i < N; i++){
        if(i == 0){
            printf("Vetor Ordenado: [ ");
            if(N == 1){
                printf("%d ]",Vetor[i]);

            }else{
                printf("%d, ",Vetor[i]);
            }
        }
        else if(i == N - 1){
            printf("%d ",Vetor[i]);
            printf("]");
        }else{
            printf("%d, ",Vetor[i]);
        }
    }

    printf("\nNúmero de Trocas: %d",troca);
    printf("\nNúmero de Comparações: %d",compara);
}

int main(){

    int N;
    scanf("%d",&N);
    int Vetor[N];

    leitura_vetor(Vetor,N);
    bubble_sort(Vetor,N);
    print_vetor(Vetor,N);

    return 0;
}
