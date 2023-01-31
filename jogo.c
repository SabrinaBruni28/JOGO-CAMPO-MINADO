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
    printf("\n\n");
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

int Revela_Quadrado(Jogo* jog, Tabuleiro* tab, int q, int posicao1, int posicao2, int *aberto, int *bandeira){
    int i,j;
    if(Posicao_Valida(q, posicao1, posicao2,1) && Ja_Foi_Aberto(jog, q, posicao1, posicao2, 1)){
        if(Existe_Bomba(tab, posicao1, posicao2, q)){
            Fim_De_Jogo(jog, tab, q);
            Explodiu(jog, q, posicao1, posicao2);
            return 1;
        }
        else if(Existe_Espaco(tab, posicao1, posicao2, q))
            Abrir_Espaco(jog, tab, q, posicao1, posicao2, aberto);
        else if(Existe_Numero(tab, posicao1, posicao2, q)){
            Abrir_Posicao(jog, tab, q, posicao1, posicao2);
            *aberto += 1;
        }
        if(Ganhou_Jogo(jog, q,  posicao1, posicao2, *aberto, *bandeira)) return 1;
        return 0;
    }
}

int Existe_Alerta(Jogo * jog, int i, int j,int q){
    if(q==1){
        if(jog->matriz8[i][j] == '?') return 1;
        return 0; 
    }
    else if(q==2){
        if(jog->matriz10[i][j] == '?') return 1;
        return 0; 
    }
    else if(q==3){
       if(jog->matriz16[i][j] == '?') return 1;
        return 0;  
    }
}


void Fim_De_Jogo(Jogo* jog, Tabuleiro* tab, int q){
    int i,j, tam;

    if(q==1) tam = 9;
    else if(q==2) tam = 11;
    else if(q==3) tam = 17;

    for(i=1;i<tam;i++){
        for(j=1;j<tam;j++){
            if(Existe_Bomba(tab, i, j, q) && !Existe_Alerta(jog, i, j, q))
                Abrir_Posicao(jog, tab, q, i, j);
            else Errado(jog, tab, q, i, j);
        }
    }
    printf("\n\n******** FIM DE JOGO!!! ********\n");
    printf("******** VOCE PERDEU!! ********\n");
}

void Abrir_Espaco(Jogo* jog, Tabuleiro* tab, int q, int posicao1, int posicao2, int* aberto){
    if (Posicao_Valida(q, posicao1, posicao2,0) && Ja_Foi_Aberto(jog, q, posicao1, posicao2, 0)) {
        if(Existe_Espaco(tab, posicao1, posicao2, q) || Existe_Numero(tab, posicao1, posicao2, q)){
            Abrir_Posicao(jog, tab, q, posicao1, posicao2);
            *aberto += 1;
        }
        if(Existe_Espaco(tab, posicao1, posicao2, q)){
            Abrir_Espaco(jog, tab, q, posicao1 - 1, posicao2 - 1, aberto);
            Abrir_Espaco(jog, tab, q, posicao1 - 1, posicao2, aberto);
            Abrir_Espaco(jog, tab, q, posicao1 - 1, posicao2 + 1, aberto);
            Abrir_Espaco(jog, tab, q, posicao1, posicao2 - 1, aberto);
            Abrir_Espaco(jog, tab, q, posicao1, posicao2 + 1, aberto);
            Abrir_Espaco(jog, tab, q, posicao1 + 1, posicao2 - 1, aberto);
            Abrir_Espaco(jog, tab, q, posicao1 + 1, posicao2,aberto);
            Abrir_Espaco(jog, tab, q, posicao1 + 1, posicao2 + 1,aberto);
        }
    }
}

int Ja_Foi_Aberto(Jogo* jog, int q, int posicao1, int posicao2, int i){
    if(q==1){
       if(jog->matriz8[posicao1][posicao2] == '0') return 1;
    }
    else if(q==2){
        if(jog->matriz10[posicao1][posicao2] == '0') return 1;
    }
    else if(q==3){
        if(jog->matriz16[posicao1][posicao2] == '0') return 1;
    }
    if(i){
        printf("\nPOSICAO JA ABERTA OU COM BANDEIRA!!!!\n");
        printf("Digite uma posicao que esteja fechada\n");
    }
    return 0;
}

void Abrir_Posicao(Jogo* jog, Tabuleiro* tab, int q, int posicao1, int posicao2){
    if(q==1)
        jog->matriz8[posicao1][posicao2] = tab->matriz8[posicao1][posicao2]; 
    else if(q==2)
        jog->matriz10[posicao1][posicao2] = tab->matriz10[posicao1][posicao2]; 
    else if(q==3)
        jog->matriz16[posicao1][posicao2] = tab->matriz16[posicao1][posicao2];
}

int Ganhou_Jogo(Jogo* jog, int q, int i, int j, int aberto, int bandeira){
    if(q==1){
        if(aberto == (8*8)-(2*8) && bandeira == 2*8){
            printf("\n\n******** PARABENS!!! ********\n");
            printf("******* VOCE GANHOU!!!!!! ********\n");
            return 1;
        }
    }
    else if(q==2){
        if(aberto == (10*10)-(2*10) && bandeira == 2*10){
            printf("\n\n******** PARABENS!!! ********\n");
            printf("******* VOCE GANHOU!!!!!! ********\n");
            return 1;
        }
    }
    else if(q==3){
        if(aberto == (16*16)-(2*16) && bandeira == 2*16){
            printf("\n\n******** PARABENS!!! ********\n");
            printf("******* VOCE GANHOU!!!!!! ********\n");
            return 1;
        }
    }
    return 0;
}

void Colocar_Alerta(Jogo* jog, int q, int posicao1, int posicao2, int *bandeira){
    if(Posicao_Valida(q, posicao1, posicao2,1) && Ja_Foi_Aberto(jog, q, posicao1, posicao2,1) && !Existe_Alerta(jog, posicao1, posicao2, q)){
        if(q==1)
            jog->matriz8[posicao1][posicao2] = '?';
        else if(q==2)
            jog->matriz10[posicao1][posicao2] = '?';
        else if(q==3)
            jog->matriz16[posicao1][posicao2] = '?';
        *bandeira += 1;
    }
}
int Tira_Alerta(Jogo* jog, int q, int posicao1, int posicao2, int *bandeira){
    if(Posicao_Valida(q, posicao1, posicao2,1) && Existe_Alerta(jog, posicao1, posicao2, q)){
        if(q==1)
            jog->matriz8[posicao1][posicao2] = '0';
        else if(q==2)
            jog->matriz10[posicao1][posicao2] = '0';
        else if(q==3)
            jog->matriz16[posicao1][posicao2] = '0';
        *bandeira -= 1;
        return 1;
    }
    printf("\nPOSICAO NAO CONTEM UM ALERTA!!!\n");
    return 0;
}

void Errado(Jogo* jog,Tabuleiro* tab, int q, int posicao1, int posicao2){
    if(Existe_Alerta(jog, posicao1, posicao2, q) && !Existe_Bomba(tab, posicao1, posicao2, q)){
        if(q==1)
            jog->matriz8[posicao1][posicao2] = '^'; 
        else if(q==2)
            jog->matriz10[posicao1][posicao2] = '^'; 
        else if(q==3)
            jog->matriz16[posicao1][posicao2] = '^';
    }
}

void Explodiu(Jogo* jog, int q, int posicao1, int posicao2){
    if(q==1)
        jog->matriz8[posicao1][posicao2] = 'X'; 
    else if(q==2)
       jog->matriz10[posicao1][posicao2] = 'X'; 
    else if(q==3)
        jog->matriz16[posicao1][posicao2] = 'X';
}