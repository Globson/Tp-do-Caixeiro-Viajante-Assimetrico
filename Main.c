#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "Libs/Menu.h"
#include "Libs/Permutacao.h"
#include "Libs/Matricula.h"
int Fatorial(int TAM){
  int fat;
  for(fat = 1; TAM > 1; TAM = TAM - 1)
      fat = fat * TAM;
  return fat;
}
int main(int argc, char const *argv[]) {
  /*
  if(strcmp(argv[1],"EasterEgg") == 1)
    EasterEgg();
  TODO:Ver isso com calma,ou nem colocar(Importacao de Lib desnecessaria)
  */
  srand((unsigned)time(NULL));
  //interativo();
  int TAM,i,j;
  printf("Entre com o numero de cidades\n");
  scanf("%d", &TAM );
  if (TAM == 0)
      exit(1);

  int Matriz[TAM][TAM];
  /*
  Sao TAM cidades que fazem conexao com TAM-1 cidades
  Lembrando que a cidade tem custo 0 com si mesma
  Lembrando que o custo de ij pode ser diferente pra ji
  */
  for ( i = 0; i < TAM; i++)
    for ( j = 0; j < TAM; j++)
      Matriz[i][j]=(i == j ? 0 : 1+(rand() % 100));//Diagonal principal com 0
  separador();
  printf("Matriz %d por %d\n",TAM,TAM );
  for (size_t i = 0; i < TAM; i++) {
    for (size_t j = 0; j < TAM; j++)
      printf("  %d",Matriz[i][j] );
    printf("\n");
  }
  separador();
  int RestoX = MatriculaRandomica(TAM-1);
  printf("RestoX - > %d\n", RestoX);
  separador();
  int FatTAM=Fatorial(TAM);
  int VetorAux[TAM-1],aux = 0,VetorPermutado[FatTAM];
  for (size_t i = 0; i < TAM-1; i++) {
    if (i==RestoX) {
      aux++;
      VetorAux[i]=aux;
    }else{
      VetorAux[i]=aux;
    }
    aux++;
  }
  aux = 0;
  int tam_VetorAux = sizeof(VetorAux) / sizeof(int);
  separador();
  printf("Vetor permutado\n");
  permuta(VetorAux, 0, tam_VetorAux - 1,VetorPermutado,&aux);
  separador();
  printf("Matriz Permutada passada por parametro:\n" );
  for (size_t i = 0; i < FatTAM; i++) {
    if (i%(TAM-1)!=0 || i==1) {
      printf("%d ",VetorPermutado[i]);
      /* code */
    }else{
      printf("\n%d ",VetorPermutado[i]);

    }
  }
  printf("\n");
  separador();
//printf("aux -> %d\n",aux );
/*Para toda permutacao se traca um caminho de RestoX por elas ate RestoX
Ou seja,se a permutacao e 2403 e o restox e 5,o algoritimo constiste em
verificar o caminho de 5->2->4->0->3->5
*/

  return 0;
}
