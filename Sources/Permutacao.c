#include <stdio.h>
#include "../Libs/Permutacao.h"

void VerificaRota(int vetor[],int QuantidadeCidades,int MatrizCusto[QuantidadeCidades][QuantidadeCidades],int Rotas[],int CidadeInicial){
   int Soma_Distancia = 0;
   for (size_t i = 1; i < QuantidadeCidades-1; i++) {
     Soma_Distancia+=MatrizCusto[vetor[i-1]][vetor[i]];
   }
   Soma_Distancia+=MatrizCusto[CidadeInicial][vetor[0]];
   Soma_Distancia+=MatrizCusto[vetor[QuantidadeCidades-2]][CidadeInicial];
   if (Soma_Distancia < Rotas[0]) {
     Rotas[0] = Soma_Distancia;
     for (size_t i = 0; i < QuantidadeCidades-1; i++) {
       Rotas[i+1] = vetor[i];
     }
   }
}




void troca(int vetor[], int i, int j)
{
  int aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}

void permuta(int vetor[], int inf, int sup,int QuantidadeCidades,int MatrizCusto[QuantidadeCidades][QuantidadeCidades],int Rotas[QuantidadeCidades],int CidadeInicial)
{
  if(inf == sup)
  {
    VerificaRota(vetor,QuantidadeCidades,MatrizCusto,Rotas,CidadeInicial);
    for(int i = 0; i <= sup; i++){
      printf("%d ", vetor[i]);
    }
    printf("\n");
  }
  else
  {
    for(int i = inf; i <= sup; i++)
    {
      troca(vetor, inf, i);
      permuta(vetor, inf + 1, sup,QuantidadeCidades,MatrizCusto,Rotas,CidadeInicial);
      troca(vetor, inf, i); // backtracking
    }
  }
}
