#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define LINHAS 12
#define COLUNAS 12
//Grupo da AV3: Diego Lima Silva, Joao Enzo Novais, Luiz Guilherme Guerreiro Carvalho e Pedro Vianna Goes Ede.
char tabuleiro[LINHAS][COLUNAS] = {
    {'*','*','*','*','*','*','*','*','*','*','*','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*','~','~','~','~','~','~','~','~','~','~','*'},
    {'*','~','~','~','~','~','~','~','~','~','~','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*','*','*','*','*','*','*','*','*','*','*','*'}
    };    
void printmapa(){

	for(int i=0; i < LINHAS; i++){ //condicao for para gerar o tabuleiro
        for(int j=0; j < COLUNAS; j++){
            printf("%c", tabuleiro[i][j]);
            if((LINHAS + COLUNAS)%2 == 0)
                printf("  ");    
    	}
        printf("\n");
    }
}
int obterCoordX(char peca){
	for(int i=0; i<11; i++){
        for(int j=0; j<11; j++){
        	if(tabuleiro[i][j]==peca)return i;
    	}
    }
    return -1;
}
int temPersEmbaixo(){
	for(int i=7; i<11; i++){
        for(int j=1; j<11; j++){
        	if(tabuleiro[i][j]!=' ')return 1;
    	}
    }
    return 0;
}
int temPersEmcima(){
	for(int i=0; i<5; i++){
        for(int j=1; j<11; j++){
        	if(tabuleiro[i][j]!=' ')return 1;
    	}
    }
    return 0;
}
int main(){
	setlocale(LC_ALL,"Portuguese");
	char jogadorA[20], jogadorB[20]; //Variaveis para o nome dos jogadores
	int jogador, a; //Jogador(variavel de turnos), a(variavel aleatoriedade true/false)
	int i, j, x, y; //Variaveis das Linhas e colunas
	int posicao;
	char peca, opcao;
	int cdJogArroba = 0, cdJogHashtag = 0; //Variaveis que representam o cooldown dos ataques especiais
	int especialHashtag = 0; //Variavel que diz se o ataques especial da pe�a # est� ativo
	int hashtagPosicionado = 0, arrobaPosicionado = 0;
	
	printf("Bem Vindo � Batalha da Laponia\n");
	printf("\n");
	printf("Diga o nome dos 2 jogadores: (Insira nome + enter)\n");
	printf("\n");
	scanf(" %[^\n]s", jogadorA);
	scanf(" %[^\n]s", jogadorB);
	printf("\n");
	printf("Em seguida sortearemos o jogador que iniciar� a partida\n");
	printf("...\n");
	printf("...\n");
	printf("...\n");
	
	srand(time(NULL)); //condicao da aleatoriedade
	a=rand()%2;	
	jogador=a;
	
	if (jogador%2==0){
		printf("Foi sorteado(a) o(a) %s \n", jogadorA);
	}
	if (jogador%2==1){
		printf("Foi sorteado(a) o(a) %s \n", jogadorB);
	}
	printf("\n");
	
    printmapa();
    
    if(jogador%2==0){
    	for(posicao=0; posicao<9; posicao++){
			printf("Rodada de posicionamento");
			printf("\n");
			printf("Primeiro o(a) %s", jogadorA);
			printf("\n");
			printf("Posicione 9 pe�as sendo elas 1, 2 ou @/# (desta escolha apenas uma delas)");
			printf("\n");
			printf("Diga a cordenada \n");
			scanf(" %d %d", &i, &j);
			if (tabuleiro[i][j] == ' ' && i<5){
				printf("Colocar pe�a: ");
				scanf(" %c", &peca);
				if(peca!='1'&&peca!='2'&&peca!='#'&&peca!='@'){
					printf("S� podem valores de 1 ou 2, al�m das pe�as especiais \n");
					posicao--;
				}
				else if(peca=='#' &&hashtagPosicionado){
					printf("O # j� est� posicionado \n");
					posicao--;
				}
				else if(peca=='@' &&arrobaPosicionado){
					printf("O @ j� est� posicionado \n");
					posicao--;
				}
				else if(peca=='@'&&obterCoordX('#')!=-1 &&obterCoordX('#')<5){
					printf("Voc� s� pode posicionar uma pe�a especial \n");
					posicao--;
				}
				else if(peca=='#'&&obterCoordX('@')!=-1 &&obterCoordX('@')<5){
					printf("Voc� s� pode posicionar uma pe�a especial \n");
					posicao--;
				}
				else{
					tabuleiro[i][j] = peca;
					if(peca=='#')hashtagPosicionado=1;
					else if (peca=='@')arrobaPosicionado=1;
					system("cls");
					printmapa();
				}
			}
			else {
				printf("A� n�o pode\n");	
				posicao--;
			}							
		}
		for(posicao=0; posicao<9; posicao++){
			printf("Rodada de posicionamento");
			printf("\n");
			printf("Agora o(a) %s", jogadorB);
			printf("\n");
			printf("Posicione 9 pe�as sendo elas 1, 2 ou @/# (desta escolha apenas uma delas)");
			printf("\n");
			printf("Diga a coordenada \n");		
			scanf(" %d %d", &i, &j);
			if (tabuleiro[i][j] == ' ' && i>6){
				printf("Colocar pe�a: ");
				scanf(" %c", &peca);
				if(peca!='1'&&peca!='2'&&peca!='#'&&peca!='@'){
					printf("S� podem valores de 1 ou 2, al�m das pe�as especiais \n");
					posicao--;
				}
				else if(peca=='#' &&hashtagPosicionado){
					printf("O # j� est� posicionado \n");
					posicao--;
				}
				else if(peca=='@' &&arrobaPosicionado){
					printf("O @ j� est� posicionado \n");
					posicao--;
				}
				else if(peca=='#'&&obterCoordX('@')!=-1 &&obterCoordX('@')>6){
					printf("Voc� s� pode posicionar uma pe�a especial \n");
					posicao--;
				}
				else if(peca=='@'&&obterCoordX('#')!=-1 &&obterCoordX('#')>6){
					printf("Voc� s� pode posicionar uma pe�a especial \n");
					posicao--;
				}
				else{
					tabuleiro[i][j] = peca;
					if(peca=='#')hashtagPosicionado=1;
					else if (peca=='@')arrobaPosicionado=1;
					system("cls");
					printmapa();
				}
			}
			else {
				printf("Ai n�o pode\n");	
				posicao--;
			}												
		}
	}
	
	if(jogador%2==1){
		for(posicao=0; posicao<9; posicao++){
			printf("Rodada de posicionamento");
			printf("\n");
			printf("Primeiro o %s", jogadorB);
			printf("\n");
			printf("Posicione 9 pe�as sendo elas 1, 2 ou @/# (desta escolha apenas uma delas)");
			printf("\n");
			printf("Diga a coordenada primeiro\n");
			scanf(" %d %d", &i, &j);
			if (tabuleiro[i][j] == ' ' && i>6){
				printf("Colocar pe�a: ");
				scanf(" %c", &peca);
				if(peca!='1'&&peca!='2'&&peca!='#'&&peca!='@'){
					printf("S� podem valores de 1 ou 2, al�m das pe�as especiais \n");
					posicao--;
				}
				else if(peca=='#' &&hashtagPosicionado){
					printf("O # j� est� posicionado \n");
					posicao--;
				}
				else if(peca=='@' &&arrobaPosicionado){
					printf("O @ j� est� posicionado \n");
					posicao--;
				}
				else if((peca=='#')&&obterCoordX('@')!=-1 &&obterCoordX('@')>6){
					printf("Voc� s� pode posicionar uma pe�a especial \n");
					posicao--;
				}
				else if((peca=='@')&&obterCoordX('#')!=-1 &&obterCoordX('#')>6){
					printf("Voc� s� pode posicionar uma pe�a especial \n");
					posicao--;
				}
				else{
					tabuleiro[i][j] = peca;
					if(peca=='#')hashtagPosicionado=1;
					else if (peca=='@')arrobaPosicionado=1;
					system("cls");
					printmapa();
				}
			}
			else {
				printf("Ai n�o pode\n");	
				posicao--;
			}						
		}
		for(posicao=0; posicao<9; posicao++){
			printf("Rodada de posicionamento");
			printf("\n");
			printf("Agora o(a) %s", jogadorA);
			printf("\n");
			printf("Posicione 9 pe�as sendo elas 1, 2 ou @/# (desta escolha apenas uma delas)");
			printf("\n");
			printf("Diga a coordenada primeiro\n");		
			scanf(" %d %d", &i, &j);
			if (tabuleiro[i][j] == ' ' && i<5){
				printf("Colocar pe�a: ");
				scanf(" %c", &peca);
				if(peca!='1'&&peca!='2'&&peca!='#'&&peca!='@'){
					printf("S� podem valores de 1 ou 2, al�m das pecas especiais \n");
					posicao--;
				}
				else if(peca=='#' &&hashtagPosicionado){
					printf("O # j� est� posicionado \n");
					posicao--;
				}
				else if(peca=='@' &&arrobaPosicionado){
					printf("O @ j� est� posicionado \n");
					posicao--;
				}
				else if((peca=='#')&&obterCoordX('@')!=-1 &&obterCoordX('@')<5){
					printf("Voc� s� pode posicionar uma pe�a especial \n");
					posicao--;
				}
				else if((peca=='@')&&obterCoordX('#')!=-1 &&obterCoordX('#')<5){
					printf("Voc� s� pode posicionar uma pe�a especial \n");
					posicao--;
				}
				else{
					tabuleiro[i][j] = peca;
					if(peca=='#')hashtagPosicionado=1;
					else if (peca=='@')arrobaPosicionado=1;
					system("cls");
					printmapa();
				}
			}
			else {
				printf("A� n�o pode\n");	
				posicao--;
			}					
		}
	}
	
	while (1){ //Turnos alternados infinitos
		system("pause");
		system("cls");
		printmapa();
		if (jogador%2==0){	
			printf("\n");
			printf("Turno do %s ", jogadorA);
			printf("\n");
		}
		else {
			printf("\n");
			printf("Turno do %s ", jogadorB);
			printf("\n");
		}
		printf("Selecione uma op��o \n 1) Movimentar \n 2) Ataque B�sico \n 3) Ataque especial \n");
		scanf(" %c", &opcao);
		
		switch (opcao){
			case '1':
				printf("Escolha a posi��o da pe�a \n");
				scanf("%d %d", &i, &j);
				if(i<1 || i>10 || j<1 || j>10){
					printf("N�o pode colocar pe�as nessa posi��o \n");
					break;
				}
				else if(tabuleiro[i][j]!='1' && tabuleiro[i][j]!='2' && tabuleiro[i][j]!='#' && tabuleiro[i][j]!='@'){
					printf("N�o h� pe�as nessa posi��o \n");
					break;
				}
				else if((jogador%2 == 0 &&i>4)||(jogador%2 == 1 &&i<7)){
					printf("Voc� selecionou uma pe�a que n�o e sua \n");
					break;
				}
				printf("Escolha a nova posi��o da pe�a \n");
				scanf("%d %d", &x, &y);
				if(x<1 || x>10 || y<1 || y>10){
					printf("N�o pode colocar pe�as nessa posi��o \n");
					break;
				}
				else if(tabuleiro[x][y]!=' '){
					printf("N�o � poss�vel se mover para essa posi��o \n");
					break;
				}
				else if((jogador%2 == 0 &&x>4)||(jogador%2 == 1 &&x<7)){
					printf("Voc� n�o pode se mover para o campo inimigo \n");
					break;
				}
				else if(x-i != 0 && y-j != 0){
					printf("Proibido movimento diagonal \n");
					break;
				}
				else if(x==i && y==j){
					printf("Voc� n�o pode se mover para o mesmo lugar \n");
					break;
				}
				else if(abs(x-i)>1||abs(y-j)>1){
					printf("S� pode mover a pe�a para uma casa ao lado");
					break;
				}
				peca = tabuleiro[i][j];
				tabuleiro[i][j] = ' ';
				tabuleiro[x][y]= peca;
				if(jogador==0) jogador = 1;
				else jogador = 0;
				if(cdJogArroba>0)cdJogArroba--;
				if(cdJogHashtag>0)cdJogHashtag--;
				break;
 			case '2':
 				printf("Escolha a posi��o da pe�a \n");
				scanf("%d %d", &i, &j);
				if(i<1 || i>10 || j<1 || j>10){
					printf("Posi��o fora do tabuleiro \n");
					break;
				}
				else if(tabuleiro[i][j]!='1' && tabuleiro[i][j]!='2' && tabuleiro[i][j]!='#' && tabuleiro[i][j]!='@'){
					printf("N�o h� pe�as nessa posi��o \n");
					break;
				}
				else if((jogador%2 == 0 &&i>4)||(jogador%2 == 1 &&i<7)){
					printf("Voc� selecionou uma pe�a que n�o � sua \n");
					break;
				}
				if(jogador%2 == 0 &&(tabuleiro[i][j] == '1'||tabuleiro[i][j] == '@')){
					for(x=7; x<11; x++){
						if(tabuleiro[x][j]!=' '){
							if(tabuleiro[x][j] =='#' &&especialHashtag!=0){
								printf("Pe�a especial recebeu um ataque, mas e� inefetivo \n");
							}
							else{
								printf("%c eliminado \n", tabuleiro[x][j]);
								tabuleiro[x][j]=' ';
								if(!temPersEmbaixo()){
									printf("Voc� venceu %s \n", jogadorA);
									system("pause");
									return 0;
								}
							}
							if(jogador==1) jogador=0;
							else jogador=1;
							if(cdJogArroba>0)cdJogArroba--;
							if(cdJogHashtag>0)cdJogHashtag--;
							break;
						}
					}
					if(x==11)printf("N�o h� inimigos nessa posi��o \n");
				}
				else if(jogador%2 == 1 &&(tabuleiro[i][j] == '1'||tabuleiro[i][j] == '@')){
					for(x=4; x>0; x--){
						if(tabuleiro[x][j]!=' '){
							if(tabuleiro[x][j] =='#' &&especialHashtag!=0){
								printf("Pe�a especial recebeu um ataque, mas � inefetivo \n");
							}
							else{
								printf("%c eliminado \n", tabuleiro[x][j]);
								tabuleiro[x][j]=' ';
								if(!temPersEmcima()){
									printf("Voc� venceu %s \n", jogadorB);
									system("pause");
									return 0;
								}
							}
							if(jogador==1) jogador=0;
							else jogador=1;
							if(cdJogArroba>0)cdJogArroba--;
							if(cdJogHashtag>0)cdJogHashtag--;
							break;
						}
					}
					if(x==0)printf("N�o h� inimigos nessa posi��o \n");
				}
				else if(jogador%2 == 0 &&(tabuleiro[i][j] == '2'||tabuleiro[i][j] == '@')){
					printf("Selecione a dire��o da diagonal \n 1) Esquerda \n 2) Direta \n");
					scanf(" %c", &opcao);
					if(opcao == '1'){
						for(x=i, y=j; x<11 && y>0; x++, y--){
							if(tabuleiro[x][y]!=' ' &&x>6){
								if(tabuleiro[x][y] =='#' &&especialHashtag!=0){
									printf("Pe�a especial recebeu um ataque, mas � inefetivo \n");
								}
								else{
									printf("%c eliminado \n", tabuleiro[x][y]);
									tabuleiro[x][y]=' ';
									if(!temPersEmbaixo()){
										printf("Voc� venceu %s \n", jogadorA);
										system("pause");
										return 0;
									}
								}
								if(jogador==1) jogador=0;
								else jogador=1;
								if(cdJogArroba>0)cdJogArroba--;
								if(cdJogHashtag>0)cdJogHashtag--;
								break;
							}
						}
						if(x>=11 ||y<=0)printf("N�o h� inimigos nessa posi��o \n");
					}
					else if(opcao == '2'){
						for(x=i, y=j; x<11 && y<11; x++, y++){
							if(tabuleiro[x][y]!=' ' &&x>6){
								if(tabuleiro[x][y] =='#' &&especialHashtag!=0){
									printf("Pe�a especial recebeu um ataque, mas � inefetivo \n");
								}
								else{
									printf("%c eliminado \n", tabuleiro[x][y]);
									tabuleiro[x][y]=' ';
									if(!temPersEmbaixo()){
										printf("Voc� venceu %s \n", jogadorA);
										system("pause");
										return 0;
									}
								}
								if(jogador==1) jogador=0;
								else jogador=1;
								if(cdJogArroba>0)cdJogArroba--;
								if(cdJogHashtag>0)cdJogHashtag--;
								break;
							}
						}
						if(x>=11 ||y>=11)printf("N�o h� inimigos nessa posi��o \n");
					}
					else{
						printf("Essa op��o n�o � v�lida \n");
						break;
					}
				}
				else if(jogador%2 == 1 &&(tabuleiro[i][j] == '2'||tabuleiro[i][j] == '#')){
					printf("Selecione a dire��o da diagonal \n 1) Esquerda \n 2) Direta \n");
					scanf(" %c", &opcao);
					if(opcao == '1'){
						for(x=i, y=j; x>0 && y>0; x--, y--){
							if(tabuleiro[x][y]!=' ' &&x<5){
								if(tabuleiro[x][y] =='#' &&especialHashtag!=0){
									printf("Pe�a especial recebeu um ataque, mas � inefetivo \n");
								}
								else{
									printf("%c eliminado \n", tabuleiro[x][y]);
									tabuleiro[x][y]=' ';
									if(!temPersEmcima()){
										printf("Voc� venceu %s \n", jogadorB);
										system("pause");
										return 0;
									}
								}
								if(jogador==1) jogador=0;
								else jogador=1;
								if(cdJogArroba>0)cdJogArroba--;
								if(cdJogHashtag>0)cdJogHashtag--;
								break;
							}
						}
						if(x<=0 ||y<=0)printf("N�o h� inimigos nessa posi��o \n");
					}
					else if(opcao == '2'){
						for(x=i, y=j; x>0 && y<11; x--, y++){
							if(tabuleiro[x][y]!=' ' &&x<5){
								if(tabuleiro[x][y] =='#' &&especialHashtag!=0){
									printf("Pe�a especial recebeu um ataque, mas � inefetivo \n");
								}
								else{
									printf("%c eliminado \n", tabuleiro[x][y]);
									tabuleiro[x][y]=' ';
									if(!temPersEmcima()){
										printf("Voc� venceu %s \n", jogadorB);
										system("pause");
										return 0;
									}
								}
								if(jogador==1) jogador=0;
								else jogador=1;
								if(cdJogArroba>0)cdJogArroba--;
								if(cdJogHashtag>0)cdJogHashtag--;
								break;
							}
						}
						if(x<=0 ||y>=11)printf("N�o h� inimigos nessa posi��o \n");
					}
					else{
						printf("Essa op��o n�o � v�lida \n");
						break;
					}
				}
 				break;
 			case '3':
 				printf("Escolha a posi��o da pe�a \n");
				scanf("%d %d", &i, &j);
				if(i<1 || i>10 || j<1 || j>10){
					printf("Posi��o fora do tabuleiro \n");
					break;
				}
				else if(tabuleiro[i][j]!='1' && tabuleiro[i][j]!='2' && tabuleiro[i][j]!='#' && tabuleiro[i][j]!='@'){
					printf("N�o h� pe�as nessa posi��o \n");
					break;
				}
				else if((jogador%2 == 0 &&i>4)||(jogador%2 == 1 &&i<7)){
					printf("Voc� selecionou uma pe�a que n�o � sua \n");
					break;
				}
				if(tabuleiro[i][j]=='#'){
					if(cdJogHashtag!=0){
						printf("O ataque especial ainda n�o est� dispon�vel \n");
						break;
					}
					especialHashtag = 2;
					cdJogHashtag = 4;
					printf("Especial do # ativado \n");
					if(jogador==1)jogador=0;
					else jogador=1;
				}
				else if(tabuleiro[i][j]=='@'){
					if(cdJogArroba!=0){
						printf("O ataque especial ainda n�o est� dispon�vel \n");
						break;
					}
					printf("Escolha a posi��o da pe�a \n");
					scanf("%d %d", &x, &y);
					if(x<1 || y>10 || y<1 || y>10){
						printf("Posi��o fora do tabuleiro \n");
						break;
					}
					else if(tabuleiro[x][y]!='1' && tabuleiro[x][y]!='2' && tabuleiro[x][y]!='#' && tabuleiro[x][y]!='@'){
						printf("N�o h� pe�as nessa posi��o \n");
						break;
					}
					else if((jogador%2 == 0 &&x>4)||(jogador%2 == 1 &&x<7)){
						printf("Voc� selecionou uma pe�a que n�o � sua \n");
						break;
					}
					cdJogArroba = 4;
					peca=tabuleiro[i][j];
					tabuleiro[i][j]=tabuleiro[x][y];
					tabuleiro[x][y]=peca;
					if(jogador==1)jogador=0;
					else jogador=1;
				}
				else{
					printf("A pe�a selecionada n�o � especial \n");
				}
 				break;
 			default:
 				printf("A� n�o pode \n");
		}
	}
return 0;
}
