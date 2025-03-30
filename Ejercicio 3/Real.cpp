#include "Numero.h"
#include <iostream>
#include <string>
using namespace std;


Real* Real::suma(Numero* otroNum){
    Real* otroReal = dynamic_cast<Real*>(otroNum); //otroNum podria ser otra cosa que un real, asi que me aseguro de que lo sea.
    if (otroReal == nullptr){ //cuando el casteo falla devuelve un nullptr
        throw invalid_argument("Se debe ingresar un numero real");
    }
    return new Real(valor + otroReal -> valor);
}

Real* Real::resta(Numero* otroNum){
    Real* otroReal = dynamic_cast<Real*>(otroNum); 
    if (otroReal == nullptr){ 
        throw invalid_argument("Se debe ingresar un numero real");
    }
    return new Real(valor - otroReal -> valor);
}

Real* Real::multiplicacion(Numero* otroNum){
    Real* otroReal = dynamic_cast<Real*>(otroNum); 
    if (otroReal == nullptr){ 
        throw invalid_argument("Se debe ingresar un numero real");
    }
    return new Real(valor * otroReal -> valor);
}

Real* Real::division(Numero* otroNum){
    Real* otroReal = dynamic_cast<Real*>(otroNum); 
    if (otroReal == nullptr){ 
        throw invalid_argument("Se debe ingresar un numero real");
    }
    if (otroReal -> valor == 0){
        throw invalid_argument("Error - division por 0");
    } 
    return new Real(valor - otroReal -> valor);
}

string Real::toString(){
    return to_string(valor);
}