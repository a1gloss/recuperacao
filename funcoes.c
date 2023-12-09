#include "funcoes.h"
#include <stdio.h>

const char *nomeDoProduto(int indice) {
    switch (indice) {
        case 0: return "Sola inteira";
        case 1: return "Meia sola";
        case 2: return "Quarto de sola";
        case 3: return "Entre sola";
        case 4: return "Palmilha";
        case 5: return "Meia Palmilha";
        case 6: return "Salto alto";
        case 7: return "Salto medio";
        case 8: return "Salto curto";
        case 9: return "Salto baixo";
        default: return "Desconhecido";
    }
}

int valorDoProduto(int indice) {
    int valores[] = {8, 4, 2, 9, 6, 1, 8, 3, 5, 7};
    return valores[indice];
}

//*/Protótipo: lerArquivo(const char *nomeArquivo, int producao[][TAMANHO_LINHA])
//*/Função: Ler arquivo .txt.
//*/Entrada: Caracteres.
//*/Saída: não tem saída
void lerArquivo(const char *nomeArquivo, int producao[][TAMANHO_LINHA]) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        exit(1);
    }

    for (int i = 0; i < NUM_PRODUTOS; i++) {
        for (int j = 0; j < TAMANHO_LINHA; j++) {
            fscanf(arquivo, "%d", &producao[i][j]);
        }
    }

    fclose(arquivo);
}

//*/Protótipo: imprimirProducao(int producao[][TAMANHO_LINHA])
//*/Função: Imprimir produção.
//*/Entrada: Caracteres.
//*/Saída: Caracteres
void imprimirProducao(int producao[][TAMANHO_LINHA]) {
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        printf("%s: ", nomeDoProduto(i));
        for (int j = 0; j < TAMANHO_LINHA; j++) {
            printf("%d ", producao[i][j]);
        }
        printf("\n");
    }

}

void calcularTotal(int producao[][TAMANHO_LINHA], int total[], int valores[]) {
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        total[i] = 0;
        for (int j = 0; j < TAMANHO_LINHA; j++) {
            total[i] += producao[i][j];
        }
         total[i] *= valores[i];
    }
}

void imprimirTotal(int total[]) {
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        printf("%s: %d\n", nomeDoProduto(i), total[i]);
    }
}

void imprimirTotalemReais(int total[]) {
    printf("\nTotal de producao (em reais) por produto:\n");
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        printf("%s: %d reais\n", nomeDoProduto(i), total[i]);
    }
}


void calcularTotalAnual(int total1[], int total2[], int totalAnual[]) {
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        totalAnual[i] = total1[i] + total2[i];
    }
}

void calcularTotalAnualemReais(int total1[], int total2[], int totalAnual[], int valores[]) {
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        totalAnual[i] = total1[i] + total2[i];
        totalAnual[i] *= valores[i];
    }
}

void calcularTotalPorMes(int producao[][TAMANHO_LINHA], int totalPorMes[][MESES], int valores[]) {
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        for (int j = 0; j < MESES; j++) {
            totalPorMes[i][j] = 0;
            for (int k = j * (TAMANHO_LINHA / MESES); k < (j + 1) * (TAMANHO_LINHA / MESES); k++) {
                totalPorMes[i][j] += producao[i][k];
            }
            totalPorMes[i][j] *= valores[i];
        }
    }
}

void imprimirTotalPorMes(int totalPorMes[][MESES]) {
    printf("\nTotal de producao (em reais) por produto por mes:\n");
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        printf("%s:\n", nomeDoProduto(i));
        for (int j = 0; j < MESES; j++) {
            printf("Mes %d: %d reais\n", j + 1, totalPorMes[i][j]);
        }
        printf("\n");
    }
}

double MaiorValorDaLinha(double *M, int nlin, int ncol, int linha) {
    double max = M[linha * ncol];
    for (int j = 1; j < ncol; j++) {
        if (M[linha * ncol + j] > max) {
            max = M[linha * ncol + j];
        }
    }
    return max;
}

double MaiorValorDaColuna(double *M, int nlin, int ncol, int coluna) {
    double max = M[coluna];
    for (int i = 1; i < nlin; i++) {
        if (M[i * ncol + coluna] > max) {
            max = M[i * ncol + coluna];
        }
    }
    return max;
}

double MenorValorDaLinha(double *M, int nlin, int ncol, int linha) {
    double min = M[linha * ncol];
    for (int j = 1; j < ncol; j++) {
        if (M[linha * ncol + j] < min) {
            min = M[linha * ncol + j];
        }
    }
    return min;
}

double MenorValorDaColuna(double *M, int nlin, int ncol, int coluna) {
    double min = M[coluna];
    for (int i = 1; i < nlin; i++) {
        if (M[i * ncol + coluna] < min) {
            min = M[i * ncol + coluna];
        }
    }
    return min;
}

void GerarArquivoDeSaida(char *nome_arquivo, double *M, int nlin, int ncol) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        exit(1);
    }

    fprintf(arquivo, "Matriz de Produção:\n");
    for (int i = 0; i < nlin; i++) {
        for (int j = 0; j < ncol; j++) {
            fprintf(arquivo, "%.2lf\t", M[i * ncol + j]);
        }
        fprintf(arquivo, "\n");
    }

    fprintf(arquivo, "\nMaiores valores por linha:\n");
    for (int i = 0; i < nlin; i++) {
        fprintf(arquivo, "Linha %d: %.2lf\n", i + 1, MaiorValorDaLinha(M, nlin, ncol, i));
    }

    fprintf(arquivo, "\nMaiores valores por coluna:\n");
    for (int j = 0; j < ncol; j++) {
        fprintf(arquivo, "Coluna %d: %.2lf\n", j + 1, MaiorValorDaColuna(M, nlin, ncol, j));
    }

    fprintf(arquivo, "\nMenores valores por linha:\n");
    for (int i = 0; i < nlin; i++) {
        fprintf(arquivo, "Linha %d: %.2lf\n", i + 1, MenorValorDaLinha(M, nlin, ncol, i));
    }

    fprintf(arquivo, "\nMenores valores por coluna:\n");
    for (int j = 0; j < ncol; j++) {
        fprintf(arquivo, "Coluna %d: %.2lf\n", j + 1, MenorValorDaColuna(M, nlin, ncol, j));
    }

    fclose(arquivo);
}

void GerarMatrizFinal(double *M, int producao1[][TAMANHO_LINHA], int producao2[][TAMANHO_LINHA], int totalPorMes1[][MESES], int totalPorMes2[][MESES], int valores[]) {
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        for (int j = 0; j < MESES; j++) {
            M[i * COLUNAS_MATRIZ_FINAL + j] = totalPorMes1[i][j];
            M[i * COLUNAS_MATRIZ_FINAL + j + MESES] = totalPorMes2[i][j];
        }

        M[i * COLUNAS_MATRIZ_FINAL + 12] = 0; 
        for (int j = 0; j < MESES; j++) {
            M[i * COLUNAS_MATRIZ_FINAL + 12] += totalPorMes1[i][j];
            M[i * COLUNAS_MATRIZ_FINAL + 12 + 1] += totalPorMes2[i][j];
        }
        M[i * COLUNAS_MATRIZ_FINAL + 12] *= valores[i]; 
        M[i * COLUNAS_MATRIZ_FINAL + 12 + 1] *= valores[i]; 
    }

    for (int j = 0; j < MESES; j++) {
        M[NUM_PRODUTOS * COLUNAS_MATRIZ_FINAL + j] = 0; 
        M[NUM_PRODUTOS * COLUNAS_MATRIZ_FINAL + j + MESES] = 0; 
        for (int i = 0; i < NUM_PRODUTOS; i++) {
            M[NUM_PRODUTOS * COLUNAS_MATRIZ_FINAL + j] += totalPorMes1[i][j] + totalPorMes2[i][j];
            M[NUM_PRODUTOS * COLUNAS_MATRIZ_FINAL + j + MESES] += totalPorMes1[i][j] + totalPorMes2[i][j];
        }
    }
}

void imprimirMatrizFinal(double *M) {
    printf("\nMatriz Final:\n");
    for (int i = 0; i < LINHAS_MATRIZ_FINAL; i++) {
        for (int j = 0; j < COLUNAS_MATRIZ_FINAL; j++) {
            printf("%.2lf\t", M[i * COLUNAS_MATRIZ_FINAL + j]);
        }
        printf("\n");
    }
}
