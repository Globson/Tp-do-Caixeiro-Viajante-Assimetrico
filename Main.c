#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libs/Interativo.h"
#include "Libs/Menu.h"
#include "Libs/Arquivo.h"
int main(int argc, char const *argv[]) {
  srand((unsigned)time(NULL));
  int op = 0;
  while(1){
  op = 0;
  separador();
  printf("\t\t\t\t   Bem  vindo ao CVA\n");
  separador();
  printf("\n1 - Interativo->\n");
  printf("2 - Entrar com um arquivo->\n" );
  printf("9 - Sair->\n");

  while(op != 1 && op != 2 && op != 9){
      printf("\nDigite a opcao desejada:");
      scanf("%d",&op);
      if(op != 1 && op != 2 && op != 9){
        printf("Opcao invalida!\n");}}

  if(op == 1){Interativo();}
  if(op == 2){Arquivo();}
  if(op == 9){
    int f = 0;
  printf("\nDeseja realmente finalizar a execucao do programa?\n\t1.Sim\n\t2.Nao\n");
  while(f != 1 && f != 2){
    printf("Digite a opcao desejada:");
    scanf("%d",&f);
    if(f != 1 && f != 2){
      printf("Opcao invalida!\n");}}
  if(f == 1){
    Agradecimentos();
    break;}
  if(f == 2){
    printf("\n\tFinalizacao cancelada!\n");}}
}


  return 0;
}
