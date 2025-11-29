#include <stdio.h>

// Counting Sort: Apenas Para Números Maiores ou iguais a 0
// Eficiência: O(N)

// Função Para Encontrar o Maior Valor no Vetor
int encontrar_maior(int arr[], int N) {
    int maior = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] > maior) {
            maior = arr[i];
        }
    }
    return maior;
}

// Função Para Inicializar o Vetor de Contagem com 0
void inicializar_mapa(int mapa[], int maior) {
    for (int i = 0; i <= maior; i++) {
        mapa[i] = 0;
    }
}

// Função para Calcular a Frequência de Cada Elemento no Vetor
void calcular_frequencia(int arr[], int N, int mapa[]) {
    for (int i = 0; i < N; i++) {
        mapa[arr[i]]++;
    }
}

// Função Para Reconstruir o Vetor Ordenado Com Base No Vetor De Contagem
void reconstruir_vetor(int arr[], int N, int mapa[]) {
    int cont = 0;
    for (int i = 0; i <= N; i++) {
        int freq = mapa[i];
        while (freq > 0) {
            arr[cont] = i;
            freq--;
            cont++;
        }
    }
}

// Função Para Imprimir o Vetor
void imprimir_vetor(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int N;

    // Leitura do Tamanho do Vetor
    scanf("%d", &N);

    int Vetor[N];
    
    // Leitura dos Elementos do Vetor
    for (int i = 0; i < N; i++) {
        scanf("%d", &Vetor[i]);
    }

    // Encontrar o Maior Valor no Vetor
    int maior = encontrar_maior(Vetor, N);
    
    // Inicializa o Mapa de Frequências
    int Mapa[maior + 1];
    inicializar_mapa(Mapa, maior);
    
    // Calcula a Frequência de Cada Número no Vetor
    calcular_frequencia(Vetor, N, Mapa);
    
    // Reconstroe o Vetor Ordenado
    reconstruir_vetor(Vetor, N, Mapa);

    // Imprime o Vetor Ordenado
    imprimir_vetor(Vetor, N);

    return 0;
}
