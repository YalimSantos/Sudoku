#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define MAX 9

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int M[MAX][MAX] = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}}; //Matriz zerada
    int i, j, x, erros = 0, z = 0, ir, jr, irf[81], jrf[81], valor, qnt = 0, errofixo = 0, resposta, n, dificuldade;
    char escolha;

    printf("Vamos jogar sudoku? Vamos!\nMas primeiro, vamos conhecer as regras do sudoku e desse jogo:\n1 - Nenhum n�mero pode se repetir com outro da mesma linha.\n2 - Nenhum n�mero pode se repetir com outro da mesma coluna.\n3 - Nenhum n�mero pode se repetir em um quadrante (a matriz 3x3).\n4 - O sinal + significa que o espa�o est� sem valor no momento.\n5 - Para apagar um n�mero, digite 0 no valor.\nAgora que sabemos as regras, vamos jogar!\n\n");

    do{
        printf("Para come�armos o jogo, voc� ter� que decidir se quer pegar um sudoku com valores j� fixados (e escolher a dificuldade do sudoku) ou quer fixar voc� mesmo os valores:\n1 - Jogar com sudoku com valores j� fixados.\n2 - Fixar os valores voc� mesmo\nDigite o n�mero da op��o desejada: ");
        scanf("%d", &resposta);
        printf("\n\n");

        if(resposta==1){
            do{
                printf("Voc� decidiu jogar com um sudoku com n�meros j� fixados!\nAgora veja as op��es abaixo:\n1 - F�cil\n2 - M�dio\n3 - Dif�cil\nDigite o n�mero da dificuldade que voc� deseja: ");
                scanf("%d", &dificuldade);

                if(dificuldade==1){
                    srand(time(NULL));
                    n = rand()%5;
                    if(n==0){
                    //Cria uma vari�nel nova e bota os valores no M pois n�o pode colocar valor de matriz no meio do c�digo
                        int MF0[MAX][MAX] = {{6, 0, 0, 0, 0, 0, 2, 9, 5}, {7, 0, 0, 4, 9, 0, 6, 0, 0}, {2, 8, 0, 0, 5, 0, 0, 0, 0}, {0, 0, 0, 9, 2, 7, 0, 3, 0}, {0, 9, 2, 8, 0, 5, 7, 1, 0}, {0, 4, 0, 1, 6, 3, 0, 0, 0}, {0, 0, 0, 0, 3, 0, 0, 5, 9}, {0, 0, 3, 0, 7, 8, 0, 0, 2}, {4, 2, 8, 0, 0, 0, 0, 0, 7}};
                        for(i=0; i<MAX; i++){
                            for(j=0; j<MAX; j++){
                                M[i][j] = MF0[i][j];
                            }
                        }
                    }
                    else if(n==1){
                        int MF1[MAX][MAX] = {{7, 0, 0, 1, 8, 0, 6, 0, 0}, {1, 0, 0, 6, 0, 0, 8, 2, 5}, {4, 8, 6, 5, 9, 0, 3, 0, 0}, {0, 2, 0, 4, 6, 8, 0, 1, 0}, {6, 3, 9, 0, 0, 0, 4, 5, 8}, {0, 1, 0, 3, 5, 9, 0, 6, 0}, {0, 0, 8, 0, 2, 5, 1, 3, 6}, {3, 6, 5, 0, 0, 4, 0, 0, 7}, {0, 0, 1, 0, 3, 6, 0, 0, 9}};
                        for(i=0; i<MAX; i++){
                            for(j=0; j<MAX; j++){
                                M[i][j] = MF1[i][j];
                            }
                        }
                    }
                    else if(n==2){
                        int MF2[MAX][MAX] = {{0, 0, 0, 0, 6, 0, 8, 0, 0}, {7, 1, 3, 0, 0, 0, 2, 0, 0}, {5, 0, 0, 2, 0, 0, 1, 3, 9}, {8, 3, 5, 0, 4, 6, 0, 0, 2}, {0, 7, 0, 0, 1, 0, 0, 4, 0}, {4, 0, 0, 9, 3, 0, 6, 7, 5}, {6, 8, 2, 0, 0, 3, 0, 0, 1}, {0, 0, 4, 0, 0, 0, 5, 2, 3}, {0, 0, 7, 0, 2, 0, 0, 0, 0}};
                        for(i=0; i<MAX; i++){
                            for(j=0; j<MAX; j++){
                                M[i][j] = MF2[i][j];
                            }
                        }
                    }
                    else if(n==3){
                        int MF3[MAX][MAX] = {{0, 0, 6, 8, 7, 0, 0, 9, 3}, {8, 0, 1, 9, 0, 0, 0, 5, 2}, {0, 0, 2, 1, 4, 5, 0, 6, 0}, {9, 5, 3, 0, 8, 0, 0, 0, 0}, {4, 2, 0, 6, 0, 3, 0, 8, 9}, {0, 0, 0, 0, 5, 0, 3, 4, 7}, {0, 8, 0, 5, 2, 7, 9, 0, 0}, {2, 3, 0, 0, 0, 1, 8, 0, 5}, {7, 6, 0, 0, 9, 8, 2, 0, 0}};
                        for(i=0; i<MAX; i++){
                            for(j=0; j<MAX; j++){
                                M[i][j] = MF3[i][j];
                            }
                        }
                    }
                    else{
                        int MF4[MAX][MAX] = {{0, 9, 7, 0, 2, 3, 4, 0, 0}, {4, 0, 0, 6, 0, 8, 0, 0, 7}, {0, 0, 0, 0, 0, 5, 2, 9, 0}, {3, 2, 0, 0, 7, 4, 0, 5, 8}, {0, 0, 0, 0, 0, 0, 9, 6, 0}, {1, 5, 0, 8, 6, 2, 0, 0, 0}, {2, 4, 0, 0, 3, 0, 0, 0, 0}, {0, 0, 0, 4, 0, 0, 0, 0, 5}, {6, 3, 0, 0, 1, 0, 0, 7, 0}};
                        for(i=0; i<MAX; i++){
                            for(j=0; j<MAX; j++){
                                M[i][j] = MF4[i][j];
                            }
                        }
                    }
                }
                else if(dificuldade==2){
                    srand(time(NULL));
                    n = rand()%4;
                    if(n==0){
                        int MM0[MAX][MAX] = {{4, 0, 6, 0, 2, 0, 9, 0, 0}, {0, 0, 0, 0, 5, 0, 4, 0, 7}, {0, 7, 2, 4, 0, 8, 0, 0, 0}, {0, 8, 0, 0, 0, 4, 6, 0, 5}, {0, 6, 7, 0, 0, 0, 0, 0, 2}, {0, 0, 0, 3, 0, 5, 0, 0, 0}, {1, 0, 3, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 7, 0, 3, 0, 9, 4}, {0, 4, 0, 6, 0, 9, 0, 3, 0}};
                        for(i=0; i<MAX; i++){
                            for(j=0; j<MAX; j++){
                                M[i][j] = MM0[i][j];
                            }
                        }
                    }
                    else if(n==1){
                        int MM1[MAX][MAX] = {{3, 8, 0, 5, 0, 0, 0, 0, 9}, {9, 0, 0, 1, 0, 0, 0, 0, 6}, {0, 0, 0, 0, 6, 2, 0, 0, 4}, {0, 0, 0, 0, 0, 0, 0, 7, 0}, {0, 2, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 3, 1, 6, 0, 0, 0}, {0, 0, 3, 0, 0, 0, 4, 0, 0}, {0, 0, 5, 8, 9, 3, 0, 0, 1}, {2, 0, 1, 0, 7, 0, 8, 0, 0}};
                        for(i=0; i<MAX; i++){
                            for(j=0; j<MAX; j++){
                                M[i][j] = MM1[i][j];
                            }
                        }
                    }
                    else if(n==2){
                        int MM2[MAX][MAX] = {{0, 0, 0, 0, 9, 8, 0, 4, 0}, {7, 0, 1, 2, 3, 0, 0, 9, 0}, {0, 0, 0, 0, 0, 4, 0, 3, 0}, {0, 0, 0, 1, 8, 0, 0, 0, 0}, {0, 0, 6, 0, 2, 0, 9, 0, 5}, {3, 0, 9, 0, 0, 0, 0, 0, 2}, {0, 2, 0, 0, 0, 0, 8, 1, 4}, {0, 6, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 4, 5, 7, 1, 0, 0, 0}};
                        for(i=0; i<MAX; i++){
                            for(j=0; j<MAX; j++){
                                M[i][j] = MM2[i][j];
                            }
                        }
                    }
                    else if(n==3){
                        int MM3[MAX][MAX] = {{0, 0, 0, 0, 0, 0, 9, 4, 3}, {1, 0, 5, 0, 0, 9, 0, 8, 0}, {0, 0, 4, 0, 7, 2, 0, 0, 0}, {4, 8, 1, 0, 9, 0, 2, 0, 0}, {0, 0, 9, 0, 0, 5, 8, 1, 0}, {0, 0, 7, 0, 0, 1, 0, 9, 0}, {0, 0, 0, 9, 2, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 5, 2, 7}, {0, 4, 0, 3, 0, 0, 0, 0, 9}};
                        for(i=0; i<MAX; i++){
                            for(j=0; j<MAX; j++){
                                M[i][j] = MM3[i][j];
                            }
                        }
                    }
                    else{
                        int MM4[MAX][MAX] = {{2, 0, 0, 1, 0, 0, 0, 0, 8}, {9, 7, 1, 0, 0, 2, 0, 0, 0}, {0, 0, 0, 4, 9, 0, 0, 0, 2}, {0, 3, 0, 0, 0, 0, 0, 5, 4}, {0, 4, 0, 0, 8, 0, 0, 2, 0}, {0, 6, 0, 0, 0, 9, 0, 3, 0}, {0, 0, 0, 0, 0, 8, 2, 0, 3}, {8, 0, 5, 0, 1, 0, 6, 0, 0}, {0, 0, 0, 0, 2, 7, 0, 0, 0}};
                        for(i=0; i<MAX; i++){
                            for(j=0; j<MAX; j++){
                                M[i][j] = MM4[i][j];
                            }
                        }
                    }
                }
                else if(dificuldade==3){
                    srand(time(NULL));
                    n = rand()%4;
                    if(n==0){
                        int MD0[MAX][MAX] = {{0, 0, 7, 2, 9, 0, 0, 0, 0}, {0, 0, 0, 0, 6, 0, 5, 0, 8}, {0, 0, 6, 0, 0, 0, 1, 0, 0}, {5, 0, 0, 7, 0, 3, 0, 0, 0}, {9, 0, 1, 5, 0, 0, 3, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 4, 0}, {0, 0, 0, 0, 0, 0, 8, 9, 3}, {0, 1, 0, 8, 4, 6, 0, 0, 0}, {7, 8, 0, 0, 0, 5, 0, 0, 4}};
                        for(i=0; i<MAX; i++){
                            for(j=0; j<MAX; j++){
                                M[i][j] = MD0[i][j];
                            }
                        }
                    }
                    else if(n==1){
                        int MD1[MAX][MAX] = {{0, 1, 0, 5, 0, 0, 3, 0, 0}, {0, 0, 2, 8, 0, 0, 0, 0, 0}, {0, 0, 3, 0, 0, 0, 1, 9, 0}, {0, 2, 0, 0, 0, 9, 0, 1, 0}, {6, 4, 0, 0, 0, 0, 0, 5, 0}, {5, 0, 0, 0, 0, 1, 0, 2, 0}, {0, 0, 0, 0, 7, 0, 0, 0, 6}, {0, 0, 0, 0, 6, 2, 0, 0, 7}, {0, 9, 0, 0, 0, 0, 0, 0, 0}};
                        for(i=0; i<MAX; i++){
                            for(j=0; j<MAX; j++){
                                M[i][j] = MD1[i][j];
                            }
                        }
                    }
                    else if(n==2){
                        int MD2[MAX][MAX] = {{0, 0, 0, 0, 0, 0, 0, 5, 3}, {0, 0, 2, 7, 0, 9, 0, 4, 0}, {0, 0, 7, 8, 0, 0, 0, 0, 0}, {0, 3, 0, 0, 0, 0, 0, 0, 6}, {0, 0, 0, 9, 0, 1, 0, 0, 0}, {0, 8, 9, 0, 0, 2, 0, 0, 7}, {4, 0, 0, 0, 0, 0, 2, 0, 0}, {1, 0, 0, 0, 6, 0, 9, 0, 0}, {8, 0, 0, 0, 4, 0, 0, 0, 0}};
                        for(i=0; i<MAX; i++){
                            for(j=0; j<MAX; j++){
                                M[i][j] = MD2[i][j];
                            }
                        }
                    }
                    else if(n==3){
                        int MD3[MAX][MAX] = {{0, 0, 0, 0, 2, 4, 3, 0, 7}, {9, 0, 0, 0, 6, 0, 0, 0, 0}, {7, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 5, 0, 0, 7, 9, 4}, {0, 6, 5, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 8, 0, 3, 0, 0, 0}, {0, 5, 4, 0, 0, 0, 0, 6, 0}, {0, 0, 0, 0, 0, 0, 0, 5, 9}, {0, 0, 3, 4, 0, 8, 0, 0, 0}};
                        for(i=0; i<MAX; i++){
                            for(j=0; j<MAX; j++){
                                M[i][j] = MD3[i][j];
                            }
                        }
                    }
                    else{
                        int MD4[MAX][MAX] = {{0, 0, 0, 0, 9, 0, 2, 0, 0}, {0, 0, 0, 6, 4, 0, 8, 0, 0}, {0, 3, 8, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 7, 0, 4, 0}, {0, 4, 7, 0, 0, 9, 0, 0, 0}, {0, 0, 0, 0, 0, 5, 0, 7, 0}, {2, 0, 0, 0, 0, 0, 6, 0, 8}, {6, 0, 0, 8, 0, 0, 0, 0, 5}, {5, 0, 0, 3, 0, 0, 0, 0, 1}};
                        for(i=0; i<MAX; i++){
                            for(j=0; j<MAX; j++){
                                M[i][j] = MD4[i][j];
                            }
                        }
                    }
                }
                else{
                    printf("\n\nValor de dificuldade incorreto!!\n\n\n");
                }
            }while(dificuldade!=1 && dificuldade!=2 && dificuldade!=3);
        }
        else if(resposta==2){
            do{
                printf("Esse � o sudoku escrito:\n");

                for(i=0; i<MAX; i++){ //C�digo que mostra o sudoku/a matriz
                    for(j=0; j<MAX; j++){
                        if(j==2 || j==5 || j==8){
                            if(M[i][j]==0){
                                printf(" + ||");
                            }
                            else{
                                printf(" %d ||", M[i][j]);
                            }
                        }
                        else{
                            if(M[i][j]==0){
                                printf(" + |");
                            }
                            else{
                                printf(" %d |", M[i][j]);
                            }
                        }
                    }
                    printf("\n");
                    if(i==2 || i==5 || i==8){
                        printf("---------------------------------------");
                        printf("\n");
                    }
                }
                printf("\n\nObs: N�meros fixados n�o podem ser mudados quando for completar o sudoku.\n\n");
                printf("Gostaria de fixar algum n�mero no sudoku? (S/N) ");
                scanf("%s", &escolha);

                if(escolha=='S' || escolha=='s'){
                    printf("\nDigite a linha que voc� gostaria de mudar o valor: ");
                    scanf("%d", &ir);

                    if(ir>=1 && ir<=9){
                        printf("Digite a coluna que voc� gostaria de mudar o valor: ");
                        scanf("%d", &jr);

                        if(jr>=1 && jr<=9){
                            printf("Escreva o n�mero que voc� deseja fixar na linha %d e coluna %d: ", ir, jr);
                            scanf("%d", &valor);

                            if(valor>=0 && valor<=9){
                                if(valor==0){ //Se o valor for 0, ele apagar� o n�mero que estava antes
                                    M[ir-1][jr-1] = 0;
                                    printf("\nN�mero que estava fixado foi apagado.\n\n");
                                }
                                else{
                                    erros = 0;
                                    for(x=0; x<MAX; x++){
                                        if(valor==M[ir-1][x] && valor!=M[ir-1][jr-1]){ //Verifica��o dos n�meros da coluna
                                            printf("\nEsse n�mero repete com o n�mero da linha %d coluna %d\n\n", ir, x+1);
                                            erros += 1;
                                        }
                                        if(valor==M[x][jr-1] && valor!=M[ir-1][jr-1]){ //Verifica��o dos n�meros da linha
                                                printf("\nEsse n�mero repete com o n�mero da linha %d coluna %d\n\n", x+1, jr);
                                                erros += 1;
                                        }
                                    }
                                    if((ir-1>=0 && ir-1<=2) && (jr-1>=0 && jr-1<=2)){ //Verifica��o do quadrante nas linhas 69-122
                                        if((valor==M[0][0] || valor==M[0][1] || valor==M[0][2] || valor==M[1][0] || valor==M[1][1] || valor==M[1][2] || valor==M[2][0] || valor==M[2][1] || valor==M[2][2]) && valor!=M[ir-1][jr-1]){
                                            printf("\nO n�mero j� existe no 1� quadrante.\n\n");
                                            erros += 1;
                                        }
                                    }
                                    else if((ir-1>=0 && ir-1<=2) && (jr-1>=3 && jr-1<=5)){
                                        if((valor==M[0][3] || valor==M[0][4] || valor==M[0][5] || valor==M[1][3] || valor==M[1][4] || valor==M[1][5] || valor==M[2][3] || valor==M[2][4] || valor==M[2][5]) && valor!=M[ir-1][jr-1]){
                                            printf("\nO n�mero j� existe no 2� quadrante.\n\n");
                                            erros += 1;
                                        }
                                    }
                                    else if((ir-1>=0 && ir-1<=2) && (jr-1>=6 && jr-1<=8)){
                                        if((valor==M[0][6] || valor==M[0][7] || valor==M[0][8] || valor==M[1][6] || valor==M[1][7] || valor==M[1][8] || valor==M[2][6] || valor==M[2][7] || valor==M[2][8]) && valor!=M[ir-1][jr-1]){
                                            printf("\nO n�mero j� existe no 3� quadrante.\n\n");
                                            erros += 1;
                                        }
                                    }
                                    else if((ir-1>=3 && ir-1<=5) && (jr-1>=0 && jr-1<=2)){
                                        if((valor==M[3][0] || valor==M[3][1] || valor==M[3][2] || valor==M[4][0] || valor==M[4][1] || valor==M[4][2] || valor==M[5][0] || valor==M[5][1] || valor==M[5][2]) && valor!=M[ir-1][jr-1]){
                                            printf("\nO n�mero j� existe no 4� quadrante.\n\n");
                                            erros += 1;
                                        }
                                    }
                                    else if((ir-1>=3 && ir-1<=5) && (jr-1>=3 && jr-1<=5)){
                                        if((valor==M[3][3] || valor==M[3][4] || valor==M[3][5] || valor==M[4][3] || valor==M[4][4] || valor==M[4][5] || valor==M[5][3] || valor==M[5][4] || valor==M[5][5]) && valor!=M[ir-1][jr-1]){
                                            printf("\nO n�mero j� existe no 5� quadrante.\n\n");
                                            erros += 1;
                                        }
                                    }
                                    else if((ir-1>=3 && ir-1<=5) && (jr-1>=6 && jr-1<=8)){
                                        if((valor==M[3][6] || valor==M[3][7] || valor==M[3][8] || valor==M[4][6] || valor==M[4][7] || valor==M[4][8] || valor==M[5][6] || valor==M[5][7] || valor==M[5][8]) && valor!=M[ir-1][jr-1]){
                                            printf("\nO n�mero j� existe no 6� quadrante.\n\n");
                                            erros += 1;
                                        }
                                    }
                                    else if((ir-1>=6 && ir-1<=8) && (jr-1>=0 && jr-1<=2)){
                                        if((valor==M[6][0] || valor==M[6][1] || valor==M[6][2] || valor==M[7][0] || valor==M[7][1] || valor==M[7][2] || valor==M[8][0] || valor==M[8][1] || valor==M[8][2]) && valor!=M[ir-1][jr-1]){
                                            printf("\nO n�mero j� existe no 7� quadrante.\n\n");
                                            erros += 1;
                                        }
                                    }
                                    else if((ir-1>=6 && ir-1<=8) && (jr-1>=3 && jr-1<=5)){
                                        if((valor==M[6][3] || valor==M[6][4] || valor==M[6][5] || valor==M[7][3] || valor==M[7][4] || valor==M[7][5] || valor==M[8][3] || valor==M[8][4] || valor==M[8][5]) && valor!=M[ir-1][jr-1]){
                                            printf("\nO n�mero j� existe no 8� quadrante.\n\n");
                                            erros += 1;
                                        }
                                    }
                                    else{
                                        if((valor==M[6][6] || valor==M[6][7] || valor==M[6][8] || valor==M[7][6] || valor==M[7][7] || valor==M[7][8] || valor==M[8][6] || valor==M[8][7] || valor==M[8][8]) && valor!=M[ir-1][jr-1]){
                                            printf("\nO n�mero j� existe no 9� quadrante.\n\n");
                                            erros += 1;
                                        }
                                    }
                                    if(erros==0){ //Se n�o achou nenhum erro, o n�mero ir� ser alterado
                                        M[ir-1][jr-1] = valor;
                                        printf("\nN�mero fixado.\n\n");
                                    }
                                    else{
                                        printf("\nO n�mero n�o pode ser fixado pela descri��o escrita anteriormente.\n\n");
                                    }
                                }
                            }
                            else{
                                printf("\nValor para a linha %d e coluna %d inv�lido!\n\n", ir, jr);
                            }
                        }
                        else{
                            printf("\nValor de coluna inv�lido!\n\n");
                        }
                    }
                    else{
                        printf("\nN�mero de linha inv�lido!\n\n");
                    }
                }
                else if(escolha=='N' || escolha=='n'){
                    qnt = 0;
                }
                else{
                    printf("Erro ao selecionar o valor!\n\n");
                }
            }while(escolha!='N' && escolha!='n');
        }
        else{
            printf("Valor Incorreto!!\n\n\n");
        }
    }while(resposta!=1 && resposta!=2);

    //Esse c�digo ir� verificar as linhas e colunas que est�o com n�meros fixados e salvar� os valores das linhas/colunas
    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++){
            if(M[i][j]!=0){
                irf[z] = i;
                jrf[z] = j;
                z++;
            }
        }
    }

    for(i=0; i<MAX; i++){ //Verifica a quantidade de valores diferentes de 0 na matriz e os coloca na vari�vel "qnt"
        for(j=0; j<MAX; j++){
            if(M[i][j]!=0){
                qnt += 1;
            }
        }
    }
    printf("\n\nAgora come�aremos o jogo, boa sorte!!\n\n");

    while(qnt!=81){ //O jogo continuar� at� o sudoku estiver totalmente preenchido com seus 81 valores
        printf("Esse � o sudoku escrito:\n");

        for(i=0; i<MAX; i++){
            for(j=0; j<MAX; j++){
                if(j==2 || j==5 || j==8){
                    if(M[i][j]==0){
                        printf(" + ||");
                    }
                    else{
                        printf(" %d ||", M[i][j]);
                    }
                }
                else{
                    if(M[i][j]==0){
                        printf(" + |");
                    }
                    else{
                        printf(" %d |", M[i][j]);
                    }
                }
            }
            printf("\n");
            if(i==2 || i==5 || i==8){
                printf("---------------------------------------");
                printf("\n");
            }
        }
        printf("\n\n");
        printf("Digite a linha que voc� deseja realizar a troca de valor: ");
        scanf("%d", &ir);

        if(ir>=1 && ir<=9){
            printf("Digite a coluna que voc� deseja realizar a troca de valor: ");
            scanf("%d", &jr);

            if(jr>=1 && jr<=9){
                printf("Escreva o n�mero que voc� deseja colocar na linha %d e coluna %d: ", ir, jr);
                scanf("%d", &valor);

                if(valor>=0 && valor<=9){
                    errofixo = 0;
                    for(x=0; x<z; x++){ //Verifica os valores fixados anteriormente pelo usu�rio
                        if((ir==irf[x]+1) && (jr==jrf[x]+1)){
                            errofixo = 1;
                        }
                    }
                    if(errofixo==1){
                        printf("\nEsse valor est� fixo e n�o pode ser alterado.\n\n");
                    }
                    else if(valor==0){
                        M[ir-1][jr-1] = 0;
                        printf("\nN�mero alterado.\n\n");
                    }
                    else{
                        erros = 0;
                        for(x=0; x<MAX; x++){
                            if(valor==M[ir-1][x] && valor!=M[ir-1][jr-1]){
                                printf("\nEsse n�mero repete com o n�mero da linha %d coluna %d\n\n", ir, x+1);
                                erros += 1;
                            }
                            if(valor==M[x][jr-1] && valor!=M[ir-1][jr-1]){
                                printf("\nEsse n�mero repete com o n�mero da linha %d coluna %d\n\n", x+1, jr);
                                erros += 1;
                            }
                        }
                        if((ir-1>=0 && ir-1<=2) && (jr-1>=0 && jr-1<=2)){
                            if((valor==M[0][0] || valor==M[0][1] || valor==M[0][2] || valor==M[1][0] || valor==M[1][1] || valor==M[1][2] || valor==M[2][0] || valor==M[2][1] || valor==M[2][2]) && valor!=M[ir-1][jr-1]){
                                printf("\nO n�mero j� existe no 1� quadrante.\n\n");
                                erros += 1;
                            }
                        }
                        else if((ir-1>=0 && ir-1<=2) && (jr-1>=3 && jr-1<=5)){
                            if((valor==M[0][3] || valor==M[0][4] || valor==M[0][5] || valor==M[1][3] || valor==M[1][4] || valor==M[1][5] || valor==M[2][3] || valor==M[2][4] || valor==M[2][5]) && valor!=M[ir-1][jr-1]){
                                printf("\nO n�mero j� existe no 2� quadrante.\n\n");
                                erros += 1;
                            }
                        }
                        else if((ir-1>=0 && ir-1<=2) && (jr-1>=6 && jr-1<=8)){
                            if((valor==M[0][6] || valor==M[0][7] || valor==M[0][8] || valor==M[1][6] || valor==M[1][7] || valor==M[1][8] || valor==M[2][6] || valor==M[2][7] || valor==M[2][8]) && valor!=M[ir-1][jr-1]){
                                printf("\nO n�mero j� existe no 3� quadrante.\n\n");
                                erros += 1;
                            }
                        }
                        else if((ir-1>=3 && ir-1<=5) && (jr-1>=0 && jr-1<=2)){
                            if((valor==M[3][0] || valor==M[3][1] || valor==M[3][2] || valor==M[4][0] || valor==M[4][1] || valor==M[4][2] || valor==M[5][0] || valor==M[5][1] || valor==M[5][2]) && valor!=M[ir-1][jr-1]){
                                printf("\nO n�mero j� existe no 4� quadrante.\n\n");
                                erros += 1;
                            }
                        }
                        else if((ir-1>=3 && ir-1<=5) && (jr-1>=3 && jr-1<=5)){
                            if((valor==M[3][3] || valor==M[3][4] || valor==M[3][5] || valor==M[4][3] || valor==M[4][4] || valor==M[4][5] || valor==M[5][3] || valor==M[5][4] || valor==M[5][5]) && valor!=M[ir-1][jr-1]){
                                printf("\nO n�mero j� existe no 5� quadrante.\n\n");
                                erros += 1;
                            }
                        }
                        else if((ir-1>=3 && ir-1<=5) && (jr-1>=6 && jr-1<=8)){
                            if((valor==M[3][6] || valor==M[3][7] || valor==M[3][8] || valor==M[4][6] || valor==M[4][7] || valor==M[4][8] || valor==M[5][6] || valor==M[5][7] || valor==M[5][8]) && valor!=M[ir-1][jr-1]){
                                printf("\nO n�mero j� existe no 6� quadrante.\n\n");
                                erros += 1;
                            }
                        }
                        else if((ir-1>=6 && ir-1<=8) && (jr-1>=0 && jr-1<=2)){
                            if((valor==M[6][0] || valor==M[6][1] || valor==M[6][2] || valor==M[7][0] || valor==M[7][1] || valor==M[7][2] || valor==M[8][0] || valor==M[8][1] || valor==M[8][2]) && valor!=M[ir-1][jr-1]){
                                printf("\nO n�mero j� existe no 7� quadrante.\n\n");
                                erros += 1;
                            }
                        }
                        else if((ir-1>=6 && ir-1<=8) && (jr-1>=3 && jr-1<=5)){
                            if((valor==M[6][3] || valor==M[6][4] || valor==M[6][5] || valor==M[7][3] || valor==M[7][4] || valor==M[7][5] || valor==M[8][3] || valor==M[8][4] || valor==M[8][5]) && valor!=M[ir-1][jr-1]){
                                printf("\nO n�mero j� existe no 8� quadrante.\n\n");
                                erros += 1;
                            }
                        }
                        else{
                            if((valor==M[6][6] || valor==M[6][7] || valor==M[6][8] || valor==M[7][6] || valor==M[7][7] || valor==M[7][8] || valor==M[8][6] || valor==M[8][7] || valor==M[8][8]) && valor!=M[ir-1][jr-1]){
                                printf("\nO n�mero j� existe no 9� quadrante.\n\n");
                                erros += 1;
                            }
                        }

                        if(erros==0){
                            M[ir-1][jr-1] = valor;
                            printf("\nN�mero alterado.\n\n");
                        }
                        else{
                            printf("\nO n�mero n�o pode ser alterado pela descri��o escrita anteriormente.\n\n");
                        }
                    }
                }
                else{
                    printf("\nValor para a linha %d e coluna %d inv�lido!\n\n", ir, jr);
                }
            }
            else{
                printf("\nValor de coluna inv�lido!\n\n");
            }
        }
        else{
            printf("\nN�mero de linha inv�lido!\n\n");
        }
        qnt = 0; //Zera a vari�vel para n�o somar os que j� estavam
        for(i=0; i<MAX; i++){  //Faz novamente a an�lise do "qnt" para verificar se o sudoku est� completo ou n�o
            for(j=0; j<MAX; j++){
                if(M[i][j]!=0){
                    qnt += 1;
                }
            }
        }
    }

    printf("Esse � o sudoku finalizado:\n");

    for(i=0; i<MAX; i++){ //Escrevendo o sudoku depois de finalizado
        for(j=0; j<MAX; j++){
            if(j==2 || j==5 || j==8){
                printf(" %d ||", M[i][j]);
            }
            else{
                printf(" %d |", M[i][j]);
            }
        }
        printf("\n");
        if(i==2 || i==5 || i==8){
            printf("---------------------------------------");
            printf("\n");
        }
    }
    printf("\n\nPARAB�NS, VOC� VENCEU!!!!!\n\n");
    system("pause");
    return 0;
}
