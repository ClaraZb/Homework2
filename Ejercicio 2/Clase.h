#pragma once
#include "Estudiante.h"

/*
Dejo en publico la sobrecarga del operador = para que pueda acceder desde el main.
Podria crear una funcion publica llamada Copiar y dejar la sobrecarga
del operador en private pero me parece mas claro poder usar el = en el main. 
Siento que queda mucho mas claro que estoy copiando, es intuitivo
*/

class Clase{
    public:
    Clase(vector<Estudiante*> lista); //Constructor
    void inscribir(Estudiante* alumno);
    bool desinscribir(Estudiante* alumno);
    bool esta_inscripto(Estudiante* alumno);
    bool esta_completa();
    void imprimir_clase();

    Clase& operator=(const Clase& otraClase); //sobrecarga de = para poder usar shallow copy
    
    private:
    vector<Estudiante*> alumnos; //vector que tiene los alumnos inscriptos (son punteros a objetos Estudiante)
    void ordenar_clase(vector<Estudiante*>); //metodo que me sirve para imprimir los alumnos de la clase
    friend ostream& operator<<(ostream& os, const Clase& clase); //sobrecarga del operador <<
};