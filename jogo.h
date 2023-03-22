#include "tabuleiro.h"

/*TAD que contem a parte visual do jogo, sendo a parte que o usuario interage*/
typedef struct {
    char matriz8[10][10];
    char matriz10[12][12];
    char matriz16[18][18];
}Jogo;

/*Funcao que Inicializa toda a matriz do jogo com zero, ate as bordas.*/
void Inicia_Jogo(Jogo* jog, int q);
/*Funcao que printa a matriz do jogo na tela.*/
void Print_Jogo(Jogo* jog, int q);
/*Funcao que revela um quadradinho escolhido.
  Conferindo se a posicao e valida e se ja foi aberta, tambem, se e bomda, espaco ou numero.
  E ao final confere se o jogo foi ganho ou nao.
  Retorna 1 se o jogo acabou, tanto perdido quanto ganho
  e retorna 0  se ainda continua.*/
int Revela_Quadrado(Jogo* jog, Tabuleiro* tab, int q, int posicao1, int posicao2, int *aberto, int *bandeira);
/*Funcao que confere se existe ou nao alerta no quadradinho.
int Existe_Alerta(Jogo * jog, int i, int j,int q);
/*Funcao que finaliza o jogo.
  Retornando 1 se houver alerta e zero caso contrario.*/
void Fim_De_Jogo(Jogo* jog, Tabuleiro* tab, int q);
/*Funcao que abre quadradinhos escolhidos que possuiem espaco.
  Mostrando todas as bombas que nao possuiem alerta.
  Feito por meio de recursividade.
  Abrindo outros quadradinhos ao redor que sejam numeros e abrindo ao redor dos que forem espaco.*/
void Abrir_Espaco(Jogo* jog, Tabuleiro* tab, int q, int x, int y, int* aberto);
/*Funcao que confere se foi ou nao aberto o quadradinho.
  Retornando 1 se fechado e zero se aberto.*/
int Ja_Foi_Aberto(Jogo* jog, int q, int posicao1, int posicao2, int i);
/*Funcao que abre o quadradinho da posicao selecionalda.
  Igualando a posicao do jogo ao tabuleiro.*/
void Abrir_Posicao(Jogo* jog, Tabuleiro* tab, int q, int posicao1, int posicao2);
/*Funcao que confere se o jogo foi ganho ou nao.
  Conferindo se a quantidade de quadradinhos totais menos a quantida&& bandeira == 2*8de de bombas foi aberto e se a quantidade de alertas e igual ao total de bombas.*/
int Ganhou_Jogo(Jogo* jog, int q, int i, int j, int aberto, int bandeira);
/*Funcao que coloca um alerta na posicao desejada, ou seja onde se pensa ter uma bomba.
  Conferindo se e uma posicao valida e se nao foi aberta.*/
void Colocar_Alerta(Jogo* jog, int q, int posicao1, int posicao2, int *bandeira);
/*Funcao que tira um alerta da posicao desejada.
  Coferindo se e uma posicao valida e se existe alerta naquela posicao.*/
int Tira_Alerta(Jogo* jog, int q, int posicao1, int posicao2, int *bandeira);
/*Funcao que confere se a posicao com alerta tem realmente uma bomba e marca ela com um ^ caso nao tenha.*/
void Errado(Jogo* jog, Tabuleiro* tab, int q, int posicao1, int posicao2);
/*Funcao que marca a posicao escolhida que possui uma bomba com um X. */
void Explodiu(Jogo* jog, int q, int posicao1, int posicao2);