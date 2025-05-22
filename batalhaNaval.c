#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Inicializa tudo com 0

    // Define os navios como vetores com valor 3 (não é obrigatório, mas ajuda na visualização)
    int navio_horizontal[NAVIO_TAM] = {3, 3, 3};
    int navio_vertical[NAVIO_TAM] = {3, 3, 3};

    // Coordenadas iniciais dos navios
    int linha_h = 2, coluna_h = 4; // Começa na linha 2, coluna 4 (horizontal)
    int linha_v = 5, coluna_v = 7; // Começa na linha 5, coluna 7 (vertical)

    // Posiciona o navio horizontal
    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
    }

    // Posiciona o navio vertical
    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }

    // Exibe o tabuleiro
    printf("Tabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
