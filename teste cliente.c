#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORTA 2000
#define LEN 4096

struct sockaddr_in remoto;
int sockfd = 0;
int atkL, atkC = 0;
char buffer[4096];

int jogCli[3];

void buildBoard()
{
	char buffer[4096];
}

struct campo
{
	int ataque[10][10];                               //matriz de ataque
	int jogada[10][10];                              //matriz de jogada
};

struct campo jogador2;                               //advers�rio

void iniciaJogoCliente()
{
    memset(&jogador2.jogada,0,100);					//matriz do adversario
	memset(&jogador2.ataque,0,100);					//matriz do adversario para atacar o jogador
    memset(&jogCli,0,3);
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

void matriz()
{
	int l,i,c;
    l = 0;
    i = 0;
    c = 0;
    char Col;
    bool linhaOK,colunaOk;
    linhaOK = false;
    colunaOk = false;
	for(i=1;i<=6;i++)																	//definindo a quantidade de vezes que o loop ocorre, tamb�m � definido a quantidade de barcos que s�o colocados
	{
		char jogAdversario [4096];
		printf("\n Digite as cordenadas do barco %d",i);

        printf("\n Escolha a linha:");
        scanf("%s",&Col);

        switch(Col)
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
            default:
                linhaOK = false;
                printf("Linha incorreta");
                break;
        }

        printf("Escolha a coluna:\n");
        scanf("%i",&c);
        c--;
        if(c <= 10 || c > 0)
        {
            colunaOk = true;
        }
        else
        {
            printf("Coluna Incorreta");
            linhaOK = false;
        }

        if(colunaOk == false)
        {
            i = i-1;
            if(i == 0)
            {
                i = 1;
            }
        }
        if(linhaOK == false)
        {
            i = i-1;
            if(i == 0)
            {
                i = 1;
            }
        }
        if (jogador2.jogada[l][c] == 1)													//essa condi��o verifica se a posi��o da matriz indica pelos �ndices j� possue um barco nela
		{                                												//j� que barco equivale a 1 na matriz
			i = i-1;
            if(i == 0)
            {
                i = 1;
            }																	//se j� ouver um barco dessa posi��o, � subtraido 1 do contador do loop para que o n�mero total de barcos a ser colocado se mantenha
		}
        else if(jogador2.jogada[l][c] == 0)												//caso a posi��o na matriz indicada pelos �ndices n�o tenha um barco nela, � colocado um barco nela
		{
			jogador2.jogada[l][c] = 1;										//os barcos na matriz s�o representados por 1, por isso � atribuido 1 �quele local na matriz
        }
        exibeJogo(jogador2.jogada);
	}
}

void jogadaCliente()																			//essa fun��o faz uma jogada aleat�ria para atacar os barcos da matriz do jogador											
{
    char l2;
    int l, c;
    bool verificaJogada = false;
    printf("\n-----------------------Seu turno de atacar---------------------\n");		
    printf("Escolha uma linha:");
    scanf("%s",&l2);	
        switch(l2)																			//depende do valor de l, �ndice da linha, esse bloco de instru��es troca ele pela letra correspondente � linha																		
        {
            case 'a':
                l = 0;
                break;
            case 'b':
                l = 1;
                break;
            case 'c':
                l = 2;
                break;
            case 'd':
                l = 3;
                break;
            case 'e':
                l = 4;
                break;
            case 'f':
                l = 5;
                break;
            case 'g':
                l = 6;
                break;
            case 'h':
                l = 7;
                break;
            case 'i':
                l = 8;
                break;
            case 'j':
                l = 9;
                break;
        }
    printf("Escolha uma coluna: ");
    scanf("%i",&c);
    jogCli[0] = l;
    jogCli[1] = c;
    c--;
    send(sockfd,jogCli, sizeof(int)*3,0);
    recv(sockfd,&jogCli,sizeof(int)*3,0);
    if (jogador2.ataque[l][c] == jogCli[2])										//como o valor dos barcos na matriz do jogador e do advers�rio � 1									
    {			
        printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
        printf("          |  O barco inimigo da coordenada %c%i foi atingido  |",l2,c+1);		//a condi��o sendo verdadeira, � informado ao jogador qual barco foi atingido
        printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
        jogador2.ataque[l][c] = 4;															//a coordendada na matriz de ataque do advers�rio recebe 4 para marcar que ele j� fez uma jogada naquela coordenada
        verificaJogada = true;
	}
		else if (jogador2.ataque[l][c]!=jogCli[2])									//se o valor da coordenada de ataca do advers�rio for diferente do valor na mesma coordenada na matriz do jogador
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
				printf("          |           Você errou o tiro            |\n          |");  //� informado ao jogador que o advers�rio errou o tiro e onde foi que o advers�rio atirou
				printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
				
                jogador2.ataque[l][c] = 4;														//matriz de ataque do advers�rio recebe 4 para marcar que ele j� fe uma jogada naquela coordenada
				verificaJogada = true;															//vari�vel recebe valor de true para sair do la�o
			}
		}
        exibeJogo(jogador2.ataque);              																																					
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
				if (qtd >= 6)																	//quando a fun��o contabiliza que 20 barcos foram atingidos
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
    recv(sockfd, jogCli, sizeof(jogCli),0);
    int l; 
    int c;
    char l2;
    l = jogCli[0];
    c = jogCli[1];
    bool verificaJogada = false;
    printf("\n-----------------------Turno Adversario---------------------\n");				
    if (jogador2.ataque[l][c] == jogCli[2])										//como o valor dos barcos na matriz do jogador e do advers�rio � 1									
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
        printf("          |  O seu barco da coordenada %c%i foi atingido  |",l2,c);		//a condi��o sendo verdadeira, � informado ao jogador qual barco foi atingido
        printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
        jogCli[2] = 3;
        jogador2.ataque[l][c] = 4;															//a coordendada na matriz de ataque do advers�rio recebe 4 para marcar que ele j� fez uma jogada naquela coordenada
        verificaJogada = true;
	}
		else if (jogador2.ataque[l][c]!=jogCli[2])									//se o valor da coordenada de ataca do advers�rio for diferente do valor na mesma coordenada na matriz do jogador
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
				jogCli[2] = 2;														//matriz do jogador recebe um dois nessa coordenada, pois significa que foi tira na �gua	
				jogador2.ataque[l][c] = 4;														//matriz de ataque do advers�rio recebe 4 para marcar que ele j� fe uma jogada naquela coordenada
				verificaJogada = true;															//vari�vel recebe valor de true para sair do la�o
			}
		send(sockfd,jogCli, sizeof(jogCli), 0);
	}	
        exibeJogo(jogador2.jogada);																	//exibe a matriz do jogador para o jogador																																
}

int main()
{

//==========================CONFIGURACOES===========================//
//==========================CONFIGURACOES===========================//

    int server;
    int slen = sizeof(remoto);
    int i = 0;
    sockfd = socket(AF_INET,SOCK_STREAM, 0);
    char msg[4096];
    char msgServidor[4096];

    if(sockfd == -1)
    {
        perror("socket ");
        exit(1);
    } 
    else 
    {
        printf("Aguarde...\n");
    }
   
    remoto.sin_family    = AF_INET;
    remoto.sin_port      = htons(PORTA);
    remoto.sin_addr.s_addr      = inet_addr("127.0.0.1");
    memset(remoto.sin_zero, 0x0, 8);

    

//==========================CONFIGURACOES===========================//
//==========================CONFIGURACOES===========================//

    connect(sockfd, (struct sockaddr*) &remoto, slen);

//==========================INICIO DO JOGO===========================//
//==========================INICIO DO JOGO===========================//

    char message[100];
    char nomeOponente[100];
    int primeiraVez = 0;

	while(1)
    {   	
        memset(buffer, 0x0, LEN);

        if(recv(sockfd, buffer, LEN,0) > 0)
        {
            if(primeiraVez == 0)
            {
                iniciaJogoCliente();
                printf("O servidor se conectou para jogar contra você!\n");
                matriz();
                strcpy(message,"Jogador 2 ja posicionou sua grid.");
                strcpy(buffer, message);
                primeiraVez++;
                send(sockfd,buffer, strlen(buffer), 0);
            } 
            else 
            {
                if(primeiraVez == 1)
                {
                    printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
                    printf("          |             Hora de comecar! :D             |");
                    printf("\n          +----+---+---+---+---+---+---+---+---+---+----+\n");
                    primeiraVez++;
                }

                jogadaCliente();
                jogadaAdversario();
                verificaMatrizAdversario();
                printf("%s\n",buffer);
                scanf("%s",buffer);
                send(sockfd,buffer, strlen(buffer), 0);
            }
        }
    
        
        

    }

	printf("Fim do programa. Socket desligado");    
    return 0;

}


