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
struct campo jogador2;                               //adversário

void iniciaJogo()									//inicia os tabuleiros e preenche com zeros
{
	memset(&jogador1.jogada,0,100);					//matriz do jogador
	memset(&jogador1.ataque,0,100);					//matriz do jogador para atacar o adversário
	memset(&jogador2.jogada,0,100);					//matriz do adversario
	memset(&jogador2.ataque,0,100);					//matriz do adversario para atacar o jogador
}
void continuarJogo()											//pausa o programa e só continua quando o jogador pressiona enter
{
	char k = 0;
	while(k == 0)												//esse laço mantém o programa em um loop enquanto aguarda que algum valor seja atribuido à variável k
	{												
		printf("\nAperte enter para continuar.");
		fflush(stdin);
		scanf("%c", &k);
	}
	if(k != 0)														//assim que algum valor é atribuido à variável k, o loop termina e a janela de visualização é limpa
	{												
		system("cls");		
	}

}

void exibeJogo(int tabuleiro[10][10])                              //essa função exibe a matriz colocada como parâmetro para o jogador
{
	int contl,contc,contc2;
	char letra;
	for(contl=0;contl<=9;contl++)									//o contador desse loop é usado como índice para indicar a linha que será printada primeiro
	{
		if(contl==0)												//primeiro é printada na tela de visualização os números de cada coluna
		{
			printf("\n");
			printf("    |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10 |");
		}
		switch(contl)                                               //dependendo do valor do contador, é printada  a linha correspondente
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
		for(contc=0;contc<=9;contc++)                                           //o contador desse loop é usado como índice para definir qual coluna será printada
		{                                                                       //juntando esse dois loops, é printado linha por linha, e a próxima linha só é pritada quando todas as suas colunas já foram printadas
			if(contc==0)                                                       
			{
				printf(" %c  |",letra);                                         //primeiro é printado a letra correspondete à linha do índice
			}
			if(tabuleiro[contl][contc] == 1)                                    //quando os contadores dos loops, que estão sendo usados como índice, correspondem a uma coordenada na matriz
			{																	//que equivale a 1, então é printado um barco na matriz
				printf(" <^> |");
			}
			else if (tabuleiro[contl][contc] == 2)                              //se os índices correspodem a um 2
			{																	//é printado água na matriz, de que o tiro foi na água
				printf("~ ~ ~|");
			}
			else if (tabuleiro[contl][contc] == 0)                              //se equivale a zero, então a cada fica em branco
			{																	//pois zero equivale a um espaço em branco na matriz
				printf("     |");
			}
			else if (tabuleiro[contl][contc] == 3)                             //se equivale a um 3, então é printado um X, de que o barco naquela coordenada foi atingido
			{
				printf("  X  |");
			}
		}
			
	}
	printf("\n    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n\n");
}
void MatrizAdversario(){                                                                //essa função preenche a matriz do adversário com barcos em coordenadas aleatórias

	srand(time(NULL));																	//esse comando gera uma "semente" a partir da hora na placa da mãe do computador para que os números aleatórios sejam gerados
	int l,c,i;
	for(i=1;i<=20;i++)																	//definindo a quantidade de vezes que o loop ocorre, também é definido a quantidade de barcos que são colocados
	{
		l = rand()%10;																	//gera um número aleatório que vai de 0 a 9 que servirá como índice da matriz para linha
		c = rand()%10;																	//e esse como índice da coluna
		
		if (jogador2.jogada[l][c] == 1)													//essa condição verifica se a posição da matriz indica pelos índices já possue um barco nela
		{                                												//já que barco equivale a 1 na matriz
			i = i-1;																	//se já ouver um barco dessa posição, é subtraido 1 do contador do loop para que o número total de barcos a ser colocado se mantenha
		}
		else if(jogador2.jogada[l][c] == 0)												//caso a posição na matriz indicada pelos índices não tenha um barco nela, é colocado um barco nela
		{
			jogador2.jogada[l][c] = 1;													//os barcos na matriz são representados por 1, por isso é atribuido 1 àquele local na matriz
		}
	}
}
void MatrizJogador(void)																//função para o usuário fazer as jogadas
{ 
  setlocale(LC_ALL, "Portuguese");														//função que imprime as letras com acentos que tem no Portugûes
  int l,c,i,s;
  iniciaJogo();																			//função que preenche as matrizes com zero
  char l2;
  bool colunaOK = true, linhaOK = true;													
  for(i=1;i<=20;i++)																	//o número de vezes que o loop ocorre, é o número de barcos que serão colocados em jogo
  {
  	if(linhaOK == true && colunaOK == true)												//se um número tiver sido atribuido com sucesso aos índices de linha e coluna
	{
		printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
		printf("          |    Escolha onde deseja colocar os barcos    |");            //é exibida essa mensagem e a função recomeça desde o início
		printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
		exibeJogo(jogador1.jogada);														//função responsável por exibir a matiz do jogador
	}
  	if(colunaOK == true)																//essa condição verifica se um valor foi atribuido com sucesso para o índice de coluna
	{                                                                                   //se sim
	  	printf(" ~ Escolha uma linha de A até J:");
	  	scanf("%s", &l2);                            									//jogador pode escolher uma linha entre A e J para posicionar o barco
	  	switch(l2)                                   									//atribui um valor a l, índice de linha, dependendo da letra passada pelo jogador
		          {                                  
			case 'a':                                									//se for passado A, que é a primeira linha do tabuleiro
				l = 0; 																	//l ganha o valor de 0, porque o valor dos índices na matriz vão de 0 a 9 e 0 é o índice da primeira linha da matriz
				linhaOK = true;  														//retorna true para essa váriável, que significa que um valor foi atribuido com sucesso ao índice da linha                           
	  			break;                              									//interrompe a função para que as outras instruções não sejam executadas
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
	  		default:															   				//caso o jogador coloque alguma letra que não esteja entre A e J
	  			system("cls");																	//o programa limpa a tela
	  			printf("\n           +----+---+---+---+---+---+---+---+---+---+----+\n");		//exibe essa mensagem
	  			printf("           |                 Jogada inválida             |          \n           |   Por favor escolha uma letra entre A e J   |\n");
	  			printf("           +----+---+---+---+---+---+---+---+---+---+----+\n");
	  			linhaOK = false;																//retorna que um valor não foi atribuido com sucesso a linha, 
																								//para que o jogador não possa escolher o valor da coluna imediatamente e escolha outra linha
	  			exibeJogo(jogador1.jogada);														//exibe a matriz do jogador
	  			if (i>1)																		//é descontado 1 do contador do loop se i for maior que um
			  	{
	  				i = i-1;
		  		}
				else																			//e mantido como 1 se i=1
				{																				//para que o número de barcos a serem colocados não seja alterado
		  		i = 1;
				}
				break;                        													
		}
			
	}
		
	if (linhaOK == true)												            			//se um valor foi atribuido com sucesso ao índice da linha, então o jogador pode escolher o índice da  coluna
	{																	         				//que será o índice da matriz que indica qual a coordenada da coluna
		printf(" ~ Escolha uma coluna entre 1 e 10:");
		scanf("%i",&c);
		if (c<0 || c>10 || c==0)												          		//verifica se o valor que o jogador passo é menor que zero, maior que 10 ou igual a zero, que também poderia ser uma letra
		{																						//se esse for o caso
			fflush(stdin);
			system("cls");                                          			   				//a tela de visualização é limpa
			printf("\n           +----+---+---+---+---+---+---+---+---+---+----+\n");          	//essa mensagem é exibida
			printf("           |                Jogada inválida              |\n           | Por favor, escolha uma coluna entre 1 e 10  |");
			printf("\n           +----+---+---+---+---+---+---+---+---+---+----+\n\n");
			printf("                    +----------------------------+\n");
			printf("--------------------| Você já escolheu a linha %c |------------------\n",l2);
			printf("                    +----------------------------+\n\n");					//informa para o jogador qual foi a linha que ele já escolheu
			exibeJogo(jogador1.jogada);															//exibe a matriz do jogador
			colunaOK = false;									 								//retorna que um valor à coluna não foi atribuido com sucesso, assim o jogador só escolhe a coluna quando o loop recomeçar
			if (i>1)
			{																					//é descontado 1 do contador do loop se i for maior que um
				i = i-1;
			}
			else																				//e é mantido o valor de 1 se i for igual a 1
			{																					//isso para que o número de barcos a ser colocado não se altere
				i = 1;																																								
			}
		}
		else																					//se o número escolhido pelo jogador foi 0<c<=10
		{
			c-=1;																				//então é subtraido um desse número, porque o índice da matriz vai de 0 a 9
			colunaOK = true;																	//retorna que um valor foi atribuido com sucesso à coluna
		}
			
	}
	if(linhaOK == true && colunaOK == true)														//linha e coluna tem seus valores atribuidos com sucesso
	{
		if (jogador1.jogada[l][c] == 1)															//verifica se os índices passados já não tem um barco atribuido a eles
		{																						//caso tenho
																					
			system("cls");																		//a tela de visualização é apagada
			printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");			//é exibida essa mensagem para o jogador
			printf("          |         Você já preencheu a casa %c%i         |\n          |           Por favor, escolha outra          |",l2,c+1);
			printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
			i = i-1;																			//e subtraido 1 do loop para o jogador possa escolher outra posição para o barco
																								//sem que seja descontado um barco do número total, já que esse não foi colocado
		}
		else if(jogador1.jogada[l][c] == 0)														//se não houver nenhum barco atibuido ao índice passado
		{
			system("cls");																		// a tela de visualização é limpa
			printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
			printf("          |       Você colocou seu barco na casa %c%i     |",l2,c+1);		//é informado ao jogador onde ele posicionou o barco
			printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
			jogador1.jogada[l][c] = 1;															//é atribuido o barco àquela posição na matriz como 1
			exibeJogo(jogador1.jogada);															//exibe a matriz do jogador
			printf("             +----------------------------------------+\n");
			printf("-------------| Você ainda pode posicionar %i barco(s) |-------------\n",20-i);
			printf("             +----------------------------------------+\n");	
			continuarJogo();																	//pausa o jogo até o jogador pressionar enter
		}
		
	}	
  }
}

bool verificaMatrizJogador()																	//essa função verifica se o jogador perdeu a partida								
{
	bool fimDeJogo;
	int qtd = 0;
	int contl,contc;
	for(contl=0;contl<=9;contl++)																//o contador dessa loop é usado como índice de linha para varrer todas as linhas da matriz
	{
		for(contc=0;contc<=9;contc++)															//o contador desse loop é usado como índice de coluna para varrer a matriz
		{																						//assim cada linha tem todas as suas colunas varridas antes da próxima ser conferida
			
			if(jogador1.jogada[contl][contc] == 1)												//essa condição verifica se a coordenada não tem um barco nela na matriz do jogador
			{
					fimDeJogo = false;															//se tiver, retorna que o jogo ainda não acabou
					break;																		//e o laço é interrompido
			} 
			else if (jogador1.jogada[contc][contl] == 3)										//essa condição verifica se houve um barco atingido naquela coordenada
			{																					//caso a condição se cima não seja verdadeira
				qtd += 1;																		//para cada barco atindigo, é incrementado 1 à variável qtd
				if (qtd >= 20)																	//quando a função contabiliza que 20 barcos foram atingidos
				{
					fimDeJogo = true;															//ele retorna que o jogo acabou															
					break;																		//e interrope o loop
				}
			}
		}
		
	}
	return fimDeJogo; 																			//essa função retorna a variável fimDeJogo                                                                 
}

bool verificaMatrizAdversario()    																//essa função verifica se o adversário perdeu                                         
{
	bool fimDeJogo;
	int qtd = 0;
	int contl,contc;
	for(contl=0;contl<=9;contl++) 																//o contador dessa loop é usado como índice de linha para varrer todas as linhas da matriz                                         
	{
		for(contc=0;contc<=9;contc++)															//o contador desse loop é usado como índice de coluna para varrer a matriz								
		{																						//assim cada linha tem todas as suas colunas varridas antes da próxima ser conferida
			if(jogador2.jogada[contl][contc] == 1)												//essa condição verifica se a coordenada não tem um barco nela na matriz do adversário
			{
					fimDeJogo = false;															//se tiver, retorna que o jogo ainda não acabou
					break;																		//e o laço é interrompido
			} 
			else if (jogador2.jogada[contc][contl] == 3)										//essa condição verifica se houve um barco atingido naquela coordenada
			{																					//caso a condição se cima não seja verdadeira
				qtd += 1;																		//para cada barco atindigo, é incrementado 1 à variável qtd
				if (qtd >= 20)																	//quando a função contabiliza que 20 barcos foram atingidos
				{
					fimDeJogo = true;															//ele retorna que o jogo acabou															
					break;																		//e interrope o loop
				}
			}
		}
		
	}
	return fimDeJogo;																			//essa função retorna a variável fimDeJogo 
}

void jogadaAdversario()																			//essa função faz uma jogada aleatória para atacar os barcos da matriz do jogador											
{
	int l,c;
	char l2;
	bool verificaJogada = false;
	srand(time(NULL));																		
	while(verificaJogada == false){																//essa condição verifica a função já fez alguma jogada na coordenada definida pelos índices															
		l = rand()%10;																			//gera um número aleatório entre 1 e 9 que será o índice da linha																		
		c = rand()%10;																			//gera um número aleatório entre 1 e 9 que será o índice da coluna
		jogador2.ataque[l][c] = 1;																//atribui o valor 1 para a coordenda definida pelos índices na matriz de ataque do inimigo		
																								
		printf("\n-----------------------JOGADA DO ADVERSÁRIO---------------------\n");				
		if (jogador2.ataque[l][c] == jogador1.jogada[l][c])										//como o valor dos barcos na matriz do jogador e do adversário é 1									
		{																						//essa condição verifica se na coordenada que o adversário está atacando não tem um barco na mesma posição na matriz do jogador, se essa condição for verdadeira							
			switch(l)																			//depende do valor de l, índice da linha, esse bloco de instruções troca ele pela letra correspondente à linha																		
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
			printf("          |  O seu barco da coordenada %c%i foi atingido  |",l2,c+1);		//a condição sendo verdadeira, é informado ao jogador qual barco foi atingido
			printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
			jogador1.jogada[l][c] = 3;															//a coordenada onde estava o barco que foi atingido recebe o valor 3
			jogador2.ataque[l][c] = 4;															//a coordendada na matriz de ataque do adversário recebe 4 para marcar que ele já fez uma jogada naquela coordenada
			verificaJogada = true;
		}
		else if (jogador2.ataque[l][c]!=jogador1.jogada[l][c])									//se o valor da coordenada de ataca do adversário for diferente do valor na mesma coordenada na matriz do jogador
		{
			if(jogador2.ataque[l][c] == 4)														//verifica se o adversário já fez alguma jogada naquela coordenada										
			{
				verificaJogada = false;															//se sim, retorna essa variável como falsa para o laço recomeçar e outra coordenada ser gerada
			}
			else																				//caso o adversário ainda não tenha jogado naquela coordenada
			{																					//significa que o adversário errou o tiro, já que o valor na coordenada de ataque do adversário é diferente do valor na mesma coordenada na matriz do jogador
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
				printf("          |           O inimigo errou o tiro            |\n          |           Ele atirou na casa %c%i             |",l2,c+1);  //é informado ao jogador que o adversário errou o tiro e onde foi que o adversário atirou
				printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
				jogador1.jogada[l][c] = 2;														//matriz do jogador recebe um dois nessa coordenada, pois significa que foi tira na água	
				jogador2.ataque[l][c] = 4;														//matriz de ataque do adversário recebe 4 para marcar que ele já fe uma jogada naquela coordenada
				verificaJogada = true;															//variável recebe valor de true para sair do laço
			}
		}																
	}
	exibeJogo(jogador1.jogada);																	//exibe a matriz do jogador para o jogador																	
}

void MensagemPerdeu()																			//essa função exibe a mensagem para o jogador de que ele perdeu
{
	printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
	printf("          |                  Você perdeu                |");
	printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");	
}

void MensagemVenceu()																			//essa função exibe a mensagem ara o jogador de que ele ganhou
{
	printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
	printf("          |                  Você ganhou                |");
	printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");	
}

void main(void)																					//função principal
{
	MatrizJogador();																			//chamada da função que permite ao jogador posicionar seus barcos
	MatrizAdversario();																			//chamada para a função que preenche a matriz do adversário com barcos em posições aleatórioas
	char l2;
	int l,c,qtd = 0;
	bool fimDeJogo = false, colunaOK = true, linhaOK = true;
	system("cls");																				//limpa a tela de visualização
	printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
	printf("          |             Hora de comecar! :D             |");
	printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
	while(fimDeJogo == false)																		
	{
		if (verificaMatrizJogador() == false)																		//verifica se o jogador não perdeu a partida
		{																											//se a função que faz essa veririfcação retorna false																									
			if(colunaOK == true && linhaOK == true)																	//se os valores atribuidos à coluna e à linha estiverem ok
			{
				printf("\n------------------------------SUA VEZ!----------------------------\n");					//é exibida  a mensagem ao jogador que é a vez dele
				exibeJogo(jogador1.ataque);																			//exibe a matriz de ataque do jogador
				printf("\n");
			}
			if(colunaOK == true)																					//se um valor tiver sido atribuido com sucesso à coluna, o jogador pode escolher a linha
			{
				printf(" ~ Escolha uma linha:");
				fflush(stdin);
				scanf("%c", &l2);
				switch(l2)																							//atribui um valor a l, índice de linha, dependendo da letra passada pelo jogador
				{
					case 'a':																						//se for passado A, que é a primeira linha do tabuleiro
						l = 0;																						//l ganha o valor de 0, porque o valor dos índices na matriz vão de 0 a 9 e 0 é o índice da primeira linha da matriz
						linhaOK = true;																				//retorna que um valor foi atribuido à linha com sucesso
						break;																						//interrompe o bloco de intrução para que as outras intruções do bloco não sejam executadas
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
						default:																						//se o jogador passar uma letra que não esteja entre A e J
						system("cls");																					// a tela de visualização é limpa
		  				printf("\n           +----+---+---+---+---+---+---+---+---+---+----+\n");						//exibe essa mensagem
		  				printf("           |                 Jogada inválida             |          \n           |   Por favor escolha uma letra entre A e J   |\n");
		  				printf("           +----+---+---+---+---+---+---+---+---+---+----+\n");
		  				linhaOK = false;																				//retorna que um valor não foi atribuido com sucesso à linha
		  																												//assim o laço continua sem o jogador escolher uma coluna e, assim que o laço recomeça, o jogador pode escolher um novo valor pra linha
		  				exibeJogo(jogador1.ataque);																		//exibe a matriz de ataque do jogador
					
				}
			}
			if(linhaOK == true)																							//se um valor tiver sido atribuido com sucesso à linha, o jogador pode escolher a coluna
			{
				printf(" ~ Escolha o número da coluna:");
				scanf("%i", &c);																						
				if (c<0 || c>10 || c==0)																				//verifica se o valor que o jogador passou é menor que zero, maior que 10, ou igual a zero que também pode ser uma letre
				{																										//se for
					fflush(stdin);
					system("cls");																						//a tela de visualização pe limpa
					printf("\n           +----+---+---+---+---+---+---+---+---+---+----+\n");          					//essa mensagem é exibida
					printf("           |                Jogada inválida              |\n           | Por favor, escolha uma coluna entre 1 e 10  |");
					printf("\n           +----+---+---+---+---+---+---+---+---+---+----+\n\n");
					printf("                    +----------------------------+\n");
					printf("--------------------| Você já escolheu a linha %c |------------------\n",l2);
					printf("                    +----------------------------+\n\n");									//é informado ao jogador qual é a linha que ele escolheu
					colunaOK = false;																					//retorna que um valor não foi atribuido com sucesso à coluna
																														//para que o laço recomece e o jogador não precise escolher ou recolocar o valor da linha
					exibeJogo(jogador1.ataque);																			//exibe a matriz de ataque do jogador
				}
				else 																									//se um valor é atribuido com sucesso à linha
				{
					c-=1;																								//é subtraido 1 do valor passodo pelo jogador para a coluna, porque os índices de coluna na matriz vão de 0 a 9
				colunaOK = true;																						//retorna essa variável como verdadeira
				}
			}
			if(linhaOK == true && colunaOK == true)																		//se linha e coluna tem seus valores atribuidos com sucesso
			{
				if (jogador1.ataque[l][c] != 0)																			//verifica se o jogador já atacou naquela posição verificando a matriz de ataque do jogador
				{																										//qualquer valor diferente de 0, pois as matrizes são iniciadas com zero
																														//caso sim
				system("cls");																							//a tela de visualização é limpa
				printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
				printf("          |          Você já atacou na casa %c%i          |\n          |          Por favor, escolha outra           |",l2,c+1);
				printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
																														//e o laço recomeça para que o jogador possa escolher outra posição para atacar
				}	
				else if (jogador1.ataque[l][c] == 0)																	//Se o jogador ainda não atacou naquela casa
				{
					system("cls");																						//a tela de visualização é limpa
					printf("\n-----------------------------SUA VEZ!---------------------------\n");						//é informado que ainda é a vez do jogador
					jogador1.ataque[l][c] = 1;																			//é atribuido 1 na matriz de ataque do jogador para as índices passados pelo jogador
					if (jogador1.ataque[l][c] == jogador2.jogada[l][c])													//verifica se onde o jogador atacou tem um barco na matriz de jogada do adversário
					{																									//o ataque e o barco tem o mesmo valor, que é 1
																														//se o jogador acertou o tiro
						printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
						printf("          |          Parabéns, você acertou             |");
						printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
						jogador2.jogada[l][c] = 4;																		//é atribuido 4 a matriz de jogada do adversário para marcar que aquele coordenada foi atingida																
						jogador1.ataque[l][c] = 3;																		//é atribuido 3 a matriz de ataque do jogador para marcar que naquela coordenada um barco foi afundado
						qtd+=1;																
					}
					else																								//se a coordenada onde o jagodor atacou não tem um barco na matriz de jogada do adversário																				
					{																									//significa que o jogador errou o tiro
						printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
						printf("          |                 Você errou                  |");							//é mostrada essa mensagem para o jogador
						printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
						jogador1.ataque[l][c] = 2;																		//e atribuido 2 na coordenada na matriz de ataque do jogador para marcar que ali teve um tiro na água												
					}
					exibeJogo(jogador1.ataque);																			//exibe a matriz de ataque do jogador
					printf("\n-----------------O inimigo ainda tem %i barcos-----------------\n",20-qtd);				//informa para o jogador quantos barcos o adversário ainda tem sobrando																
					continuarJogo();																			
					if(verificaMatrizAdversario() == false)																//verifica se o adversário não perdeu para que ele possa jogar														
					{																									//se a função responsável por isso retorna false
						jogadaAdversario();																				//função que faz a jogada do adversário																	
						continuarJogo();																											
					} 
					else																								//se o adversário perdeu o jogo
					{
						break;																							//ele não pode jogar e sai da função principal
					}
					
				}
		
			}
		} 
		else if (verificaMatrizJogador() == true)																		//se o jogador perdeu o jogo
		{
			MensagemPerdeu();																							//ele não joga mais e é mostrada a mensagem para ele de que ele perdeu
			break;																										//sai do laço
			
		}
	
	}
		
	if(verificaMatrizAdversario() == true)																				//quando o laço principal acaba por que o jogador ganhou, essa condição se torna verdadeira
	{
			MensagemVenceu();																							//e é exibida para o jogador a mensagem de que ele venceu
	}
		
	if(fimDeJogo == true)																								//se o laço principal terminar
	{
		printf("Fim de jogo");																							//é fim de jogo
	}
}
	

