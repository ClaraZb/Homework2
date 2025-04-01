#include "Banco.h"
#include <iostream>
#include <string>
using namespace std;


double verificarBalance(CajaDeAhorro &caja){
    return caja.balance;
}

void CuentaCorriente::retirar(int cantidad){
    if (balance < cantidad){
        if (cantidad <= verificarBalance(*cajaAhorro)){
            cout << "Fondos insuficientes, descontamos tambien de la caja de ahorro" << endl;
            float diferencia = cantidad - balance;
            balance = 0; //descontamos todo lo que podemos de balance
            cajaAhorro -> retirar(diferencia); //descontamos lo que queda de la caja de ahorro
        }
        else throw invalid_argument("Error: Se quiere retirar mas dinero del que hay en la cuenta y en la caja de ahorro");
    }
    else{
        balance -= cantidad;
    }
}  

void CuentaCorriente::mostrarInfo(){
    cout << "Tipo: Cuenta corriente" << endl
    << "Balance: " << balance << endl
    << "Titular: " << titularCuenta << endl;
}