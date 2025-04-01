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
    delete respuesta;
    respuesta = entero1.resta(&entero2);
    cout << "La resta de " + entero1.toString() + " y de " + entero2.toString() + " es " + respuesta -> toString() << endl;
    delete respuesta;
    respuesta = entero1.multiplicacion(&entero2);
    cout << "La multiplicacion de " + entero1.toString() + " y de " + entero2.toString() + " es " + respuesta -> toString() << endl;
    delete respuesta;
    respuesta = entero1.division(&entero2);
    cout << "La division de " + entero1.toString() + " y de " + entero2.toString() + " es " + respuesta -> toString() << endl;
    delete respuesta;

    //Testeo reales
    cout << "\nTesteo de reales" << endl;
    Real real1 = Real(1.2);
    Real real2 = Real(sqrt(5));

    respuesta = real1.suma(&real2);
    cout << "La suma de " + real1.toString() + " y de " + real2.toString() + " es " + respuesta -> toString() << endl;
    delete respuesta;
    respuesta = real1.resta(&real2);
    cout << "La resta de " + real1.toString() + " y de " + real2.toString() + " es " + respuesta -> toString() << endl;
    delete respuesta;
    respuesta = real1.multiplicacion(&real2);
    cout << "La multiplicacion de " + real1.toString() + " y de " + real2.toString() + " es " + respuesta -> toString() << endl;
    delete respuesta;
    respuesta = real1.division(&real2);
    cout << "La division de " + real1.toString() + " y de " + real2.toString() + " es " + respuesta -> toString() << endl;
    delete respuesta;

    //Testeo complejos
    cout << "\nTesteo de complejos" << endl;
    Complejo complejo1 (7.0, -9.0); //7 -9i
    Complejo complejo2(-3.0, -5.0); //-3 - 5i

    respuesta = complejo1.suma(&complejo2);
    cout << "La suma de " << complejo1.toString() << " y " << complejo2.toString() << " es " << respuesta -> toString() << endl;
    delete respuesta;
    respuesta = complejo1.resta(&complejo2);
    cout << "La resta de " << complejo1.toString() << " y " << complejo2.toString() << " es " << respuesta -> toString() << endl;
    delete respuesta;
    respuesta = complejo1.multiplicacion(&complejo2);
    cout << "La multiplicacion de " << complejo1.toString() << " y " << complejo2.toString() << " es " << respuesta -> toString() << endl;
    delete respuesta;
    respuesta = complejo1.division(&complejo2);
    cout << "La division de " << complejo1.toString() << " y " << complejo2.toString() << " es " << respuesta -> toString() << endl;
    delete respuesta;

    //Testeo errores
    cout << "\nTesteo de errores" << endl;
    Real real0(0.0);

    //intento inicializar un entero con un numero flaot
    try{
        Entero entero3(3.4); //lo castea implicitamente a un int
        cout << entero3.toString() << endl;
    }
    catch (const invalid_argument &e){
        cout << "Error: ingrese el tipo correspondiente" << endl;
    }
    
    //intento sumar un entero con un real
    try {
        respuesta = entero1.suma(&real2); 
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    //intento dividir por 0
    try {
        respuesta = real1.division(&real0);
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
}
