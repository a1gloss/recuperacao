#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "constantes.h"

int main() {
    int producao1[NUM_PRODUTOS][TAMANHO_LINHA];
    int producao2[NUM_PRODUTOS][TAMANHO_LINHA];
    int total1[NUM_PRODUTOS];
    int total2[NUM_PRODUTOS];
    int totalPorMes1[NUM_PRODUTOS][MESES];
    int totalPorMes2[NUM_PRODUTOS][MESES];
    int totalAnual[NUM_PRODUTOS];
    double matrizProducao[NUM_PRODUTOS][TAMANHO_LINHA];
    double matrizFinal[LINHAS_MATRIZ_FINAL][COLUNAS_MATRIZ_FINAL];

    int valores[] = {8, 4, 2, 9, 6, 1, 8, 3, 5, 7};

    int menu = 1, opcao = 0;

    lerArquivo("prod2023-1.txt", producao1);
    lerArquivo("prod2023-2.txt", producao2);



    while (menu == 1)
    {
        printf("----------------------------------------------\n");
        printf("Bem Vindo ao analytics da Paco firme calcados \n");
        printf("----------------------------------------------\n");
        printf("-           O que deseja ver hoje?           -\n");
        printf("-      1. producao primeiro semestre         -\n");
        printf("-      2. producao segundo semestre          -\n");
        printf("-      3. Total primeiro semestre            -\n");
        printf("-      4. Total segundo semestre             -\n");
        printf("-      5. Total por mes primeiro semestre    -\n");
        printf("-      6. Total por mes segundo semestre     -\n");
        printf("-      7. Total anual                        -\n");
        printf("-      8. Total anual em reais               -\n");
        printf("-      9. imprimir matriz final              -\n");
        printf("-      0. Sair                               -\n");
        printf("----------------------------------------------\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        printf("Producao do 1o Semestre:\n\n");
        imprimirProducao(producao1);
            break;

        case 2:
        printf("\nProducao do 2o Semestre:\n\n");
        imprimirProducao(producao2);
            break;

        case 3:
        calcularTotal(producao1, total1, valores);
        printf("\nTotal de producao 1o Semestre:\n\n");
        imprimirTotal(total1);
            break;

        case 4:
        calcularTotal(producao2, total2, valores);
        printf("\nTotal de producao 2o Semestre:\n\n");
        imprimirTotal(total2);
            break;

        case 5:
            calcularTotalPorMes(producao1, totalPorMes1, valores);
            printf("\nProducao do 1o Semestre por mes:\n");
            imprimirTotalPorMes(totalPorMes1);
                break;

        case 6:
            calcularTotalPorMes(producao2, totalPorMes2, valores);
            printf("\nProducao do 2o Semestre por mes:\n");
            imprimirTotalPorMes(totalPorMes2);
                break;

        case 7: 
            calcularTotalAnual(total1, total2, totalAnual);
            printf("\nTotal de producao anual: \n\n");
            imprimirTotal(totalAnual);
                break;

        case 8:
            calcularTotalAnualemReais(total1, total2, totalAnual, valores);
            printf("\nTotal de producao anual: \n\n");
            imprimirTotal(totalAnual);
                break;

        case 9:

          //*/Protótipo: GerarMatrizFinal((double *)matrizFinal, producao1, producao2, totalPorMes1, totalPorMes2, valores);
          //*/Função: Gerar matriz final.
          //*/Entrada: Números.
          //*/Saída: Valores

            GerarMatrizFinal((double *)matrizFinal, producao1, producao2, totalPorMes1, totalPorMes2, valores);
            printf("\n\n\n");
            imprimirMatrizFinal((double *)matrizFinal);
                break;

        case 0: 
            menu = 0;
                break;
        default:
            printf("opcao invalida");
            break;
        }

    }
//*/Protótipo: GerarArquivoDeSaida (char *nome_arquivo, double *M)
  //*/Função: Gerar o arquivo de saída.
  //*/Entrada: Dados.
  //*/Saída: Arquivo .txt
  GerarArquivoDeSaida("saida.txt", (double *)matrizProducao, NUM_PRODUTOS, TAMANHO_LINHA);


    return 0;
}
