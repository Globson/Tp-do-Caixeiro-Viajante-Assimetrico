#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libs/Menu.h"

int main(int argc, char const *argv[]) {
  srand((unsigned)time(NULL));
  //interativo();
  int TAM,i,j;
  scanf("%d", &TAM );
  int Matriz[TAM][TAM]; //Sao TAM cidades que fazem conexao com TAM cidades
  //Lembrando que a cidade tem custo 0 com si mesma
  //Lembrando que o custo de ij pode ser diferente pra ji
  for ( i = 0; i < TAM; i++)
    for ( j = 0; j < TAM; j++)
      Matriz[i][j]=(i == j ? 0 : 1+(rand() % 10));
  //Diagonal principal com 0
  //a = rand() % 10;


//Arquivo():
//TA na agenda do Grobs pra FAZER.... --->> EASTER EGGS VIRÂO!!<<---
  return 0;
}
