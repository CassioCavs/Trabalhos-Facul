#include <iostream>
using namespace std;


// Usar função para separar a lógica de desenhar o padrão para fora do main
void DesenharPadrao();


// Código principal
int main()
{
    char escolha;

    cout << "Você quer desenhar a figura ou sair?" << endl;
    cout << "Y (ou y) - sim" << endl;
    cout << "Q (ou q) - sair" << endl;
    cout << "Escolha: ";
    cin >> escolha;

    switch(escolha)
    {
        // Caso seja digitado y ou Y
        case 'y':
        case 'Y':
            DesenharPadrao();
            break;

        // Caso seja digitado q ou Q
        case 'q':
        case 'Q':
            cout << "Fechando o software!" << endl;
            break;

        // Caso seja digitado qualquer coisa que não seja uma das opções acima
        default:
            cout << "!!! Comando inválido !!!" << endl;
            cout << "! Fechando o software !" << endl;
    }

    return 0;
}



// Lógica principal para desenhar o padrão
void DesenharPadrao()
{
    int i, j;

    //Como são 8 linhas, serão 8 repetições
    for(i = 0; i < 8; i ++)
    {
        // O mesmo padrão se repete, a diferença de uma linha para outra é que tem um espaço na frente
        // Então podemos reaproveitar a mesma lógica, só verificar se a linha é par ou ímpar para colocar o espaço ou não
        if(i%2 == 0)
        {
            // Lógica para desenhar o padrão
            for(j = 0; j < 9; j++)
                cout << "* ";
            cout << endl;
        }
        else
        {
            // Como a linha é impar, colocar o espaço na frente
            cout << " "; 
            // Lógica para desenhar o padrão
            for(j = 0; j < 9; j++)
                cout << "* ";
            cout << endl;
        }
    }

    cout.flush(); // limpar o buffer de saida
}
