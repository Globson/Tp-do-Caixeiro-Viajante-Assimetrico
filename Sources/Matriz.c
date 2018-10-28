#include "../Libs/Matriz.h"
#include <stdio.h>
#include <stdlib.h>
void PreencheCustos(int QuantidadeCidades,int Matriz[QuantidadeCidades][QuantidadeCidades]){
  for ( size_t i = 0; i < QuantidadeCidades; i++)
    for ( size_t j = 0; j < QuantidadeCidades; j++)
      Matriz[i][j]=(i == j ? 0 : 1+(rand() % 100));
}
void PrintCustos(int QuantidadeCidades,int Matriz[QuantidadeCidades][QuantidadeCidades]){
  printf("Matriz de Custo %d por %d\n",QuantidadeCidades,QuantidadeCidades );
  for (size_t i = 0; i < QuantidadeCidades; i++) {
    for (size_t j = 0; j < QuantidadeCidades; j++)
      printf(" %d ",Matriz[i][j] );
      printf("\n");
  }
}
void PreencherParaPermutacao(int QuantidadeCidades,int vetor[QuantidadeCidades-1],int CidadeInicial){
  int aux = 0;
  for (size_t i = 0; i < QuantidadeCidades; i++) {
    if (i != CidadeInicial) {
      vetor[aux]=i;
      aux++;
    }
  }
}
