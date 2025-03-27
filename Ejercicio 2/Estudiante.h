#include <string>
#include <vector> 

class Estudiante{
    public:
    Estudiante(string nombrecompleto, int l, vector<pair<string, float>> notasfinales);
    string get_nombre();
    int get_legajo();
    float get_promedio();

    private:
    string nombre;
    int legajo;
    vector<pair<string, float>> notas; //uso un vector o un set?
};

//cuando defino el constructor estudiante, los parametros tienen que tener
//el mismo nombre que el que le doy en el .cpp de la clase?