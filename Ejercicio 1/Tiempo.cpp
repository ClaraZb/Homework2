#include "Tiempo.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//chequeo los valores inadecuados adentro de la clase?

Tiempo::Tiempo(){
    hora = 0; seg = 0; min = 0;
    momto = "a.m";
}
Tiempo::Tiempo(int horas){
    if (horas <= 0 || horas >= 12) {
        horas = 0; //o tiro error?
        throw invalid_argument("Error en el ingreso de los datos");
    }
    hora = horas;
    min = 0; seg = 0; momto = "a.m";
}
Tiempo::Tiempo(int horas, int minutos){
    if (horas < 0 || horas >= 12 || minutos < 0 || minutos > 59) {
        minutos = 0; horas = 0;
        throw invalid_argument("Error en el ingreso de los datos");
    }
    hora = horas; min = minutos;
    seg = 0; momto = "a.m";
}
Tiempo::Tiempo(int horas, int minutos, int segundos){
    if (horas < 0 || horas >= 12 || minutos < 0 || minutos > 59 || segundos < 0 || segundos > 59){
        minutos = 0; horas = 0; segundos = 0;
        throw invalid_argument("Error en el ingreso de los datos");
    }
    hora = horas; min = minutos; seg = segundos;
    momto = "a.m";
}
Tiempo::Tiempo(int horas, int minutos, int segundos, string momento){
    if (horas < 0 || horas >= 12 || minutos < 0 || minutos > 59 || segundos < 0 || segundos > 59 || (momento != "a.m" && momento != "p.m")){
        minutos = 0; horas = 0; segundos = 0; momento = "a.m";
        throw invalid_argument("Error en el ingreso de los datos");
    }
    hora = horas; min = minutos; seg = segundos;
    momto = momento;
}

void Tiempo::imprimir(){
    cout << setfill('0') << setw(2) << hora << "h "
    << setfill('0') << setw(2) << min << "m "
    << setfill('0') << setw(2) << seg << "s "
    << momto << endl;
}

void Tiempo::ajusteformato(){
    if (hora < 12){
        if (momto == "p.m"){
            hora += 12;
        }
    }
    cout << setfill('0') << setw(2) << hora << "horas";
}

// el usuario da la hora en q formato? 13h o 1h?