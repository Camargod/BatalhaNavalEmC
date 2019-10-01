#include <locale.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

struct campo
{
	int ataque[10][10];
	int jogada[10][10];
};

struct campo jogador1;
struct campo jogador2;

void iniciaJogo(){//inicia os tabuleiros e preenche com zeros
	memset(&jogador1.jogada,0,100);//matriz do jogador
	memset(&jogador1.ataque,0,100);//matriz do jogador para atacar o advers�rio
	memset(&jogador2.jogada,0,100);//matriz do adversario
	memset(&jogador2.ataque,0,100);//matriz do adversario para atacar o jogador
}

void exibeJogo(int tabuleiro[10][10]){
	int contl,contc;
	char letra;
	for(contl=0;contl<=9;contl++)
	{
		if(contl==0)
		{
			printf("\n");
			printf("    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|");
		}
		switch(contl)
		{
			case 0:
				letra = 'A';
				break;
			case 1:
				letra = 'B';
				break;
			case 2:
				letra = 'C';
				break;
			case 3:
				letra = 'D';
				break;
			case 4:
				letra = 'E';
				break;
			case 5:
				letra = 'F';
				break;
			case 6:
				letra = 'G';
				break;
			case 7:
				letra = 'H';
				break;
			case 8:
				letra = 'I';
				break;
			case 9:
				letra = 'J';
				break;
		}
		printf("\n    +---+---+---+---+---+---+---+---+---+---+\n");
		for(contc=0;contc<=9;contc++)
		{
			if(contc==0)
			{
				printf("  %c |",letra);
			}
			if(tabuleiro[contl][contc] == 1)
			{
				printf(" X |");
			}
			else if (tabuleiro[contl][contc] == 2)
			{
				printf("~ ~|");
			}
			else if (tabuleiro[contl][contc] == 0)
			{
				printf("   |");
			}
			
		}
			
	}
	printf("\n    +---+---+---+---+---+---+---+---+---+---+\n");
}

void exibeCampo(int tabuleiro[10][10])
{
	int contl,contc;
	char letra;
	for(contl=0;contl<=9;contl++)
	{
		if(contl==0)
		{
			printf("\n");
			printf("    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|");
		}
		switch(contl)
		{
			case 0:
				letra = 'A';
				break;
			case 1:
				letra = 'B';
				break;
			case 2:
				letra = 'C';
				break;
			case 3:
				letra = 'D';
				break;
			case 4:
				letra = 'E';
				break;
			case 5:
				letra = 'F';
				break;
			case 6:
				letra = 'G';
				break;
			case 7:
				letra = 'H';
				break;
			case 8:
				letra = 'I';
				break;
			case 9:
				letra = 'J';
				break;
		}
		printf("\n    +---+---+---+---+---+---+---+---+---+---+\n");
		for(contc=0;contc<=9;contc++)
		{
			if(contc==0)
			{
				printf("  %c |",letra);
			}
			if(tabuleiro[contl][contc] == 2)
			{//marco um X se o jogador acertar o navio inimigo
				printf(" X |");
			}
			else if(tabuleiro[contl][contc] == 1)
			{
				printf("~ ~|");//marca dessa forma se o jogador acertar na �gua
			}
			else if (tabuleiro[contl][contc] == 0)
			{
				printf("   |");
			}
			
		}
			
	}
	printf("\n    +---+---+---+---+---+---+---+---+---+---+\n");
}

void MatrizAdversario()
{//fun��o para a IA escolher as jogadas
	srand(time(NULL));
	int l,c,i;
	for(i=1;i<=20;i++)
	{
		l = rand()%11;
		c = rand()%11;
		if (jogador2.jogada[l][c] == 1)
		{
			i = i-1;
		}
		else if(jogador2.jogada[l][c] == 0)
		{
			jogador2.jogada[l][c] = 1;
		}
	}
}

void MatrizJogador(void)  //fun��o para o usu�rio fazer as jogadas
{
  setlocale(LC_ALL, "Portuguese");
  int l,c,i,s;
  iniciaJogo();
  char l2;
  bool colunaOK = true, linhaOK = true;
  printf("Escolha onde deseja colocar seus barcos\n\n"); //definindo a quantidade de vezes que o for ir� acontecer, � poss�vel definir a quatidade de barcos no tabuleiro
  for(i=1;i<=2;i++)
  {
  		if(colunaOK == true)
		  {
	  		printf("Escolha uma linha de A at� J:");
	  		scanf("%s", &l2);
		  	switch (l2)
			  {
			  	case 'a':
		  			l = 0;
		  			linhaOK = true;
		  			break;
		  		case 'b':
		  			l = 1;
		  			linhaOK = true;
		  			break;
		  		case 'c':
		  			l = 2;
		  			linhaOK = true;
		  			break;
		  		case 'd':
		  			l = 3;
		  			linhaOK = true;
		  			break;
		  		case 'e':
		  			l = 4;
		  			linhaOK = true;
		  			break;
		  		case 'f':
		  			l = 5;
		  			linhaOK = true;
		  			break;
		  		case 'g':
		  			l = 6;
		  			linhaOK = true;
		  			break;
		  		case 'h':
		  			l = 7;
		  			linhaOK = true;
		  			break;
		  		case 'i':
		  			l = 8;
		  			linhaOK = true;
		  			break;
		  		case 'j':
		  			l = 9;
		  			linhaOK = true;
		  			break;
		  		default:
		  			printf("Essa linha n�o existe.\nPor favor escolha uma letra entre A e J.\n\n");
		  			linhaOK = false;
		  			if (i>1)
					{
		  				i = i-1;
		  			}
		  			else
					{
		  				i = 1;
					}
					break;
			}
			
		}
		
		if (linhaOK == true){
			printf("Escolha uma coluna entre 1 e 10:");
			scanf("%i",&c);
			printf("\n");
			if (c<0 || c>10){
				printf("Jogada inv�lida. Por favor, escolha uma coluna entre 1 e 10.");
				colunaOK = false;
				if (i>1){
					i = i-1;
				}
				else{
					i = 1;
				}
			}
			else
			{
				c = c-1;
				colunaOK = true;
			}
			
		}
		if(linhaOK == true && colunaOK == true)
		{
			if (jogador1.jogada[l][c] == 1)
			{
				printf("Voc� j� preencheu essa casa, por favor escolha outra.\n");
				i = i-1;
				exibeJogo(jogador1.jogada);
			}
			else if(jogador1.jogada[l][c] == 0)
			{
				jogador1.jogada[l][c] = 1;
				exibeJogo(jogador1.jogada);
			}
		
		}	
  	}
}

bool verificaMatriz()
{
	bool fimDeJogo;
	int contl,contc;
	for(contl=0;contl<=9;contl++)
	{
		for(contc=0;contc<=9;contc++)
		{
			if(jogador1.jogada[contl][contc] == 1 || jogador2.jogada[contl][contc] == 1)
			{
				fimDeJogo = false;
				break;
			}
			else
			{
				fimDeJogo = true;
			}
		}
	}
	return fimDeJogo;
}

void jogadaAdversario(int l, int c)
{
	int l,c;
	char l2;
	srand(time(NULL));
	jogador2.ataque[l][c] = 1;
	if (jogador2.ataque[l][c] == jogador1.jogada[l][c])
	{
		switch(l){
			case 0:
				l2 = 'A';
			case 1:
				l2 = 'B';
			case 2:
				l2 = 'C';
			case 3:
				l2 = 'D';
			case 4:
				l2 = 'E';
			case 5:
				l2 = 'F';
			case 6:
				l2 = 'G';
			case 7:
				l2 = 'H';
			case 8:
				l2 = 'I';
			case 9:
				l2 = 'J';
		}
		printf("O seu barco da coordenada %c%i foi atingido.\n",l2,c);
		jogador1.jogada[l][c] = 2;
	}
	else
	{
		printf("O inimigo errou o tiro.\n");
	}
	exibeJogo(jogador1.jogada);
}

void LetterToNumber(char* letter, int* l)
{
	switch(*letter)
	{
		case 'a':
			*l = 0;
		case 'b':
			*l = 1;
		case 'c':
			*l = 2;
		case 'd':
			*l = 3;
		case 'e':
			*l = 4;
		case 'f':
			*l = 5;
		case 'g':
			*l = 6;
		case 'h':
			*l = 7;
		case 'i':
			*l = 8;
		case 'j':
			*l = 9;
	}	
}


void main(void)
{
	int udpSocket, nBytes;
	char buffer[1024];
	struct sockaddr_in serverAddr, clientAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size, client_addr_size;
	int i;

	/*Create UDP socket*/
	udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

	/*Configure settings in address struct*/
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7891);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

	/*Bind socket with address struct*/
	bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

	/*Initialize size variable to be used later on*/
	addr_size = sizeof serverStorage;

	MatrizJogador();
	// MatrizAdversario();
	char l2;
	int l,c;
	bool fimDeJogo = false;
	system("cls");
	printf("Hora de come�ar!\n");
	while(fimDeJogo == false)
	{
		int *Vrecv[2];
		recvfrom(udpSocket,Vrecv,sizeof(Vrecv),0,(struct sockaddr *)&serverStorage, &addr_size);
		jogadaAdversario(Vrecv[1],Vrecv[2]);
		printf("Escolha uma linha:");
		fflush(stdin);
		scanf("%c", &l2);
		LetterToNumber(&l2, &l);
		printf("Escolha o n�mero da coluna:");
		scanf("%d", &c);
		if (jogador1.ataque[l][c] == 1 || jogador1.ataque[l][c] == 2)
		{
			printf("Voc� j� atacou nessa casa. Por favor, escolha outra.");
		}
		else
		{
			c-=1;
			jogador1.ataque[l][c] = 1;
			if (jogador1.ataque[l][c] == jogador2.jogada[l][c])
			{
				printf("Par�bens voc� acertou\n");
				jogador2.jogada[l][c] = 2;
				jogador1.ataque[l][c] = 1;
			}
			else
			{
				printf("Voc� errou\n");
				jogador1.ataque[l][c] = 2;
			}
			exibeCampo(jogador1.ataque);
			bool p = verificaMatriz();//precisa de uma vari�vel para que uma fun��o possa retornar um valor
			p = verificaMatriz();
		}
		sleep(3);
		system("cls");
	}
		
	if(fimDeJogo == true){
		printf("Fim de jogo");
	}
	
}
