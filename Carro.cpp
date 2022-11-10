#include <string>
#include <iostream>
#include <cstdlib>
#include "Carro.hpp"
using namespace std;

namespace Giras
{
    Carro::Carro()
    {
        marca = " ";
        potencia = 0;
        serie = 0;
        tanque = 0.0;
    }

    Carro::Carro(string m, int p, int s, float t)
    {
        marca = m;
        potencia = p;
        serie = s;
        tanque = t;
    }

    void Carro::setMarca(string m)
    {
        marca = m;
    }
    string Carro::getMarca()
    {
        return marca;
    }

    void Carro::setPotencia(int p)
    {
        potencia = p;
    }
    int Carro::getPotencia()
    {
        return potencia;
    }

    void Carro::setSerie(int s)
    {
        serie = s;
    }
    int Carro::getSerie()
    {
        return serie;
    }

    void Carro::setTanque(float t)
    {
        tanque = t;
    }
    float Carro::getTanque()
    {
        return tanque;
    }

    float Carro::Andar(float distancia)
    {
        if(tanque - distancia*potencia*0.001 >= 0)
            return tanque - distancia*potencia*0.001;
        else
            return 0;
    }
    void Carro::Buzinar()
    {
        cout << "Carro go broommm\n";
    }  
}
