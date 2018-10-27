#include <stdio.h>
#include <stdlib.h>
#include "../Libs/Interativo.h"
#include "../Libs/Menu.h"
#include "../Libs/Permutacao.h"
#include "../Libs/Matricula.h"
#include "../Libs/Matriz.h"
int Fatorial(int QuantidadeCidades){
  int fat;
  for(fat = 1; QuantidadeCidades > 1; QuantidadeCidades = QuantidadeCidades - 1)
      fat = fat * QuantidadeCidades;
  return fat;
}
void Interativo() {
  int QuantidadeCidades;
  printf("Entre com o numero de cidades\n");
  scanf("%d", &QuantidadeCidades );
  int MatrizCusto[QuantidadeCidades][QuantidadeCidades];
  separador();
  PreencheCustos(QuantidadeCidades,MatrizCusto);
  PrintCustos(QuantidadeCidades,MatrizCusto);
  //Primeira MatrizCusto,que e apenas a distanticas entre as ciadades
  //====================================================================================
  int CidadeInicial = MatriculaRandomica(QuantidadeCidades);
  separador();
  int VetorAux[QuantidadeCidades-1],Rota[QuantidadeCidades];
  Rota[0] = 100*QuantidadeCidades;
  PreencherParaPermutacao(QuantidadeCidades,VetorAux,CidadeInicial);
  //Definindo um vetor de QuantidadeCidades-1 para fazer a permutacao de (QuantidadeCidades-1)! (Ja que esse e o numero de permutacoes possiveis)
  //====================================================================================
  int tam_VetorAux = sizeof(VetorAux) / sizeof(int);
  separador();
  printf("Vetor permutado\n");
  permuta(VetorAux, 0,tam_VetorAux - 1,QuantidadeCidades,MatrizCusto,Rota,CidadeInicial);
  separador();
  printf("Custo - > %d\n",Rota[0] );
  printf("de %d ate %d -> Custo %d\n",CidadeInicial,Rota[1],MatrizCusto[CidadeInicial][Rota[1]] );
  for (size_t i = 2; i < QuantidadeCidades; i++) {
    printf("de %d ate %d -> %d\n",Rota[i-1],Rota[i],MatrizCusto[Rota[i-1]][Rota[i]] );
  }
  printf("de %d ate %d -> Custo %d\n",Rota[QuantidadeCidades-1],CidadeInicial,MatrizCusto[Rota[QuantidadeCidades-1]][CidadeInicial] );
}
