#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro no formato com letras e números
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (char letra = 'A'; letra < 'A' + TAMANHO_TABULEIRO; letra++) {
        printf(" %c ", letra); // cabeçalho de letras
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1); // índice das linhas (1 a 10)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas dos navios (0-indexado): (linha, coluna)
    int linhaNavio1 = 1, colunaNavio1 = 1; // horizontal (linha 2, coluna B)
    int linhaNavio2 = 4, colunaNavio2 = 7; // vertical (linha 5, coluna H)

    // Posiciona navio horizontal
    if (colunaNavio1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavio1][colunaNavio1 + i] = 3;
        }
    }

    // Posiciona navio vertical
    if (linhaNavio2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaNavio2 + i][colunaNavio2] == 3) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavio2 + i][colunaNavio2] = 3;
            }
        }
    }

    // Exibe o tabuleiro formatado
    exibirTabuleiro(tabuleiro);

    return 0;
}
