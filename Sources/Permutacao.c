#include <stdio.h>
#include "../Libs/Permutacao.h"

void troca(int vetor[], int i, int j)
{
  int aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}

void permuta(int vetor[], int inf, int sup,int VetorPermutado[],int *aux)
{
  if(inf == sup)
  {
    int aux2 = *aux;
    for(int i = 0; i <= sup; i++){
      VetorPermutado[aux2] = vetor[i];
      printf("%d ", vetor[i]);
      //printf(" | aux ->%d / %d | ",*aux,aux2 );
      *aux+=1;
      aux2 = *aux;
    }
    printf("\n");
  }
  else
  {
    for(int i = inf; i <= sup; i++)
    {
      troca(vetor, inf, i);
      permuta(vetor, inf + 1, sup,VetorPermutado,aux);
      troca(vetor, inf, i); // backtracking
    }
  }
}
