#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Estruturar dados
    int lin, col, indlin, indcol, player, vitoria, playercount, playagain;
    char jogo[3][3];
    
    do{
        player = 1;
        vitoria = 0;
        playercount = 0;
        for (lin = 0; lin < 3;  lin++)
        {
            for (col = 0; col < 3; col++)
            {
                jogo[lin][col] = ' ';
            }
        }

        do {
            // Print do jogo
            printf("\n\n\t 0   1   2\n\n");
            for (lin = 0; lin < 3; lin++) {
                for(col = 0; col < 3; col++)
                {
                    if(col == 0)
                        printf("\t"); 
                    printf(" %c ", jogo[lin][col]);
                    if(col < 2)
                        printf("|");
                    if(col == 2)
                        printf("   %d", lin);
                        
                }
                if(lin < 2)
                    printf("\n\t-----------");
                printf("\n");
            }

            // Leitura de coordenadas

            do{
                printf("\nDigite a linha e a coluna que deseja jogar, jogador %d: ", player);
                scanf("%d%d", &indlin, &indcol);
            }while(indlin < 0 || indlin > 2 || indcol < 0 || indcol > 2 || jogo[indlin][indcol] != ' ');

            // Salvamento de coordenadas
            if(player == 1) {
                jogo[indlin][indcol] = 'O';
                player++;
            }
            else {
                jogo[indlin][indcol] = 'X';
                player--;
            }
            playercount++;

            // Verificação - linha

            if(jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O' ||
            jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O' ||
            jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O') {
                printf("\nO jogador 1 ganhou na linha!\n");
                vitoria = 1;
            }
            
            if(jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||
            jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||
            jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X') {
                printf("\nO jogador 2 ganhou na linha!\n");
                vitoria = 1;
            }

            // Verificação - coluna

            if(jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O' ||
            jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O' ||
            jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] == 'O') {
                printf("\nO jogador 1 ganhou na coluna!\n");
                vitoria = 1;
            }

            if(jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
            jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||
            jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X') {
                printf("\nO jogador 2 ganhou na coluna!\n");
                vitoria = 1;
            }

            // Verificação - diagonal principal

            if(jogo[0][0] == 'O' && jogo [1][1] == 'O' && jogo[2][2] == 'O') {
                printf("\nO jogador 1 ganhou na diagonal!\n");
                vitoria = 1;
            }

            if(jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X') {
                printf("\nO jogador 2 ganhou na diagonal!\n");
                vitoria = 1;
            }

            // Verificação - diagonal secundária

            if(jogo[0][2] == 'O' && jogo [1][1] == 'O' && jogo[2][0] == 'O') {
                printf("\nO jogador 1 ganhou na diagonal!\n");
                vitoria = 1;
            }

            if(jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X') {
                printf("\nO jogador 2 ganhou na diagonal!\n");
                vitoria = 1;
            }
        } while(vitoria == 0 && playercount < 9);

        if(vitoria == 0)
            printf("\nVelha!\n");

        printf("\nDeseja jogar novamente? Digite '1'.\n");
        scanf("%d", &playagain);
    }while(playagain == 1);
    return 0;
}