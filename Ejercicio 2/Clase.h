#pragma once
#include "Estudiante.h"

class Clase{
    public:
    Clase(vector<Estudiante*> lista);
    void inscribir(Estudiante* alumno);
    bool desinscribir(Estudiante* alumno);
    bool esta_inscripto(Estudiante* alumno);
    bool esta_completa();
    void imprimir_clase();
    Clase& operator=(const Clase& otraClase); //sobrecarga de = para poder copiar
    
    private:
    vector<Estudiante*> alumnos;
    void ordenar_clase(vector<Estudiante*>);
    friend ostream& operator<<(ostream& os, const Clase& clase);
};