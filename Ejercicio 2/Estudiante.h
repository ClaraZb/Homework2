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
    vector<pair<string, float>> notas; 
};
