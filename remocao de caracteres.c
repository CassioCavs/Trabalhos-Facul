#include <stdio.h>
#include <string.h>
#include <locale.h>
void filtro(char msg[500] ,int tamanho, char c){
    
    char mensagem[500];
    strcpy(mensagem,msg);
    int i,r=0;
    for (i=0; i<tamanho; i++){
        if(mensagem[i]==c){
            r++;
            mensagem[i] = '*';
        }
    }
    printf("\nMensagem modificada: \n %s", mensagem);
    printf("\nCaracteres retirados: %d", r);
}
int main(){
    
    char msg[500], c;
    printf("Escreva uma mensagem de ate 500 caracteres\n");
    gets(msg);
    printf("Informe o caracter a ser removido: ");
    scanf("%c", &c);
    filtro(msg, strlen(msg), c);
}