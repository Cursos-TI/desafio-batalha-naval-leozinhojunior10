#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3
#define HABIL_TAM 5
#define NAVIO 3
#define HABIL 5

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

int podePosicionar(int tabuleiro[TAM][TAM], int linha[], int coluna[]) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        if (linha[i] < 0 || linha[i] >= TAM || coluna[i] < 0 || coluna[i] >= TAM)
            return 0;
        if (tabuleiro[linha[i]][coluna[i]] != 0)
            return 0;
    }
    return 1;
}

void posicionarNavio(int tabuleiro[TAM][TAM], int linha[], int coluna[]) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[linha[i]][coluna[i]] = NAVIO;
    }
}

void construirCone(int matriz[HABIL_TAM][HABIL_TAM]) {
    for (int i = 0; i < HABIL_TAM; i++) {
        for (int j = 0; j < HABIL_TAM; j++) {
            if (j >= (HABIL_TAM / 2 - i) && j <= (HABIL_TAM / 2 + i) && i <= HABIL_TAM / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void construirCruz(int matriz[HABIL_TAM][HABIL_TAM]) {
    for (int i = 0; i < HABIL_TAM; i++) {
        for (int j = 0; j < HABIL_TAM; j++) {
            if (i == HABIL_TAM / 2 || j == HABIL_TAM / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void construirOctaedro(int matriz[HABIL_TAM][HABIL_TAM]) {
    for (int i = 0; i < HABIL_TAM; i++) {
        for (int j = 0; j < HABIL_TAM; j++) {
            if (abs(i - HABIL_TAM / 2) + abs(j - HABIL_TAM / 2) <= HABIL_TAM / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM][TAM], int matriz[HABIL_TAM][HABIL_TAM], int origem_linha, int origem_coluna) {
    int offset = HABIL_TAM / 2;

    for (int i = 0; i < HABIL_TAM; i++) {
        for (int j = 0; j < HABIL_TAM; j++) {
            int li = origem_linha - offset + i;
            int col = origem_coluna - offset + j;

            if (li >= 0 && li < TAM && col >= 0 && col < TAM) {
                if (matriz[i][j] == 1 && tabuleiro[li][col] == 0)
                    tabuleiro[li][col] = HABIL;
            }
        }
    }
}

void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("Tabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Posicionar navios
    int l1[] = {1, 1, 1}, c1[] = {2, 3, 4};
    int l2[] = {5, 6, 7}, c2[] = {7, 7, 7};
    int l3[] = {0, 1, 2}, c3[] = {0, 1, 2};
    int l4[] = {7, 8, 9}, c4[] = {2, 1, 0};

    if (podePosicionar(tabuleiro, l1, c1)) posicionarNavio(tabuleiro, l1, c1);
    if (podePosicionar(tabuleiro, l2, c2)) posicionarNavio(tabuleiro, l2, c2);
    if (podePosicionar(tabuleiro, l3, c3)) posicionarNavio(tabuleiro, l3, c3);
    if (podePosicionar(tabuleiro, l4, c4)) posicionarNavio(tabuleiro, l4, c4);

    // Criar e aplicar habilidades
    int cone[HABIL_TAM][HABIL_TAM];
    int cruz[HABIL_TAM][HABIL_TAM];
    int octaedro[HABIL_TAM][HABIL_TAM];

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 2, 7);       // cone com origem em (2,7)
    aplicarHabilidade(tabuleiro, cruz, 5, 2);       // cruz com origem em (5,2)
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);   // octaedro com origem em (7,7)

    imprimirTabuleiro(tabuleiro);

    return 0;
}
