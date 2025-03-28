#include "Clase.h"
#include <vector>
#include "Estudiante.h"
#include <iostream>
#include <algorithm>
using namespace std;

Clase::Clase(vector<Estudiante*> lista){
    alumnos = lista;
}

void Clase::inscribir(Estudiante* alumno){
    alumnos.push_back(alumno);
    return;
}

bool Clase::desinscribir(Estudiante* alumno){
    for (int i = 0; i < alumnos.size(); i++){
        if (alumnos[i] == alumno){
            alumnos.erase(alumnos.begin() + i);
            return true;
        }
    }
    return false; //caso donde no se encontro al alumno en cuestion
}

bool Clase::esta_inscripto(Estudiante* alumno){
    for (int i = 0; i < alumnos.size(); i++){
        if (alumnos[i] == alumno){
            return true;
        }
    }
    return false;
}

bool Clase::esta_completa(){
    return alumnos.size() == 20;
}

void Clase::ordenar_clase(vector<Estudiante*> listaclase){
    sort(listaclase.begin(), listaclase.end(), [](Estudiante* alumno1, Estudiante* alumno2){
        return *alumno1 < *alumno2; //operador sobrecargado
    });
    return; //entender
}
void Clase::imprimir_clase(){
    ordenar_clase(alumnos);
    cout << this;
    /*
    for (int i = 0; i < alumnos.size(); i++){
        cout << alumnos[i] -> get_nombre() << endl;
    }
    */
}

/* 
ESTA FUNCION NO FUNCIONA
LA VDD NO ENTIENDO Q SERIA SOBRECARGAR ESTE OPERADOR EN ESPECIFICO
osea no tira error pero tpc lo q quiero

string Clase::operator<<(const Clase& clase) const{
    string temp;
    for (int i = 0; i < alumnos.size(); i++){
        temp += " ";
        temp += alumnos[i] -> get_nombre();
    }
    return temp;
}
*/

/*
- problemas al sobrecargar <<
- relacion entre las clases? tipo friends?
- creacion de las materias de la clase por consola?
*/