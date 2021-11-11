#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void preenche(int *vet, int tam){
    int i;
    if (vet != NULL){ // preenchimento do vetor
        for(i = 0; i < tam; i++)
            vet[i] = 1 + rand() % 10001;
    }
}
void imprime (int *vet, int tam){
 int i;
        for(i = 0; i < tam; i++){
            printf("\n[%d] ", vet[i]);
        }
}
void OrdenaVetor(int *vet, int tam){
      int i, j, aux;

      for (i=0;i<tam-1;i++){
          for (j=i+1;j<tam;j++){
                  if (vet[i] > vet[j]){
                      aux=vet[i];
                      vet[i]=vet[j];
                      vet[j]=aux;
                   }
              }
      }

 }
 int PesquisaBinaria(int *vet, int tam, int n){
     int comeco = 0; //Limite inferior (em C o �ndice inicial � zero)
     int final = tam-1; //Limite superior (tamanho do vetor -1
                            // porque o �ndice inicial � zero )
     int meio;
     while (comeco <= final)
     {
          //meio = comeco + (final-comeco)/2;
          meio = (comeco + final)/2;
          if (n == vet[meio])
               return meio;
          else if (n < vet[meio])
               final = meio-1;
          else
               comeco = meio+1;
     }
     return -1;   // n�o encontrado
}
int main(){
    clock_t t;
    int n, i, *vet, tam, pos;

    printf("Tamanho do vetor: ");
    scanf("%d", &tam);
    vet = (int *) malloc(tam * sizeof(int)); // aloca a m�moria
    preenche(vet, tam);
    OrdenaVetor(vet, tam);
    imprime (vet, tam);


    printf("\nValor a ser pesquisado?:");
    scanf ("%d", &n);

    t = clock();
    pos = PesquisaBinaria(vet,tam, n);
    t = clock() - t;
    if (pos==-1){
        printf("\n\nValor nao encontrado no vetor!");
    }else{
        printf("\n\nValor encontrado na posicao %d", pos+1);
    }

    printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
    free(vet);

    return 0;
}
