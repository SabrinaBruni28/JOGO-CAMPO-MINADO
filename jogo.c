#include "jogo.h"

void Inicia_Jogo(Jogo* jog, int q){
    int i,j;
    if(q==1){
        for(i=0;i<10;i++)
            for(j=0;j<10;j++)
                jog->matriz8[i][j] = '0';
    }
    else if(q==2){
        for(i=0;i<12;i++)
            for(j=0;j<12;j++)
                jog->matriz10[i][j] = '0';
    }
     else if(q==3){
        for(i=0;i<18;i++)
            for(j=0;j<18;j++)
                jog->matriz16[i][j] = '0';
    }
}

void Print_Jogo(Jogo* jog, int q){
    int i,j;
    if(q==1){
        for(i=1;i<9;i++){
            for(j=1;j<9;j++)
                printf("%c ",jog->matriz8[i][j]);
            printf("\n");
        }
    }
    else if(q==2){
        for(i=1;i<11;i++){
            for(j=1;j<11;j++)
                printf("%c ",jog->matriz10[i][j]);
            printf("\n");
        }
    }
    else if(q==3){
        for(i=1;i<17;i++){
            for(j=1;j<17;j++)
                printf("%c ",jog->matriz16[i][j]);
            printf("\n");
        }
    }
    printf("\n\n");
}

int Revela_Quadrado(Jogo* jog, Tabuleiro* tab, int q, int posicao1, int posicao2){
    int i,j;
    if(q==1){
        if(Existe_Bomba(tab, posicao1, posicao2, q)){
            Fim_De_Jogo(jog, tab, q);
            printf("\n\nFIM DE JOGO!!!\n\n");
            return 1;
        }
        jog->matriz8[posicao1][posicao2] = tab->matriz8[posicao1][posicao2]; 
        return 0;
    }
    else if(q==2){
         if(Existe_Bomba(tab, posicao1, posicao2, q)){
            Fim_De_Jogo(jog, tab, q);
             printf("FIM DE JOGO!!!\n");
            return 1;
        }
        jog->matriz10[posicao1][posicao2] = tab->matriz10[posicao1][posicao2];
        return 0;
    }
    else if(q==3){
        if(Existe_Bomba(tab, posicao1, posicao2, q)){
            Fim_De_Jogo(jog, tab, q);
            printf("FIM DE JOGO!!!\n");
            return 1;
        }
        jog->matriz16[posicao1][posicao2] = tab->matriz16[posicao1][posicao2];
        return 0; 
    }
}

int Existe_Bomba(Tabuleiro* tab, int i, int j,int q){
    if(q==1){
        if(tab->matriz8[i][j] == '!') return 1;
        return 0; 
    }
    else if(q==2){
        if(tab->matriz10[i][j] == '!') return 1;
        return 0; 
    }
    else if(q==3){
       if(tab->matriz16[i][j] == '!') return 1;
        return 0;  
    }
}

void Fim_De_Jogo(Jogo* jog, Tabuleiro* tab, int q){
    int i,j;
    if(q==1){
        for(i=1;i<9;i++){
            for(j=1;j<9;j++){
                if(tab->matriz8[i][j]=='!')
                    jog->matriz8[i][j] = tab->matriz8[i][j];
            }
        }
    }
    else if(q==2){
        for(i=1;i<11;i++){
            for(j=1;j<11;j++){
                if(tab->matriz10[i][j]=='!')
                    jog->matriz10[i][j] = tab->matriz10[i][j];
            }
        }
    }
    else if(q==3){
        for(i=1;i<17;i++){
            for(j=1;j<17;j++){
                if(tab->matriz16[i][j]=='!')
                    jog->matriz16[i][j] = tab->matriz16[i][j];
            }
        }
    }
}