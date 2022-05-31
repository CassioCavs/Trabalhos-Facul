#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
int 	numContas=0;
int 	contaTaAberta[100];
int 	auxX;
float 	auxY;
float 	saldo[100];
char 	transaction;

void printMenu();
void selectionMenu();

void open();
void balance();
void deposit();
void withdrawl();
void close();
void print();

int main(){
	selectionMenu();
}
void open(){
	if(numContas<100){
		int random=rand()%100+1;
		while(contaTaAberta[random]==1)random=rand()%100+1;
		printf("Bem vindo dono da nova conta %d, qual seu deposito inicial?: ",1000+random);
		scanf("%f", &saldo[random]);
		while(saldo[random]<=0){
			printf("Valor invalido, insira outro valor para o deposito inicial");
			scanf("%f",&saldo[random]);
			}
		contaTaAberta[random]=1;
		numContas++;
		system("PAUSE");
	}
	else{printf("Numero maximo de contas abertas atingido");system("PAUSE");return;}
}

void balance(){
	printf("Insira o numero da conta: ");
	scanf("%d", &auxX);
	printf("A conta %d possui $%f.2\n",auxX,saldo[auxX-1001]);
	system("PAUSE");
}

void deposit(){
	printf("Insira o numero da conta: ");
	scanf("%d", &auxX);
	auxX-=1000;
	if(contaTaAberta[auxX]!=1){printf("Conta nao existente, tente novamente.\n");deposit();}
	printf("Insira o valor a ser depositado:");
	scanf("%f", &auxY);
	saldo[auxX]+=auxY;
	printf("$%.2f foi depositado,saldo atual eh de $%.2f\n", auxY, saldo[auxX]);
	system("PAUSE");
}

void withdrawl(){
	printf("Insira o numero da conta: ");
	scanf("%d", &auxX);
	auxX-=1000;
	if(contaTaAberta[auxX]!=1){printf("Conta nao existente, tente novamente.\n");withdrawl();}
	printf("Insira o valor a ser sacado:");
	scanf("%f", &auxY);
	saldo[auxX]-=auxY;
	printf("$%.2f foi sacado,saldo atual eh de $%.2f\n", auxY, saldo[auxX]);
	system("PAUSE");
}

void close(){
	printf("Insira o numero da conta: ");
	scanf("%d", &auxX);
	auxX-=1000;
	if(contaTaAberta[auxX]!=1){printf("Conta nao existente, tente novamente.\n");close();}
	saldo[auxX]=0;
	contaTaAberta[auxX]=0;
	numContas--;
	printf("Conta fechada com sucesso\n");
	system("PAUSE");
}

void print(){
	int indice=0;
	for(int i=0;i<100;++i){
		if(contaTaAberta[i]==1){
			indice++;
			printf("%d, %d: %.2f\n",indice,i+1000,saldo[i]);
		}
	}
	system("PAUSE");
}


void selectionMenu(){
	system("CLS");
	fflush(stdin);
	printf("Qual a transacao que voce deseja realizar: \n");
	printMenu();
	scanf("%c",&transaction);
	switch(transaction){
		case 'O':
		case 'o':
			open();
			selectionMenu();
		case 'B':
		case 'b':
			balance();
			selectionMenu();
		case 'D':
		case 'd':
			deposit();
			selectionMenu();
		case 'W':
		case 'w':
			withdrawl();
			selectionMenu();
		case 'C':
		case 'c':
			close();
			selectionMenu();
		case 'P':
		case 'p':
			print();
			selectionMenu();
		case 'E':
		case 'e':
			return;
		default:
			printf("Transacao invalida\n");
			system("PAUSE");
			selectionMenu();
	}
}

void printMenu(){
	printf("O - Abrir conta\n");
	printf("B - Saldo\n");
	printf("D - Depositar\n");
	printf("W - Sacar\n");
	printf("P - Mostrar todas as contas e saldo\n");
	printf("C - Fechar conta\n");
	printf("E - Sair\n");
}