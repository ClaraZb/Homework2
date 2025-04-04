#pragma once
#include <iostream>
#include <string>
using namespace std;

/*Lo que mas me costo de este ejercicio fue entender la  utilidad de las clases. Al principio habia definido en la 
interfaz que los metodos suma, resta, multiplicacion y division devuelvan un float, que supuse que englobaria todos los casos
de las diferentes clases. Eso funciono hasta la clase Complejos. Ahi me di cuenta que deberia devolver un Complejo, y en las otras
clases deberia devolver el tipo correspondiente. Para que eso funcione, cambie en la interfaz el float por un puntero a Numero. 
De esa manera podria devolver un Entero, Real o Complejo segun correspondiera.*/


//Interfaz
class Numero {
    public:
    virtual Numero* suma(Numero* otroNum) = 0;
    virtual Numero* resta(Numero* otroNum) = 0;
    virtual Numero* multiplicacion(Numero* otroNum) = 0;
    virtual Numero* division(Numero* otroNum) = 0; //opcional
    virtual string toString() = 0;
};

//Clases derivadas de numero
class Entero: public Numero{
    public:
    Entero(int v): valor(v){} //Constructor
    Numero* suma(Numero* otroNum) override; //Implemento las clases definidas en la interfaz
    Numero* resta(Numero* otroNum) override;
    Numero* multiplicacion(Numero* otroNum) override;
    Numero* division(Numero* otroNum) override;
    string toString() override; 

    private:
    int valor;
};

class Real: public Numero{
    public:
    Real(float v): valor(v) {}; //Constructor
    Numero* suma(Numero* otroNum) override; //Implemento las clases definidas en la interfaz
    Numero* resta(Numero* otroNum) override;
    Numero* multiplicacion(Numero* otroNum) override;
    Numero* division(Numero* otroNum) override;
    string toString() override;

    private:
    float valor; 
};

class Complejo: public Numero{
    public:
    Complejo(float parte_real, float parte_imaginaria): real(parte_real), img(parte_imaginaria) {}; //Constructor
    Numero* suma(Numero* otroNum) override; //Implemento las clases definidas en la interfaz;
    Numero* resta(Numero* otroNum) override;
    Numero* multiplicacion(Numero* otroNum) override;
    Numero* division(Numero* otroNum) override;
    string toString() override; 

    private: //un complejo esta formado por una parte real y otra imaginaria
    float img;
    float real;
};