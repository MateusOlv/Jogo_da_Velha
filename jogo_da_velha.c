#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void imprimir(char jogo[3][3]){
	printf("\t   0    1    2\n\n");
	printf("\t    %c | %c | %c    0\n", jogo[0][0], jogo[0][1], jogo[0][2]);
	printf("\t   -----------\n");
	printf("\t    %c | %c | %c    1\n", jogo[1][0], jogo[1][1], jogo[1][2]);
	printf("\t   -----------\n");
	printf("\t    %c | %c | %c    2\n\n", jogo[2][0], jogo[2][1], jogo[2][2]);
}

void limpar(char jogo[3][3]){
	int i, j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			jogo[i][j] = ' ';
		}
	}
}

int vitoria(char jogo[3][3]){
	// vitória em linha
	if(jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X') return 0;
	if(jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X') return 0;
	if(jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X') return 0;
	
	if(jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O') return 1;
	if(jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O') return 1;
	if(jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O') return 1;
	
	// vitória em coluna
	if(jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X') return 0;
	if(jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X') return 0;
	if(jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X') return 0;
	
	if(jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O') return 1;
	if(jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O') return 1;
	if(jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] == 'O') return 1;
	
	// vitória em diagonal principal
	if(jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X') return 0;
	if(jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O') return 1;
	
	// vitória em diagonal secundária
	if(jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X') return 0;
	if(jogo[0][2] == 'O' && jogo[1][1] == 'O' && jogo[2][0] == 'O') return 1;
	
}

int main(){
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	int i, j, jogadas;
	char continuar;
	char jogo_da_velha[3][3];
	
	
	do{
		system("cls");
		jogadas = 1;
		limpar(jogo_da_velha);
		do{
			printf("\t\t\t\t\t\t---- JOGO DA VELHA ----\n\n");
			
			imprimir(jogo_da_velha);
			
			printf("JOGADOR X\n");
			printf("Digite a linha: ");
			scanf("%d", &i);
			printf("Digite a coluna: ");
			scanf("%d", &j);
			
			while(i < 0 || j < 0 || i > 2 || j > 2){
				system("cls");
				
				printf("\t\t\t\t\t\t---- JOGO DA VELHA ----\n\n");
			
				imprimir(jogo_da_velha);
				
				printf("O(s) número(s) digitado(s) não é (são) válido(s)! Digite somente valores entre \"0\" e \"2\"!\n");
				
				printf("\nJOGADOR X\n");
				printf("Digite a linha: ");
				scanf("%d", &i);
				printf("Digite a coluna: ");
				scanf("%d", &j);
			}
			
			while(jogo_da_velha[i][j] != ' '){
				system("cls");
				
				printf("\t\t\t\t\t\t---- JOGO DA VELHA ----\n\n");
			
				imprimir(jogo_da_velha);
				
				printf("Esta casa já está ocupada! Por favor, selecione uma casa vazia!\n");
				
				printf("\nJOGADOR X\n");
				printf("Digite a linha: ");
				scanf("%d", &i);
				printf("Digite a coluna: ");
				scanf("%d", &j);
			}
			
			jogo_da_velha[i][j] = 'X';
			jogadas++;
			
			if(vitoria(jogo_da_velha) == 0){
				system("cls");
				
				printf("\t\t\t\t\t\t---- JOGO DA VELHA ----\n\n");
			
				imprimir(jogo_da_velha);
				
				printf("Vitória do Jogador X\n");
				break;
			}
			
			if(jogadas >= 9){
				system("cls");
				imprimir(jogo_da_velha);
				printf("Deu velha!\n");
				break;
			}
			
			system("cls");
			
			printf("\t\t\t\t\t\t---- JOGO DA VELHA ----\n\n");
			
			imprimir(jogo_da_velha);
			
			printf("JOGADOR O\n");
			printf("Digite a linha: ");
			scanf("%d", &i);
			printf("Digite a coluna: ");
			scanf("%d", &j);
			
			while(i < 0 || j < 0 || i > 2 || j > 2){
				system("cls");
				
				printf("\t\t\t\t\t\t---- JOGO DA VELHA ----\n\n");
			
				imprimir(jogo_da_velha);
				
				printf("O(s) número(s) digitado(s) não é (são) válido(s)! Digite somente valores entre \"0\" e \"2\"!\n");
				
				printf("\nJOGADOR O\n");
				printf("Digite a linha: ");
				scanf("%d", &i);
				printf("Digite a coluna: ");
				scanf("%d", &j);
			}
			
			while(jogo_da_velha[i][j] != ' '){
				system("cls");
				
				printf("\t\t\t\t\t\t---- JOGO DA VELHA ----\n\n");
			
				imprimir(jogo_da_velha);
				
				printf("Esta casa já está ocupada! Por favor, selecione uma casa vazia!\n");
				
				printf("\nJOGADOR O\n");
				printf("Digite a linha: ");
				scanf("%d", &i);
				printf("Digite a coluna: ");
				scanf("%d", &j);
			}
			
			jogo_da_velha[i][j] = 'O';
			jogadas++;
			
			if(vitoria(jogo_da_velha) == 1){
				system("cls");
				
				printf("\t\t\t\t\t\t---- JOGO DA VELHA ----\n\n");
			
				imprimir(jogo_da_velha);
				
				printf("Vitória do Jogador O\n");
				break;
			}
			
			system("cls");
			
		} while(jogadas <= 9);
		
		printf("Quer continuar? [s/n]\n");
		fflush(stdin);
		scanf("%s", &continuar);
		
	} while(continuar == 's');
	
	
	return 0;
}
