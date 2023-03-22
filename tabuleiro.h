#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Inteiros que indeicam a quantidade de bombas em cada tamanho de tabuleiro.*/
int n1 = 8, n2 = 13, n3 = 32;

/*TAD que contem a parte logica do tabuleiro, sendo o background do jogo.*/
typedef struct{
    char matriz8[10][10];
    char matriz10[12][12];
    char matriz16[18][18];
}Tabuleiro;

void Inicia_Tabuleiro(Tabuleiro* tab, int q);
/*Funcao que inicia toda a matriz do tabuleiro com zero, ate as bordas.
  E chama as funcoes de colocar bomba e completar o tabuleiro.*/
void Print_Tabuleiro(Tabuleiro* tab, int q);
/*Funcao que printa a matriz do tabuleiro na tela.*/
void Coloca_Bomba(Tabuleiro* tab, int q);
/*Funcao que gera aleatoriamente locais para colocar as bombas, sendo 2 vezes o tamanho da linha/coluna da matriz quadrada.
  Conferindo se ja existe bomba ou nao no local gerado.*/
void Coloca_Espaco(Tabuleiro* tab, int q);
/*Funcao que coloca espaco onde possui zero.*/
void Completa_Tabuleiro(Tabuleiro* tab, int q);
/*Funcao que conta a quantidade de bombas em volta de cada quadradinho que nao possui bomba.
  Chamando no final a funcao de colocar espaco.*/
int Existe_Bomba(Tabuleiro* tab, int i, int j,int q);
/*Funcao que confere se existe ou nao bomba no quadradinho.
  Retornando 1 se houver bomba e zero caso contrario.*/
int Existe_Espaco(Tabuleiro* tab, int i, int j,int q);
/*Funcao que confere se existe ou nao espaco no quadradinho.
  Retornando 1 se houver espaco e zero caso contrario.*/
int Existe_Numero(Tabuleiro* tab, int i, int j,int q);
/*Funcao que confere se existe ou nao numero no quadradinho.
  Conferindo se e diferente de espaco e bomba.
  Retornando 1 se houver numero e zero caso contrario.*/
int Posicao_Valida(int q, int posicao1, int posicao2, int i);
/*Funcao que confere se as posicoes sao validas dentro do tamanho da matriz.
  Retornando 1 se for valida e zero caso contrario.
  Tendo a opcao de printar ou nao o aviso.*/