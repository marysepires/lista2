#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preenche(int *vet, int tam){
    int i;
    if (vet != NULL){
        for(i = 0; i < tam; i++)
            vet[i] = 1 + rand() % 10001; // preenchimento do vetor
    }
}
void imprime (int *vet, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("\n[%d] ", vet[i]);
    }
}

void selecao(int *vet, int tam){
    int i=0,j,menor,temp;
    for(i=0;i<tam-1;i++){
    menor = i;
    for(j=i+1; j<tam; j++){
        if(vet[j] < vet[menor]){
        menor = j;
        }
    }
    temp = vet[i];
    vet[i] = vet[menor];
    vet[menor] = temp;
    }
}
 int PesquisaBinaria(int *vet, int tam, int n){
     int comeco = 0; //Limite inferior (em C o índice inicial é zero)
     int final = tam-1; //Limite superior (tamanho do vetor -1
                            // porque o índice inicial é zero )
     int meio;
     while (comeco <= final){
          //meio = comeco + (final-comeco)/2;
          meio = (comeco + final)/2;
          if (n == vet[meio])
               return meio;
          else if (n < vet[meio])
               final = meio-1;
          else
               comeco = meio+1;
     }
     return -1;   // não encontrado
}
int main(){
    clock_t t;
    int n, i, *vet, tam, pos;

    printf("Tamanho do vetor: ");
    scanf("%d", &tam);
    vet = (int *) malloc(tam * sizeof(int)); // aloca a mémoria
    preenche(vet, tam);
    selecao(vet, tam);
    imprime (vet, tam);

    printf("\nValor a ser pesquisado?:");
    scanf ("%d", &n);

    clock_t begin = clock();
    pos = PesquisaBinaria(vet,tam, n);
    clock_t end = clock();
    if (pos==-1){
        printf("\n\nValor nao encontrado no vetor!");
    }else{
        printf("\n\nValor encontrado na posicao %d", pos+1);
    }

    printf("\nTempo de execucao: %f segundos", (double)(end - begin) / CLOCKS_PER_SEC);
    free(vet);

    return 0;
}
