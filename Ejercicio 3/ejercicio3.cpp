#include "Numero.h"
#include <iostream>
#include <cmath> //para sqrt
using namespace std;

int main(){
    //Testeo enteros
    cout << "Testeo de enteros: " << endl;
    Entero entero1(5);
    Entero entero2(4);
    Numero* respuesta = entero1.suma(&entero2);
    cout << "La suma de " + entero1.toString() + " y de " + entero2.toString() + " es " + respuesta -> toString() << endl;
    //delete memoria para liberar memoria????

    //Testeo reales
    cout << "\n Testeo de reales" << endl;
    Real real1 = Real(1.2);
    Real real2 = Real(sqrt(5));
    Real real3 = Real(3);
    Real real4 = Real(0);

    respuesta = real1.suma(&real2);
    cout << "La suma de " + real1.toString() + " y de " + real2.toString() + " es " + respuesta -> toString() << endl;
    respuesta = real1.suma(&real3);
    cout << "La suma de " + real1.toString() + " y de " + real3.toString() + " es " + respuesta -> toString() << endl;
    
    //Testeo complejos

    //Testeo errores
    /*
    Entero entero3 = Entero(3.4);
    respuesta = entero1.suma(real2);
    respuesta = entero1.suma(real1);
    respuesta = real1/real4;*/
}
