#include "Numero.h"
#include <iostream>
#include <string>
using namespace std;


Entero* Entero::suma(Numero* otroNum){
    Entero* otroEntero = dynamic_cast<Entero*>(otroNum); //otroNum podria ser otra cosa que un entero, asi que me aseguro de que lo sea.
    if (otroEntero == nullptr){ //cuando el casteo falla devuelve un nullptr
        throw invalid_argument("Se debe ingresar un entero");
    }
    return new Entero(valor + otroEntero -> valor);
}   

Entero* Entero::resta(Numero* otroNum){
    Entero* otroEntero = dynamic_cast<Entero*>(otroNum); 
    if (otroEntero == nullptr){ 
        throw invalid_argument("Se debe ingresar un entero");
    }
    return new Entero(valor - otroEntero -> valor);
}

Entero* Entero::multiplicacion(Numero* otroNum){
    Entero* otroEntero = dynamic_cast<Entero*>(otroNum); 
    if (otroEntero == nullptr){ 
        throw invalid_argument("Se debe ingresar un entero");
    }
    return new Entero(valor * otroEntero -> valor);
}

Entero* Entero::division(Numero* otroNum){
    Entero* otroEntero = dynamic_cast<Entero*>(otroNum); 
    if (otroEntero == nullptr){ 
        throw invalid_argument("Se debe ingresar un entero");
    }
    if (otroEntero -> valor == 0){ //Chequeo la division por 0
        throw invalid_argument("Error - division por 0");
    } 
    return new Entero(valor - otroEntero -> valor);
}

string Entero::toString(){
    return to_string(valor);
}