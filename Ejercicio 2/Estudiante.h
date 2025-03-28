#pragma once

#include <string>
#include <vector> 
using namespace std;

class Estudiante{
    public:
    Estudiante(string nombrecompleto, int l, vector<pair<string, float>> notasfinales);
    string get_nombre();
    int get_legajo();
    float get_promedio();
    bool operator == (const Estudiante& otro) const;
    bool operator < (const Estudiante& otro) const;
    
    private:
    string nombre;
    int legajo;
    vector<pair<string, float>> notas; //uso un vector o un set?
};

//cuando defino el constructor estudiante, los parametros tienen que tener
//el mismo nombre que el que le doy en el .cpp de la clase?