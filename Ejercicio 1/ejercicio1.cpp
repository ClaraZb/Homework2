#include <iostream>
#include "Tiempo.h"

/*
Crear el main fue lo que mas dificil me parecio. Al principio era
un codigo gigante y horrible pero despues lo fui modularizando. 
Decidi no modularizar la inicializacion de tiempo ya que complicaria
mas el codigo que lo que mejoraria la legibilidad. 

En tiempo.h tengo la declaracion de los constructores, metodos y atributos. 
En timempo.cpp implemente lo que declare en tiempo.h.

Para resolver esta consigna, implemente una classe Tiempo con diferentes
constructores, dependiendo de los parametros que le pasaran. Para poder
acceder a la informacion de manera segura, puse los atributos como private
e implemente setters y getters publicos. Ademas agregue metodos para poder 
ver la informacion en pantalla.
*/


int manejoError(){ //Imprimo por pantalla en caso de error
    int res;
    cout << "Error en el ingreso de los datos" << endl;
    cout << "Quieres salir (0) o ingresar un numero nuevamente (1)? ";
    cin >> res;
    return res;
}

void cambiarHora(Tiempo& tiempo){ //cambio la hora y manejo los posibles errores
    int hora;
    cout << "Ingresar la nueva hora: ";
    cin >> hora ;
    try{
        tiempo.setHoras(hora);
    }
    catch(const invalid_argument& e){
        cout << "Error en el ingreso de los datos" << endl;
    }
}

void cambiarMinutos(Tiempo& tiempo){ //cambio los minutos y manejo los posibles errores
    int min;
    cout << "Ingresar los nuevos minutos: ";
    cin >> min;
    try{
        tiempo.setMinutos(min);
    }
    catch(const invalid_argument& e){
        cout << "Error en el ingreso de los datos" << endl;
    }
}

void cambiarSegundos(Tiempo& tiempo){ //cambio los segundos y manejo los posibles errores
    int seg;
    cout << "Ingresar los nuevos segundos: ";
    cin >> seg;
    try{
        tiempo.setSegundos(seg);
    }
    catch(const invalid_argument& e){
        cout << "Error en el ingreso de los datos" << endl;
    }
}

void cambiarMomento(Tiempo& tiempo){ //cambio el momento del dia y manejo los posibles errores
    string momto;
    cout << "Ingresar el nuevo momento del dia (p.m o a.m): ";
    cin >> momto ;
    try{
        tiempo.setMomento(momto);
    }
    catch(const invalid_argument& e){
        cout << "Error en el ingreso de los datos" << endl;
    }
}


int main(){
    //Inicializo parametros
    int hora; int min; int seg; int res; 
    string momto; 
    bool exitoso = false; //me va a permitir manejar los errores 
    Tiempo tiempo;

    cout << "Quieres definir el tiempo...\n" 
    << "- Con valores predeterminados (0) \n"
    << "- Solo con horas (1) \n"
    << "- Con horas y minutos (2) \n"
    << "- Con horas, minutos y segundos (3) \n"
    << "- Con horas, minutos, segundos y momento del dia (4)" << endl;

    cin >> res;

    if (res == 1){ //Inicializo con la hora
        while (exitoso == false){
            cout << "Ingresar hora: ";
            cin >> hora;
            try{
                tiempo = Tiempo(hora);
                exitoso = true;
            }
            catch(const invalid_argument& e){
                res = manejoError();
                if (res == 1) exitoso = false;
                else return 0; //salgo del main 
            }
        }
    }

    else if (res == 2){ //Inicializo con la hora y los minutos
        while (exitoso == false){
            cout << "Ingresar hora y minutos: ";
            cin >> hora >> min;
            try{
                tiempo = Tiempo(hora, min);
                exitoso = true;
            }
            catch(const invalid_argument& e){
                res = manejoError();
                if (res == 1) exitoso = false;
                else return 0; //salgo del main 
            }
        }
    }

    else if (res == 3){ //Inicializo con la hora, los minutos y los segundos
        while (exitoso == false){
            cout << "Ingresar hora, minutos y segundos: ";
            cin >> hora >> min >> seg;
            try{
                tiempo = Tiempo(hora, min, seg);
                exitoso = true;
            }
            catch(const invalid_argument& e){
                res = manejoError();
                if (res == 1) exitoso = false;
                else return 0; //salgo del main 
            }
        }  
    }

    else if (res == 4){ //Inicializo con la hora, los minutos, los segundos y el momento del dia
        while (exitoso == false) {
            cout << "Ingresar hora, minutos, segundos y momento del dia (a.m o p.m): ";
            cin >> hora >> min >> seg >> momto;
            try{
                tiempo = Tiempo(hora, min, seg, momto);
                exitoso = true;
            }
            catch(const invalid_argument& e){
                res = manejoError();
                if (res == 1) exitoso = false;
                else return 0; //salgo del main 
            }
        }
    }

    else{ //Inicializo por default sin parametros
        tiempo = Tiempo();
    }

    
    while (true){
        cout << "Quieres...\n" 
        << "- Terminar la sesion (0) \n"
        << "- Obtener la hora (1), los minutos (2), los segundos (3) o el momento del dia (4) \n" 
        << "- Cambiar la hora (5), los minutos (6), los segundos (7) o el momento del dia (8) \n"
        << "- Imprimir el tiempo (9) \n"
        << "- Imprimir el tiempo en formato 0 a 24 (10) \n"
        << "-> ";

        cin >> res;
        exitoso = false;

        if (res == 0) return 0;
        //Getters
        else if (res == 1) cout << tiempo.getHoras() << "h" << endl;
        else if (res == 2) cout << tiempo.getMinutos() << "min" << endl;
        else if (res == 3) cout << tiempo.getSegundos() << "seg" << endl;
        else if (res == 4) cout << tiempo.getMomento() << endl;
        
        //Setters
        else if (res == 5) cambiarHora(tiempo);
        else if (res == 6) cambiarMinutos(tiempo);
        else if (res == 7) cambiarSegundos(tiempo);
        else if (res == 8) cambiarMomento(tiempo);

        //Impresion por pantalla
        else if (res == 9) tiempo.imprimir();
        else if (res == 10) tiempo.ajusteformato();
        
        else{ //lpm pone un valor correcto
            cout << "Ingrese un numero valido" << endl;
        }
    }
    return 0;
}