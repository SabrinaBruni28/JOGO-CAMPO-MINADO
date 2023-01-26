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
            return 1;
        }
        else if(Existe_Espaco(tab,posicao1,posicao2,q))
            Abrir_Espaco(jog, tab, q, posicao1, posicao2);
        else if(Existe_Numero(tab,posicao1,posicao2,q))
            jog->matriz8[posicao1][posicao2] = tab->matriz8[posicao1][posicao2]; 
        return 0;
    }
    else if(q==2){
         if(Existe_Bomba(tab, posicao1, posicao2, q)){
            Fim_De_Jogo(jog, tab, q);
            return 1;
        }
        else if(Existe_Espaco(tab,posicao1,posicao2,q))
            Abrir_Espaco(jog, tab, q, posicao1, posicao2);
        else if(Existe_Numero(tab,posicao1,posicao2,q))
            jog->matriz10[posicao1][posicao2] = tab->matriz10[posicao1][posicao2]; 
        return 0;
    }
    else if(q==3){
        if(Existe_Bomba(tab, posicao1, posicao2, q)){
            Fim_De_Jogo(jog, tab, q);
            return 1;
        }
        else if(Existe_Espaco(tab,posicao1,posicao2,q))
            Abrir_Espaco(jog, tab, q, posicao1, posicao2);
        else if(Existe_Numero(tab,posicao1,posicao2,q))
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

int Existe_Espaco(Tabuleiro* tab, int i, int j,int q){
    if(q==1){
        if(tab->matriz8[i][j] == '_') return 1;
        return 0; 
    }
    else if(q==2){
        if(tab->matriz10[i][j] == '_') return 1;
        return 0; 
    }
    else if(q==3){
       if(tab->matriz16[i][j] == '_') return 1;
        return 0;  
    }
}

int Existe_Numero(Tabuleiro* tab, int i, int j,int q){
    if(q==1){
        if(tab->matriz8[i][j] != '_' && tab->matriz8[i][j] != '!' && tab->matriz8[i][j] != '0') return 1;
        return 0; 
    }
    else if(q==2){
        if(tab->matriz10[i][j] != '_' && tab->matriz10[i][j] != '!' && tab->matriz10[i][j] != '0') return 1;
        return 0; 
    }
    else if(q==3){
       if(tab->matriz16[i][j] != '_' && tab->matriz16[i][j] != '!' && tab->matriz16[i][j] != '0') return 1;
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
    printf("\n\nFIM DE JOGO!!!\n");
    printf("VOCE PERDEU!!\n");
}

int Abrir_Espaco(Jogo* jog, Tabuleiro* tab, int q, int posicao1, int posicao2){
    int i,j;
    if(q==1){
        if(posicao1<9 && posicao2<9){
            jog->matriz8[posicao1][posicao2] = tab->matriz8[posicao1][posicao2];
            for(int i=-1 ; i<=1 ; i++){
                for(int j=-1 ; j<=1 ; j++){
                    if((posicao1+i)<9 && (posicao2+j)<9 && (posicao1+i)>0 && (posicao2+j)>0){
                        if(Existe_Bomba(tab,posicao1+i,posicao2+j,q)){
                            printf("1\n");
                            break;
                        }
                        else if(Existe_Numero(tab,posicao1+i,posicao2+j,q)){
                            printf("2\n");
                            jog->matriz8[posicao1+i][posicao2+j] = tab->matriz8[posicao1+i][posicao2+j];
                        }
                        else if(Existe_Espaco(tab, posicao1+i, posicao2+j, q)){
                            printf("3\n");
                            Abrir_Espaco(jog,tab,q,posicao1+i,posicao2+j);
                        }
                    }
                }
            }
        }
    }
   /* else if(q==2){
        jog->matriz10[i][j] = tab->matriz10[i][j];
        for(int i=-1 ; i<=1 ; i++){
            for(int j=-1 ; j<=1 ; j++){
                if(Existe_Espaco(tab, posicao1+i, posicao2+j, q))
                    Abrir_Espaco(jog,tab,q,posicao1+i,posicao2+j);
                else if(Existe_Numero(tab, posicao1+i, posicao2+j, q))
                        jog->matriz10[posicao1+i][posicao2+j] = tab->matriz10[posicao1+i][posicao2+j];
            }
        }
    }
    else if(q==3){
        jog->matriz16[i][j] = tab->matriz16[i][j];
        for(int i=-1 ; i<=1 ; i++){
            for(int j=-1 ; j<=1 ; j++){
                if(Existe_Espaco(tab, posicao1+i, posicao2+j, q))
                    Abrir_Espaco(jog,tab,q,posicao1+i,posicao2+j);
                else if(Existe_Numero(tab, posicao1+i, posicao2+j, q))
                        jog->matriz16[posicao1+i][posicao2+j] = tab->matriz16[posicao1+i][posicao2+j];
            }
        }
    }*/
}
