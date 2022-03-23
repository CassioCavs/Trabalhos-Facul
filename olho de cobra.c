#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
//olho de cobra

void main ()
{
	int start, end, repeat, reroll1, reroll2, j1, j2;
	int dado1, dado2, dado3 = 0, dado4 = 0;
	int inicio1, total1=0, inicio2, total2=0;
	char nome1[50] , nome2[50];
	srand(time(NULL));
	///////////////menu
	menu:
	
		printf("voce escolheu os olhos de cobra \n \n");
	
	
		
		
	
	comeco: printf("Esse jogo precisa de dois jogadores, chame um amigo para continuar e quem chegar a 50 pontos ganha!! \n \n");
	
		
	
	printf("Por favor, insira o nome do jogador numero um\n");gets(nome1); // pega o nome do primeiro jogador
	
	printf("\nPor favor, insira o nome do jogador numero dois\n");gets(nome2); // pega o nome do segundo jogador
	
	start:
	/////////////////////////////////////////////////////////////////////////////jogador 1\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	

	dado1 = rand() %5; //gera um numero de 0-5
	++dado1; //muda o valor para 1-6
	
	dado2 = rand() %5;
	++dado2;
	
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
		
	dado1 = rand() % 5; //gera um numero de 0-5
	++dado1; //muda o valor para 1-6
	
	dado2 = rand() % 5;
	++dado2;
	
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
	dado3 = rand() %5; //gera um numero de 0-5
	++dado3; //muda o valor para 1-6
	
	dado4 = rand() %5; //gera um numero de 0-5
	++dado4; //muda o valor para 1-6
	
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
		dado3 = rand() % 5;
		++dado3;
		dado4 = rand() % 5;
		++dado4;
		
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
		system ("cls");
		
	goto comeco;
	
	}
	else
	{
		total1=0, total2=0;
		system ("cls");
		goto menu;
	}

}

