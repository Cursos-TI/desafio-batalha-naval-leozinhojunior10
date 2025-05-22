#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3
#define NAVIO 3

// Função para verificar se é possível posicionar um navio
int podePosicionar(int tabuleiro[TAM][TAM], int linha[], int coluna[]) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        if (linha[i] < 0 || linha[i] >= TAM || coluna[i] < 0 || coluna[i] >= TAM)
            return 0; // Fora do limite
        if (tabuleiro[linha[i]][coluna[i]] != 0)
            return 0; // Sobreposição
    }
    return 1;
}

// Função para posicionar o navio
void posicionarNavio(int tabuleiro[TAM][TAM], int linha[], int coluna[]) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[linha[i]][coluna[i]] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Navio 1 - Horizontal
    int linha1[] = {1, 1, 1};
    int coluna1[] = {2, 3, 4};

    if (podePosicionar(tabuleiro, linha1, coluna1))
        posicionarNavio(tabuleiro, linha1, coluna1);

    // Navio 2 - Vertical
    int linha2[] = {5, 6, 7};
    int coluna2[] = {7, 7, 7};

    if (podePosicionar(tabuleiro, linha2, coluna2))
        posicionarNavio(tabuleiro, linha2, coluna2);

    // Navio 3 - Diagonal principal (↘)
    int linha3[] = {0, 1, 2};
    int coluna3[] = {0, 1, 2};

    if (podePosicionar(tabuleiro, linha3, coluna3))
        posicionarNavio(tabuleiro, linha3, coluna3);

    // Navio 4 - Diagonal secundária (↙)
    int linha4[] = {7, 8, 9};
    int coluna4[] = {2, 1, 0};

    if (podePosicionar(tabuleiro, linha4, coluna4))
        posicionarNavio(tabuleiro, linha4, coluna4);

    // Exibir o tabuleiro
    printf("Tabuleiro Batalha Naval:\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
