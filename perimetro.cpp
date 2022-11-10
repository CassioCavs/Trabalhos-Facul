#include <iostream>
using namespace std;

int Perimetro(int a, int b, int c);
int Perimetro(int a, int b, int c, int d);
int Perimetro(int a, int b, int c, int d, int e);

int main()
{
    int a, b, c, d, e;

    cout << "Digite o valor para 'a': ";
    cin >> a;
    cout << "Digite o valor para 'b': ";
    cin >> b;
    cout << "Digite o valor para 'c': ";
    cin >> c;
    cout << "Digite o valor para 'd': ";
    cin >> d;
    cout << "Digite o valor para 'e': ";
    cin >> e;

    cout << "Triangulo: " << Perimetro(a, b, c) << "\n";
    cout << "Retangulo: " << Perimetro(a, b, c, d) << "\n";
    cout << "Pentagono: " << Perimetro(a, b, c, d, e) << "\n";

    return 0;
}


int Perimetro(int a, int b, int c)
{
    return (a+b+c);
}

int Perimetro(int a, int b, int c, int d)
{
    return (a+b+c+d);
}

int Perimetro(int a, int b, int c, int d, int e)
{
    return (a+b+c+d+e);
}
