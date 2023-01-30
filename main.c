#include "jogo.h"

void Inicial(){
    printf("***********************************************************************************************\n");
    printf("\t#### CAMPO MINADO ####\n\n");
}

int Opcoes_Iniciais(){
    int a;
    printf("\n1- Jogar\n2- Sair\n");
    scanf("%d",&a);
    if(a == 1) return 1;
    else return 0;
}

int Opcoes_Jogo(){
    int a;
    printf("\nEscolha o tamanho do tabuleiro:\n");
    printf("1) 8\t2) 10\t3) 16\n");
    scanf("%d", &a);
    return a;
}

int Opcoes_Bandeira(){
     int a;
    printf("\n1- Abrir um quadrado\n2- Colocar alerta\n");
    scanf("%d",&a);
    if(a == 1) return 2;
    else return 3;
}
int Opcoes_Finais(){
    int a;
    printf("\n1- Jogar Novamente\n2- Sair\n");
    scanf("%d", &a);
    if(a == 1) return 1;
    else return 0;
}
void Final(){
    printf("***********************************************************************************************\n");
}

int main(){
    Tabuleiro tab;
    Jogo jog;
    int i,j,q;
    int choice;
    int a = 0,b = 0;
    choice = Opcoes_Iniciais();
    while(choice){
        switch (choice){
            case 1:
                q = Opcoes_Jogo();
                Inicial();
                Inicia_Tabuleiro(&tab, q);
                Inicia_Jogo(&jog, q);
                Print_Tabuleiro(&tab, q);
                Print_Jogo(&jog, q);
                choice = Opcoes_Bandeira();
                break;
            case 2:
                printf("\nPosicoes: ");
                scanf("%d %d",&i,&j);
                if(Revela_Quadrado(&jog, &tab, q, i, j, &a, &b)) choice = 4;
                Print_Jogo(&jog, q);
                if(choice!=4) choice = Opcoes_Bandeira();
                break;
            case 3:
                printf("\nPosicoes: ");
                scanf("%d %d",&i,&j);
                Colocar_Bandeira(&jog, q, i, j);
                Print_Jogo(&jog, q);
                if(Ganhou_Jogo(&jog, q, i, j, &a, &b)) choice = 4;
                else choice = Opcoes_Bandeira();
                break;
            case 4:
                choice = Opcoes_Finais();
                break;
        }
        
    }
    Final();
    return 0;
}
