#include <iostream>
#include <string>
#include <vector> 
using namespace std;

class Estudiante{
    public:
    Estudiante(string nombre, int legajo, vector<pair<string, float>> notas);
    string get_nombre();
    int get_legajo();
    float get_promedio();

    private:
    string nombre;
    int legajo;
    vector<pair<string, float>> notas; //uso un vector o un set?
};