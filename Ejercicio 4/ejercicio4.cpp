#include "Banco.h"
#include <iostream>
using namespace std;

/*
EXPLICAR POR QUE LOS PRIVATE PROTECTED Y ESO
*/

int main() {
    CajaDeAhorro ahorro(1000, "Clara");
    CuentaCorriente corriente(500, "Clara", &ahorro);

    //Situacion inicial
    cout << "Estado inicial:" << endl;
    ahorro.mostrarInfo();
    corriente.mostrarInfo();

    //Testeo retirar de la cuenta corriente
    cout << "\nRetiro $100 de la cuenta corriente" << endl;
    corriente.retirar(100);
    cout << "Estado actual: " << endl;
    corriente.mostrarInfo();

    //Testeo retirar mas que lo disponible en la cuenta corriente
    cout << "\nIntento retirar $600 de la cuenta corriente" << endl;
    corriente.retirar(600);
    cout << "Estado actual:" << endl;
    ahorro.mostrarInfo();
    corriente.mostrarInfo();

    //Accedo por tercera vez a la caja de ahorro (==accedo demasiadas veces)
    cout << "\nAccedo por tercera vez a la caja de ahorro" << endl;
    ahorro.mostrarInfo();

    //Testeo retirar mas que lo disponible en la cuenta corriente y en la caja de ahorro
    cout << "\nIntento retirar $1500 de la cuenta corriente" << endl;
    try{
        corriente.retirar(1500);
    }
    catch(const invalid_argument& e){
        cout << e.what() << endl;
    }

    return 0;
}