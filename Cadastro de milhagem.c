#include <stdio.h>
#include <conio.h>
int choice, numCli=0, rep, selection;
char client[10][10];
float mileage[10];

int high=0,low=0,auxH=0,auxL=0;

void printMenu();
void selectMenu();

void regClient();
void printMileage();
void printHighsnLows();
void printAll();

int main(){
	printMenu();
	selectMenu();
}

void printMenu(){
	system("cls");
	printf("********************\n");
	printf("*        MENU      *\n");	
	printf("********************\n");	
	printf("1 - Cadastrar dados do cliente\n");
	printf("2 - Listar milhagem do cliente\n");
	printf("3 - Imprimir o nome de quem possui a maior e menor milhagem\n");
	printf("4 - Imprimir o nome e as milhagens de todos os clientes cadastrados\n");
	printf("5 - Sair\n");

}
	
void selectMenu(){
	scanf("%d", &choice);
	switch(choice){
		case 1:
			regClient();
			printMenu();
			selectMenu();
			break;
		case 2:
			printMileage();
			printMenu();
			selectMenu();
			break;
		case 3:
			printHighsnLows();
			printMenu();
			selectMenu();
			break;
		case 4:
			printAll();
			printMenu();
			selectMenu();
			break;
		case 5:
			return;
		default:
			printf("Por favor insira uma opcao valida\n");
			selectMenu();
		}	
}

void regClient(){
	rep = 1;
	if(numCli<10){ 
	while(rep == 1){
		system("cls");
			printf("Insira o nome do cliente: ");
			scanf("%s", client[numCli]);
			printf("Insira o numero de milhas do mesmo: ");
			scanf("%f", &mileage[numCli]);
			numCli++;
			if(numCli<10){
			printf("Voce deseja adicionar outro? Se sim, aperte 1: ");
			scanf("%d", &rep);
			}else{printf("Numero maximo de clientes atingido"); return;
			}}
		}
	else{
			printf("Numero maximo de clientes registrados\n");
			system("PAUSE");

		}
	}

void printMileage(){
	system("cls");
	rep = 1;
	for(int i=0;i<numCli;++i)printf("%d. %s\n", i+1, client[i]);
	while(rep == 1){
	printf("Selecione o numero de qual cliente voce quer consultar: ");
	scanf("%d", &selection);
	if(selection<=numCli){
	printf("%s possui %.2f milhas\n", client[selection-1],mileage[selection-1]);
	printf("Voce deseja verificar outra conta? Se sim, aperte 1: ");
	scanf("%d", &rep);}
	else{printf("Usuario invalido\n");}
	}
}

void printHighsnLows(){
	for(int i=0;i<numCli;++i){
		if(auxH<mileage[i]){high=i;auxH=mileage[i];}
		if(auxL>mileage[i]){low=i;auxL=mileage[i];}
	}
	printf("%s possui %.2f milhas\n",client[high],mileage[high]);
	printf("%s possui %.2f milhas\n",client[low],mileage[low]);
	system("PAUSE");
}

void printAll(){
	for(int i=0;i<numCli;i++)printf("%d. %s possui %.2f milhas\n", i+1, client[i],mileage[i]);
	system("PAUSE");
}

