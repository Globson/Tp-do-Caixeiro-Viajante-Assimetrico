#include <stdio.h>
#include "../Libs/Permutacao.h"
#include "../Libs/Menu.h"

void VerificaRota(int vetor[],int QuantidadeCidades,int MatrizCusto[QuantidadeCidades][QuantidadeCidades],int Rotas[],int CidadeInicial,int *MelhorCaminho){
   int Soma_Distancia = 0;
   for (size_t i = 1; i < QuantidadeCidades - 1 ; i++) {
     Soma_Distancia+=MatrizCusto[vetor[i-1]][vetor[i]];
   }
   Soma_Distancia+=MatrizCusto[CidadeInicial][vetor[0]];
   Soma_Distancia+=MatrizCusto[vetor[QuantidadeCidades-2]][CidadeInicial];
   printf("= %d\n",Soma_Distancia );
   separador_fino();

   if (Soma_Distancia < *MelhorCaminho) {
    *MelhorCaminho = Soma_Distancia;
     for (size_t i = 0; i < QuantidadeCidades-1; i++) {
       Rotas[i] = vetor[i];
     }
   }
}



void troca(int vetor[], int i, int j)
{
  int aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}

void permuta(int vetor[], int inf, int sup,int QuantidadeCidades,int MatrizCusto[QuantidadeCidades][QuantidadeCidades],int Rotas[QuantidadeCidades],int CidadeInicial,int *MelhorCaminho)
{
  if(inf == sup)
  {
    for(int i = 0; i <= sup; i++){
        printf("%d ", vetor[i]);
    }
    VerificaRota(vetor,QuantidadeCidades,MatrizCusto,Rotas,CidadeInicial,MelhorCaminho);
  }
  else
  {
    for(int i = inf; i <= sup; i++)
    {
      troca(vetor, inf, i);
      permuta(vetor, inf + 1, sup,QuantidadeCidades,MatrizCusto,Rotas,CidadeInicial,MelhorCaminho);
      troca(vetor, inf, i); // backtracking
    }
  }
}
