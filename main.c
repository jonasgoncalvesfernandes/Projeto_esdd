#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000000
#define DIV 10000

void criar_vetor_aleatorio(int vetor[], int tam){
    srand(time(NULL));

    vetor[0] = rand() % 10;
    for (int i = 1; i < tam; i++) {
        vetor[i] = vetor[i - 1] + rand() % 10;
    }
}

void preenche_auxiliar(int vetor_auxiliar[], int tam, int tam2) {
    int contador_auxiliar = 0;

    for (int contador_principal = 0; contador_principal < tam; contador_principal += tam2) {
        vetor_auxiliar[contador_auxiliar] = contador_principal;
        contador_auxiliar++;
    }
}

int busca_indexada(int vetor[], int chave, int arquivo_auxiliar[], int tam_aux) {
    int inicio, fim;
    for (int j = 1; j < tam_aux; j++) {
        if (chave < vetor[arquivo_auxiliar[j]]) {
            inicio = arquivo_auxiliar[j - 1];
            fim = arquivo_auxiliar[j];
            for (int i = inicio; i < fim; i++) {
                if (vetor[i] == chave) {
                    return i; // Retorna a posição onde a chave foi encontrada
                }
            }
        }
    }
    return -1; 
}

int main() {
    int tamanho = MAX / DIV;
    int vetor[MAX], arquivo_auxiliar[tamanho], chave;

    printf("Digite um numero para busca\n");
    scanf("%d", &chave);

    criar_vetor_aleatorio(vetor, MAX);
    preenche_auxiliar(arquivo_auxiliar, MAX, DIV);

    int posicao = busca_indexada(vetor, chave, arquivo_auxiliar, tamanho);

    if (posicao != -1) {
        printf("O numero informado existe no arquivo e se encontra na posição %d\n", posicao);
    } else {
        printf("O numero informado nao existe no arquivo\n");
    }

    return 0;
}