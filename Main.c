#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libs/Menu.h"
#include "Libs/Permutacao.h"
#include "Libs/Matricula.h"
int Fatorial(int QuantidadeCidades){
  int fat;
  for(fat = 1; QuantidadeCidades > 1; QuantidadeCidades = QuantidadeCidades - 1)
      fat = fat * QuantidadeCidades;
  return fat;
}
int main(int argc, char const *argv[]) {
  srand((unsigned)time(NULL));
  //interativo();
  int QuantidadeCidades,i,j;
  printf("Entre com o numero de cidades\n");
  scanf("%d", &QuantidadeCidades );
  int MatrizCusto[QuantidadeCidades][QuantidadeCidades];
  for ( i = 0; i < QuantidadeCidades; i++)
    for ( j = 0; j < QuantidadeCidades; j++)
      MatrizCusto[i][j]=(i == j ? 0 : 1+(rand() % 100));
  separador();
  printf("MatrizCusto %d por %d\n",QuantidadeCidades,QuantidadeCidades );
  for (size_t i = 0; i < QuantidadeCidades; i++) {
    for (size_t j = 0; j < QuantidadeCidades; j++)
      printf("  %d",MatrizCusto[i][j] );
    printf("\n");
  }
  //Primeira MatrizCusto,que e apenas a distanticas entre as ciadades
  //====================================================================================
  separador();
  int CidadeInicial = MatriculaRandomica(QuantidadeCidades);
  printf("CidadeInicial - > %d\n", CidadeInicial);
  //Qual cidade ira iniciar
  //====================================================================================
  separador();

  separador();
  int VetorAux[QuantidadeCidades-1],aux = 0;
  for (size_t i = 0; i < QuantidadeCidades-1; i++) {
    if (i==CidadeInicial) {
      aux++;
      VetorAux[i]=aux;
    }else{
      VetorAux[i]=aux;
    }
    aux++;
  }
  //Definindo um vetor de QuantidadeCidades-1 para fazer a permutacao de (QuantidadeCidades-1)! (Ja que esse e o numero de permutacoes possiveis)
  //====================================================================================

  aux = 0;
  int tam_VetorAux = sizeof(VetorAux) / sizeof(int);
  int Ocorrencias=Fatorial(QuantidadeCidades-1);
  int CaminhoVSOcorrencia = (QuantidadeCidades-1)*Ocorrencias;
  printf("%d\n",CaminhoVSOcorrencia );
  int VetorPermutado[CaminhoVSOcorrencia];//TODO:Fazer por outro metodo
  separador();
  printf("Vetor permutado\n");
  permuta(VetorAux, 0,tam_VetorAux - 1);
  separador();

  //Possivelmente fazer direto no algoritimo de Permutacao
  //Com isso da pra economizar memoria,mas vai ser extremamente chato e dificil

  //
  //====================================================================================
  //====================================================================================
  //====================================================================================
  //Apartir daqui pra baixo e inutil
  //====================================================================================
  //====================================================================================
  //====================================================================================










/*
  printf("Copia Vetor permutado\n");
  for (size_t i = 0; i < CaminhoVSOcorrencia; i++) {
    if (i%(QuantidadeCidades-1)!=0) {
      printf("%d ",VetorPermutado[i]);
    }else{
      printf("\n%d ",VetorPermutado[i]);

    }
  }
  printf("\n");

  separador();

  printf("\n");
  printf("%d\n",Ocorrencias );
  int Soma = 1000*Ocorrencias;
  printf("%d\n",Ocorrencias );

  printf("\n%d\n",sizeof(VetorPermutado)/sizeof(int) );

  separador();

  //Aqui sera as comparacoes de tempos para saber qual e o mais rapido
  for (size_t i = 0; i < QuantidadeCidades-1; i++) {
    printf("%d -> %d = %d\n",CidadeInicial,VetorPermutado[i],MatrizCusto[CidadeInicial][VetorPermutado[i]] );
  }*/
  /*int Caminho[QuantidadeCidades-1],Soma = 0,MelhorCaminho[QuantidadeCidades];
  Soma = MatrizCusto[CidadeInicial][VetorPermutado[0]];
  Caminho[0]=VetorPermutado[0];
  printf("%d -> %d -> %d\n",CidadeInicial,Caminho[0],MatrizCusto[CidadeInicial][Caminho[0]] );


  for (size_t i = 1; i < QuantidadeCidades-3; i++) {
    Caminho[i] = VetorPermutado[i];
    printf("%d -> %d -> %d\n",Caminho[i],Caminho[i+1],MatrizCusto[Caminho[i]][Caminho[i+1]] );
    Soma+= MatrizCusto[VetorPermutado[i]][VetorPermutado[i+1]];
  }
  Soma += MatrizCusto[CidadeInicial][VetorPermutado[QuantidadeCidades-2]];
  printf("%d -> %d -> %d\n",Caminho[QuantidadeCidades-2],CidadeInicial,MatrizCusto[Caminho[QuantidadeCidades-2]][CidadeInicial] );

  printf("\n" );

            | Chegada
           \ /
->Saida





  MelhorCaminho[0]=1000*QuantidadeCidades;
  for (size_t i = 0; i < Ocorrencias; i++) {
    Soma = 0;
    for (j = 0; j < QuantidadeCidades-1; j++) {
      Caminho[j]=VetorPermutado[aux];
      printf("%d ",VetorPermutado[aux]  );
      if (j!=0) {
        Soma += MatrizCusto[VetorPermutado[aux]-1][VetorPermutado[aux]];
      }else{
        Soma += MatrizCusto[CidadeInicial][VetorPermutado[aux]];
        printf("Custo da primeira cidade ate a proxima %d\n",MatrizCusto[CidadeInicial][VetorPermutado[aux]] );
      }
      //Soma += (j != 0 ? MatrizCusto[j-1][j] : MatrizCusto[CidadeInicial][j] );
      aux++;
    }
    Soma += MatrizCusto[VetorPermutado[aux]][CidadeInicial];
    printf("Custo da ultima cidade a origem %d\n",MatrizCusto[j][CidadeInicial] );
    printf("%d\n",Soma );
    if (Soma < MelhorCaminho[0]) {
      MelhorCaminho[0] = Soma;
      for (size_t k = 0; k < sizeof(Caminho)/sizeof(int); k++) {
        MelhorCaminho[k+1]=Caminho[k];
      }
    }
  }




printf("Esse e o melhor caminho: \n");
for (size_t i = 1; i < QuantidadeCidades; i++) {
  //printf("%d ",MelhorCaminho[i] );
}
*/
//printf("\nCom o custo de: %d ", MelhorCaminho[0] );
//printf("aux -> %d\n",aux );
/*Para toda permutacao se traca um caminho de CidadeInicial por elas ate CidadeInicial
Ou seja,se a permutacao e 2403 e o CidadeInicial e 5,o algoritimo constiste em
verificar o caminho de 5->2->4->0->3->5
*/

  return 0;
}
