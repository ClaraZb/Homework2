#include <string>
using namespace std;

class Tiempo{
    public:
        Tiempo();
        Tiempo(int horas);
        Tiempo(int horas, int minuntos);
        Tiempo(int horas, int minutos, int segundos);
        Tiempo(int horas, int minutos, int segundos, string momento);
        void imprimir();
        void ajusteformato();
        int hora;
        int seg;
        int min;
        string momto;
        private:
    };