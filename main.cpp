#include <iostream>
#include <string>
#include "Carro.hpp"
using namespace std;
using namespace Giras;

int main()
{
    Carro v8 = Carro("Ford", 350, 93100, 50.5);
    v8.Buzinar();

    std::cout << "";

    return 0;
}