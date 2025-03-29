#include <iostream>
#include "Tiempo.h"

int manejoError(){
    int res;
    cout << "Error en el ingreso de los datos" << endl;
    cout << "Quieres salir (0) o ingresar un numero nuevamente (1)? ";
    cin.clear();
    cin.ignore(100, '\n');
    cin >> res;
    return res;
}

bool cambiarHora(Tiempo& tiempo, int hora){
    
}

int main(){
    //Inicializo parametros
    int hora; int min; int seg; int res; 
    string momto; 
    bool exitoso = false;
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
        else if (res == 1) cout << tiempo.getHoras() << endl;
        else if (res == 2) cout << tiempo.getMinutos() << endl;
        else if (res == 3) cout << tiempo.getSegundos() << endl;
        else if (res == 4) cout << tiempo.getMomento() << endl;
        
        else if (res == 5){ //Cambio la hora
            while (exitoso == false) {
                cout << "Ingresar la nueva hora: ";
                cin >> hora ;
                try{
                    tiempo.setHoras(hora);
                    exitoso = true;
                }
                catch(const invalid_argument& e){
                    res = manejoError();
                    if (res == 1) exitoso = false;
                    else return 0; //salgo del main o salgo del while?
                }
            } 
        }

        else if (res == 6){ //Cambio los minutos
            while (exitoso == false) {
                cout << "Ingresar el nuevo minuto: ";
                cin >> min;
                try{
                    tiempo.setMinutos(min);
                    exitoso = true;
                }
                catch(const invalid_argument& e){
                    res = manejoError();
                    if (res == 1) exitoso = false;
                    else return 0; //salgo del main o salgo del while?
                }
            } 
        }

        else if (res == 7){ //Cambio los segundos
            while (exitoso == false) {
                cout << "Ingresar el nuevo segundo: ";
                cin >> seg;
                try{
                    tiempo.setSegundos(seg);
                    exitoso = true;
                }
                catch(const invalid_argument& e){
                    res = manejoError();
                    if (res == 1) exitoso = false;
                    else return 0; //salgo del main o salgo del while?
                }
            } 
        }

        else if (res == 8){ //Cambio el momento del dia
            while (exitoso == false) {
                cout << "Ingresar el nuevo momento del dia (p.m o a.m): ";
                cin >> momto ;
                try{
                    tiempo.setMomento(momto);
                    exitoso = true;
                }
                catch(const invalid_argument& e){
                    res = manejoError();
                    if (res == 1) exitoso = false;
                    else return 0; //salgo del main o salgo del while?
                }
            } 
        }

        else if (res == 9){ //Imprimo por pantalla
            tiempo.imprimir();
        }
        else if (res == 10){ //Imprimo por pantalla con otro formato
            tiempo.ajusteformato();
        }
        else{ //lpm pone un valor correcto
            cout << "Ingrese un numero valido" << endl;
        }
    }
    return 0;


    //compilar para chequear
    //esta bien todos los catch q puse? no se me ocurre otra manera
    //arrgelar q no me reconozca el tiempo

    //agregar comentarios descriptivos

    //cuando pongo como compilar, asumo que ya se metieron correctamente a 
    //la carpeta?

    //el main con un choclo gigante me parece feisimo. defino funciones?
}