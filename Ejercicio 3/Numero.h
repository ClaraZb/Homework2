#pragma once
#include <iostream>
#include <string>
using namespace std;

class Numero {
    public:
        Numero();
        virtual float suma(Numero* otroNum) = 0;
        virtual float resta(Numero* otroNum) = 0;
        virtual float multiplicacion(Numero* otroNum) = 0;
        virtual float division(Numero* otroNum) = 0; //opcional
        virtual string toString() = 0;
};

//IMPLEMENTO GETTERS Y SETTERS?

//Clases derivadas de numero
class Entero: public Numero{
    public:
        Entero(int v): valor(v){}
        float suma(Numero* otroNum) override;
        float resta(Numero* otroNum) override;
        float multiplicacion(Numero* otroNum) override;
        float division(Numero* otroNum) override;
        string toString() override; 
    private:
        int valor;
};

class Real: public Numero{
    public:
        Real(float v): valor(v) {};
        float suma(Numero* otroNum) override;
        float resta(Numero* otroNum) override;
        float multiplicacion(Numero* otroNum) override;
        float division(Numero* otroNum) override;
        string toString() override;
    private:
        float valor; 
};

class Complejo: public Numero{
    public:
        Complejo(float real, float imaginaria): real(real), img(imaginaria) {};
        float suma(Numero* otroNum) override;
        float resta(Numero* otroNum) override;
        float multiplicacion(Numero* otroNum) override;
        float division(Numero* otroNum) override;
        string toString() override; 
    private: //un complejo esta formado por una parte real y otra imaginaria
        float img;
        float real;
};