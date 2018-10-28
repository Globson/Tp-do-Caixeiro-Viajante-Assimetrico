#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Libs/Interativo.h"
#include "../Libs/Menu.h"
#include "../Libs/Permutacao.h"
#include "../Libs/Matricula.h"
#include "../Libs/Matriz.h"
#include "../Libs/Arquivo.h"

void Arquivo(){
  FILE *f;
      char nome_arquivo[20];
      printf("\nDigite o nome do arquivo que deseja abrir:");
      scanf("%s",nome_arquivo);
      f = fopen(nome_arquivo,"r");
      if(f == NULL){
        printf("\n\tErro!Nao foi possivel abrir arquivo!\n");}
        else{
          clock_t inicio, fim;
          double tempo_exe;
          int Matricula1,Matricula2,Matricula3,QuantidadeCidades;
          printf("\n\tArquivo aberto com sucesso!\n");
          fscanf(f,"%d",&Matricula1);
          fscanf(f,"%d",&Matricula2);
          fscanf(f,"%d",&Matricula3);
          fscanf(f,"%d",&QuantidadeCidades);
          int MatrizCusto[QuantidadeCidades][QuantidadeCidades];
          for(int i = 0;i<QuantidadeCidades;i++)
            for(int j = 0;j<QuantidadeCidades;j++){
              if(i==j){MatrizCusto[i][j] = 0;}
              else{fscanf(f,"%d",&MatrizCusto[i][j]);}
            }


          PrintCustos(QuantidadeCidades,MatrizCusto);
          int CidadeInicial = RetornaModN(Matricula1,Matricula2,Matricula3,QuantidadeCidades);
          int VetorAux[QuantidadeCidades-1],Rota[QuantidadeCidades-1],MelhorCaminho;
          MelhorCaminho = 100*QuantidadeCidades;
          PreencherParaPermutacao(QuantidadeCidades,VetorAux,CidadeInicial);
          int tam_VetorAux = sizeof(VetorAux) / sizeof(int);
          printf("Possiveis Caminhos e Custos:\n");
          inicio = clock();
          permuta(VetorAux, 0,tam_VetorAux - 1,QuantidadeCidades,MatrizCusto,Rota,CidadeInicial,&MelhorCaminho);
          separador();
          printf("O Melhor caminho e: \n");
          for (size_t i = 1; i < QuantidadeCidades; i++) {
            printf("%d ",Rota[i] );}
          printf("\nCom o custo de: %d\n",Rota[0] );
          fim = clock();//Fim da contagem
          tempo_exe = ((double) (fim - inicio) / (((double) CLOCKS_PER_SEC)));
          separador();
          printf("Tempo de Execucao => %.3lf ms.\n",tempo_exe);
          separador();


          fclose(f);}
      }
