#include "Numero.h"
#include <iostream>
#include <string>
using namespace std;

Complejo* Complejo::suma(Numero* otroNum){
    Complejo* otroComplejo = dynamic_cast<Complejo*>(otroNum); //otroNum podria ser otra cosa que un complejo, asi que me aseguro de que lo sea.
    if (otroComplejo == nullptr){ //cuando el casteo falla devuelve un nullptr
        throw invalid_argument("Se debe ingresar un numero complejo");
    }
    return new Complejo(real + otroComplejo -> real, img + otroComplejo -> img);
}

Complejo* Complejo::resta(Numero* otroNum){
    Complejo* otroComplejo = dynamic_cast<Complejo*>(otroNum); 
    if (otroComplejo == nullptr){ 
        throw invalid_argument("Se debe ingresar un numero complejo");
    }
    return new Complejo(real - otroComplejo -> real, img - otroComplejo -> img);
}

Complejo* Complejo::multiplicacion(Numero* otroNum){ //LA MULTIPLICACION SE HACE ASI?
    Complejo* otroComplejo = dynamic_cast<Complejo*>(otroNum); 
    if (otroComplejo == nullptr){ 
        throw invalid_argument("Se debe ingresar un numero complejo");
    }
    return new Complejo(real * otroComplejo -> real, img * otroComplejo -> img);
}

Complejo* Complejo::division(Numero* otroNum){
    Complejo* otroComplejo = dynamic_cast<Complejo*>(otroNum); //otroNum podria ser otra cosa que un entero, asi que me aseguro de que lo sea.
    if (otroComplejo == nullptr){ //estoo quiere decir que fallo
        throw invalid_argument("Se debe ingresar un numero complejo");
    }
    //CHEQUEAR DIVISION POR 0
    return new Complejo(real / otroComplejo -> real, img / otroComplejo -> img);

}

string Complejo::toString(){
    return to_string(real) + " " + to_string(img);
}