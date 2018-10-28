#include "../Libs/Matricula.h"
#include <stdio.h>
#include <stdlib.h>
int MatriculaRandomica(int N){
  int Matricula1 = rand()%3600;
  int Matricula2 = rand()%3600;
  int Matricula3 = rand()%3600;
  return RetornaModN(Matricula1,Matricula2,Matricula3,N);
}
int LeituraMatriculas(int N){
  int Matricula1,Matricula2,Matricula3;
  printf("\nEntre com a primeira matricula:");
  scanf("%d",&Matricula1 );
  printf("\nEntre com a segunda matricula:");
  scanf("%d",&Matricula2 );
  printf("\nEntre com a terceira matricula:");
  scanf("%d",&Matricula3 );
  printf("\n");
  return RetornaModN(Matricula1,Matricula2,Matricula3,N);
}
int RetornaModN(int Matricula1,int Matricula2,int Matricula3,int N){
  int SUMMatricula = 0;
  SUMMatricula = Matricula1/1000 + (Matricula1/100 - (Matricula1/1000)*10) + (Matricula1/10 -(Matricula1/100)*10) + (Matricula1 - (Matricula1/10)*10);
  SUMMatricula += Matricula2/1000 + (Matricula2/100 - (Matricula2/1000)*10) + (Matricula2/10 -(Matricula2/100)*10) + (Matricula2 - (Matricula2/10)*10);
  SUMMatricula += Matricula3/1000 + (Matricula3/100 - (Matricula3/1000)*10) + (Matricula3/10 -(Matricula3/100)*10) + (Matricula3 - (Matricula3/10)*10);
  return (SUMMatricula%N);
}
