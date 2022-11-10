
#include <iostream>
using namespace std;

int main()
{
    int x, y, z;
    
    cout << "Digite um número: ";
    cin >> x;
    cout << "Digite um número: ";
    cin >> y;
    cout << "Digite um número: ";
    cin >> z;

    // Fazer x virar o maior valor, y do meio e z o menor
    int temp;
    if(y > x)
    {
        temp = x;
        x = y;
        y = temp;
    }
    if(z > x)
    {
        temp = x;
        x = z;
        z = temp;
    }   
    if(z > y)
    {
        temp = y;
        y = z;
        z = temp;
    }

    cout << "Maior valor: " << x << endl;
    cout << "Valor meio: " << y << endl;
    cout << "Menor valor: " << z << endl;

    return 0;
}
