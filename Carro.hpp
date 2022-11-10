#ifndef CARRO_HPP
#define CARRO_HPP

#include <string>
#include <cstdlib>
using namespace std;

namespace Giras
{    
    class Carro
    {
        private:
            string marca;
            int potencia;
            int serie;
            float tanque;

        public:
            // Construtor padrão da classe
            // Coloca valores neutros para as caracteristicas:
            //      Marca, Potencia, Serie e Tanque
            Carro();

            // Construtor padrão da classe
            // Recebe quatro valores de entreda:
            //      string m, int p, int s, float t
            // Atribui os valores passados para cada uma das características
            Carro(string m, int p, int s, float t);

            void setMarca(string m);
            string getMarca();

            void setPotencia(int p);
            int getPotencia();

            void setSerie(int s);
            int getSerie();

            void setTanque(float f);
            float getTanque();

            float Andar(float distancia);
            void Buzinar();
    };
}


#endif