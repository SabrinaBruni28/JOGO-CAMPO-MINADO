#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    char matriz8[10][10];
    char matriz10[12][12];
    char matriz16[18][18];
}Tabuleiro;

void Inicia_Tabuleiro(Tabuleiro* tab, int q);
void Print_Tabuleiro(Tabuleiro* tab, int q);
void Coloca_Bomba(Tabuleiro* tab, int q);
void Completa_Tabuleiro(Tabuleiro* tab, int q);