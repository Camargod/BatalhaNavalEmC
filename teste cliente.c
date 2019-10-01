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

void buildBoard(){
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
	}
}

int main()
{

//==========================CONFIGURACOES===========================//
//==========================CONFIGURACOES===========================//



    int server;
    int slen = sizeof(remoto);
    int i = 0;

    int sockfd = socket(AF_INET,SOCK_STREAM, 0);
    char buffer[4096];
    char msg[4096];
    char msgServidor[4096];

    if(sockfd == -1){
        perror("socket ");
        exit(1);
    } else {
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

    char nome[100];
    char nomeOponente[100];
    int primeiraVez = 0;

	while(1)
    {   	
        memset(buffer, 0x0, LEN);

        
        if(recv(sockfd, buffer, LEN,0) > 0)
        {
            if(primeiraVez == 0)
            {
                printf("%s se conectou para jogar contra você!\n", buffer);
                strcpy(nomeOponente, buffer);
                printf("Digite seu nome: ");
                scanf("%s",nome);
                strcpy(buffer, nome);
                primeiraVez++;
                send(sockfd,buffer, strlen(buffer), 0);
            } 
            else 
            {
                printf("Preparem-se para a BATTLESHIP: ");
                matriz();
                strcpy(buffer,"Barcos posicionados.");
                scanf("%s",buffer);
                send(sockfd,buffer, strlen(buffer), 0);
            }
        }
    
        
        

    }

	printf("Fim do programa. Socket desligado");    
    return 0;

}


