#include <Estudiante.h>
#include <string>
#include <vector>
using namespace std;

//Constructor
Estudiante::Estudiante(string nombrecompleto, int l, vector<pair<string, float>> notasfinales){
    nombre = nombrecompleto;
    legajo = l;
    notas = notasfinales;
}

//Defino los getters
string Estudiante::get_nombre(){
    return nombre;
}
int Estudiante::get_legajo(){
    return legajo;
}
float Estudiante::get_promedio(){
    float suma = 0;
    int cant_elts = notas.size();
    for (int i = 0; i <= cant_elts; i++){
        suma += notas[i].second; //accedo al segundo elemento del par
    }
    return suma/cant_elts;
}