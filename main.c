#include "jogo.h"

int main(){
    Tabuleiro tab;
    Jogo jog;
    int i,j;
    Inicia_Tabuleiro(&tab, 3);
    Coloca_Bomba(&tab,3);
    Completa_Tabuleiro(&tab,3);
    Print_Tabuleiro(&tab,3);
    Inicia_Jogo(&jog,3);
    Print_Jogo(&jog,3);
    printf("Posicoes: ");
    scanf("%d %d",&i,&j);
    Revela_Quadrado(&jog, &tab,3,i,j);
    Print_Jogo(&jog,3);
    return 0;
}