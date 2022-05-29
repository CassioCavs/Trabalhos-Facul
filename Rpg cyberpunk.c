#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char armas;
char armour;
int dado12;
int dado61 = 0, dado62 = 0, dado4 = 0;
int iForca = 0, iDestreza = 0, iAgilidade = 0, iConstituicao = 0;
typedef struct personagens
{
	char Nome[50];
    int Pv;
    int Forca;
    int Destreza;
    int Agilidade;
    int constituicao;
    int Xp;
    int Nivel;
    int gun;
    int prot;
} PERSONAGENS;

typedef struct stats{
	int pv;
	int dano;
	int defesa;
	int agilidade;
}inimigos;

PERSONAGENS personagens;
inimigos horik;
inimigos borg;
inimigos aelle;
inimigos rollo;
inimigos ecbert;
inimigos ragnar;

void criacao(PERSONAGENS personagens);



int main()
{
	PERSONAGENS personagens;
	criacao(personagens);
	return 0;
}

void criacao(PERSONAGENS personagens)
{
	
	srand(time(NULL));
	int dado1, dado2, dado3;
	int pontos = 15;
	printf("Digite seu nome: ");
	gets(personagens.Nome);
	
	printf("\n%s, voce tem 15 pontos para distribuir entre Forca, Destreza, Agilidade e constituicao\n", &personagens.Nome);
	printf("(Forca influencia no dado da arma pesada)\n");
	printf("(Destreza influencia no dano da arma leve)\n");
	printf("(Agilidade influencia na ordem dos turnos durante o combate)\n");
	printf("(Constituicao influencia na quantidade de P.V. e na defesa)\n\n");
	
	printf("Pontos: %d\n\n", pontos);
	printf("Quantos pontos voce quer distribuir em forca?\n");
	scanf(" %d", &personagens.Forca);
	pontos = pontos - personagens.Forca;
	printf("\nPontos: %d\n\n", pontos);
	
	printf("Quantos pontos voce quer distribuir em destreza?\n");
	scanf(" %d", &personagens.Destreza);
	pontos = pontos - personagens.Destreza;
	printf("\nPontos: %d\n\n", pontos);
	
	printf("Quantos pontos voce quer distribuir em agilidade?\n");
	scanf(" %d", &personagens.Agilidade);
	pontos = pontos - personagens.Agilidade;
	printf("\nPontos: %d\n\n", pontos);
	
	printf("Quantos pontos voce quer distribuir em constituicao?\n");
	scanf(" %d", &personagens.constituicao);
	pontos = pontos - personagens.constituicao;
	
	printf("\nCom base nos seus atributos de constituicao vamos rolar tres dados de seis lados para definir seus pontos de vida ok?\n\n");
	
	dado1 = rand() %5;
	dado1 = dado1 + 1;
	dado2 = rand() %5;
	dado2 = dado2 + 1;
	dado3 = rand() %5;
	dado3 = dado3 + 1;
	printf("O resultado dos seus dados foram %d, %d e %d\n", dado1, dado2, dado3);
	
	personagens.Pv = personagens.constituicao + dado1 + dado2 + dado3;
	
	printf("Logo, seus pontos de vida sao: %d\n\n", personagens.Pv);
	printf("Pressione 'Enter' para continuar");
	
	getchar();
	getchar();
	
	system("cls");
	printf("Com os stats distribuidos, vamos escolher sua arma:\n");
	printf("(Calculo da arma pesada: Dano + Dado de 12 Lados * 1,5 * Forca)\n");
	printf("(Calculo da arma leve: Dano + 2 Dados de 6 Lados + Dado de 4 Lados + Destreza)\n\n");
	
	printf("|A- Escudo e Espada|B- Dois Machados  |C- Arco e Flecha  |\n");
	printf("|Arma Pesada       |Arma Leve         |Arma Leve         |\n");
	printf("|Dano: 6           |Dano: 5           |Dano: 4           |\n\n");
	printf("Escolha a opcao desejada: ");
	scanf(" %c", &armas);
	
	
	switch(armas)
	{
		case 'a':
		case 'A':	
			
	        dado12 = rand() %12;
            dado12 = dado12 + 1;
	        personagens.gun = 6 + dado12 + 1.5 * personagens.Forca;
	        printf("\nVoce escolheu espada e escudo!\n");
	        printf("Seu dado foi %d, seu dano eh: %d\n\n", dado12, personagens.gun);
			break;
			
		case 'b':
		case 'B':	
				;
	            dado61 = rand() %6;
	            dado61 = dado61 + 1;
	            dado62 = rand() %6;
	            dado62 = dado62 + 1;
	            dado4 = rand() %4;
	            dado4 = dado4 + 1;
	
	            personagens.gun = 5 + dado61 + dado62 + dado4 + personagens.Destreza;
	
	            printf("\nVoce escolheu os dois machados!\n");
	            printf("Seus dados foram %d, %d e %d, seu dano eh: %d\n\n", dado61, dado62, dado4, personagens.gun);
			break;
			
		case 'c':
		case 'C':
			
	            dado61 = rand() %6;
	            dado61 = dado61 + 1;
	            dado62 = rand() %6;
	            dado62 = dado62 + 1;
	            dado4 = rand() %4;
	            dado4 = dado4 + 1;
	
	           personagens.gun = 4 + dado61 + dado62 + dado4 + personagens.Destreza;
	
	           printf("\nVoce escolheu arco e flecha!\n");
	           printf("Seus dados foram %d, %d e %d, seu dano eh: %d\n\n", dado61, dado62, dado4, personagens.gun);
			break;
			
		default:
			printf("Valor invalido");
	}
	
	printf("Pressione 'Enter' para continuar");
	
	getchar();
	getchar();
	
	system("cls");
	printf("Agora que ja esta armado, escolha sua armadura:\n");
	printf("(Calculo da defesa: Defesa da armadura + 1,5 * constituicao)\n\n");
	printf("|A- Pele de Dragao |B- Pele de Urso   |C- Pele de Lobo   |\n");
	printf("|Defesa: 7         |Defesa: 5         |Defesa: 3         |\n\n");
	printf("Escolha a opcao desejada: ");
	scanf(" %c", &armour);
	
	switch (armour)
	{
		case 'A':
		case 'a':
			personagens.prot = 7 + 1.5 * personagens.constituicao;
	        printf("\nVoce escolheu a armadura de pele de dragao!\n");
	        printf("Sua defesa total eh %d\n\n", personagens.prot);
		break;
		
		case 'b':
		case 'B':
			personagens.prot = 4 + 1.5 * personagens.constituicao;
	        printf("\nVoce escolheu a armadura de pele de urso!\n");
	        printf("Sua defesa total eh %d\n\n", personagens.prot);
		break;
		
		case 'c':
		case 'C':
			personagens.prot = 2 + 1.5 * personagens.constituicao;
	        printf("\nVoce escolheu a armadura de pele de urso!\n");
	        printf("Sua defesa total eh %d\n\n", personagens.prot);
		break;	
	}
	
	printf("Pressione 'Enter' para continuar");
	
	getchar();
	getchar();
	
	system("cls");
	printf("Tudo selecionado, seus stats sao:\n");
	printf("Nome:         %s\n", personagens.Nome);
	printf("Vida:         %d\n", personagens.Pv);
	printf("Forca:        %d\n", personagens.Forca);
	printf("Agilidade:    %d\n", personagens.Agilidade);
	printf("Destreza:     %d\n", personagens.Destreza);
	printf("Constituicao: %d\n", personagens.constituicao);
	printf("Dano:         %d\n", personagens.gun);
	printf("Defesa:       %d\n\n", personagens.prot);
	
	printf("Pressione 'Enter' para continuar");
	
	getchar();
	
	horik.pv = 7;
	horik.dano = 8;
	horik.defesa = 15;
	horik.agilidade = 4;
	
	borg.pv = 10;
	borg.dano = 10;
	borg.defesa = 15;
	borg.agilidade = 3;
		
	aelle.pv = 10;
	aelle.dano = 10;
	aelle.defesa = 14;
	aelle.agilidade = 4;
	
	rollo.pv = 15;
	rollo.dano = 15;
	rollo.defesa = 20;
	rollo.agilidade = 7;
	
	ecbert.pv = 15;
	ecbert.dano = 17;
	ecbert.defesa = 19;
	ecbert.agilidade = 7;
	
	ragnar.pv = 37;
	ragnar.dano = 36;
	ragnar.defesa = 30;
	ragnar.agilidade = 8;
	
	int batalha, defesa2, defesa1, pv1, pv2;
	int i, a, op;
	
	pv1 = personagens.Pv;
	defesa1 = personagens.prot;
	srand(time(NULL));
	i = rand () %3;
	
	system("cls");
	
	if(i == 0)
	{
		defesa2 = horik.defesa;
		pv2 = horik.pv;
		printf("O Seu oponente eh Horik\n\n");
		do{
			horik.defesa = defesa2;
			personagens.prot = defesa1;
			a = rand()%3;
			if(personagens.Agilidade >= horik.agilidade){
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", horik.pv);
				printf("Dano:      %d\n", horik.dano);
				printf("Defesa:    %d\n", horik.defesa);
				printf("Agilidade: %d\n\n", horik.agilidade);
				printf("O que voce fara a seguir?:\n\n");
				printf("Os seus stats sao:\n");
				printf("PV:        %d\n", personagens.Pv);
				printf("Dano:      %d\n", personagens.gun);
				printf("Defesa:    %d\n", personagens.prot);
				printf("Agilidade: %d\n\n", personagens.Agilidade);
				printf("|1 - Atacar    |\n");
				printf("|2 - Defender  |\n");
				printf("|3 - Usar Pocao|\n");
				printf("Escolha a opcao desejada: ");
				scanf(" %d", &op);
				switch(op){
					case 1:
						if(personagens.gun > horik.defesa){
						horik.pv = horik.pv - (personagens.gun - horik.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", horik.pv);
						}
						else if(personagens.gun <= horik.defesa){
							horik.pv = horik.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", borg.pv);
						}
						break;
						
					case 2:
						personagens.prot = personagens.prot * 2;
						printf("Voce se defendeu, sua defesa dobrou!\n\n");
						break;
					
					case 3:
						dado1 = rand()%6+1;
						dado2 = rand()%6+1;
						dado3 = rand()%6+1;
						if(personagens.Pv == pv1){
							printf("Sua vida ja esta cheia\n\n");
						}
						else if(personagens.Pv <= 0){
							personagens.Pv = 0;
						}
						else{
							personagens.Pv = personagens.Pv + dado1 + dado2 + dado3;
							if(personagens.Pv >= pv1){
								personagens.Pv = pv1;
								printf("\nVamos rolar 3 dados para calcular sua pocao\n\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
							else{
								printf("\nVamos rolar 3 dados para calcular sua pocao\n\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
						}
						break;
					
					default:
						printf("Valor Invalido!\n");
						break;
				}
				if(a == 0){
					if(horik.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (horik.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(horik.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					horik.defesa = horik.defesa * 2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(horik.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(horik.pv <= 0){
						horik.pv = 0;
					}
					else{
						horik.pv = horik.pv + dado1 + dado2 + dado3;
						if(horik.pv >= pv2){
							horik.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", horik.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", horik.pv);
						}
					}
				}
			}	
			else if(horik.agilidade > personagens.Agilidade){
				a = rand()%3;
				if(a == 0){
					if(horik.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (horik.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(horik.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					horik.defesa = defesa2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(horik.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(horik.pv <= 0){
						horik.pv = 0;
					}
					else{
						horik.pv = horik.pv + dado1 + dado2 + dado3;
						if(horik.pv >= pv2){
							horik.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", horik.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", horik.pv);
						}
					}
				}
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", horik.pv);
				printf("Dano:      %d\n", horik.dano);
				printf("Defesa:    %d\n", horik.defesa);
				printf("Agilidade: %d\n\n", horik.agilidade);
				printf("Os seus stats sao:\n");
				printf("PV:        %d\n", personagens.Pv);
				printf("Dano:      %d\n", personagens.gun);
				printf("Defesa:    %d\n", personagens.prot);
				printf("Agilidade: %d\n\n", personagens.Agilidade);
				printf("O que voce fara a seguir?:\n\n");
				printf("|1 - Atacar    |\n");
				printf("|2 - Defender  |\n");
				printf("|3 - Usar Pocao|\n");
				printf("Escolha a opcao desejada: ");
				scanf(" %d", &op);
				switch(op){
					case 1:
						if(personagens.gun > horik.defesa){
						horik.pv = horik.pv - (personagens.gun - horik.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", horik.pv);
						}
						else if(personagens.gun <= horik.defesa);{
							horik.pv = horik.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", borg.pv);
						}
						break;
						
					case 2:
						personagens.prot = personagens.prot * 2;
						printf("Voce se defendeu, sua defesa dobrou!\n\n");
						break;
					
					case 3:
						dado1 = rand()%6+1;
						dado2 = rand()%6+1;
						dado3 = rand()%6+1;
						
						if(personagens.Pv == pv1){
							printf("Sua vida ja esta cheia");
						}
						else if(personagens.Pv <= 0){
							personagens.Pv = 0;
						}
						else{
							personagens.Pv = personagens.Pv + dado1 + dado2 + dado3;
							if(personagens.Pv >= pv1){
								personagens.Pv = pv1;
								printf("\nVamos rolar 3 dados para calcular sua pocao\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
							else{
								printf("\nVamos rolar 3 dados para calcular sua pocao\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
						}
						break;
					
					default:
						printf("Valor Invalido!\n");
						break;
				}
		    }
		}while(personagens.Pv > 0 && horik.pv > 0);
		if(personagens.Pv <= 0)
		{
			printf("fim de jogo");
			exit(0);
		}
		else if(horik.pv <= 0)
		{
		    int pontos = 5;
			printf("\nvoce ganhou\n");
		    printf("Pontos: %d\n\n", pontos);
	        printf("Quantos pontos voce quer distribuir em forca?\n");
	        scanf(" %d", &iForca);
	        pontos = pontos - iForca;
	        printf("\nPontos: %d\n\n", pontos);
	
	        printf("Quantos pontos voce quer distribuir em destreza?\n");
	        scanf(" %d", &iDestreza);
	        pontos = pontos - iDestreza;
	        printf("\nPontos: %d\n\n", pontos);
	
	        printf("Quantos pontos voce quer distribuir em agilidade?\n");
	        scanf(" %d", &iAgilidade);
	        pontos = pontos - iAgilidade;
	        printf("\nPontos: %d\n\n", pontos);
	
	       printf("Quantos pontos voce quer distribuir em constituicao?\n");
	       scanf(" %d", &iConstituicao);
	       pontos = pontos - iConstituicao;
	       
	       personagens.Forca = personagens.Forca + iForca;
	       personagens.Destreza = personagens.Destreza + iDestreza;
	       personagens.Agilidade = personagens.Agilidade + iAgilidade;
	       personagens.constituicao = personagens.constituicao + iConstituicao;
	       personagens.Pv = personagens.Pv + personagens.constituicao;
			printf("\nSeus novos stats sao: \n");
			
			printf("\nForca: %d", personagens.Forca);
			printf("\nDestreza: %d", personagens.Destreza);
			printf("\nAgilidade: %d", personagens.Agilidade);
			printf("\nConstituicao: %d", personagens.constituicao);
			printf("\nPontos de vida: %d", personagens.Pv);

			printf("\n\nAgora escolha uma arma: ");
			printf("\n|A- Espada Longa|B- Macahado Leviantan  |C- Arco de atreus  |\n");
	        printf("\n|Arma Pesada       |Arma Leve         |Arma Leve         |\n");
	        printf("\n|Dano: 12           |Dano: 10           |Dano: 8           |\n\n");
	        printf("Escolha a opcao desejada: ");
	        scanf(" %c", &armas);
	
	
	        switch(armas)
	    {
		case 'a':
		case 'A':	
			
	        dado12 = rand() %12;
            dado12 = dado12 + 1;
	        personagens.gun = 12 + dado12 + 1.5 * personagens.Forca;
	        printf("\nVoce escolheu Espada Longa!\n");
	        printf("Seu dado foi %d, seu dano eh: %d\n\n", dado12, personagens.gun);
			break;
			
		case 'b':
		case 'B':	
				;
	            dado61 = rand() %6;
	            dado61 = dado61 + 1;
	            dado62 = rand() %6;
	            dado62 = dado62 + 1;
	            dado4 = rand() %4;
	            dado4 = dado4 + 1;
	
	            personagens.gun = 10 + dado61 + dado62 + dado4 + personagens.Destreza;
	
	            printf("\nVoce escolheu os Machado Leviatan\n");
	            printf("Seus dados foram %d, %d e %d, seu dano eh: %d\n\n", dado61, dado62, dado4, personagens.gun);
			break;
			
		case 'c':
		case 'C':
			
	            dado61 = rand() %6;
	            dado61 = dado61 + 1;
	            dado62 = rand() %6;
	            dado62 = dado62 + 1;
	            dado4 = rand() %4;
	            dado4 = dado4 + 1;
	
	           personagens.gun = 8 + dado61 + dado62 + dado4 + personagens.Destreza;
	
	           printf("\nVoce escolheu arco de atreus!\n");
	           printf("Seus dados foram %d, %d e %d, seu dano eh: %d\n\n", dado61, dado62, dado4, personagens.gun);
			break;
			
		default:
			printf("Valor invalido");
	}
		}
	}
	else if(i == 1)
	{
		defesa2 = borg.defesa;
		pv2 = borg.pv;
		printf("O Seu oponente eh Jael Borg\n\n");
		do{
			borg.defesa = defesa2;
			personagens.prot = defesa1;
			a = rand()%3;
			if(personagens.Agilidade >= borg.agilidade){
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", borg.pv);
				printf("Dano:      %d\n", borg.dano);
				printf("Defesa:    %d\n", borg.defesa);
				printf("Agilidade: %d\n\n", borg.agilidade);
				printf("Os seus stats sao:\n");
				printf("PV:        %d\n", personagens.Pv);
				printf("Dano:      %d\n", personagens.gun);
				printf("Defesa:    %d\n", personagens.prot);
				printf("Agilidade: %d\n\n", personagens.Agilidade);
				printf("O que voce fara a seguir?:\n\n");
				printf("|1 - Atacar    |\n");
				printf("|2 - Defender  |\n");
				printf("|3 - Usar Pocao|\n");
				printf("Escolha a opcao desejada: ");
				scanf(" %d", &op);
				switch(op){
					case 1:
						if(personagens.gun > borg.defesa){
						borg.pv = borg.pv - (personagens.gun - borg.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", borg.pv);
						}
						else if(personagens.gun <= borg.defesa){
							borg.pv = borg.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", borg.pv);
						}
						break;
						
					case 2:
						personagens.prot = personagens.prot * 2;
						printf("Voce se defendeu, sua defesa dobrou!\n\n");
						break;
					
					case 3:
						dado1 = rand()%6+1;
						dado2 = rand()%6+1;
						dado3 = rand()%6+1;
						
						if(personagens.Pv == pv1){
							printf("Sua vida ja esta cheia\n\n");
						}
						else if(personagens.Pv <= 0){
							personagens.Pv = 0;
						}
						else{
							personagens.Pv = personagens.Pv + dado1 + dado2 + dado3;
							if(personagens.Pv >= pv1){
								personagens.Pv = pv1;
								printf("\nVamos rolar 3 dados para calcular sua pocao\n\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
							else{
								printf("\nVamos rolar 3 dados para calcular sua pocao\n\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
						}
						break;
					
					default:
						printf("Valor Invalido!\n");
						break;
				}
				if(a == 0){
					if(borg.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (borg.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(borg.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					borg.defesa = borg.defesa * 2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(borg.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(borg.pv <= 0){
						borg.pv = 0;
					}
					else{
						borg.pv = borg.pv + dado1 + dado2 + dado3;
						if(borg.pv >= pv2){
							borg.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", borg.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", borg.pv);
						}
					}
				}
			}
			else if(borg.agilidade > personagens.Agilidade){
				if(a == 0){
					if(borg.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (borg.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(borg.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					borg.defesa = borg.defesa * 2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(borg.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(borg.pv <= 0){
						borg.pv = 0;
					}
					else{
						borg.pv = borg.pv + dado1 + dado2 + dado3;
						if(borg.pv >= pv2){
							borg.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", borg.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", borg.pv);
						}
					}
				}
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", borg.pv);
				printf("Dano:      %d\n", borg.dano);
				printf("Defesa:    %d\n", borg.defesa);
				printf("Agilidade: %d\n\n", borg.agilidade);
				printf("Os seus stats sao:\n");
				printf("PV:        %d\n", personagens.Pv);
				printf("Dano:      %d\n", personagens.gun);
				printf("Defesa:    %d\n", personagens.prot);
				printf("Agilidade: %d\n\n", personagens.Agilidade);
				printf("O que voce fara a seguir?:\n\n");
				printf("|1 - Atacar    |\n");
				printf("|2 - Defender  |\n");
				printf("|3 - Usar Pocao|\n");
				printf("Escolha a opcao desejada: ");
				scanf(" %d", &op);
				switch(op){
					case 1:
						if(personagens.gun > borg.defesa){
						borg.pv = borg.pv - (personagens.gun - borg.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", borg.pv);
						}
						else if(personagens.gun <= borg.defesa){
							borg.pv = borg.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", borg.pv);
						}
						break;
						
					case 2:
						personagens.prot = personagens.prot * 2;
						printf("Voce se defendeu, sua defesa dobrou!\n\n");
						break;
					
					case 3:
						dado1 = rand()%6+1;
						dado2 = rand()%6+1;
						dado3 = rand()%6+1;
						
						if(personagens.Pv == pv1){
							printf("Sua vida ja esta cheia\n\n");
						}
						else if(personagens.Pv <= 0){
							personagens.Pv = 0;
						}
						else{
							personagens.Pv = personagens.Pv + dado1 + dado2 + dado3;
							if(personagens.Pv >= pv1){
								personagens.Pv = pv1;
								printf("\nVamos rolar 3 dados para calcular sua pocao\n\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
							else{
								printf("\nVamos rolar 3 dados para calcular sua pocao\n\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
						}
						break;
					
					default:
						printf("Valor Invalido!\n");
						break;
				}
			}	
		}while(personagens.Pv > 0 && borg.pv > 0);
		if(personagens.Pv <= 0)
		{
			printf("fim de jogo");
			exit(0);
		}
		else if(borg.pv <= 0)
		{
		    int pontos = 5;
			printf("\nvoce ganhou\n");
		    printf("Pontos: %d\n\n", pontos);
	        printf("Quantos pontos voce quer distribuir em forca?\n");
	        scanf(" %d", &iForca);
	        pontos = pontos - iForca;
	        printf("\nPontos: %d\n\n", pontos);
	
	        printf("Quantos pontos voce quer distribuir em destreza?\n");
	        scanf(" %d", &iDestreza);
	        pontos = pontos - iDestreza;
	        printf("\nPontos: %d\n\n", pontos);
	
	        printf("Quantos pontos voce quer distribuir em agilidade?\n");
	        scanf(" %d", &iAgilidade);
	        pontos = pontos - iAgilidade;
	        printf("\nPontos: %d\n\n", pontos);
	
	       printf("Quantos pontos voce quer distribuir em constituicao?\n");
	       scanf(" %d", &iConstituicao);
	       pontos = pontos - iConstituicao;
	       
	       personagens.Forca = personagens.Forca + iForca;
	       personagens.Destreza = personagens.Destreza + iDestreza;
	       personagens.Agilidade = personagens.Agilidade + iAgilidade;
	       personagens.constituicao = personagens.constituicao + iConstituicao;
	       personagens.Pv = personagens.Pv + personagens.constituicao;
			printf("\nSeus novos stats sao: \n");
			
			printf("\nForca: %d", personagens.Forca);
			printf("\nDestreza: %d", personagens.Destreza);
			printf("\nAgilidade: %d", personagens.Agilidade);
			printf("\nConstituicao: %d", personagens.constituicao);
			printf("\nPontos de vida: %d", personagens.Pv);

			printf("\n\nAgora escolha uma arma: ");
			printf("\n|A- Espada Longa|B- Macahado Leviantan  |C- Arco de atreus  |\n");
	        printf("\n|Arma Pesada       |Arma Leve         |Arma Leve         |\n");
	        printf("\n|Dano: 12           |Dano: 10           |Dano: 8           |\n\n");
	        printf("Escolha a opcao desejada: ");
	        scanf(" %c", &armas);
	
	
	        switch(armas)
	    {
		case 'a':
		case 'A':	
			
	        dado12 = rand() %12;
            dado12 = dado12 + 1;
	        personagens.gun = 12 + dado12 + 1.5 * personagens.Forca;
	        printf("\nVoce escolheu Espada Longa!\n");
	        printf("Seu dado foi %d, seu dano eh: %d\n\n", dado12, personagens.gun);
			break;
			
		case 'b':
		case 'B':	
				;
	            dado61 = rand() %6;
	            dado61 = dado61 + 1;
	            dado62 = rand() %6;
	            dado62 = dado62 + 1;
	            dado4 = rand() %4;
	            dado4 = dado4 + 1;
	
	            personagens.gun = 10 + dado61 + dado62 + dado4 + personagens.Destreza;
	
	            printf("\nVoce escolheu os Machado Leviatan\n");
	            printf("Seus dados foram %d, %d e %d, seu dano eh: %d\n\n", dado61, dado62, dado4, personagens.gun);
			break;
			
		case 'c':
		case 'C':
			
	            dado61 = rand() %6;
	            dado61 = dado61 + 1;
	            dado62 = rand() %6;
	            dado62 = dado62 + 1;
	            dado4 = rand() %4;
	            dado4 = dado4 + 1;
	
	           personagens.gun = 8 + dado61 + dado62 + dado4 + personagens.Destreza;
	
	           printf("\nVoce escolheu arco de atreus!\n");
	           printf("Seus dados foram %d, %d e %d, seu dano eh: %d\n\n", dado61, dado62, dado4, personagens.gun);
			break;
			
		default:
			printf("Valor invalido");
	}
		}
	}	
	else if(i == 2)
	{
		defesa2 = aelle.defesa;
		pv2 = aelle.pv;
		printf("O seu oponente eh Aelle\n\n");
		do{
			aelle.defesa = defesa2;
			personagens.prot = defesa1;			
			a = rand()%3;
			if(personagens.Agilidade >= aelle.agilidade){
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", aelle.pv);
				printf("Dano:      %d\n", aelle.dano);
				printf("Defesa:    %d\n", aelle.defesa);
				printf("Agilidade: %d\n\n", aelle.agilidade);
				printf("Os seus stats sao:\n");
				printf("PV:        %d\n", personagens.Pv);
				printf("Dano:      %d\n", personagens.gun);
				printf("Defesa:    %d\n", personagens.prot);
				printf("Agilidade: %d\n\n", personagens.Agilidade);
				printf("O que voce fara a seguir?:\n\n");
				printf("|1 - Atacar    |\n");
				printf("|2 - Defender  |\n");
				printf("|3 - Usar Pocao|\n");
				printf("Escolha a opcao desejada: ");
				scanf(" %d", &op);
				switch(op){
					case 1:
						if(personagens.gun > aelle.defesa){
						aelle.pv = aelle.pv - (personagens.gun - aelle.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", aelle.pv);
						}
						else if(personagens.gun <= aelle.defesa){
							aelle.pv = aelle.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", borg.pv);
						}
						break;
						
					case 2:
						personagens.prot = personagens.prot * 2;
						printf("Voce se defendeu, sua defesa dobrou!\n\n");
						break;
					
					case 3:
						dado1 = rand()%6+1;
						dado2 = rand()%6+1;
						dado3 = rand()%6+1;
						
						if(personagens.Pv == pv1){
							printf("Sua vida ja esta cheia\n\n");
						}
						else if(personagens.Pv <= 0){
							personagens.Pv = 0;
						}
						else{
							personagens.Pv = personagens.Pv + dado1 + dado2 + dado3;
							if(personagens.Pv >= pv1){
								personagens.Pv = pv1;
								printf("\nVamos rolar 3 dados para calcular sua pocao\n\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
							else{
								printf("\nVamos rolar 3 dados para calcular sua pocao\n\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
						}
						break;
					
					default:
						printf("Valor Invalido!\n");
						break;
				}
				if(a == 0){
					if(aelle.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (aelle.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(aelle.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					aelle.defesa = aelle.defesa * 2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(aelle.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(aelle.pv <= 0){
						borg.pv = 0;
					}
					else{
						aelle.pv = aelle.pv + dado1 + dado2 + dado3;
						if(aelle.pv >= pv2){
							aelle.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", aelle.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", aelle.pv);
						}
					}
				}
			}
			else if(aelle.agilidade > personagens.Agilidade){
				a = rand()%3;
				if(a == 0){
					if(aelle.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (aelle.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(aelle.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					aelle.defesa = aelle.defesa * 2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(aelle.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(aelle.pv <= 0){
						borg.pv = 0;
					}
					else{
						aelle.pv = aelle.pv + dado1 + dado2 + dado3;
						if(aelle.pv >= pv2){
							aelle.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", aelle.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", aelle.pv);
						}
					}
				}
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", aelle.pv);
				printf("Dano:      %d\n", aelle.dano);
				printf("Defesa:    %d\n", aelle.defesa);
				printf("Agilidade: %d\n\n", aelle.agilidade);
				printf("Os seus stats sao:\n");
				printf("PV:        %d\n", personagens.Pv);
				printf("Dano:      %d\n", personagens.gun);
				printf("Defesa:    %d\n", personagens.prot);
				printf("Agilidade: %d\n\n", personagens.Agilidade);
				printf("O que voce fara a seguir?:\n\n");
				printf("|1 - Atacar    |\n");
				printf("|2 - Defender  |\n");
				printf("|3 - Usar Pocao|\n");
				printf("Escolha a opcao desejada: ");
				scanf(" %d", &op);
				switch(op){
					case 1:
						if(personagens.gun > aelle.defesa){
						aelle.pv = aelle.pv - (personagens.gun - aelle.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", aelle.pv);
						}
						else if(personagens.gun <= aelle.defesa){
							aelle.pv = aelle.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", aelle.pv);
						}
						break;
						
					case 2:
						personagens.prot = personagens.prot * 2;
						printf("Voce se defendeu, sua defesa dobrou!\n\n");
						break;
					
					case 3:
						dado1 = rand()%6+1;
						dado2 = rand()%6+1;
						dado3 = rand()%6+1;
						
						if(personagens.Pv == pv1){
							printf("Sua vida ja esta cheia\n\n");
						}
						else if(personagens.Pv <= 0){
							personagens.Pv = 0;
						}
						else{
							personagens.Pv = personagens.Pv + dado1 + dado2 + dado3;
							if(personagens.Pv >= pv1){
								personagens.Pv = pv1;
								printf("\nVamos rolar 3 dados para calcular sua pocao\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
							else{
								printf("\nVamos rolar 3 dados para calcular sua pocao\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
						}
						break;
					
					default:
						printf("Valor Invalido!\n");
						break;
				}
		    }
		}while(personagens.Pv > 0 && aelle.pv > 0);
		if(personagens.Pv <= 0)
		{
			printf("fim de jogo");
			exit(0);
		}	
		else if(aelle.pv <= 0)
		{
		    int pontos = 5;
			printf("\nvoce ganhou\n");
		    printf("Pontos: %d\n\n", pontos);
	        printf("Quantos pontos voce quer distribuir em forca?\n");
	        scanf(" %d", &iForca);
	        pontos = pontos - iForca;
	        printf("\nPontos: %d\n\n", pontos);
	
	        printf("Quantos pontos voce quer distribuir em destreza?\n");
	        scanf(" %d", &iDestreza);
	        pontos = pontos - iDestreza;
	        printf("\nPontos: %d\n\n", pontos);
	
	        printf("Quantos pontos voce quer distribuir em agilidade?\n");
	        scanf(" %d", &iAgilidade);
	        pontos = pontos - iAgilidade;
	        printf("\nPontos: %d\n\n", pontos);
	
	       printf("Quantos pontos voce quer distribuir em constituicao?\n");
	       scanf(" %d", &iConstituicao);
	       pontos = pontos - iConstituicao;
	       
	       personagens.Forca = personagens.Forca + iForca;
	       personagens.Destreza = personagens.Destreza + iDestreza;
	       personagens.Agilidade = personagens.Agilidade + iAgilidade;
	       personagens.constituicao = personagens.constituicao + iConstituicao;
	       personagens.Pv = personagens.Pv + personagens.constituicao;
			printf("\nSeus novos stats sao: \n");
			
			printf("\nForca: %d", personagens.Forca);
			printf("\nDestreza: %d", personagens.Destreza);
			printf("\nAgilidade: %d", personagens.Agilidade);
			printf("\nConstituicao: %d", personagens.constituicao);
			printf("\nPontos de vida: %d", personagens.Pv);

			printf("\n\nAgora escolha uma arma: ");
			printf("\n|A- Espada Longa|B- Macahado Leviantan  |C- Arco de atreus  |\n");
	        printf("\n|Arma Pesada       |Arma Leve         |Arma Leve         |\n");
	        printf("\n|Dano: 12           |Dano: 10           |Dano: 8           |\n\n");
	        printf("Escolha a opcao desejada: ");
	        scanf(" %c", &armas);
	
	
	        switch(armas)
	    {
		case 'a':
		case 'A':	
			
	        dado12 = rand() %12;
            dado12 = dado12 + 1;
	        personagens.gun = 12 + dado12 + 1.5 * personagens.Forca;
	        printf("\nVoce escolheu Espada Longa!\n");
	        printf("Seu dado foi %d, seu dano eh: %d\n\n", dado12, personagens.gun);
			break;
			
		case 'b':
		case 'B':	
				;
	            dado61 = rand() %6;
	            dado61 = dado61 + 1;
	            dado62 = rand() %6;
	            dado62 = dado62 + 1;
	            dado4 = rand() %4;
	            dado4 = dado4 + 1;
	
	            personagens.gun = 10 + dado61 + dado62 + dado4 + personagens.Destreza;
	
	            printf("\nVoce escolheu os Machado Leviatan\n");
	            printf("Seus dados foram %d, %d e %d, seu dano eh: %d\n\n", dado61, dado62, dado4, personagens.gun);
			break;
			
		case 'c':
		case 'C':
			
	            dado61 = rand() %6;
	            dado61 = dado61 + 1;
	            dado62 = rand() %6;
	            dado62 = dado62 + 1;
	            dado4 = rand() %4;
	            dado4 = dado4 + 1;
	
	           personagens.gun = 8 + dado61 + dado62 + dado4 + personagens.Destreza;
	
	           printf("\nVoce escolheu arco de atreus!\n");
	           printf("Seus dados foram %d, %d e %d, seu dano eh: %d\n\n", dado61, dado62, dado4, personagens.gun);
			break;
			
		default:
			printf("Valor invalido");
	}
		}
	}
	
	i = rand()%2;
	
	if(i == 0){
		defesa2 = rollo.defesa;
		pv2 = rollo.pv;
		printf("O Seu oponente eh Rollo\n\n");
		do{
			rollo.defesa = defesa2;
			personagens.prot = defesa1;
			a = rand()%3;
			if(personagens.Agilidade >= rollo.agilidade){
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", rollo.pv);
				printf("Dano:      %d\n", rollo.dano);
				printf("Defesa:    %d\n", rollo.defesa);
				printf("Agilidade: %d\n\n", rollo.agilidade);
				printf("O que voce fara a seguir?:\n\n");
				printf("Os seus stats sao:\n");
				printf("PV:        %d\n", personagens.Pv);
				printf("Dano:      %d\n", personagens.gun);
				printf("Defesa:    %d\n", personagens.prot);
				printf("Agilidade: %d\n\n", personagens.Agilidade);
				printf("|1 - Atacar    |\n");
				printf("|2 - Defender  |\n");
				printf("|3 - Usar Pocao|\n");
				printf("Escolha a opcao desejada: ");
				scanf(" %d", &op);
				switch(op){
					case 1:
						if(personagens.gun > rollo.defesa){
						rollo.pv = rollo.pv - (personagens.gun - rollo.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", rollo.pv);
						}
						else if(personagens.gun <= horik.defesa){
							rollo.pv = rollo.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", rollo.pv);
						}
						break;
						
					case 2:
						personagens.prot = personagens.prot * 2;
						printf("Voce se defendeu, sua defesa dobrou!\n\n");
						break;
					
					case 3:
						dado1 = rand()%6+1;
						dado2 = rand()%6+1;
						dado3 = rand()%6+1;
						if(personagens.Pv == pv1){
							printf("Sua vida ja esta cheia\n\n");
						}
						else if(personagens.Pv <= 0){
							personagens.Pv = 0;
						}
						else{
							personagens.Pv = personagens.Pv + dado1 + dado2 + dado3;
							if(personagens.Pv >= pv1){
								personagens.Pv = pv1;
								printf("\nVamos rolar 3 dados para calcular sua pocao\n\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
							else{
								printf("\nVamos rolar 3 dados para calcular sua pocao\n\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
						}
						break;
					
					default:
						printf("Valor Invalido!\n");
						break;
				}
				if(a == 0){
					if(rollo.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (rollo.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(rollo.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					rollo.defesa = rollo.defesa * 2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(rollo.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(rollo.pv <= 0){
						horik.pv = 0;
					}
					else{
						rollo.pv = rollo.pv + dado1 + dado2 + dado3;
						if(rollo.pv >= pv2){
							rollo.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", rollo.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", rollo.pv);
						}
					}
				}
			}	
			else if(rollo.agilidade > personagens.Agilidade){
				a = rand()%3;
				if(a == 0){
					if(rollo.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (rollo.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(rollo.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					rollo.defesa = defesa2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(rollo.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(rollo.pv <= 0){
						rollo.pv = 0;
					}
					else{
						rollo.pv = rollo.pv + dado1 + dado2 + dado3;
						if(rollo.pv >= pv2){
							rollo.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", rollo.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", rollo.pv);
						}
					}
				}
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", rollo.pv);
				printf("Dano:      %d\n", rollo.dano);
				printf("Defesa:    %d\n", rollo.defesa);
				printf("Agilidade: %d\n\n", rollo.agilidade);
				printf("Os seus stats sao:\n");
				printf("PV:        %d\n", personagens.Pv);
				printf("Dano:      %d\n", personagens.gun);
				printf("Defesa:    %d\n", personagens.prot);
				printf("Agilidade: %d\n\n", personagens.Agilidade);
				printf("O que voce fara a seguir?:\n\n");
				printf("|1 - Atacar    |\n");
				printf("|2 - Defender  |\n");
				printf("|3 - Usar Pocao|\n");
				printf("Escolha a opcao desejada: ");
				scanf(" %d", &op);
				switch(op){
					case 1:
						if(personagens.gun > rollo.defesa){
						rollo.pv = rollo.pv - (personagens.gun - rollo.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", rollo.pv);
						}
						else if(personagens.gun <= rollo.defesa);{
							horik.pv = horik.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", rollo.pv);
						}
						break;
						
					case 2:
						personagens.prot = personagens.prot * 2;
						printf("Voce se defendeu, sua defesa dobrou!\n\n");
						break;
					
					case 3:
						dado1 = rand()%6+1;
						dado2 = rand()%6+1;
						dado3 = rand()%6+1;
						
						if(personagens.Pv == pv1){
							printf("Sua vida ja esta cheia");
						}
						else if(personagens.Pv <= 0){
							personagens.Pv = 0;
						}
						else{
							personagens.Pv = personagens.Pv + dado1 + dado2 + dado3;
							if(personagens.Pv >= pv1){
								personagens.Pv = pv1;
								printf("\nVamos rolar 3 dados para calcular sua pocao\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
							else{
								printf("\nVamos rolar 3 dados para calcular sua pocao\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
						}
						break;
					
					default:
						printf("Valor Invalido!\n");
						break;
				}
		    }
		}while(personagens.Pv > 0 && rollo.pv > 0);
		if(personagens.Pv <= 0)
		{
			printf("fim de jogo");
			exit(0);
		}
		else if(rollo.pv <= 0)
		{
		    int pontos = 10;
			printf("\nvoce ganhou\n");
		    printf("Pontos: %d\n\n", pontos);
	        printf("Quantos pontos voce quer distribuir em forca?\n");
	        scanf(" %d", &iForca);
	        pontos = pontos - iForca;
	        printf("\nPontos: %d\n\n", pontos);
	
	        printf("Quantos pontos voce quer distribuir em destreza?\n");
	        scanf(" %d", &iDestreza);
	        pontos = pontos - iDestreza;
	        printf("\nPontos: %d\n\n", pontos);
	
	        printf("Quantos pontos voce quer distribuir em agilidade?\n");
	        scanf(" %d", &iAgilidade);
	        pontos = pontos - iAgilidade;
	        printf("\nPontos: %d\n\n", pontos);
	
	       printf("Quantos pontos voce quer distribuir em constituicao?\n");
	       scanf(" %d", &iConstituicao);
	       pontos = pontos - iConstituicao;
	       
	       personagens.Forca = personagens.Forca + iForca;
	       personagens.Destreza = personagens.Destreza + iDestreza;
	       personagens.Agilidade = personagens.Agilidade + iAgilidade;
	       personagens.constituicao = personagens.constituicao + iConstituicao;
	       personagens.Pv = personagens.Pv + personagens.constituicao;
			printf("\nSeus novos stats sao: \n");
			
			printf("\nForca: %d", personagens.Forca);
			printf("\nDestreza: %d", personagens.Destreza);
			printf("\nAgilidade: %d", personagens.Agilidade);
			printf("\nConstituicao: %d", personagens.constituicao);
			printf("\nPontos de vida: %d", personagens.Pv);
		}
	}
	else if(i == 1){
		defesa2 = ecbert.defesa;
		pv2 = ecbert.pv;
		printf("O Seu oponente eh Ecbert\n\n");
		do{
			ecbert.defesa = defesa2;
			personagens.prot = defesa1;
			a = rand()%3;
			if(personagens.Agilidade >= ecbert.agilidade){
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", ecbert.pv);
				printf("Dano:      %d\n", ecbert.dano);
				printf("Defesa:    %d\n", ecbert.defesa);
				printf("Agilidade: %d\n\n", ecbert.agilidade);
				printf("O que voce fara a seguir?:\n\n");
				printf("Os seus stats sao:\n");
				printf("PV:        %d\n", personagens.Pv);
				printf("Dano:      %d\n", personagens.gun);
				printf("Defesa:    %d\n", personagens.prot);
				printf("Agilidade: %d\n\n", personagens.Agilidade);
				printf("|1 - Atacar    |\n");
				printf("|2 - Defender  |\n");
				printf("|3 - Usar Pocao|\n");
				printf("Escolha a opcao desejada: ");
				scanf(" %d", &op);
				switch(op){
					case 1:
						if(personagens.gun > ecbert.defesa){
						ecbert.pv = ecbert.pv - (personagens.gun - ecbert.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", ecbert.pv);
						}
						else if(personagens.gun <= ecbert.defesa){
							ecbert.pv = ecbert.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", ecbert.pv);
						}
						break;
						
					case 2:
						personagens.prot = personagens.prot * 2;
						printf("Voce se defendeu, sua defesa dobrou!\n\n");
						break;
					
					case 3:
						dado1 = rand()%6+1;
						dado2 = rand()%6+1;
						dado3 = rand()%6+1;
						if(personagens.Pv == pv1){
							printf("Sua vida ja esta cheia\n\n");
						}
						else if(personagens.Pv <= 0){
							personagens.Pv = 0;
						}
						else{
							personagens.Pv = personagens.Pv + dado1 + dado2 + dado3;
							if(personagens.Pv >= pv1){
								personagens.Pv = pv1;
								printf("\nVamos rolar 3 dados para calcular sua pocao\n\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
							else{
								printf("\nVamos rolar 3 dados para calcular sua pocao\n\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
						}
						break;
					
					default:
						printf("Valor Invalido!\n");
						break;
				}
				if(a == 0){
					if(ecbert.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (ecbert.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(ecbert.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					ecbert.defesa = ecbert.defesa * 2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(ecbert.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(ecbert.pv <= 0){
						ecbert.pv = 0;
					}
					else{
						ecbert.pv = ecbert.pv + dado1 + dado2 + dado3;
						if(ecbert.pv >= pv2){
							ecbert.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", ecbert.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", ecbert.pv);
						}
					}
				}
			}	
			else if(ecbert.agilidade > personagens.Agilidade){
				a = rand()%3;
				if(a == 0){
					if(ecbert.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (ecbert.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(ecbert.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					ecbert.defesa = defesa2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(ecbert.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(ecbert.pv <= 0){
						ecbert.pv = 0;
					}
					else{
						ecbert.pv = ecbert.pv + dado1 + dado2 + dado3;
						if(ecbert.pv >= pv2){
							ecbert.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", ecbert.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", ecbert.pv);
						}
					}
				}
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", ecbert.pv);
				printf("Dano:      %d\n", ecbert.dano);
				printf("Defesa:    %d\n", ecbert.defesa);
				printf("Agilidade: %d\n\n", ecbert.agilidade);
				printf("Os seus stats sao:\n");
				printf("PV:        %d\n", personagens.Pv);
				printf("Dano:      %d\n", personagens.gun);
				printf("Defesa:    %d\n", personagens.prot);
				printf("Agilidade: %d\n\n", personagens.Agilidade);
				printf("O que voce fara a seguir?:\n\n");
				printf("|1 - Atacar    |\n");
				printf("|2 - Defender  |\n");
				printf("|3 - Usar Pocao|\n");
				printf("Escolha a opcao desejada: ");
				scanf(" %d", &op);
				switch(op){
					case 1:
						if(personagens.gun > horik.defesa){
						ecbert.pv = ecbert.pv - (personagens.gun - ecbert.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", ecbert.pv);
						}
						else if(personagens.gun <= ecbert.defesa);{
							ecbert.pv = ecbert.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", ecbert.pv);
						}
						break;
						
					case 2:
						personagens.prot = personagens.prot * 2;
						printf("Voce se defendeu, sua defesa dobrou!\n\n");
						break;
					
					case 3:
						dado1 = rand()%6+1;
						dado2 = rand()%6+1;
						dado3 = rand()%6+1;
						
						if(personagens.Pv == pv1){
							printf("Sua vida ja esta cheia");
						}
						else if(personagens.Pv <= 0){
							personagens.Pv = 0;
						}
						else{
							personagens.Pv = personagens.Pv + dado1 + dado2 + dado3;
							if(personagens.Pv >= pv1){
								personagens.Pv = pv1;
								printf("\nVamos rolar 3 dados para calcular sua pocao\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
							else{
								printf("\nVamos rolar 3 dados para calcular sua pocao\n");
								printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
							}
						}
						break;
					
					default:
						printf("Valor Invalido!\n");
						break;
				}
		    }
		}while(personagens.Pv > 0 && ecbert.pv > 0);
		if(personagens.Pv <= 0)
		{
			printf("fim de jogo");
			exit(0);
		}
		else if(ecbert.pv <= 0)
		{
		    int pontos = 10;
			printf("\nvoce ganhou\n");
		    printf("Pontos: %d\n\n", pontos);
	        printf("Quantos pontos voce quer distribuir em forca?\n");
	        scanf(" %d", &iForca);
	        pontos = pontos - iForca;
	        printf("\nPontos: %d\n\n", pontos);
	
	        printf("Quantos pontos voce quer distribuir em destreza?\n");
	        scanf(" %d", &iDestreza);
	        pontos = pontos - iDestreza;
	        printf("\nPontos: %d\n\n", pontos);
	
	        printf("Quantos pontos voce quer distribuir em agilidade?\n");
	        scanf(" %d", &iAgilidade);
	        pontos = pontos - iAgilidade;
	        printf("\nPontos: %d\n\n", pontos);
	
	       printf("Quantos pontos voce quer distribuir em constituicao?\n");
	       scanf(" %d", &iConstituicao);
	       pontos = pontos - iConstituicao;
	       
	       personagens.Forca = personagens.Forca + iForca;
	       personagens.Destreza = personagens.Destreza + iDestreza;
	       personagens.Agilidade = personagens.Agilidade + iAgilidade;
	       personagens.constituicao = personagens.constituicao + iConstituicao;
	       personagens.Pv = personagens.Pv + personagens.constituicao;
			printf("\nSeus novos stats sao: \n");
			
			printf("\nForca: %d", personagens.Forca);
			printf("\nDestreza: %d", personagens.Destreza);
			printf("\nAgilidade: %d", personagens.Agilidade);
			printf("\nConstituicao: %d", personagens.constituicao);
			printf("\nPontos de vida: %d", personagens.Pv);
		}
	}
	defesa2 = ragnar.defesa;
	pv2 = ragnar.pv;
	printf("\nO Seu oponente eh Ragnar Lothbrok\n\n");
	do{
		ragnar.defesa = defesa2;
		personagens.prot = defesa1;
		a = rand()%3;
		if(personagens.Agilidade >= ragnar.agilidade){
			printf("Os stats dele sao:\n");
			printf("PV:        %d\n", ragnar.pv);
			printf("Dano:      %d\n", ragnar.dano);
			printf("Defesa:    %d\n", ragnar.defesa);
			printf("Agilidade: %d\n\n", ragnar.agilidade);
			printf("O que voce fara a seguir?:\n\n");
			printf("Os seus stats sao:\n");
			printf("PV:        %d\n", personagens.Pv);
			printf("Dano:      %d\n", personagens.gun);
			printf("Defesa:    %d\n", personagens.prot);
			printf("Agilidade: %d\n\n", personagens.Agilidade);
			printf("|1 - Atacar    |\n");
			printf("|2 - Defender  |\n");
			printf("|3 - Usar Pocao|\n");
			printf("Escolha a opcao desejada: ");
			scanf(" %d", &op);
			switch(op){
				case 1:
					if(personagens.gun > ragnar.defesa){
					ragnar.pv = ragnar.pv - (personagens.gun - ragnar.defesa);
					printf("Voce o acertou! os PV do adversario cairam para %d\n\n", ragnar.pv);
					}
					else if(personagens.gun <= ragnar.defesa){
						ragnar.pv = ragnar.pv-1;
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", ragnar.pv);
					}
					break;
						
				case 2:
					personagens.prot = personagens.prot * 2;
					printf("Voce se defendeu, sua defesa dobrou!\n\n");
					break;
					
				case 3:
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					if(personagens.Pv == pv1){
						printf("Sua vida ja esta cheia\n\n");
					}
					else if(personagens.Pv <= 0){
						personagens.Pv = 0;
					}
					else{
						personagens.Pv = personagens.Pv + dado1 + dado2 + dado3;
						if(personagens.Pv >= pv1){
							personagens.Pv = pv1;
							printf("\nVamos rolar 3 dados para calcular sua pocao\n\n");
							printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
						}
						else{
							printf("\nVamos rolar 3 dados para calcular sua pocao\n\n");
							printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
						}
					}
					break;
					
					default:
						printf("Valor Invalido!\n");
						break;
				}
				if(a == 0){
					if(ragnar.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (ragnar.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(ragnar.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					ragnar.defesa = ragnar.defesa * 2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(ragnar.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(ragnar.pv <= 0){
						ragnar.pv = 0;
					}
					else{
						ragnar.pv = ragnar.pv + dado1 + dado2 + dado3;
						if(ragnar.pv >= pv2){
							ragnar.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", ragnar.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", ragnar.pv);
						}
					}
				}
		}	
		else if(ragnar.agilidade > personagens.Agilidade){
			a = rand()%3;
			if(a == 0){
				if(ragnar.dano > personagens.prot){
					personagens.Pv = personagens.Pv - (ragnar.dano - personagens.prot);
					printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
				}
				else if(ragnar.dano <= personagens.prot){
					personagens.Pv = personagens.Pv-1;
					printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
				}	
			}
			else if(a == 1){
				ragnar.defesa = defesa2;
				printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
			}
			else if(a == 2){
				dado1 = rand()%6+1;
				dado2 = rand()%6+1;
				dado3 = rand()%6+1;
				
				if(ragnar.pv == pv2){
					printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
				}
				else if(ragnar.pv <= 0){
					ragnar.pv = 0;
				}
				else{
					ragnar.pv = ecbert.pv + dado1 + dado2 + dado3;
					if(ragnar.pv >= pv2){
						ragnar.pv = pv2;
						printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", ragnar.pv);
					}
					else{
						printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", ragnar.pv);
					}
				}
			}
			printf("Os stats dele sao:\n");
			printf("PV:        %d\n", ragnar.pv);
			printf("Dano:      %d\n", ragnar.dano);
			printf("Defesa:    %d\n", ragnar.defesa);
			printf("Agilidade: %d\n\n", ragnar.agilidade);
			printf("Os seus stats sao:\n");
			printf("PV:        %d\n", personagens.Pv);
			printf("Dano:      %d\n", personagens.gun);
			printf("Defesa:    %d\n", personagens.prot);
			printf("Agilidade: %d\n\n", personagens.Agilidade);
			printf("O que voce fara a seguir?:\n\n");
			printf("|1 - Atacar    |\n");
			printf("|2 - Defender  |\n");
			printf("|3 - Usar Pocao|\n");
			printf("Escolha a opcao desejada: ");
			scanf(" %d", &op);
			switch(op){
				case 1:
					if(personagens.gun > ragnar.defesa){
					ragnar.pv = ragnar.pv - (personagens.gun - ragnar.defesa);
					printf("Voce o acertou! os PV do adversario cairam para %d\n\n", ragnar.pv);
					}
					else if(personagens.gun <= ragnar.defesa);{
						ragnar.pv = ragnar.pv-1;
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", ragnar.pv);
					}
					break;
					
				case 2:
					personagens.prot = personagens.prot * 2;
					printf("Voce se defendeu, sua defesa dobrou!\n\n");
					break;
				
				case 3:
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(personagens.Pv == pv1){
						printf("Sua vida ja esta cheia");
					}
					else if(personagens.Pv <= 0){
						personagens.Pv = 0;
					}
					else{
						personagens.Pv = personagens.Pv + dado1 + dado2 + dado3;
						if(personagens.Pv >= pv1){
							personagens.Pv = pv1;
							printf("\nVamos rolar 3 dados para calcular sua pocao\n");
							printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
						}
						else{
							printf("\nVamos rolar 3 dados para calcular sua pocao\n");
							printf("Os dados deram %d, %d e %d, seus PV subiram para %d\n\n", dado1, dado2, dado3, personagens.Pv);
						}
					}
					break;
				
				default:
					printf("Valor Invalido!\n");
					break;
			}
		}
	}while(personagens.Pv > 0 && ragnar.pv > 0);
	if(personagens.Pv <= 0)
	{
		printf("fim de jogo");
		exit(0);
	}
	else if(ragnar.pv <= 0)
	{
		printf("\nvoce ganhou\n");
		printf("\nParabens voce ganhou +5 atk e +4 de agilidade\n");
	    personagens.Agilidade = personagens.Agilidade + 4;
	    personagens.gun = personagens.gun + 5;
		printf("\n\nAgilidade: %d", personagens.Agilidade);
		printf("\n\nAtaque: %d", personagens.gun);
	}
}
