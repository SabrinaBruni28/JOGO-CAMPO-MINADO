#include "tabuleiro.h"

void Inicia_Tabuleiro(Tabuleiro* tab, int q){
    int i,j;
    if(q==1){
        for(i=0;i<10;i++)
            for(j=0;j<10;j++)
                tab->matriz8[i][j] = '0';
    }
    else if(q==2){
        for(i=0;i<12;i++)
            for(j=0;j<12;j++)
                tab->matriz10[i][j] = '0';
    }
     else if(q==3){
        for(i=0;i<18;i++)
            for(j=0;j<18;j++)
                tab->matriz16[i][j] = '0';
    }
    Coloca_Bomba(tab,q);
    Completa_Tabuleiro(tab,q);
}

void Print_Tabuleiro(Tabuleiro* tab, int q){
    int i,j;
    if(q==1){
        for(i=1;i<9;i++){
            for(j=1;j<9;j++)
                printf("%c ",tab->matriz8[i][j]);
            printf("\n");
        }
    }
    else if(q==2){
        for(i=1;i<11;i++){
            for(j=1;j<11;j++)
                printf("%c ",tab->matriz10[i][j]);
            printf("\n");
        }
    }
    else if(q==3){
        for(i=1;i<17;i++){
            for(j=1;j<17;j++)
                printf("%c ",tab->matriz16[i][j]);
            printf("\n");
        }
    }
    printf("\n\n");
}

void Coloca_Bomba(Tabuleiro* tab, int q){
    int bombas = 0;
    int posicao1, posicao2;
    int i,j,existe;
    if(q==1){
        srand( (unsigned)time(NULL) );
        while(bombas!=16){
            posicao1 = rand()%8;
            posicao2 = rand()%8;
            existe=0;
            for(i=1;i<9;i++){
                for(j=1;j<9;j++){
                    if(tab->matriz8[i][j]=='!' && posicao1==i && posicao2==j){
                        existe=1;
                        break;
                    }
                }
            }
            if(posicao1!=0 && posicao2!=0 && existe==0){
                tab->matriz8[posicao1][posicao2] = '!';
                bombas++;
            }
        }
    }
    else if(q==2){
        srand( (unsigned)time(NULL) );
        while(bombas!=20){
            posicao1 = rand()%10;
            posicao2 = rand()%10;
            existe=0;
            for(i=1;i<11;i++){
                for(j=1;j<11;j++){
                    if(tab->matriz10[i][j]=='!' && posicao1==i && posicao2==j){
                        existe=1;
                        break;
                    }
                }
            }
            if(posicao1!=0 && posicao2!=0 && existe==0){
                tab->matriz10[posicao1][posicao2] = '!';
                bombas++;
            }
        }
    }
    else if(q==3){
        srand( (unsigned)time(NULL) );
        while(bombas!=32){
            posicao1 = rand()%16;
            posicao2 = rand()%16;
            existe=0;
            for(i=1;i<17;i++){
                for(j=1;j<17;j++){
                    if(tab->matriz16[i][j]=='!' && posicao1==i && posicao2==j){
                        existe=1;
                        break;
                    }
                }
            }
            if(posicao1!=0 && posicao2!=0 && existe==0){
                tab->matriz16[posicao1][posicao2] = '!';
                bombas++;
            }
        }
    }
}
void Completa_Tabuleiro(Tabuleiro* tab, int q){
    int i,j,linha,coluna;
    if(q==1){
        for(linha=1;linha<9;linha++){
            for(coluna=1;coluna<9;coluna++){
                for(int i=-1 ; i<=1 ; i++){
                    for(int j=-1 ; j<=1 ; j++){
                        if(tab->matriz8[linha+i][coluna+j] == '!' && tab->matriz8[linha][coluna] != '!')
                                tab->matriz8[linha][coluna]++;
                    }
                }
            }
        }
        for(i=1;i<9;i++)
                for(j=1;j<9;j++)
                    if(tab->matriz8[i][j]!='!' && tab->matriz8[i][j]=='0')
                        tab->matriz8[i][j] = '_';
    }
    else if(q==2){
        for(linha=1;linha<11;linha++){
            for(coluna=1;coluna<11;coluna++){
                for(int i=-1 ; i<=1 ; i++){
                    for(int j=-1 ; j<=1 ; j++){
                        if(tab->matriz10[linha+i][coluna+j] == '!' && tab->matriz10[linha][coluna] != '!')
                                tab->matriz10[linha][coluna]++;
                    }
                }
            }
        }
        for(i=1;i<11;i++)
                for(j=1;j<11;j++)
                    if(tab->matriz10[i][j]!='!' && tab->matriz10[i][j]=='0')
                        tab->matriz10[i][j] = '_';
    }
    else if(q==3){
        for(linha=1;linha<17;linha++){
            for(coluna=1;coluna<17;coluna++){
                for(int i=-1 ; i<=1 ; i++){
                    for(int j=-1 ; j<=1 ; j++){
                        if(tab->matriz16[linha+i][coluna+j] == '!' && tab->matriz16[linha][coluna] != '!')
                                tab->matriz16[linha][coluna]++;
                    }
                }
            }
        }
        for(i=1;i<17;i++)
                for(j=1;j<17;j++)
                    if(tab->matriz16[i][j]!='!' && tab->matriz16[i][j]=='0')
                        tab->matriz16[i][j] = '_';
    }
}