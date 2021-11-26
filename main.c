#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*void preenche(int *vet, int tam){
    int i;
    if (vet != NULL){
        for(i = 0; i < tam; i++)
            vet[i] = 1 + rand() % 100000; // preenchimento do vetor
    }
}*/
void preencheVetor(int *vet, int tam){
    int i;
    for (i=0;i<tam;i++){
        vet[i] = i + 1;
    }

    int escolha = 0,rand_num = tam,pos_vetor = 0,tmp;
    while( pos_vetor < tam - 1 ){
        // Escolhe uma posicao aleatoria /
        escolha = rand() % rand_num;
        // Faz a troca pela posicao sequencial /
        tmp = vet[pos_vetor];
        vet[pos_vetor] = vet[escolha];
        vet[escolha] = tmp;
        // Proxima posicao que sera trocada /
        pos_vetor++;
    }

}
void imprime (int *vet, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("\n[%d] ", vet[i]);
    }
}
int partition(int *vet, int inicio, int tam){
    int j, temp;

    temp = (int*) malloc (tam*sizeof(int));
    int pivo = vet[tam];
    int i = inicio-1;
    for(j=inicio; j<tam; j++){
        if(vet[j] <= pivo){
        i++;

        temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;

        }
    }
    temp = vet[i+1];
    vet[i+1] = vet[tam];
    vet[tam] = temp;
    return i+1;
}
void quicksort(int *vet, int inicio, int tam){
    int meio=0;
    if(inicio<tam){
    meio = partition(vet, inicio, tam);
    quicksort(vet, inicio, meio-1);
    quicksort(vet, meio+1, tam);
    }
}
int main(){
   int n, i, *vet, tam;

    printf("Tamanho do vetor: ");
    scanf("%d", &tam);
    vet = (int *) malloc(tam * sizeof(int)); // aloca a m�moria
    preencheVetor(vet, tam);

    imprime(vet, tam);

    clock_t begin = clock();
    quicksort(vet, 0, tam -1);
    clock_t end = clock();

    printf("\n\nTempo de execucao em ms (quicksort): %f", (double)(end - begin) *1000 / CLOCKS_PER_SEC);
    free(vet);

    return 0;
}
