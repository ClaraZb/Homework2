#include "Banco.h"
#include <iostream>
#include <string>
using namespace std;

double verificarBalance(CajaDeAhorro & caja){
    return caja.balance;
}

void CuentaCorriente::retirar(int cantidad){
    if (balance - cantidad < 0){
        if (cantidad <= verificarBalance(*cajaAhorro)){
            cout << "Fondos insuficientes, descontamos de la caja de ahorro" << endl;
            cajaAhorro -> retirar(cantidad);
        }
        else throw invalid_argument("Error: Se quiere retirar mas dinero del que hay en la cuenta y en la caja de ahorro");
    }
    else{
        balance -= cantidad;
    }
}  

void CuentaCorriente::mostrarInfo(){
    cout << "El balance de la cuenta corriente es de " << balance << endl
    << "El titular es " << titularCuenta << endl;
}