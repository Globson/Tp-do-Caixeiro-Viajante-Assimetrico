#include <stdio.h>
#include <stdlib.h>
#include "../Libs/Interativo.h"
#include "../Libs/Menu.h"
#include "../Libs/Permutacao.h"
#include "../Libs/Matricula.h"
#include "../Libs/Matriz.h"
#include <time.h>

void Interativo() {
  clock_t inicio, fim;
  double tempo_exe;
  int QuantidadeCidades;
  printf("Entre com o numero de cidades:");
  scanf("%d", &QuantidadeCidades );
  int MatrizCusto[QuantidadeCidades][QuantidadeCidades];
  separador();
  PreencheCustos(QuantidadeCidades,MatrizCusto);
  PrintCustos(QuantidadeCidades,MatrizCusto);
  //Primeira MatrizCusto,que e apenas a distanticas entre as ciadades
  //====================================================================================
  int CidadeInicial = LeituraMatriculas(QuantidadeCidades);
  int VetorAux[QuantidadeCidades-1],Rota[QuantidadeCidades-1],MelhorCaminho;
  MelhorCaminho = 100*QuantidadeCidades;
  PreencherParaPermutacao(QuantidadeCidades,VetorAux,CidadeInicial);

  //Definindo um vetor de QuantidadeCidades-1 para fazer a permutacao de (QuantidadeCidades-1)! (Ja que esse e o numero de permutacoes possiveis)
  //====================================================================================
  int tam_VetorAux = sizeof(VetorAux) / sizeof(int);
  separador();
  printf("Possiveis Caminhos e Custos:\n");
  separador_fino();
  inicio = clock();//Inicio da contagem
  permuta(VetorAux, 0,tam_VetorAux - 1,QuantidadeCidades,MatrizCusto,Rota,CidadeInicial,&MelhorCaminho);
  printf("Iniciando pela cidade: %d \n", CidadeInicial);
  separador_fino();
  printf("O Melhor caminho: \n");
  printf("%d ", CidadeInicial );
  for (size_t i = 0; i < QuantidadeCidades-1; i++) {
    printf("%d ",Rota[i] );}
  printf("%d ", CidadeInicial );
  printf("\nCom o custo de: %d\n",MelhorCaminho );
  fim = clock();//Fim da contagem
  tempo_exe = ((double) (fim - inicio) / (((double) CLOCKS_PER_SEC)));
  separador();
  printf("Tempo de Execucao => %.5lf ms.\n",tempo_exe);
  separador();
  printf("\n");

}
