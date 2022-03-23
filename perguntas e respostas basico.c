#include <stdio.h>
#include <stdlib.h>



int main()
{
	

	
	
			system("cls");
				
			int p;
			char r1;
			char r2;
			char r3;
			char a;
			char b;
			char c;
			int repeat;	
		
			primeira:
				
			printf("Qual resultado de 7 vezes 5?\n");
			printf("a)35\n");
			printf("b)45\n");
			printf("c)30\n");
			scanf(" %c", &r1);
			
			switch(r1)
				{
					case 'a':
					printf("Parabens, resposta correta!!\n\n");
					break;
					
					case 'b':
					printf("Resposta errada, o resultado eh igual a 35.\n\n");
					break;
					
					case 'c':
					printf("Resposta errada, o resultado eh igual a 35.\n\n");
					break;
					
					default :
					printf("Resposta invalida!\n\n");
				}	
				 
			printf("Proxima pergunta:\n");	 
			printf("Qual resultado de 49 dividido por 7?\n");
			printf("a)6\n");
			printf("b)9\n");
			printf("c)7\n");
			scanf(" %c", &r2);	 
			
			switch(r2)
				{
					case 'a':
					printf("Resposta errada, o resultado eh igual a 7.\n\n");
					break;
					
					case 'b':
					printf("Resposta errada, o resultado eh igual a 7.\n\n");
					break;
					
					case 'c':
					printf("Parabens, resposta correta!!\n\n");
					break;
					
					default :
					printf("Resposta invalida!\n\n");
				}
				
			printf("Proxima pergunta:\n");	 
			printf("Qual resultado de 3x = 75?\n");
			printf("a)20\n");
			printf("b)25\n");
			printf("c)32\n");
			scanf(" %c", &r3);	 
			
			switch(r3)
				{
					case 'a':
					printf("Resposta errada, o resultado eh igual a 25.\n\n");
					break;
					
					case 'b':
					printf("Parabens, resposta correta!!\n\n");
					break;
					
					case 'c':
					printf("Resposta errada, o resultado eh igual a 25.\n\n");
					break;
					
					default :
					printf("Resposta invalida!");	
				}			
			
			printf("Caso deseje jogar novamnete digite (1)\n");
			printf("Caso deseje voltar ao menu digite (2)\n");
			scanf("%d", &repeat);
			
			
			if(repeat == 1)
				{
					system("cls");
					goto primeira;
				}
				else
				{
					system("cls");
					
				}
			
		

				

	

	
	return 0;
	
	
}
