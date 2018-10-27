#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libs/Interativo.h"
#include "Libs/Menu.h"
int main(int argc, char const *argv[]) {
  srand((unsigned)time(NULL));
  int op = 0;

  while (op != 9) {
    op = 0;
  separador();
  printf("\t\t Bem  vindo ao CVA\n");
  separador();
  printf("1 -> Interativo\n");
  printf("2 -> Entrar com um arquivo\n" );
  printf("9 -> Sair\n");
  while (op != 1  && op!= 2 && op!= 9) {
  scanf("%d",&op );
  switch (op) {
    case 1:
    Interativo();
    //printf("1\n" );
    break;
    case 2:
    //printf("2\n" );
    //Arquivo();
    break;
    }
  }
}
  return 0;
}
