#include <stdio.h>
#include <stdlib.h> // para abs()

#define TAM 10       // tamanho do tabuleiro
#define HAB_TAM 5    // tamanho das matrizes de habilidade
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para exibir o tabuleiro numerado com letras nas colunas
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    char letrasColunas[TAM] = {'A','B','C','D','E','F','G','H','I','J'};

    printf("\n    ");
    for (int j = 0; j < TAM; j++) printf("%c ", letrasColunas[j]);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d  ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar uma matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[HAB_TAM][HAB_TAM], int origemLinha, int origemColuna) {
    int offset = HAB_TAM / 2;

    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha - offset + i;
                int colunaTab = origemColuna - offset + j;

                // Garante que está dentro dos limites do tabuleiro
                if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                    // Marca a área afetada se não for navio
                    if (tabuleiro[linhaTab][colunaTab] == AGUA)
                        tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // ----------------------------
    // Criar NAVIOS (exemplo simples)
    // ----------------------------
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;
    tabuleiro[2][6] = NAVIO;

    tabuleiro[6][2] = NAVIO;
    tabuleiro[7][2] = NAVIO;
    tabuleiro[8][2] = NAVIO;

    // ----------------------------
    // Criar as MATRIZES DE HABILIDADE
    // ----------------------------
    int cone[HAB_TAM][HAB_TAM];
    int cruz[HAB_TAM][HAB_TAM];
    int octaedro[HAB_TAM][HAB_TAM];

    // Habilidade em CONE (ponta no topo)
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (j >= (HAB_TAM/2 - i) && j <= (HAB_TAM/2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // Habilidade em CRUZ (centro no meio)
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (i == HAB_TAM/2 || j == HAB_TAM/2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // Habilidade em OCTAEDRO (forma de losango)
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (abs(i - HAB_TAM/2) + abs(j - HAB_TAM/2) <= HAB_TAM/2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // ----------------------------
    // Aplicar as habilidades no tabuleiro
    // ----------------------------
    aplicarHabilidade(tabuleiro, cone, 4, 4);      // Cone no centro
    aplicarHabilidade(tabuleiro, cruz, 7, 7);      // Cruz mais abaixo
    aplicarHabilidade(tabuleiro, octaedro, 5, 2);  // Octaedro à esquerda

    // ----------------------------
    // Exibir resultado final
    // ----------------------------
    printf("\n=== TABULEIRO COM HABILIDADES ===\n");
    printf("0 = Água | 3 = Navio | 5 = Área afetada\n");
    exibirTabuleiro(tabuleiro);

    // ----------------------------
    // Mostrar as MATRIZES de HABILIDADE separadamente
    // ----------------------------
    printf("\n=== MATRIZ: CONE ===\n");
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++)
            printf("%d ", cone[i][j]);
        printf("\n");
    }

    printf("\n=== MATRIZ: CRUZ ===\n");
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++)
            printf("%d ", cruz[i][j]);
        printf("\n");
    }

    printf("\n=== MATRIZ: OCTAEDRO ===\n");
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++)
            printf("%d ", octaedro[i][j]);
        printf("\n");
    }

    return 0;
}