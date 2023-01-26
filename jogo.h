#include "tabuleiro.h"

typedef struct {
    char matriz8[10][10];
    char matriz10[12][12];
    char matriz16[18][18];
}Jogo;

void Inicia_Jogo(Jogo* jog, int q);
void Print_Jogo(Jogo* jog, int q);
int Revela_Quadrado(Jogo* jog, Tabuleiro* tab, int q, int posicao1, int posicao2);
int Existe_Bomba(Tabuleiro* tab, int i, int j,int q);
void Fim_De_Jogo(Jogo* jog, Tabuleiro* tab, int q);