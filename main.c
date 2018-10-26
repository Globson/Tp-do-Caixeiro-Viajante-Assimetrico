#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libs/Menu.h"
#include "Libs/Permutacao.h"


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
      Matriz[i][j]=(i == j ? 0 : 1+(rand() % 100));

  //Diagonal principal com 0
  //a = rand() % 10;
  //Soma dos digitos das matriculas dos integrantes do grupo
  //printf("Entre com as 3 matriculas\n");
  separador();
  int Matricula1,Matricula2,Matricula3,SUMMatricula;
  //scanf("%d",&Matricula1 );
  Matricula1 = rand()%3600;
  Matricula2 = rand()%3600;
  Matricula3 = rand()%3600;
  printf("Matricula 1 - > %d\n",Matricula1 );
  printf("Matricula 2 - > %d\n",Matricula2 );
  printf("Matricula 3 - > %d\n",Matricula3 );
  separador();
  printf("Matriz %d por %d\n",TAM,TAM );
  for (size_t i = 0; i < TAM; i++) {
    for (size_t j = 0; j < TAM; j++) {
      printf("  %d",Matriz[i][j] );
    }
    printf("\n");
  }
  SUMMatricula = Matricula1/1000 + (Matricula1/100 - (Matricula1/1000)*10) + (Matricula1/10 -(Matricula1/100)*10) + (Matricula1 - (Matricula1/10)*10);
  //scanf("%d\n",&Matricula2 );
  SUMMatricula += Matricula2/1000 + (Matricula2/100 - (Matricula2/1000)*10) + (Matricula2/10 -(Matricula2/100)*10) + (Matricula2 - (Matricula2/10)*10);
  //scanf("%d\n",&Matricula3 );
  SUMMatricula += Matricula3/1000 + (Matricula3/100 - (Matricula3/1000)*10) + (Matricula3/10 -(Matricula3/100)*10) + (Matricula3 - (Matricula3/10)*10);
  separador();
  printf("SUMMatricula - > %d\n",SUMMatricula );
  //Resto da divisao entre soma das matriculas e N
  int RestoX = SUMMatricula%TAM;
  printf("RestoX - > %d\n", RestoX);
  separador();

  int v[TAM],aux = 0;
  for (size_t i = 0; i < TAM; i++) {
    if (i==RestoX) {
      aux++;
      v[i]=aux;
    }else{
      v[i]=aux;
    }
    aux++;
  }
  int tam_v = sizeof(v) / sizeof(int);

  separador();
  permuta(v, 0, tam_v - 1);
/*Para toda permutacao se traca um caminho de RestoX por elas ate RestoX
Ou seja,se a permutacao e 2403 e o restox e 5,o algoritimo constiste em
verificar o caminho de 5->2->4->0->3->5
*/
  return 0;
}
