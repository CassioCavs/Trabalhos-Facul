#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int numero;

int main()
{
	menu:
		
	printf("==============================POLYSTATION===============================\n\n");
	printf("1- Perguntas e Respostas\n");
	printf("2- Advinhe o numero\n");
	printf("3- Olho de Cobra\n");
	printf("4- Sair");
	printf("\nEscolha a opcao desejada: \n");
	scanf("%d", &numero);
	fflush(stdin);
	
	switch(numero)
	{
		case 1:
			system("cls");
				
			int p, repeat;
			char p1, p2, p3, a, b, c;	
		{
			primeira:
				
			printf("Quem Escreveu Harry Potter?\n");
			printf("a)J. R. R. Tolkien\n");
			printf("b)J. K. Rowling\n");
			printf("c)George Lucas\n");
			scanf(" %c", &p1);
			
			switch(p1)
				{
					case 'a':
					printf("Voce errou!!! Nao foi dessa vez :-(\n\n");
					break;
					
					case 'b':
					printf("Voce acertou!!! Parabens :-)\n\n");
					break;
					
					case 'c':
					printf("Voce errou!!! Nao foi dessa vez :-(\n\n");
					break;
					
					default :
					printf("Resposta invalida!\n\n");
				}	
				 
			printf("Proxima pergunta:\n");	 
			printf("Qual o nome do mordomo do Batman?\n");
			printf("a)Alfred Pennyworth\n");
			printf("b)Jarvis\n");
			printf("c)Robin\n");
			scanf(" %c", &p2);	 
			
			switch(p2)
				{
					case 'a':
					printf("Voce acertou!!! Parabens :-)\n\n");
					break;
					
					case 'b':
					printf("Voce errou!!! Nao foi dessa vez :-(\n\n");
					break;
					
					case 'c':
					printf("Voce errou!!! Nao foi dessa vez :-(\n\n");
					break;
					
					default :
					printf("Resposta invalida!\n\n");
				}
				
			printf("Proxima pergunta:\n");	 
			printf("Qual o formato da bola do Quico?\n");
			printf("a)Triangular\n");
			printf("b)Circular\n");
			printf("c)Quadrada\n");
			scanf(" %c", &p3);	 
			
			switch(p3)
				{
					case 'a':
					printf("Voce errou!!! Nao foi dessa vez :-(\n\n");
					break;
					
					case 'b':
					printf("Voce errou!!! Nao foi dessa vez :-(\n\n");
					break;
					
					case 'c':
					printf("Voce acertou!!! Parabens :-)\n\n");
					break;
					
					default :
					printf("Resposta invalida!");	
				}			
			
			printf("Caso queira jogar novamente digite (1)\n");
			printf("Caso queira voltar ao menu digite (2)\n");
			scanf("%d", &repeat);
			
			
			if(repeat == 1)
				{
					system("cls");
					goto primeira;
				}
				else
				{
					system("cls");
					goto menu;
				}
					break;
		}
		case 3:
		system("cls");
		{
			int start, end, repeat, reroll1, reroll2, j1, j2;
			int dado1 = 0, dado2 = 0, dado3 = 0, dado4 = 0;
			int inicio1, total1=0, inicio2, total2=0;
			char nome1[50] , nome2[50];
			srand(time(NULL));
				
			
			comeco: printf("Instrucoes: Esse jogo precisa de dois jogadores, chame um amigo para continuar e quem chegar a 50 pontos ganha!! \n \n");
			
	

			printf("Por favor, insira o nome do jogador numero um\n");gets(nome1);// pega o nome do primeiro jogador
			printf("\nPor favor, insira o nome do jogador numero dois\n");gets(nome2); // pega o nome do segundo jogador

			start:
		
		
			/////////////////////////////////////////////////////////////////////////////jogador 1\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
			
		
			dado1 = rand() %5 + 1; //gera um numero de 0-5
			dado1++; //muda o valor para 1-6
			
			dado2 = rand() %5 + 1;
			dado2++;
			
			inicio1 = total1; // transforma o inicio em total
			
			printf("voce eh o %s seus dados sao %d e %d \n", nome1, dado1, dado2);
			//roda os dados
			total1 += dado1 + dado2; // soma dos dados e total
			printf("o total : %d \n", total1);
			
			
			
			if(total1>=50)
			{
			printf("Parabens! Voce ganhou!");
			goto end; // vai para o final do codigo
			}
			
		    reroll1: // comeco do rodar denovo
			printf("Voce deseja rodar denovo? se sim, aperte 1:  \n");
			scanf(" %d", &j1 );
				
			if(j1 == 1)
			{
			dado1 = 0;	
			dado1 = rand() % 5 + 1; //gera um numero de 0-5
			dado1++; //muda o valor para 1-6
			dado2 = 0;
			dado2 = rand() % 5 + 1;
			dado2++;
			
			printf("voce eh o %s seus dados sao %d e %d \n", nome1, dado1, dado2);
			
			 
			 
			if(dado1 == 1 ^ dado2 == 1)
			{
				
				printf("Voce rodou 1, logo voce perdeu seu turno e os pontos acumulados no mesmo\n");
					total1 = inicio1;	
					printf("Seu total eh %d\n", total1);
				
			}
			else 
			if (dado1 == 1 && dado2 == 1)
			{
			    printf("Voce rodou olhos de cobra e perdeu todos seus pontos\n");
				     total1 = 0;
					 printf("Seu total eh %d \n\n", total1);
		
			}
			else 
			{ 
				total1 += dado1 + dado2;
				printf("Seu total eh %d \n\n", total1);
				
				if(total1>=50)
				{
				printf("Parabens! Voce ganhou!");
				goto end;
				}
				goto reroll1;
			}}
			/////////////////////////////////////////////////////////////////////////////jogador 2\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
			dado3 = 0;
			dado3 = rand() %5 + 1; 		
			dado3++; 
			
			dado4 = 0;
			dado4 = rand() %5 + 1; 
			dado4++; 
			
			inicio2 = total2;
			
			printf("voce eh o %s seus dados sao %d e %d \n", nome2, dado3, dado4);
			
			total2 += dado3 + dado4;
			
			printf("o seu total eh %d \n\n", total2);
			
			if (total2>= 50)
			{
				printf("Parabens voce ganhou!");
				total1=0, total2=0;
			 goto end;
			}
			
			reroll2:
				printf("Deseja rodar de novo? Se sim, aperte 1:  ");
				scanf(" %d", &j2);
			
			if(j2 == 1)
			{
				dado3 = rand() %5;
				dado3++;
				dado4 = rand() %5;
				dado4++;
				
				printf("voce eh %s seus dados sao %d e %d\n", nome2, dado3, dado4);
				
				if (dado3 == 1 ^ dado4 == 1){
					printf("Voce rodou 1, logo voce perdeu seu turno e os pontos acumulados no mesmo \n\n");
						total2 = inicio2;	
						printf("Seu total eh %d\n", total2);
		
				} 
				else 
				if (dado3 == 1 && dado4 == 1)
				{
					printf("Voce rodou olhos de cobra e perdeu todos seus pontos \n\n");
						total2 = 0;
						printf("Seu total eh %d \n\n", total2);
				} 
				else 
				{ 
				total2 += dado3 + dado4;
				printf("Seu total eh %d \n\n", total2);
				
				if(total2>=50)
				{
				printf("Parabens! Voce ganhou!");
				total1=0, total2=0;
				goto end;
				}
			goto reroll2;
			}}
				
			goto start;
			end:
			printf("\nVoce deseja continuar? Se sim aperte 1, se deseja voltar ao menu, aperte qualquer tecla: ");
		 	scanf("%d", &repeat);
			fflush(stdin);
			if(repeat==1)
			{
				total1=0, total2=0;
				dado1 = 0, dado2 = 0;
				dado3 = 0, dado4 = 0;
				fflush(stdin);
				system ("cls");
				
			goto comeco;
			
			}
			else
			{
				total1=0, total2=0;
				dado1 = 0, dado2 = 0;
				dado3 = 0, dado4 = 0;
				fflush(stdin);
				system ("cls");
				goto menu;
			}
		
		}
	
				system("cls");
				break;			
	

				
			case 2:
			
{
	
			int i,tentativa, numero, valortotal, voltar;
    		srand(time(NULL));
    		voltar:
			j:
       		 system("cls");
 		       printf("Tende adivinhar um numero entre 1 e 1000...\n");
				valortotal = rand() % 999;
				++valortotal;
		
			for(i=0; i < 5; i++)
			{
				printf("Insira um valor: ");
				scanf("%d", &tentativa);
				fflush(stdin);
		
			if(tentativa < valortotal)
			{
				printf("O numero sorteado eh maior \n");
			}
			else if(tentativa > valortotal)
			{
				printf("O numero sorteado eh menor \n");
			}
			else
			{
				printf("Voce acertou! \n");
				break;
			}	    
		}	
	 
		if(tentativa != valortotal)
	{
		printf("O valor era %d \n", valortotal);
		
	}
	printf("\nVoce deseja continuar? Se sim aperte 1, se deseja voltar ao menu, aperte qualquer tecla: ");
    scanf("%d", &voltar);
	fflush(stdin);
	if(voltar == 1)
	{
		system("cls");
		goto j;
	}
	else
	{
		system("cls");
		goto menu;
	}
}
		break;
				
			case 4:
				printf("obrigado por jogar!! :)");
				exit( 0 );
					
			default:
			system("cls");
			printf("opcao invalida\n");
		}
		
		system("pause");
		
		return 0;
		
	
}
