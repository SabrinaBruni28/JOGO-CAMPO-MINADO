#include "tabuleiro.h"

typedef struct {
    char matriz8[10][10];
    char matriz10[12][12];
    char matriz16[18][18];
}Jogo;

void Inicia_Jogo(Jogo* jog, int q);
/*Funcao que Inicializa toda a matriz do jogo com zero, ate as bordas.*/
void Print_Jogo(Jogo* jog, int q);
/*Funcao que printa a matriz do jogo na tela*/
int Revela_Quadrado(Jogo* jog, Tabuleiro* tab, int q, int posicao1, int posicao2, int *aberto, int *bandeira);
/*Funcao que revela um quadradinho escolhido.
  Conferindo se a posicao e valida e se ja foi aberta, tambem, se e bomda, espaco ou numero.
  E ao final confere se o jogo foi ganho ou nao*/
int Existe_Alerta(Jogo * jog, int i, int j,int q);
/**/
void Fim_De_Jogo(Jogo* jog, Tabuleiro* tab, int q);
/**/
void Abrir_Espaco(Jogo* jog, Tabuleiro* tab, int q, int x, int y, int* aberto);
int Ja_Foi_Aberto(Jogo* jog, int q, int posicao1, int posicao2, int i);
void Abrir_Posicao(Jogo* jog, Tabuleiro* tab, int q, int posicao1, int posicao2);
int Ganhou_Jogo(Jogo* jog, int q, int i, int j, int aberto, int bandeira);
void Colocar_Alerta(Jogo* jog, int q, int posicao1, int posicao2, int *bandeira);
int Tira_Alerta(Jogo* jog, int q, int posicao1, int posicao2, int *bandeira);