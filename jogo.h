#include "tabuleiro.h"

typedef struct {
    char matriz8[10][10];
    char matriz10[12][12];
    char matriz16[18][18];
}Jogo;

void Inicia_Jogo(Jogo* jog, int q);
void Print_Jogo(Jogo* jog, int q);
int Revela_Quadrado(Jogo* jog, Tabuleiro* tab, int q, int posicao1, int posicao2, int *aberto, int *bandeira);
void Fim_De_Jogo(Jogo* jog, Tabuleiro* tab, int q);
void Abrir_Espaco(Jogo* jog, Tabuleiro* tab, int q, int x, int y, int* aberto);
int Ja_Foi_Aberto(Jogo* jog, int q, int posicao1, int posicao2);
void Abrir_Posicao(Jogo* jog, Tabuleiro* tab, int q, int posicao1, int posicao2);
int Ganhou_Jogo(Jogo* jog, int q, int i, int j, int aberto, int bandeira);
int Posicao_Valida(int q, int posicao1, int posicao2);
void Colocar_Alerta(Jogo* jog, int q, int posicao1, int posicao2, int *bandeira);
int Existe_Alerta(Jogo * jog, int i, int j,int q);
int Tira_Alerta(Jogo* jog, int q, int posicao1, int posicao2, int *bandeira);