#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	
	int i,tentativa, numero, valortotal, voltar;
    srand(time(NULL));
    voltar:
    
    do{
	
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
	
	
	}while(voltar == 1);
	
		getchar();
		system("cls");
		goto voltar;
}

