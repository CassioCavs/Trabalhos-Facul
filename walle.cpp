#include <iostream>
using namespace std;

class Robo
{
    private:
        int serie;
        int x;
        int y;

    public:
        void Cima(int n)
        {
            y += n;
        }
        void Baixo(int n)
        {
            y -= n;
        }
        void Direita(int n)
        {
            x += n;
        }
        void Esquerda(int n)
        {
            x -= n;
        }
        void Informação()
        {
            cout << "Número de série: " << serie << "\n";
            cout << "(x, y) = " << "(" << x << ", " << y << ")\n";
        }

        Robo(int nSerie, int nX, int nY)
        {
            serie = nSerie;
            x = nX;
            y = nY;
        }
        Robo()
        {
            serie = 413;
            x = 0;
            y = 0;
        }
};

int main ()
{
    Robo wall_e;
    Robo eva = Robo(321, 10, 40);

    wall_e.Informação();
    eva.Informação();

    wall_e.Direita(7);
    wall_e.Cima(20);

    eva.Esquerda(3);
    eva.Baixo(20);

    wall_e.Informação();
    eva.Informação();
}
