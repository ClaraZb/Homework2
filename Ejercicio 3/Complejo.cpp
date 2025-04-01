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
    float parte_real = real * otroComplejo -> real - img * otroComplejo -> img;
    float parte_imaginaria = real * otroComplejo -> img + img * otroComplejo -> real;
    return new Complejo(parte_real, parte_imaginaria);
}

Complejo* Complejo::division(Numero* otroNum){
    Complejo* otroComplejo = dynamic_cast<Complejo*>(otroNum); //otroNum podria ser otra cosa que un entero, asi que me aseguro de que lo sea.
    if (otroComplejo == nullptr){ //estoo quiere decir que fallo
        throw invalid_argument("Se debe ingresar un numero complejo");
    }
    if (otroComplejo -> real == 0 && otroComplejo -> img == 0){
        throw invalid_argument("Error - division por 0");
    } 
    Complejo conjugado(otroComplejo -> real, -(otroComplejo -> img));
    float divisor = otroComplejo -> real * otroComplejo -> real + otroComplejo -> img * otroComplejo -> img;
    Complejo *numerador = this -> multiplicacion(&conjugado);
    //delete numerador
    return new Complejo(numerador -> real /divisor, numerador -> img/divisor);

}

string Complejo::toString(){
    return to_string(real) + " " + to_string(img) + "i";
}