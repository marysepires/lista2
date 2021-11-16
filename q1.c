#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preenche(int *vet, int tam){
    int i;
    if (vet != NULL){ // preenchimento do vetor
        for(i = 0; i < tam; i++)
            vet[i] = 1 + rand() % 10001;
    for(i = 0; i < tam; i++)
            printf("[%d] ", vet[i]); // mostrar os valores do vetor
        } else{
            printf("\nErro em alocar");
        }
}

int buscaSequencial(int *vet, int n, int tam){ // busca sequencial
    int i;
    for (i = 0; i < tam; i++){
        if(vet[i] == n){
            return i;
        }
    }
    return -1;
}
int main(){
    int n, i, *vet, tam, pos;



    printf("Tamanho do vetor: ");
    scanf("%d", &tam);
    vet = (int *) malloc(tam * sizeof(int)); // aloca a m�moria
    preenche(vet, tam);

    clock_t start = clock();
    printf ("\n\nQual valor deseja buscar? ");
    scanf("\t%d", &n);

    pos = buscaSequencial(vet, n, tam);
    clock_t stop = clock();

    if(pos == -1){
        printf("\nValor n�o encontrado");
    }else{
        printf ("\nValor encontrado na posi��o %d", pos +1);
    }

    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n\nTempo em ms: %f", elapsed);
    free(vet);
    return 0;
}
