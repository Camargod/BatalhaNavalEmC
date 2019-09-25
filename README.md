# Batalha Naval Em C
Projeto elaborado para avaliação na disciplina de Tecnologia de Redes de Computadores, ministrada por Fábio Cabrini na Faculdade de Tecnologia de São Caetano do Sul (FATEC Antonio Russo).

Por: Amanda Vergueiro, Gabriel Camargo, Andreia Martin, Giovanna Reis e Bruno Perrote.

O PROJETO
O projeto “Batalha Naval” tem por objetivo simular, em redes, o funcionamento do clássico jogo de tabuleiro com o mesmo nome, através de uma releitura adaptada do mesmo. Basicamente, o jogo consiste em dois jogadores adversários que possuem, cada um, seu próprio tabuleiro para posicionar suas peças (barcos) e, após posiciona-las, eles devem tentar adivinhar em que casa está o barco do adversário. Aquele que eliminar primeiro todos os barcos do adversário vence. Para tal, é necessário que o jogador dê coordenadas para atirar o “míssil” e afundar o navio adversário.
Em termos de estrutura lógica, o programa é composto por quatro matrizes 10X10, totalizando 100 casas que formam o tabuleiro. A primeira matriz corresponde ao tabuleiro do jogador, a segunda ao tabuleiro do adversário, a terceira corresponde aos barcos/navios, e a ultima corresponde as posições de ataques do adversário.
Basicamente, o programa é executado através de comparações entre as matrizes. Por exemplo, se a coordenada do adversário equivale a um barco da mesma matriz do jogador, significa que o adversário acertou o barco, se não, ele acertou a água e é a vez do jogador fazer seu ataque.
Todo o programa roda através da atribuição de valores que são interpretados por uma função que desenha a matriz na tela do jogador, baseada nas posições. Além disso, foi necessário também criar uma forma de conversão de letra para números através do “sweet case”, pois o jogador vê as coordenadas das linhas e colunas como letras e números, porém o computador só processa números. 
Para o design do jogo, foi utilizado a técnica de ASCII art, conhecida pelo uso de símbolos que formam todas as figuras e palavras do jogo.

COMO FUNCIONA?
Nesse programa, em questão, o jogador joga contra uma inteligência artificial. E deve, digitar as coordenas da casa em que deseja acertar, objetivando acertar um navio inimigo. Em seguida, é a vez da IA tentar sua jogada e o processo se repete nesse ciclo. Em outras palavras, é um jogo de turnos em que o objetivo é destruir todos os barcos inimigos primeiro.

TUTORIAL
O jogo é composto por 100 casas que formam o tabuleiro e as coordenadas estão distribuídas em dez linhas e dez colunas. Tanto o jogador quanto a IA têm à sua disposição oito barcos, que devem ser posicionados à escolha do jogador em seu tabuleiro, sendo que ele não consegue ver as posições dos barcos no tabuleiro do oponente. 
Após posicionar todos os barcos, o jogo começa. O jogador, deve digitar a coordenada que deseja acertar o míssil. Em seguida, o programa irá processar e mostrar na tela se foi atingido o barco ou a água. Em seguida, é a vez da IA fazer a sua jogada e assim, segue o jogo, em um revezamento entre as jogadas do jogador e do adversário.
Ao fim, ganha quem acertar todos os oito barcos do oponente primeiro.


Project by Amanda Vergueiro, Gabriel Camargo, Andreia Martin, Giovanna Reis and Bruno Perrote.


THE PROJECT
The naval battle project aims to simulate, in networks, the classic board game's function; being an adapted re-reading. This game consists of two opposing players: each have their own board to position eight boats and, after positioning them, they must try to guess in which house the opponent's boat is. The player who eliminates all the opponent's boats first wins. This requires the player to give coordinates to fire the missile and sink the opposing ship.
In terms of logical structure, the program consists of four 10x10 matrices, totaling 100 squares that make the board up. The first matrix corresponds to the player's board, the second corresponds to the opponent's board and the third the boats. The last matrix corresponds to the opponent's attack positions.
The program is executed through comparisons between matrices. For example, if the opponent choose a coordinate equivalent to a boat existing in the other player's matrix, the opponent will hit the boat; else they'll hit the water and the next player's turn begin. 
The entire program runs by assigning values  interpreted by a function that draws the matrix on the player screen based on position. In addition, it was also necessary to create a letter-to-number conversion by "sweet care". The player sees the rows and column's coordinates as letters and numbers, but the computer can only process numbers. 
For the game's design, the ASCII art technique was used. This type of art is known by the use of symbols to form figures and words.


How does it work? 
In this program, the player plays against artificial intelligence. They enter the board's coordinates in which they want to hit, aiming an enemy ship. This process repeats itself in this cycle. In other words, it's a turn-based game where the goal is to destroy all enemy boats first. 

Tutorial 
The game consists of 100 squares, forming the board. The coordinates are distributed in ten rows and ten columns. Both the player and the AI ​​have at their disposal eight boats, which they must position at their own choice on their board. However, the player can't see his opponent's boat positions. 
After positioning all the boats, the game begins. The player must enter the wanted coordinate to aim the missile. The program will process and show on screen if a boat has been hit. The AI's turn begin afterwards and so the game goes on, taking turns between the player and the opponent's moves. 
In the end, whoever hits all eight of the opponent's boats first wins.
