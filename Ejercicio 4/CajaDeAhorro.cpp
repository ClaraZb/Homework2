#include "Banco.h"
#include <iostream>
#include <string>
using namespace std;


void CajaDeAhorro::retirar(int cantidad){
    if (balance - cantidad < 0){
        throw invalid_argument("Error: Se quiere retirar mas dinero del que hay en la cuenta");
    }
    balance -= cantidad;
}  

void CajaDeAhorro::mostrarInfo(){
    contadorChequeos += 1;
    if (contadorChequeos > 2){
        balance -= 20;
    }
    cout << "El balance de la caja de ahorro es de " << balance << endl
    << "El titular es " << titularCuenta << endl;
}
