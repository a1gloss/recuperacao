#ifndef FUNCOES_H
#define FUNCOES_H
#include "constantes.h"
#define TAMANHO_LINHA 10  
#define MESES 12 

const char *nomeDoProduto(int indice);
int valorDoProduto(int indice);
void lerArquivo(const char *nomeArquivo, int producao[][TAMANHO_LINHA]);
void imprimirProducao(int producao[][TAMANHO_LINHA]);
void calcularTotal(int producao[][TAMANHO_LINHA], int total[], int valores[]);
void imprimirTotal(int total[]);
void imprimirTotalemReais(int total[]);
void calcularTotalAnual(int total1[], int total2[], int totalAnual[]);
void calcularTotalAnualemReais(int total1[], int total2[], int totalAnual[], int valores[]);
void calcularTotalPorMes(int producao[][TAMANHO_LINHA], int totalPorMes[][MESES], int valores[]);
void imprimirTotalPorMes(int totalPorMes[][MESES]);
double MaiorValorDaLinha(double *M, int nlin, int ncol, int linha);
double MaiorValorDaColuna(double *M, int nlin, int ncol, int coluna);
double MenorValorDaLinha(double *M, int nlin, int ncol, int linha);
double MenorValorDaColuna(double *M, int nlin, int ncol, int coluna);
void GerarArquivoDeSaida(char *nome_arquivo, double *M, int nlin, int ncol);
void GerarMatrizFinal(double *M, int producao1[][TAMANHO_LINHA], int producao2[][TAMANHO_LINHA], int totalPorMes1[][MESES], int totalPorMes2[][MESES], int valores[]);
void imprimirMatrizFinal(double *M);

#endif
