#include <stdio.h>

#define TAM 10      // tamanho do tabuleiro
#define NAVIO_TAM 3 // tamanho de cada navio
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];
    int navio1[NAVIO_TAM]; // navio horizontal
    int navio2[NAVIO_TAM]; // navio vertical
    char letrasColunas[TAM] = {'A','B','C','D','E','F','G','H','I','J'};

    // 1. Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Inicializa os navios (valor 3)
    for (int i = 0; i < NAVIO_TAM; i++) {
        navio1[i] = NAVIO;
        navio2[i] = NAVIO;
    }

    // 3. Escolher posições iniciais (fixas para exemplo)
    int linha1 = 2, coluna1 = 4; // início do navio horizontal
    int linha2 = 5, coluna2 = 7; // início do navio vertical

    // 4. Posicionar navio horizontal (garantindo que cabe no tabuleiro)
    if (coluna1 + NAVIO_TAM <= TAM) {
        for (int i = 0; i < NAVIO_TAM; i++) {
            tabuleiro[linha1][coluna1 + i] = navio1[i];
        }
    }

    // 5. Posicionar navio vertical (garantindo que cabe no tabuleiro)
    if (linha2 + NAVIO_TAM <= TAM) {
        for (int i = 0; i < NAVIO_TAM; i++) {
            tabuleiro[linha2 + i][coluna2] = navio2[i];
        }
    }

    // 6. Exibir o tabuleiro com letras e números
    printf("    ");  // espaço inicial antes das letras
    for (int j = 0; j < TAM; j++) {
        printf("%c ", letrasColunas[j]);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d  ", i + 1); // numeração das linhas (1–10)
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}