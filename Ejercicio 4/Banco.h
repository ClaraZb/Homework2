#pragma once
#include <iostream>
#include <string>
using namespace std;


//Clase abstracta
class Banco {
    public:
        virtual void depositar(int cantidad) {
            balance += cantidad;
        } //metodo virtual no puro, lo implemento aca
        virtual void retirar(int cantidad) = 0; //metodo virtual puro
        virtual void mostrarInfo() = 0; //metodo virtual puro
    protected:
        double balance;
        string titularCuenta;
};

//Clases derivadas de banco
class CajaDeAhorro: public Banco{
    public:
        CajaDeAhorro(double b, string titular){
            balance = b;
            titularCuenta = titular;
        } 
        void retirar(int cantidad) override;
        void mostrarInfo() override;

        friend double verificarBalance(CajaDeAhorro& caja);
    private:
        int contadorChequeos = 0;
};

class CuentaCorriente: public Banco{
    public:
        CuentaCorriente(double b, string titular){
            balance = b;
            titularCuenta = titular;
        } 
        void retirar(int cantidad) override;
        void mostrarInfo() override;
        void asociarCajaAhorro(CajaDeAhorro* caja);

        friend double verificarBalance(CajaDeAhorro& caja);
    private:
        CajaDeAhorro* cajaAhorro;
};