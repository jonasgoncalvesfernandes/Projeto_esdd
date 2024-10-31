#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 1000000
void criar_vetor_aleatorio(int vetor[],int tam ){
     srand(time(NULL));

     vetor[0]=rand() % tam;
     for (int i = 1; i < tam; i++)
     {
        vetor[i]= vetor[i-1] + rand () %(tam-1);
     }
     
}
// void preenche arquivo_auxiliar(int vetor, int vetor_auxiliar){
//     for (int i = 0; i < tam; i+)
//     {
//         /* code */
//     }
    
// }
void busca_indexada(int vetor[], int tam);
    

    

int main()
{   
    int vetor[MAX], arquivo_auxilar[MAX/10];
    criar_vetor_aleatorio(vetor,MAX);

    for (int i = 0; i < MAX; i++)
    {
        printf("vETOR[%d], : %d\n", i,vetor[i]);
    }
    
    
    return 0;
}
