#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000000
#define TAM 10000

void criar_vetor_aleatorio(int vetor[], int tam){
    srand(time(NULL));

    vetor[0] = rand() % 10;
    for (int i = 1; i < tam; i++)
    {
        vetor[i] = vetor[i - 1] + rand() % 10;
    }
}
void preenche_auxiliar(int vetor_auxiliar[], int tam)
{
    int contador_auxiliar = 0;

    for (int contador_principal = 0; contador_principal < tam; contador_principal += tam / 10)
    {
        vetor_auxiliar[contador_auxiliar] = contador_principal;
        contador_auxiliar++;
    }
}

bool busca_indexada(int vetor[], int chave, int arquivo_auxiliar[])
{
    bool achou = false;
    int inicio, fim;
    for (int j = 0; j < TAM; j++)
    {
        if (chave < vetor[arquivo_auxiliar[j]])
        {
            inicio = arquivo_auxiliar[j - 1];
            fim = arquivo_auxiliar[j];
            for (int i = inicio; i < fim; i++)
            {
                if (vetor[i] == chave && achou == false)
                {
                    achou = true;
                }
            }
        }
    }
    return achou;
}

int main()
{

    int vetor[MAX], arquivo_auxiliar[TAM], chave;

    printf("Digite um numero para busca\n");
    scanf("%d", &chave);
    criar_vetor_aleatorio(vetor, MAX);
    preenche_auxiliar(arquivo_auxiliar, TAM);
    busca_indexada(vetor, chave, arquivo_auxiliar);

    if ( busca_indexada(vetor, chave, arquivo_auxiliar))
    {
        printf("O numero informado existe no arquivo");
    }
    else
    {
        printf("O numero informado nao existe no arquivo");
    }

    for (int i = 0; i < MAX; i++)
    {
        printf("%d\n", vetor[i]);
    }
    

    return 0;
}
/*se a chave for menor que o kindex vou comparar entre kindex menos um. no vetor principal */