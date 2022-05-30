#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char armas;
char armour;
int numero;
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
inimigos hernanes;
inimigos jael;
inimigos portaand;
inimigos clear;
inimigos caua;
inimigos boi;

void criacao(PERSONAGENS personagens);



int main()
{
	PERSONAGENS personagens;
	do{
	
	
	printf("Bem vindo ao menu!!\n");
	printf("//////////////////////////////////////////CYBERPUNK/////////////////////////////////////////////////////////////\n");
    printf("Selecione a opcao que deseja:\n\n");
    printf("1- Comecar o jogo\n");
    printf("2- Historia do jogo\n");
    printf("3- Fechar o jogo\n");
    printf("////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    scanf(" %d", &numero);
    fflush(stdin);
	
	switch(numero)
	{
		case 1 :
			criacao(personagens);
		break;	
		
		case 2 :
		printf("Em um mundo onde a tecnologia evolui bruscamente, existe uma cidade\nesquecida por Deus onde o trafico reina, a poluicao em todo lugar, crimes e\nmortes, a policia nem liga mais. Um ex agente secreto viuvo tem sua filha\nsequestrada por traficantes da cidade, entao ele comeca a procura-la ate\ndescobrir que ela esta morta, morta por overdose de uma droga experimental\nque o traficante estava desenvolvendo. O Agente acaba descobrindo o nome\ndo traficante que orquestrou tudo e vai atras de sua vinganca.");
		break;
	} 
	}while(numero != 3);
	

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
	
	printf("|A- Foice Sanguinea|B- Espada de obsidiana  |C- Adagas Ionicas  |\n");
	printf("|Arma Pesada       |Arma Leve               |Arma Leve          |\n");
	printf("|Dano: 6           |Dano: 5                 |Dano: 4            |\n\n");
	printf("Escolha a opcao desejada: ");
	scanf(" %c", &armas);
	
	
	switch(armas)
	{
		case 'a':
		case 'A':	
			
	        dado12 = rand() %12;
            dado12 = dado12 + 1;
	        personagens.gun = 6 + dado12 + 1.5 * personagens.Forca;
	        printf("\nVoce escolheu foice sanguinea!\n");
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
	
	            printf("\nVoce escolheu os espada de obsidiana!\n");
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
	
	           printf("\nVoce escolheu adagas ionicas!\n");
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
	printf("|A- Carapuca Draconica |B- Armadura de Placas   |C- Pele de Lobo   |\n");
	printf("|Defesa: 7             |Defesa: 5               |Defesa: 3         |\n\n");
	printf("Escolha a opcao desejada: ");
	scanf(" %c", &armour);
	
	switch (armour)
	{
		case 'A':
		case 'a':
			personagens.prot = 7 + 1.5 * personagens.constituicao;
	        printf("\nVoce escolheu a carapuca draconica!\n");
	        printf("Sua defesa total eh %d\n\n", personagens.prot);
		break;
		
		case 'b':
		case 'B':
			personagens.prot = 5 + 1.5 * personagens.constituicao;
	        printf("\nVoce escolheu a armadura de placas\n");
	        printf("Sua defesa total eh %d\n\n", personagens.prot);
		break;
		
		case 'c':
		case 'C':
			personagens.prot = 3 + 1.5 * personagens.constituicao;
	        printf("\nVoce escolheu a pele de lobo!\n");
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
	
	hernanes.pv = 7;
	hernanes.dano = 8;
	hernanes.defesa = 15;
	hernanes.agilidade = 4;
	
	jael.pv = 10;
	jael.dano = 10;
	jael.defesa = 15;
	jael.agilidade = 3;
		
	portaand.pv = 10;
	portaand.dano = 10;
	portaand.defesa = 14;
	portaand.agilidade = 4;
	
	clear.pv = 15;
	clear.dano = 15;
	clear.defesa = 20;
	clear.agilidade = 7;
	
	caua.pv = 15;
	caua.dano = 17;
	caua.defesa = 19;
	caua.agilidade = 7;
	
	boi.pv = 37;
	boi.dano = 36;
	boi.defesa = 30;
	boi.agilidade = 8;
	
	int batalha, defesa2, defesa1, pv1, pv2;
	int i, a, op;
	
	pv1 = personagens.Pv;
	defesa1 = personagens.prot;
	srand(time(NULL));
	i = rand () %3;
	
	system("cls");
	
	if(i == 0)
	{
		defesa2 = hernanes.defesa;
		pv2 = hernanes.pv;
		printf("O Seu oponente eh Hernanes Brocador\n\n");
		do{
			hernanes.defesa = defesa2;
			personagens.prot = defesa1;
			a = rand()%3;
			if(personagens.Agilidade >= hernanes.agilidade){
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", hernanes.pv);
				printf("Dano:      %d\n", hernanes.dano);
				printf("Defesa:    %d\n", hernanes.defesa);
				printf("Agilidade: %d\n\n", hernanes.agilidade);
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
						if(personagens.gun > hernanes.defesa){
						hernanes.pv = hernanes.pv - (personagens.gun - hernanes.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", hernanes.pv);
						}
						else if(personagens.gun <= hernanes.defesa){
							hernanes.pv = hernanes.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", jael.pv);
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
					if(hernanes.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (hernanes.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(hernanes.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					hernanes.defesa = hernanes.defesa * 2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(hernanes.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(hernanes.pv <= 0){
						hernanes.pv = 0;
					}
					else{
						hernanes.pv = hernanes.pv + dado1 + dado2 + dado3;
						if(hernanes.pv >= pv2){
							hernanes.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", hernanes.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", hernanes.pv);
						}
					}
				}
			}	
			else if(hernanes.agilidade > personagens.Agilidade){
				a = rand()%3;
				if(a == 0){
					if(hernanes.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (hernanes.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(hernanes.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					hernanes.defesa = defesa2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(hernanes.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(hernanes.pv <= 0){
						hernanes.pv = 0;
					}
					else{
						hernanes.pv = hernanes.pv + dado1 + dado2 + dado3;
						if(hernanes.pv >= pv2){
							hernanes.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", hernanes.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", hernanes.pv);
						}
					}
				}
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", hernanes.pv);
				printf("Dano:      %d\n", hernanes.dano);
				printf("Defesa:    %d\n", hernanes.defesa);
				printf("Agilidade: %d\n\n", hernanes.agilidade);
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
						if(personagens.gun > hernanes.defesa){
						hernanes.pv = hernanes.pv - (personagens.gun - hernanes.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", hernanes.pv);
						}
						else if(personagens.gun <= hernanes.defesa);{
							hernanes.pv = hernanes.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", jael.pv);
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
		}while(personagens.Pv > 0 && hernanes.pv > 0);
		if(personagens.Pv <= 0)
		{
			printf("fim de jogo");
			exit(0);
		}
		else if(hernanes.pv <= 0)
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
			printf("\n|A- Espada Longa de Sirius |B- Adaga Abissal  |C- Sabre Temporal |\n");
	        printf("\n|Arma Pesada               |Arma Leve         |Arma Leve         |\n");
	        printf("\n|Dano: 12                  |Dano: 10          |Dano: 8           |\n\n");
	        printf("Escolha a opcao desejada: ");
	        scanf(" %c", &armas);
	
	
	        switch(armas)
	    {
		case 'a':
		case 'A':	
			
	        dado12 = rand() %12;
            dado12 = dado12 + 1;
	        personagens.gun = 12 + dado12 + 1.5 * personagens.Forca;
	        printf("\nVoce escolheu Espada Longa de Sirius!\n");
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
	
	            printf("\nVoce escolheu os Adaga Abissal!\n");
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
	
	           printf("\nVoce escolheu Sabre Temporal!\n");
	           printf("Seus dados foram %d, %d e %d, seu dano eh: %d\n\n", dado61, dado62, dado4, personagens.gun);
			break;
			
		default:
			printf("Valor invalido");
	}
		}
	}
	else if(i == 1)
	{
		defesa2 = jael.defesa;
		pv2 = jael.pv;
		printf("O Seu oponente eh Jael, O cruel\n\n");
		do{
			jael.defesa = defesa2;
			personagens.prot = defesa1;
			a = rand()%3;
			if(personagens.Agilidade >= jael.agilidade){
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", jael.pv);
				printf("Dano:      %d\n", jael.dano);
				printf("Defesa:    %d\n", jael.defesa);
				printf("Agilidade: %d\n\n", jael.agilidade);
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
						if(personagens.gun > jael.defesa){
						jael.pv = jael.pv - (personagens.gun - jael.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", jael.pv);
						}
						else if(personagens.gun <= jael.defesa){
							jael.pv = jael.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", jael.pv);
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
					if(jael.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (jael.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(jael.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					jael.defesa = jael.defesa * 2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(jael.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(jael.pv <= 0){
						jael.pv = 0;
					}
					else{
						jael.pv = jael.pv + dado1 + dado2 + dado3;
						if(jael.pv >= pv2){
							jael.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", jael.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", jael.pv);
						}
					}
				}
			}
			else if(jael.agilidade > personagens.Agilidade){
				if(a == 0){
					if(jael.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (jael.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(jael.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					jael.defesa = jael.defesa * 2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(jael.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(jael.pv <= 0){
						jael.pv = 0;
					}
					else{
						jael.pv = jael.pv + dado1 + dado2 + dado3;
						if(jael.pv >= pv2){
							jael.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", jael.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", jael.pv);
						}
					}
				}
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", jael.pv);
				printf("Dano:      %d\n", jael.dano);
				printf("Defesa:    %d\n", jael.defesa);
				printf("Agilidade: %d\n\n", jael.agilidade);
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
						if(personagens.gun > jael.defesa){
						jael.pv = jael.pv - (personagens.gun - jael.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", jael.pv);
						}
						else if(personagens.gun <= jael.defesa){
							jael.pv = jael.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", jael.pv);
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
		}while(personagens.Pv > 0 && jael.pv > 0);
		if(personagens.Pv <= 0)
		{
			printf("fim de jogo");
			exit(0);
		}
		else if(jael.pv <= 0)
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
			printf("\n|A- Espada Longa de Sirius |B- Adaga Abissal   |C- Sabre Temporal  |\n");
	        printf("\n|Arma Pesada               |Arma Leve          |Arma Leve          |\n");
	        printf("\n|Dano: 12                  |Dano: 10           |Dano: 8            |\n\n");
	        printf("Escolha a opcao desejada: ");
	        scanf(" %c", &armas);
	
	
	        switch(armas)
	    {
		case 'a':
		case 'A':	
			
	        dado12 = rand() %12;
            dado12 = dado12 + 1;
	        personagens.gun = 12 + dado12 + 1.5 * personagens.Forca;
	        printf("\nVoce escolheu Espada Longa de Sirius!\n");
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
	
	            printf("\nVoce escolheu os Adaga Abissal!\n");
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
	
	           printf("\nVoce escolheu Sabre Temporal!\n");
	           printf("Seus dados foram %d, %d e %d, seu dano eh: %d\n\n", dado61, dado62, dado4, personagens.gun);
			break;
			
		default:
			printf("Valor invalido");
	}
		}
	}	
	else if(i == 2)
	{
		defesa2 = portaand.defesa;
		pv2 = portaand.pv;
		printf("O seu oponente eh Porta And\n\n");
		do{
			portaand.defesa = defesa2;
			personagens.prot = defesa1;			
			a = rand()%3;
			if(personagens.Agilidade >= portaand.agilidade){
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", portaand.pv);
				printf("Dano:      %d\n", portaand.dano);
				printf("Defesa:    %d\n", portaand.defesa);
				printf("Agilidade: %d\n\n", portaand.agilidade);
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
						if(personagens.gun > portaand.defesa){
						portaand.pv = portaand.pv - (personagens.gun - portaand.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", portaand.pv);
						}
						else if(personagens.gun <= portaand.defesa){
							portaand.pv = portaand.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", jael.pv);
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
					if(portaand.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (portaand.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(portaand.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					portaand.defesa = portaand.defesa * 2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(portaand.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(portaand.pv <= 0){
						jael.pv = 0;
					}
					else{
						portaand.pv = portaand.pv + dado1 + dado2 + dado3;
						if(portaand.pv >= pv2){
							portaand.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", portaand.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", portaand.pv);
						}
					}
				}
			}
			else if(portaand.agilidade > personagens.Agilidade){
				a = rand()%3;
				if(a == 0){
					if(portaand.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (portaand.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(portaand.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					portaand.defesa = portaand.defesa * 2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(portaand.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(portaand.pv <= 0){
						jael.pv = 0;
					}
					else{
						portaand.pv = portaand.pv + dado1 + dado2 + dado3;
						if(portaand.pv >= pv2){
							portaand.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", portaand.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", portaand.pv);
						}
					}
				}
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", portaand.pv);
				printf("Dano:      %d\n", portaand.dano);
				printf("Defesa:    %d\n", portaand.defesa);
				printf("Agilidade: %d\n\n", portaand.agilidade);
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
						if(personagens.gun > portaand.defesa){
						portaand.pv = portaand.pv - (personagens.gun - portaand.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", portaand.pv);
						}
						else if(personagens.gun <= portaand.defesa){
							portaand.pv = portaand.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", portaand.pv);
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
		}while(personagens.Pv > 0 && portaand.pv > 0);
		if(personagens.Pv <= 0)
		{
			printf("fim de jogo");
			exit(0);
		}	
		else if(portaand.pv <= 0)
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
			printf("\n|A- Espada Longa    |B- Macahado Leviantan  |C- Arco de atreus  |\n");
	        printf("\n|Arma Pesada        |Arma Leve              |Arma Leve          |\n");
	        printf("\n|Dano: 12           |Dano: 10               |Dano: 8            |\n\n");
	        printf("Escolha a opcao desejada: ");
	        scanf(" %c", &armas);
	
	
	        switch(armas)
	    {
		case 'a':
		case 'A':	
			
	        dado12 = rand() %12;
            dado12 = dado12 + 1;
	        personagens.gun = 12 + dado12 + 1.5 * personagens.Forca;
	        printf("\nVoce escolheu Espada Longa de Sirius!\n");
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
	
	            printf("\nVoce escolheu os Adaga Abissal!\n");
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
	
	           printf("\nVoce escolheu Sabre Temporal!\n");
	           printf("Seus dados foram %d, %d e %d, seu dano eh: %d\n\n", dado61, dado62, dado4, personagens.gun);
			break;
			
		default:
			printf("Valor invalido");
	}
		}
	}
	
	i = rand() %2;
	
	if(i == 0){
		defesa2 = clear.defesa;
		pv2 = clear.pv;
		printf("O Seu oponente eh Clear Man\n\n");
		do{
			clear.defesa = defesa2;
			personagens.prot = defesa1;
			a = rand()%3;
			if(personagens.Agilidade >= clear.agilidade){
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", clear.pv);
				printf("Dano:      %d\n", clear.dano);
				printf("Defesa:    %d\n", clear.defesa);
				printf("Agilidade: %d\n\n", clear.agilidade);
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
						if(personagens.gun > clear.defesa){
						clear.pv = clear.pv - (personagens.gun - clear.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", clear.pv);
						}
						else if(personagens.gun <= hernanes.defesa){
							clear.pv = clear.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", clear.pv);
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
					if(clear.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (clear.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(clear.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					clear.defesa = clear.defesa * 2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(clear.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(clear.pv <= 0){
						hernanes.pv = 0;
					}
					else{
						clear.pv = clear.pv + dado1 + dado2 + dado3;
						if(clear.pv >= pv2){
							clear.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", clear.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", clear.pv);
						}
					}
				}
			}	
			else if(clear.agilidade > personagens.Agilidade){
				a = rand()%3;
				if(a == 0){
					if(clear.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (clear.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(clear.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					clear.defesa = defesa2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(clear.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(clear.pv <= 0){
						clear.pv = 0;
					}
					else{
						clear.pv = clear.pv + dado1 + dado2 + dado3;
						if(clear.pv >= pv2){
							clear.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", clear.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", clear.pv);
						}
					}
				}
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", clear.pv);
				printf("Dano:      %d\n", clear.dano);
				printf("Defesa:    %d\n", clear.defesa);
				printf("Agilidade: %d\n\n", clear.agilidade);
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
						if(personagens.gun > clear.defesa){
						clear.pv = clear.pv - (personagens.gun - clear.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", clear.pv);
						}
						else if(personagens.gun <= clear.defesa);{
							hernanes.pv = hernanes.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", clear.pv);
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
		}while(personagens.Pv > 0 && clear.pv > 0);
		if(personagens.Pv <= 0)
		{
			printf("fim de jogo");
			exit(0);
		}
		else if(clear.pv <= 0)
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
			printf("\n(Calculo da defesa: Defesa da armadura + 1,5 * constituicao)\n\n");
			printf("|A- Armadura de Dima |B- Protecao de Cronos   |C- Armadura de Malha   |\n");
			printf("|Defesa: 14          |Defesa: 10              |Defesa: 6              |\n\n");
			printf("Escolha a opcao desejada: ");
			scanf(" %c", &armour);
	
			switch (armour)
			{
				case 'A':
				case 'a':
					personagens.prot = 14 + 1.5 * personagens.constituicao;
			        printf("\nVoce escolheu a armadura de Dima!\n");
			        printf("Sua defesa total eh %d\n\n", personagens.prot);
				break;
				
				case 'b':
				case 'B':
					personagens.prot = 10 + 1.5 * personagens.constituicao;
			        printf("\nVoce escolheu a Protecao de Cronos!\n");
			        printf("Sua defesa total eh %d\n\n", personagens.prot);
				break;
				
				case 'c':
				case 'C':
					personagens.prot = 6 + 1.5 * personagens.constituicao;
			        printf("\nVoce escolheu a Armadura de Malha!\n");
			        printf("Sua defesa total eh %d\n\n", personagens.prot);
				break;	
			}
		}

	}
	else if(i == 1){
		defesa2 = caua.defesa;
		pv2 = caua.pv;
		printf("O Seu oponente eh Caua, O guerreiro\n\n");
		do{
			caua.defesa = defesa2;
			personagens.prot = defesa1;
			a = rand()%3;
			if(personagens.Agilidade >= caua.agilidade){
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", caua.pv);
				printf("Dano:      %d\n", caua.dano);
				printf("Defesa:    %d\n", caua.defesa);
				printf("Agilidade: %d\n\n", caua.agilidade);
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
						if(personagens.gun > caua.defesa){
						caua.pv = caua.pv - (personagens.gun - caua.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", caua.pv);
						}
						else if(personagens.gun <= caua.defesa){
							caua.pv = caua.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", caua.pv);
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
					if(caua.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (caua.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(caua.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					caua.defesa = caua.defesa * 2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(caua.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(caua.pv <= 0){
						caua.pv = 0;
					}
					else{
						caua.pv = caua.pv + dado1 + dado2 + dado3;
						if(caua.pv >= pv2){
							caua.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", caua.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", caua.pv);
						}
					}
				}
			}	
			else if(caua.agilidade > personagens.Agilidade){
				a = rand()%3;
				if(a == 0){
					if(caua.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (caua.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(caua.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					caua.defesa = defesa2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(caua.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(caua.pv <= 0){
						caua.pv = 0;
					}
					else{
						caua.pv = caua.pv + dado1 + dado2 + dado3;
						if(caua.pv >= pv2){
							caua.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", caua.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", caua.pv);
						}
					}
				}
				printf("Os stats dele sao:\n");
				printf("PV:        %d\n", caua.pv);
				printf("Dano:      %d\n", caua.dano);
				printf("Defesa:    %d\n", caua.defesa);
				printf("Agilidade: %d\n\n", caua.agilidade);
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
						if(personagens.gun > hernanes.defesa){
						caua.pv = caua.pv - (personagens.gun - caua.defesa);
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", caua.pv);
						}
						else if(personagens.gun <= caua.defesa);{
							caua.pv = caua.pv-1;
							printf("Voce o acertou! os PV do adversario cairam para %d\n\n", caua.pv);
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
		}while(personagens.Pv > 0 && caua.pv > 0);
		if(personagens.Pv <= 0)
		{
			printf("fim de jogo");
			exit(0);
		}
		else if(caua.pv <= 0)
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
			printf("\nForca: %d", personagens.Forca);
			printf("\nDestreza: %d", personagens.Destreza);
			printf("\nAgilidade: %d", personagens.Agilidade);
			printf("\nConstituicao: %d", personagens.constituicao);
			printf("\nPontos de vida: %d", personagens.Pv);
			printf("\n(Calculo da defesa: Defesa da armadura + 1,5 * constituicao)\n\n");
			printf("|A- Armadura de Dima |B- Protecao de Cronos   |C- Armadura de Malha   |\n");
			printf("|Defesa: 14          |Defesa: 10              |Defesa: 6              |\n\n");
			printf("Escolha a opcao desejada: ");
			scanf(" %c", &armour);
	
	switch (armour)
	{
		case 'A':
		case 'a':
			personagens.prot = 14 + 1.5 * personagens.constituicao;
	        printf("\nVoce escolheu a armadura de Dima!\n");
	        printf("Sua defesa total eh %d\n\n", personagens.prot);
		break;
		
		case 'b':
		case 'B':
			personagens.prot = 10 + 1.5 * personagens.constituicao;
	        printf("\nVoce escolheu a Protecao de Cronos!\n");
	        printf("Sua defesa total eh %d\n\n", personagens.prot);
		break;
		
		case 'c':
		case 'C':
			personagens.prot = 6 + 1.5 * personagens.constituicao;
	        printf("\nVoce escolheu a Armadura de Malha!\n");
	        printf("Sua defesa total eh %d\n\n", personagens.prot);
		break;	
	}
		}
	}
	defesa1 = personagens.prot;
	defesa2 = boi.defesa;
	pv2 = boi.pv;
	printf("\nO Seu oponente eh Aloisio, O boi bandido\n\n");
	do{
		boi.defesa = defesa2;
		personagens.prot = defesa1;
		a = rand()%3;
		if(personagens.Agilidade >= boi.agilidade){
			printf("Os stats dele sao:\n");
			printf("PV:        %d\n", boi.pv);
			printf("Dano:      %d\n", boi.dano);
			printf("Defesa:    %d\n", boi.defesa);
			printf("Agilidade: %d\n\n", boi.agilidade);
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
					if(personagens.gun > boi.defesa){
					boi.pv = boi.pv - (personagens.gun - boi.defesa);
					printf("Voce o acertou! os PV do adversario cairam para %d\n\n", boi.pv);
					}
					else if(personagens.gun <= boi.defesa){
						boi.pv = boi.pv-1;
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", boi.pv);
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
					if(boi.dano > personagens.prot){
						personagens.Pv = personagens.Pv - (boi.dano - personagens.prot);
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}
					else if(boi.dano <= personagens.prot){
						personagens.Pv = personagens.Pv-1;
						printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
					}	
				}
				else if(a == 1){
					boi.defesa = boi.defesa * 2;
					printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
				}
				else if(a == 2){
					dado1 = rand()%6+1;
					dado2 = rand()%6+1;
					dado3 = rand()%6+1;
					
					if(boi.pv == pv2){
						printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
					}
					else if(boi.pv <= 0){
						boi.pv = 0;
					}
					else{
						boi.pv = boi.pv + dado1 + dado2 + dado3;
						if(boi.pv >= pv2){
							boi.pv = pv2;
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", boi.pv);
						}
						else{
							printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", boi.pv);
						}
					}
				}
		}	
		else if(boi.agilidade > personagens.Agilidade){
			a = rand()%3;
			if(a == 0){
				if(boi.dano > personagens.prot){
					personagens.Pv = personagens.Pv - (boi.dano - personagens.prot);
					printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
				}
				else if(boi.dano <= personagens.prot){
					personagens.Pv = personagens.Pv-1;
					printf("O oponente lhe acertou! Seus PV cairam para %d\n\n", personagens.Pv);
				}	
			}
			else if(a == 1){
				boi.defesa = defesa2;
				printf("O oponente se defendeu! A defesa dele dobrou!\n\n");
			}
			else if(a == 2){
				dado1 = rand()%6+1;
				dado2 = rand()%6+1;
				dado3 = rand()%6+1;
				
				if(boi.pv == pv2){
					printf("O oponente usou uma pocao! Mas a vida dele ja esta cheia\n\n");
				}
				else if(boi.pv <= 0){
					boi.pv = 0;
				}
				else{
					boi.pv = boi.pv + dado1 + dado2 + dado3;
					if(boi.pv >= pv2){
						boi.pv = pv2;
						printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", boi.pv);
					}
					else{
						printf("O oponente usou uma pocao! Os PV dele subiram para %d\n\n", boi.pv);
					}
				}
			}
			printf("Os stats dele sao:\n");
			printf("PV:        %d\n", boi.pv);
			printf("Dano:      %d\n", boi.dano);
			printf("Defesa:    %d\n", boi.defesa);
			printf("Agilidade: %d\n\n", boi.agilidade);
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
					if(personagens.gun > boi.defesa){
					boi.pv = boi.pv - (personagens.gun - boi.defesa);
					printf("Voce o acertou! os PV do adversario cairam para %d\n\n", boi.pv);
					}
					else if(personagens.gun <= boi.defesa);{
						boi.pv = boi.pv-1;
						printf("Voce o acertou! os PV do adversario cairam para %d\n\n", boi.pv);
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
	}while(personagens.Pv > 0 && boi.pv > 0);
	if(personagens.Pv <= 0)
	{
		printf("fim de jogo");
		exit(0);
	}
	else if(boi.pv <= 0)
	{
		printf("VOCE GANHOU UHUUUULL!!!! voce conquistou sua vinganca");

	}
}
