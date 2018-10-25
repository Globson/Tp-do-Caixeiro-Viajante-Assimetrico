#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libs/Menu.h"

int main(int argc, char const *argv[]) {
  srand((unsigned)time(NULL));
  //interativo();
  int TAM,i,j;
  printf("Entre com o numero de cidades\n");
  scanf("%d", &TAM );
  int Matriz[TAM][TAM]; //Sao TAM cidades que fazem conexao com TAM cidades
  //Lembrando que a cidade tem custo 0 com si mesma
  //Lembrando que o custo de ij pode ser diferente pra ji
  for ( i = 0; i < TAM; i++)
    for ( j = 0; j < TAM; j++)
      Matriz[i][j]=(i == j ? 0 : 1+(rand() % 10));
  //Diagonal principal com 0
  //a = rand() % 10;
  //Soma dos digitos das matriculas dos integrantes do grupo
  printf("Entre com as 3 matriculas\n");
  int Matricula1,Matricula2,Matricula3,SUMMatricula;
  scanf("%d",&Matricula1 );
  SUMMatricula = Matricula1/1000 + (Matricula1/100 - (Matricula1/1000)*10) + (Matricula1/10 -(Matricula1/100)*10) + (Matricula1 - (Matricula1/10)*10);
  printf("%d\n",SUMMatricula );
  //scanf("%d\n",&Matricula2 );
  //SUMMatricula += Matricula2/1000 + (Matricula2/100 - (Matricula2/1000)*10) + (Matricula2/10 -(Matricula2/100)*10) + (Matricula2 - (Matricula2/10)*10);
  //scanf("%d\n",&Matricula3 );
  //SUMMatricula += Matricula3/1000 + (Matricula3/100 - (Matricula3/1000)*10) + (Matricula3/10 -(Matricula3/100)*10) + (Matricula3 - (Matricula3/10)*10);
  //Resto da divisao entre soma das matriculas e N
  int RestoX = SUMMatricula%TAM;



//Arquivo():
//TA na agenda do Grobs pra FAZER.... --->> EASTER EGGS VIRÂO!!<<---
  return 0;
}
