#include <iostream>
using namespace std;

float Media(float nota1, float nota2, float nota3);

int main()
{
    float n1, n2, n3;

    cout << "Digite o valor da 1° nota: ";
    cin >> n1;
    cout << "Digite o valor da 2° nota: ";
    cin >> n2;
    cout << "Digite o valor da 3° nota: ";
    cin >> n3;

    cout << "Média: " << Media(n1, n2, n3) << "\n";

    return 0;
}

float Media(float nota1, float nota2, float nota3)
{
    return (nota1+nota2+nota3)/3;
}
