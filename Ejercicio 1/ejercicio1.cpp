#include <iostream>
#include "Tiempo.h"

int main(){
    //Inicializo sin parametros
    Tiempo tiempo0;
    cout << "Testeo sin parametros" << endl;
    tiempo0.imprimir();

    //Inicializo con la hora
    int hora;
    cout << "Testeo con la hora" << endl;
    cout << "Ingresar hora: ";
    cin >> hora;
    Tiempo tiempo1(hora);
    tiempo1.imprimir();

    //Inicializando horas y mins
    int min;
    cout << "Testeo con la hora y los minutos" << endl;
    cout << "Ingresar hora y minutos: ";
    cin >> hora >> min;
    Tiempo tiempo2(hora, min);
    tiempo2.imprimir();

    //Inicializando horas, mins y segs
    int seg;
    cout << "Testeo con la hora, los minutos y los segundos" << endl;
    cout << "Ingresar hora, minutos y segundos: ";
    cin >> hora >> min >> seg;
    Tiempo tiempo3(hora, min, seg);
    tiempo3.imprimir();

    //Inicializando horas, mins, segundos y momento del dia
    string momto;
    cout << "Testeo con la hora, los minutos, los segundos y el momento del dia" << endl;
    cout << "Ingresar hora, minutos, segundos y momento del dia (a.m o p.m): ";
    cin >> hora >> min >> seg >> momto;
    Tiempo tiempo4(hora, min, seg, momto);
    tiempo4.imprimir();

    //Inicializando con errores:
    cout << "Testeo con errores" << endl;
    Tiempo tiempo5(30);
    Tiempo tiempo6(10, 61);
    Tiempo tiempo7(10, 59, 71);
    Tiempo tiempo8(10, 59, 48, "t.m");

    //Testeando modificacion de los atributos
    cout << "Testeo modificacion de atributos" << endl;
    tiempo4.hora = 4;
    tiempo4.min = 5;
    tiempo4.seg = 40;
    tiempo4.momto = "a.m";

    cout << tiempo4.hora << endl;
    cout << tiempo4.min << endl;
    cout << tiempo4.seg << endl;
    cout << tiempo4.momto << endl;

    return 0;

    //implementalo con try y catch
}