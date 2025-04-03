#include "Banco.h"
#include <iostream>
#include <string>
using namespace std;


void CajaDeAhorro::retirar(int cantidad){
    if (balance < cantidad){
        throw invalid_argument("Error: Se quiere retirar mas dinero del que hay en la cuenta");
    }
    balance -= cantidad;
}  

void CajaDeAhorro::mostrarInfo(){
    contadorChequeos += 1; //me sirve para chequear la cantidad de veces que pide mostrarInfo de la cuenta
    if (contadorChequeos > 2){
        cout << "Muchos chequeos, descuento 20 de la caja de ahorro" << endl;
        balance -= 20;
    }
    cout << "Tipo: Caja de ahorro" << endl
    << "Balance: " << balance << endl
    << "Titular: " << titularCuenta << endl;
}
