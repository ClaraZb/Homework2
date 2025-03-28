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
        
        //Getters y setters
        int getHoras();
        int getMinutos();
        int getSegundos();
        string getMomento();
        void setHoras(int horas);
        void setMinutos(int minuto);
        void setSegundos(int segundo);
        void setMomento(string momento);

    private:
        int hora;
        int seg;
        int min;
        string momto;
    };