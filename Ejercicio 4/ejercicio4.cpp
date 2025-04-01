#include "Banco.h"
#include <iostream>
using namespace std;

int main() {
    // Crear una Caja de Ahorro y una Cuenta Corriente
    CajaDeAhorro ahorro1(1000, "Juan");
    CuentaCorriente corriente1(500, "Juan");

    // Asociar la Caja de Ahorro a la Cuenta Corriente
    //corriente1.cajaAhorro = &ahorro1;

    // Mostrar balances iniciales
    cout << "Balances iniciales:" << endl;
    ahorro1.mostrarInfo();
    corriente1.mostrarInfo();

    // Intentar retirar más dinero del que hay en la Cuenta Corriente
    cout << "\nIntentando retirar $600 de la cuenta corriente..." << endl;
    corriente1.retirar(600);

    // Mostrar balances después del retiro
    cout << "\nBalances después del retiro:" << endl;
    ahorro1.mostrarInfo();
    corriente1.mostrarInfo();

    // Intentar retirar más dinero del que hay en ambas cuentas
    cout << "\nIntentando retirar $1500 de la cuenta corriente..." << endl;
    corriente1.retirar(1500);

    return 0;
}