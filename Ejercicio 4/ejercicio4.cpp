#include "Banco.h"
#include <iostream>
using namespace std;

/*
Para este ejercicio, cree una clase abstracta (tiene metodos virtuales puros y otros no) 
de la que derivan las clases CajaDeAhorro y CuentaCorriente. Los metodos declarados como virtuales
puros los implemento si o si en las clases derivadas con override. 
Aparte, dentro de las clases derivadas creo metodos que no estan en la clase abstracta base.

En la clase abstracta Banco pongo los metodos en public ya que van a ser accedidos 
por el usuario. Por otro lado, los atributos los declaro como protected para que las 
clases derivadas puedan acceder a ellos y manipularlos. 
Para el caso de las clases derivadas CuentaCorriente y CajaDeAhorro, deje los metodos 
en public y los atributos en privado, ya que no quiero que se pueda acceder a ellos 
desde el main por ejemplo. 

En el main testeo posibles funcionalidades de estas clases, teniendo en cuenta las posibles
situaciones mencionadas en la consigna. 
*/

int main() {
    //Inicializo las clases
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