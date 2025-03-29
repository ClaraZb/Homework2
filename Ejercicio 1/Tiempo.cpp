#include "Tiempo.h"
#include <iostream>
#include <iomanip> 
#include <string>
using namespace std;

Tiempo::Tiempo(){
    hora = 0; seg = 0; min = 0;
    momto = "a.m";
}
Tiempo::Tiempo(int horas){
    if (horas < 0 || horas >= 12) {
        throw invalid_argument("Error en el ingreso de los datos");
    }
    hora = horas;
    min = 0; seg = 0; momto = "a.m";
}
Tiempo::Tiempo(int horas, int minutos){
    if (horas < 0 || horas >= 12 || minutos < 0 || minutos > 59) {
        throw invalid_argument("Error en el ingreso de los datos");
    }
    hora = horas; min = minutos;
    seg = 0; momto = "a.m";
}
Tiempo::Tiempo(int horas, int minutos, int segundos){
    if (horas < 0 || horas >= 12 || minutos < 0 || minutos > 59 || segundos < 0 || segundos > 59){
        throw invalid_argument("Error en el ingreso de los datos");
    }
    hora = horas; min = minutos; seg = segundos;
    momto = "a.m";
}
Tiempo::Tiempo(int horas, int minutos, int segundos, string momento){
    if (horas < 0 || horas >= 12 || minutos < 0 || minutos > 59 || segundos < 0 || segundos > 59 || (momento != "a.m" && momento != "p.m")){
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
    int nuevahora = hora;
    if (momto == "p.m"){
        nuevahora += 12;
    }
    cout << setfill('0') << setw(2) << nuevahora << "h "
    << setfill('0') << setw(2) << min << "m "
    << setfill('0') << setw(2) << seg << "s " << endl;
}

int Tiempo::getHoras() {return hora;}
int Tiempo::getMinutos() {return min;}
int Tiempo::getSegundos() {return seg;}
string Tiempo::getMomento() {return momto;}

void Tiempo::setHoras(int horas){
    if (horas < 0 || horas >= 12) {
        throw invalid_argument("Error en el ingreso de los datos");
    }
    hora = horas;
    return;
}

void Tiempo::setMinutos(int minutos){
    if (minutos < 0 || minutos > 59) {
        throw invalid_argument("Error en el ingreso de los datos");
    }
    min = minutos;
    return;
}

void Tiempo::setSegundos(int segundos){
    if (segundos < 0 || segundos > 59){
        throw invalid_argument("Error en el ingreso de los datos");
    }
    seg = segundos;
    return;
}

void Tiempo::setMomento(string momento){
    if (momento != "a.m" && momento != "p.m"){
        throw invalid_argument("Error en el ingreso de los datos");
    }
    momto = momento;
    return;
}