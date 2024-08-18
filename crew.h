#define palavra

#include <iostream>
#include <string>
#include <cstring>

#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define ORANGE "\033[38;5;208m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define LIGHT_BLUE "\033[94m"
#define WHITE   "\033[37m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDGREEN   "\033[1m\033[32m"
#define RESET   "\033[0m"

const int SIZEH = 7;
const int SIZEV = 12;

void inicializarMatriz(char matriz[SIZEH][SIZEV]) {
    for (int i = 0; i < SIZEH; i++) {
        for (int j = 0; j < SIZEV; j++) {
            matriz[i][j] = ' ';
        }
    }
}

void exibirMatriz(char matriz[7][12]) {
    for (int i = 0; i < SIZEH; i++) {
        for (int j = 0; j < SIZEV; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void preencherPalavraVertical(char matriz[7][12], string palavra, int linha, int coluna) {
    for (int i = 0; i < palavra.length(); i++) {
        matriz[linha + i][coluna] = palavra[i];
    }
}

struct PalavraPontuacao {
    string palavra;
    int pontuacao;
};