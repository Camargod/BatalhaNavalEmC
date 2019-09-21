#include <locale.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct campo{
	int ataque[10][10];                               //matriz de ataque
	int jogada[10][10];                              //matriz de jogada
};

struct campo jogador1;                               //jogador
struct campo jogador2;                               //advers�rio

void iniciaJogo()									//inicia os tabuleiros e preenche com zeros
{
	memset(&jogador1.jogada,0,100);					//matriz do jogador
	memset(&jogador1.ataque,0,100);					//matriz do jogador para atacar o advers�rio
	memset(&jogador2.jogada,0,100);					//matriz do adversario
	memset(&jogador2.ataque,0,100);					//matriz do adversario para atacar o jogador
}
void continuarJogo()											//pausa o programa e s� continua quando o jogador pressiona enter
{
	char k = 0;
	while(k == 0)												//esse la�o mant�m o programa em um loop enquanto aguarda que algum valor seja atribuido � vari�vel k
	{												
		printf("\nAperte enter para continuar.");
		fflush(stdin);
		scanf("%c", &k);
	}
	if(k != 0)														//assim que algum valor � atribuido � vari�vel k, o loop termina e a janela de visualiza��o � limpa
	{												
		system("cls");		
	}

}

void exibeJogo(int tabuleiro[10][10])                              //essa fun��o exibe a matriz colocada como par�metro para o jogador
{
	int contl,contc,contc2;
	char letra;
	for(contl=0;contl<=9;contl++)									//o contador desse loop � usado como �ndice para indicar a linha que ser� printada primeiro
	{
		if(contl==0)												//primeiro � printada na tela de visualiza��o os n�meros de cada coluna
		{
			printf("\n");
			printf("    |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10 |");
		}
		switch(contl)                                               //dependendo do valor do contador, � printada  a linha correspondente
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
		printf("\n    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n");
		for(contc=0;contc<=9;contc++)                                           //o contador desse loop � usado como �ndice para definir qual coluna ser� printada
		{                                                                       //juntando esse dois loops, � printado linha por linha, e a pr�xima linha s� � pritada quando todas as suas colunas j� foram printadas
			if(contc==0)                                                       
			{
				printf(" %c  |",letra);                                         //primeiro � printado a letra correspondete � linha do �ndice
			}
			if(tabuleiro[contl][contc] == 1)                                    //quando os contadores dos loops, que est�o sendo usados como �ndice, correspondem a uma coordenada na matriz
			{																	//que equivale a 1, ent�o � printado um barco na matriz
				printf(" <^> |");
			}
			else if (tabuleiro[contl][contc] == 2)                              //se os �ndices correspodem a um 2
			{																	//� printado �gua na matriz, de que o tiro foi na �gua
				printf("~ ~ ~|");
			}
			else if (tabuleiro[contl][contc] == 0)                              //se equivale a zero, ent�o a cada fica em branco
			{																	//pois zero equivale a um espa�o em branco na matriz
				printf("     |");
			}
			else if (tabuleiro[contl][contc] == 3)                             //se equivale a um 3, ent�o � printado um X, de que o barco naquela coordenada foi atingido
			{
				printf("  X  |");
			}
		}
			
	}
	printf("\n    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n\n");
}
void MatrizAdversario(){                                                                //essa fun��o preenche a matriz do advers�rio com barcos em coordenadas aleat�rias

	srand(time(NULL));																	//esse comando gera uma "semente" a partir da hora na placa da m�e do computador para que os n�meros aleat�rios sejam gerados
	int l,c,i;
	for(i=1;i<=20;i++)																	//definindo a quantidade de vezes que o loop ocorre, tamb�m � definido a quantidade de barcos que s�o colocados
	{
		l = rand()%10;																	//gera um n�mero aleat�rio que vai de 0 a 9 que servir� como �ndice da matriz para linha
		c = rand()%10;																	//e esse como �ndice da coluna
		
		if (jogador2.jogada[l][c] == 1)													//essa condi��o verifica se a posi��o da matriz indica pelos �ndices j� possue um barco nela
		{                                												//j� que barco equivale a 1 na matriz
			i = i-1;																	//se j� ouver um barco dessa posi��o, � subtraido 1 do contador do loop para que o n�mero total de barcos a ser colocado se mantenha
		}
		else if(jogador2.jogada[l][c] == 0)												//caso a posi��o na matriz indicada pelos �ndices n�o tenha um barco nela, � colocado um barco nela
		{
			jogador2.jogada[l][c] = 1;													//os barcos na matriz s�o representados por 1, por isso � atribuido 1 �quele local na matriz
		}
	}
}
void MatrizJogador(void)																//fun��o para o usu�rio fazer as jogadas
{ 
  setlocale(LC_ALL, "Portuguese");														//fun��o que imprime as letras com acentos que tem no Portug�es
  int l,c,i,s;
  iniciaJogo();																			//fun��o que preenche as matrizes com zero
  char l2;
  bool colunaOK = true, linhaOK = true;													
  for(i=1;i<=20;i++)																	//o n�mero de vezes que o loop ocorre, � o n�mero de barcos que ser�o colocados em jogo
  {
  	if(linhaOK == true && colunaOK == true)												//se um n�mero tiver sido atribuido com sucesso aos �ndices de linha e coluna
	{
		printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
		printf("          |    Escolha onde deseja colocar os barcos    |");            //� exibida essa mensagem e a fun��o recome�a desde o in�cio
		printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
		exibeJogo(jogador1.jogada);														//fun��o respons�vel por exibir a matiz do jogador
	}
  	if(colunaOK == true)																//essa condi��o verifica se um valor foi atribuido com sucesso para o �ndice de coluna
	{                                                                                   //se sim
	  	printf(" ~ Escolha uma linha de A at� J:");
	  	scanf("%s", &l2);                            									//jogador pode escolher uma linha entre A e J para posicionar o barco
	  	switch(l2)                                   									//atribui um valor a l, �ndice de linha, dependendo da letra passada pelo jogador
		          {                                  
			case 'a':                                									//se for passado A, que � a primeira linha do tabuleiro
				l = 0; 																	//l ganha o valor de 0, porque o valor dos �ndices na matriz v�o de 0 a 9 e 0 � o �ndice da primeira linha da matriz
				linhaOK = true;  														//retorna true para essa v�ri�vel, que significa que um valor foi atribuido com sucesso ao �ndice da linha                           
	  			break;                              									//interrompe a fun��o para que as outras instru��es n�o sejam executadas
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
	  		default:															   				//caso o jogador coloque alguma letra que n�o esteja entre A e J
	  			system("cls");																	//o programa limpa a tela
	  			printf("\n           +----+---+---+---+---+---+---+---+---+---+----+\n");		//exibe essa mensagem
	  			printf("           |                 Jogada inv�lida             |          \n           |   Por favor escolha uma letra entre A e J   |\n");
	  			printf("           +----+---+---+---+---+---+---+---+---+---+----+\n");
	  			linhaOK = false;																//retorna que um valor n�o foi atribuido com sucesso a linha, 
																								//para que o jogador n�o possa escolher o valor da coluna imediatamente e escolha outra linha
	  			exibeJogo(jogador1.jogada);														//exibe a matriz do jogador
	  			if (i>1)																		//� descontado 1 do contador do loop se i for maior que um
			  	{
	  				i = i-1;
		  		}
				else																			//e mantido como 1 se i=1
				{																				//para que o n�mero de barcos a serem colocados n�o seja alterado
		  		i = 1;
				}
				break;                        													
		}
			
	}
		
	if (linhaOK == true)												            			//se um valor foi atribuido com sucesso ao �ndice da linha, ent�o o jogador pode escolher o �ndice da  coluna
	{																	         				//que ser� o �ndice da matriz que indica qual a coordenada da coluna
		printf(" ~ Escolha uma coluna entre 1 e 10:");
		scanf("%i",&c);
		if (c<0 || c>10 || c==0)												          		//verifica se o valor que o jogador passo � menor que zero, maior que 10 ou igual a zero, que tamb�m poderia ser uma letra
		{																						//se esse for o caso
			fflush(stdin);
			system("cls");                                          			   				//a tela de visualiza��o � limpa
			printf("\n           +----+---+---+---+---+---+---+---+---+---+----+\n");          	//essa mensagem � exibida
			printf("           |                Jogada inv�lida              |\n           | Por favor, escolha uma coluna entre 1 e 10  |");
			printf("\n           +----+---+---+---+---+---+---+---+---+---+----+\n\n");
			printf("                    +----------------------------+\n");
			printf("--------------------| Voc� j� escolheu a linha %c |------------------\n",l2);
			printf("                    +----------------------------+\n\n");					//informa para o jogador qual foi a linha que ele j� escolheu
			exibeJogo(jogador1.jogada);															//exibe a matriz do jogador
			colunaOK = false;									 								//retorna que um valor � coluna n�o foi atribuido com sucesso, assim o jogador s� escolhe a coluna quando o loop recome�ar
			if (i>1)
			{																					//� descontado 1 do contador do loop se i for maior que um
				i = i-1;
			}
			else																				//e � mantido o valor de 1 se i for igual a 1
			{																					//isso para que o n�mero de barcos a ser colocado n�o se altere
				i = 1;																																								
			}
		}
		else																					//se o n�mero escolhido pelo jogador foi 0<c<=10
		{
			c-=1;																				//ent�o � subtraido um desse n�mero, porque o �ndice da matriz vai de 0 a 9
			colunaOK = true;																	//retorna que um valor foi atribuido com sucesso � coluna
		}
			
	}
	if(linhaOK == true && colunaOK == true)														//linha e coluna tem seus valores atribuidos com sucesso
	{
		if (jogador1.jogada[l][c] == 1)															//verifica se os �ndices passados j� n�o tem um barco atribuido a eles
		{																						//caso tenho
																					
			system("cls");																		//a tela de visualiza��o � apagada
			printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");			//� exibida essa mensagem para o jogador
			printf("          |         Voc� j� preencheu a casa %c%i         |\n          |           Por favor, escolha outra          |",l2,c+1);
			printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
			i = i-1;																			//e subtraido 1 do loop para o jogador possa escolher outra posi��o para o barco
																								//sem que seja descontado um barco do n�mero total, j� que esse n�o foi colocado
		}
		else if(jogador1.jogada[l][c] == 0)														//se n�o houver nenhum barco atibuido ao �ndice passado
		{
			system("cls");																		// a tela de visualiza��o � limpa
			printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
			printf("          |       Voc� colocou seu barco na casa %c%i     |",l2,c+1);		//� informado ao jogador onde ele posicionou o barco
			printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
			jogador1.jogada[l][c] = 1;															//� atribuido o barco �quela posi��o na matriz como 1
			exibeJogo(jogador1.jogada);															//exibe a matriz do jogador
			printf("             +----------------------------------------+\n");
			printf("-------------| Voc� ainda pode posicionar %i barco(s) |-------------\n",20-i);
			printf("             +----------------------------------------+\n");	
			continuarJogo();																	//pausa o jogo at� o jogador pressionar enter
		}
		
	}	
  }
}

bool verificaMatrizJogador()																	//essa fun��o verifica se o jogador perdeu a partida								
{
	bool fimDeJogo;
	int qtd = 0;
	int contl,contc;
	for(contl=0;contl<=9;contl++)																//o contador dessa loop � usado como �ndice de linha para varrer todas as linhas da matriz
	{
		for(contc=0;contc<=9;contc++)															//o contador desse loop � usado como �ndice de coluna para varrer a matriz
		{																						//assim cada linha tem todas as suas colunas varridas antes da pr�xima ser conferida
			
			if(jogador1.jogada[contl][contc] == 1)												//essa condi��o verifica se a coordenada n�o tem um barco nela na matriz do jogador
			{
					fimDeJogo = false;															//se tiver, retorna que o jogo ainda n�o acabou
					break;																		//e o la�o � interrompido
			} 
			else if (jogador1.jogada[contc][contl] == 3)										//essa condi��o verifica se houve um barco atingido naquela coordenada
			{																					//caso a condi��o se cima n�o seja verdadeira
				qtd += 1;																		//para cada barco atindigo, � incrementado 1 � vari�vel qtd
				if (qtd >= 20)																	//quando a fun��o contabiliza que 20 barcos foram atingidos
				{
					fimDeJogo = true;															//ele retorna que o jogo acabou															
					break;																		//e interrope o loop
				}
			}
		}
		
	}
	return fimDeJogo; 																			//essa fun��o retorna a vari�vel fimDeJogo                                                                 
}

bool verificaMatrizAdversario()    																//essa fun��o verifica se o advers�rio perdeu                                         
{
	bool fimDeJogo;
	int qtd = 0;
	int contl,contc;
	for(contl=0;contl<=9;contl++) 																//o contador dessa loop � usado como �ndice de linha para varrer todas as linhas da matriz                                         
	{
		for(contc=0;contc<=9;contc++)															//o contador desse loop � usado como �ndice de coluna para varrer a matriz								
		{																						//assim cada linha tem todas as suas colunas varridas antes da pr�xima ser conferida
			if(jogador2.jogada[contl][contc] == 1)												//essa condi��o verifica se a coordenada n�o tem um barco nela na matriz do advers�rio
			{
					fimDeJogo = false;															//se tiver, retorna que o jogo ainda n�o acabou
					break;																		//e o la�o � interrompido
			} 
			else if (jogador2.jogada[contc][contl] == 3)										//essa condi��o verifica se houve um barco atingido naquela coordenada
			{																					//caso a condi��o se cima n�o seja verdadeira
				qtd += 1;																		//para cada barco atindigo, � incrementado 1 � vari�vel qtd
				if (qtd >= 20)																	//quando a fun��o contabiliza que 20 barcos foram atingidos
				{
					fimDeJogo = true;															//ele retorna que o jogo acabou															
					break;																		//e interrope o loop
				}
			}
		}
		
	}
	return fimDeJogo;																			//essa fun��o retorna a vari�vel fimDeJogo 
}

void jogadaAdversario()																			//essa fun��o faz uma jogada aleat�ria para atacar os barcos da matriz do jogador											
{
	int l,c;
	char l2;
	bool verificaJogada = false;
	srand(time(NULL));																		
	while(verificaJogada == false){																//essa condi��o verifica a fun��o j� fez alguma jogada na coordenada definida pelos �ndices															
		l = rand()%10;																			//gera um n�mero aleat�rio entre 1 e 9 que ser� o �ndice da linha																		
		c = rand()%10;																			//gera um n�mero aleat�rio entre 1 e 9 que ser� o �ndice da coluna
		jogador2.ataque[l][c] = 1;																//atribui o valor 1 para a coordenda definida pelos �ndices na matriz de ataque do inimigo		
																								
		printf("\n-----------------------JOGADA DO ADVERS�RIO---------------------\n");				
		if (jogador2.ataque[l][c] == jogador1.jogada[l][c])										//como o valor dos barcos na matriz do jogador e do advers�rio � 1									
		{																						//essa condi��o verifica se na coordenada que o advers�rio est� atacando n�o tem um barco na mesma posi��o na matriz do jogador, se essa condi��o for verdadeira							
			switch(l)																			//depende do valor de l, �ndice da linha, esse bloco de instru��es troca ele pela letra correspondente � linha																		
			{
				case 0:
					l2 = 'A';
					break;
				case 1:
					l2 = 'B';
					break;
				case 2:
					l2 = 'C';
					break;
				case 3:
					l2 = 'D';
					break;
				case 4:
					l2 = 'E';
					break;
				case 5:
					l2 = 'F';
					break;
					case 6:
					l2 = 'G';
					break;
				case 7:
					l2 = 'H';
					break;
				case 8:
					l2 = 'I';
					break;
				case 9:
					l2 = 'J';
					break;
				}
			printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
			printf("          |  O seu barco da coordenada %c%i foi atingido  |",l2,c+1);		//a condi��o sendo verdadeira, � informado ao jogador qual barco foi atingido
			printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
			jogador1.jogada[l][c] = 3;															//a coordenada onde estava o barco que foi atingido recebe o valor 3
			jogador2.ataque[l][c] = 4;															//a coordendada na matriz de ataque do advers�rio recebe 4 para marcar que ele j� fez uma jogada naquela coordenada
			verificaJogada = true;
		}
		else if (jogador2.ataque[l][c]!=jogador1.jogada[l][c])									//se o valor da coordenada de ataca do advers�rio for diferente do valor na mesma coordenada na matriz do jogador
		{
			if(jogador2.ataque[l][c] == 4)														//verifica se o advers�rio j� fez alguma jogada naquela coordenada										
			{
				verificaJogada = false;															//se sim, retorna essa vari�vel como falsa para o la�o recome�ar e outra coordenada ser gerada
			}
			else																				//caso o advers�rio ainda n�o tenha jogado naquela coordenada
			{																					//significa que o advers�rio errou o tiro, j� que o valor na coordenada de ataque do advers�rio � diferente do valor na mesma coordenada na matriz do jogador
				switch(l)															
				{
				case 0:
					l2 = 'A';
					break;
				case 1:
					l2 = 'B';
					break;
				case 2:
					l2 = 'C';
					break;
				case 3:
					l2 = 'D';
					break;
				case 4:
					l2 = 'E';
					break;
				case 5:
					l2 = 'F';
					break;
					case 6:
					l2 = 'G';
					break;
				case 7:
					l2 = 'H';
					break;
				case 8:
					l2 = 'I';
					break;
				case 9:
					l2 = 'J';
					break;
				}
				printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
				printf("          |           O inimigo errou o tiro            |\n          |           Ele atirou na casa %c%i             |",l2,c+1);  //� informado ao jogador que o advers�rio errou o tiro e onde foi que o advers�rio atirou
				printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
				jogador1.jogada[l][c] = 2;														//matriz do jogador recebe um dois nessa coordenada, pois significa que foi tira na �gua	
				jogador2.ataque[l][c] = 4;														//matriz de ataque do advers�rio recebe 4 para marcar que ele j� fe uma jogada naquela coordenada
				verificaJogada = true;															//vari�vel recebe valor de true para sair do la�o
			}
		}																
	}
	exibeJogo(jogador1.jogada);																	//exibe a matriz do jogador para o jogador																	
}

void MensagemPerdeu()																			//essa fun��o exibe a mensagem para o jogador de que ele perdeu
{
	printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
	printf("          |                  Voc� perdeu                |");
	printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");	
}

void MensagemVenceu()																			//essa fun��o exibe a mensagem ara o jogador de que ele ganhou
{
	printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
	printf("          |                  Voc� ganhou                |");
	printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");	
}

void main(void)																					//fun��o principal
{
	MatrizJogador();																			//chamada da fun��o que permite ao jogador posicionar seus barcos
	MatrizAdversario();																			//chamada para a fun��o que preenche a matriz do advers�rio com barcos em posi��es aleat�rioas
	char l2;
	int l,c,qtd = 0;
	bool fimDeJogo = false, colunaOK = true, linhaOK = true;
	system("cls");																				//limpa a tela de visualiza��o
	printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
	printf("          |             Hora de comecar! :D             |");
	printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
	while(fimDeJogo == false)																		
	{
		if (verificaMatrizJogador() == false)																		//verifica se o jogador n�o perdeu a partida
		{																											//se a fun��o que faz essa veririfca��o retorna false																									
			if(colunaOK == true && linhaOK == true)																	//se os valores atribuidos � coluna e � linha estiverem ok
			{
				printf("\n------------------------------SUA VEZ!----------------------------\n");					//� exibida  a mensagem ao jogador que � a vez dele
				exibeJogo(jogador1.ataque);																			//exibe a matriz de ataque do jogador
				printf("\n");
			}
			if(colunaOK == true)																					//se um valor tiver sido atribuido com sucesso � coluna, o jogador pode escolher a linha
			{
				printf(" ~ Escolha uma linha:");
				fflush(stdin);
				scanf("%c", &l2);
				switch(l2)																							//atribui um valor a l, �ndice de linha, dependendo da letra passada pelo jogador
				{
					case 'a':																						//se for passado A, que � a primeira linha do tabuleiro
						l = 0;																						//l ganha o valor de 0, porque o valor dos �ndices na matriz v�o de 0 a 9 e 0 � o �ndice da primeira linha da matriz
						linhaOK = true;																				//retorna que um valor foi atribuido � linha com sucesso
						break;																						//interrompe o bloco de intru��o para que as outras intru��es do bloco n�o sejam executadas
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
						default:																						//se o jogador passar uma letra que n�o esteja entre A e J
						system("cls");																					// a tela de visualiza��o � limpa
		  				printf("\n           +----+---+---+---+---+---+---+---+---+---+----+\n");						//exibe essa mensagem
		  				printf("           |                 Jogada inv�lida             |          \n           |   Por favor escolha uma letra entre A e J   |\n");
		  				printf("           +----+---+---+---+---+---+---+---+---+---+----+\n");
		  				linhaOK = false;																				//retorna que um valor n�o foi atribuido com sucesso � linha
		  																												//assim o la�o continua sem o jogador escolher uma coluna e, assim que o la�o recome�a, o jogador pode escolher um novo valor pra linha
		  				exibeJogo(jogador1.ataque);																		//exibe a matriz de ataque do jogador
					
				}
			}
			if(linhaOK == true)																							//se um valor tiver sido atribuido com sucesso � linha, o jogador pode escolher a coluna
			{
				printf(" ~ Escolha o n�mero da coluna:");
				scanf("%i", &c);																						
				if (c<0 || c>10 || c==0)																				//verifica se o valor que o jogador passou � menor que zero, maior que 10, ou igual a zero que tamb�m pode ser uma letre
				{																										//se for
					fflush(stdin);
					system("cls");																						//a tela de visualiza��o pe limpa
					printf("\n           +----+---+---+---+---+---+---+---+---+---+----+\n");          					//essa mensagem � exibida
					printf("           |                Jogada inv�lida              |\n           | Por favor, escolha uma coluna entre 1 e 10  |");
					printf("\n           +----+---+---+---+---+---+---+---+---+---+----+\n\n");
					printf("                    +----------------------------+\n");
					printf("--------------------| Voc� j� escolheu a linha %c |------------------\n",l2);
					printf("                    +----------------------------+\n\n");									//� informado ao jogador qual � a linha que ele escolheu
					colunaOK = false;																					//retorna que um valor n�o foi atribuido com sucesso � coluna
																														//para que o la�o recomece e o jogador n�o precise escolher ou recolocar o valor da linha
					exibeJogo(jogador1.ataque);																			//exibe a matriz de ataque do jogador
				}
				else 																									//se um valor � atribuido com sucesso � linha
				{
					c-=1;																								//� subtraido 1 do valor passodo pelo jogador para a coluna, porque os �ndices de coluna na matriz v�o de 0 a 9
				colunaOK = true;																						//retorna essa vari�vel como verdadeira
				}
			}
			if(linhaOK == true && colunaOK == true)																		//se linha e coluna tem seus valores atribuidos com sucesso
			{
				if (jogador1.ataque[l][c] != 0)																			//verifica se o jogador j� atacou naquela posi��o verificando a matriz de ataque do jogador
				{																										//qualquer valor diferente de 0, pois as matrizes s�o iniciadas com zero
																														//caso sim
				system("cls");																							//a tela de visualiza��o � limpa
				printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
				printf("          |          Voc� j� atacou na casa %c%i          |\n          |          Por favor, escolha outra           |",l2,c+1);
				printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
																														//e o la�o recome�a para que o jogador possa escolher outra posi��o para atacar
				}	
				else if (jogador1.ataque[l][c] == 0)																	//Se o jogador ainda n�o atacou naquela casa
				{
					system("cls");																						//a tela de visualiza��o � limpa
					printf("\n-----------------------------SUA VEZ!---------------------------\n");						//� informado que ainda � a vez do jogador
					jogador1.ataque[l][c] = 1;																			//� atribuido 1 na matriz de ataque do jogador para as �ndices passados pelo jogador
					if (jogador1.ataque[l][c] == jogador2.jogada[l][c])													//verifica se onde o jogador atacou tem um barco na matriz de jogada do advers�rio
					{																									//o ataque e o barco tem o mesmo valor, que � 1
																														//se o jogador acertou o tiro
						printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
						printf("          |          Parab�ns, voc� acertou             |");
						printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
						jogador2.jogada[l][c] = 4;																		//� atribuido 4 a matriz de jogada do advers�rio para marcar que aquele coordenada foi atingida																
						jogador1.ataque[l][c] = 3;																		//� atribuido 3 a matriz de ataque do jogador para marcar que naquela coordenada um barco foi afundado
						qtd+=1;																
					}
					else																								//se a coordenada onde o jagodor atacou n�o tem um barco na matriz de jogada do advers�rio																				
					{																									//significa que o jogador errou o tiro
						printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
						printf("          |                 Voc� errou                  |");							//� mostrada essa mensagem para o jogador
						printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
						jogador1.ataque[l][c] = 2;																		//e atribuido 2 na coordenada na matriz de ataque do jogador para marcar que ali teve um tiro na �gua												
					}
					exibeJogo(jogador1.ataque);																			//exibe a matriz de ataque do jogador
					printf("\n-----------------O inimigo ainda tem %i barcos-----------------\n",20-qtd);				//informa para o jogador quantos barcos o advers�rio ainda tem sobrando																
					continuarJogo();																			
					if(verificaMatrizAdversario() == false)																//verifica se o advers�rio n�o perdeu para que ele possa jogar														
					{																									//se a fun��o respons�vel por isso retorna false
						jogadaAdversario();																				//fun��o que faz a jogada do advers�rio																	
						continuarJogo();																											
					} 
					else																								//se o advers�rio perdeu o jogo
					{
						break;																							//ele n�o pode jogar e sai da fun��o principal
					}
					
				}
		
			}
		} 
		else if (verificaMatrizJogador() == true)																		//se o jogador perdeu o jogo
		{
			MensagemPerdeu();																							//ele n�o joga mais e � mostrada a mensagem para ele de que ele perdeu
			break;																										//sai do la�o
			
		}
	
	}
		
	if(verificaMatrizAdversario() == true)																				//quando o la�o principal acaba por que o jogador ganhou, essa condi��o se torna verdadeira
	{
			MensagemVenceu();																							//e � exibida para o jogador a mensagem de que ele venceu
	}
		
	if(fimDeJogo == true)																								//se o la�o principal terminar
	{
		printf("Fim de jogo");																							//� fim de jogo
	}
}
	

