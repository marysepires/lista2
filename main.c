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
    vet = (int *) malloc(tam * sizeof(int)); // aloca a mémoria
    preenche(vet, tam);

    printf ("\nQual valor deseja buscar?:");
    scanf("%d", &n);

    clock_t begin = clock();
    pos = buscaSequencial(vet, n, tam);
    clock_t end = clock();

    if(pos == -1){
        printf("Valor não encontrado");
    }else{
        printf ("Valor encontrado na posição %d", pos +1);
    }

    printf("\nTempo de execucao: %f segundos", (double)(end - begin) / CLOCKS_PER_SEC);
    free(vet);


    return 0;
}
