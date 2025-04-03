#pragma once

#include <string>
#include <vector> 
using namespace std;

class Estudiante{
    public:
    //Constructor
    Estudiante(string nombrecompleto, int l, vector<pair<string, float>> notasfinales); 

    //Getters
    string get_nombre();
    int get_legajo();
    float get_promedio();
    
    //Sobrecarga de operadores
    bool operator == (const Estudiante& otro) const;
    bool operator < (const Estudiante& otro) const;
    
    private:
    //Declaracion de atributos
    string nombre;
    int legajo;
    vector<pair<string, float>> notas;
};
