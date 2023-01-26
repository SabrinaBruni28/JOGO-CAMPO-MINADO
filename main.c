#include "jogo.h"

int main(){
    Tabuleiro tab;
    Jogo jog;
    int i,j;
    Inicia_Tabuleiro(&tab, 1);
    Coloca_Bomba(&tab,1);
    Completa_Tabuleiro(&tab,1);
    Print_Tabuleiro(&tab,1);
    Inicia_Jogo(&jog,1);
    Print_Jogo(&jog,1);
    printf("Posicoes: ");
    scanf("%d %d",&i,&j);
    Revela_Quadrado(&jog, &tab,1,i,j);
    Print_Jogo(&jog,1);
    return 0;
}