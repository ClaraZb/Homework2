#include <iostream>
#include "Tiempo.h"

int main(){
    //Inicializo parametros
    int hora; int min; int seg; string momto; int res;

    //Inicializo sin parametros
    Tiempo tiempo0;
    cout << "Testeo sin parametros" << endl;
    tiempo0.imprimir();

    //Inicializo con la hora (con manejo de error)
    res = 1;
    while (res == 1){
        cout << "Testeo con la hora" << endl;
        cout << "Ingresar hora: ";
        cin >> hora;
        try{
            Tiempo tiempo1(hora);
            tiempo1.imprimir();
            res = 0;
        }
        catch(const invalid_argument& e){
            cout << "Error en el ingreso de los datos" << endl;
            cout << "Quieres ingresar un numero nuevamente? (responder con 0 o 1)" << endl;
            cin >> res;
        }
    }

    //Inicializando horas y mins (con manejo de error)
    res = 1;
    while (res == 1){
        int hora;
        cout << "Testeo con la hora y los minutos" << endl;
        cout << "Ingresar hora y minutos: ";
        cin >> hora >> min;
        try{
            Tiempo tiempo2(hora, min);
            tiempo2.imprimir();
            res = 0;
        }
        catch(const invalid_argument& e){
            cout << "Error en el ingreso de los datos" << endl;
            cout << "Quieres ingresar un numero nuevamente? (responder con 0 o 1)" << endl;
            cin >> res;
        }
    }

    //Inicializando horas, mins y segs
    res = 1;
    while (res == 1){
        int hora;
        cout << "Testeo con la hora, los minutos y los segundos" << endl;
        cout << "Ingresar hora, minutos y segundos: ";
        cin >> hora >> min >> seg;
        try{
            Tiempo tiempo3(hora, min, seg);
            tiempo3.imprimir();
            res = 0;
        }
        catch(const invalid_argument& e){
            cout << "Error en el ingreso de los datos" << endl;
            cout << "Quieres ingresar un numero nuevamente? (responder con 0 o 1)" << endl;
            cin >> res;
        }
    }

    //Inicializando horas, mins, segundos y momento del dia
    res = 1;
    while (res == 1){
        int hora;
        cout << "Testeo con la hora, los minutos, los segundos y el momento del dia" << endl;
        cout << "Ingresar hora, minutos, segundos y momento del dia (a.m o p.m): ";
        cin >> hora >> min >> seg >> momto;
        try{
            Tiempo tiempo4(hora, min, seg, momto);
            tiempo4.imprimir();
            res = 0;
        }
        catch(const invalid_argument& e){
            cout << "Error en el ingreso de los datos" << endl;
            cout << "Quieres ingresar un numero nuevamente? (responder con 0 o 1)" << endl;
            cin >> res;
        }
    }

    //Testeando modificacion de los atributos
    cout << "Testeo modificacion de atributos" << endl;
    Tiempo tiempo5(10, 54, 30, "a.m");
    tiempo5.hora = 4;
    tiempo5.min = 5;
    tiempo5.seg = 40;
    tiempo5.momto = "a.m";

    cout << tiempo5.hora << endl;
    cout << tiempo5.min << endl;
    cout << tiempo5.seg << endl;
    cout << tiempo5.momto << endl;

    //Testeando ajustar formato
    Tiempo tiempo6(10, 0, 5, "p.m"); 
    tiempo6.imprimir();
    tiempo6.ajusteformato();

    return 0;

    //esta bien todos los catch q puse? no se me ocurre otra manera

    //en la consigna g, que tengo que dejar que el usuario pueda modificar
    // la hora por ejemplo. solo se trata de poner los atributos en public?
    // o creo metodos tipo GetHora()?

    //agregar comentarios descriptivos
}