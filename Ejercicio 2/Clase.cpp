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
    return false; //manejo el caso donde no se encontro al alumno en cuestion?
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
    for (int i = 0; i < alumnos.size(); i++){
        cout << alumnos[i] << endl;
    }
}
void Clase::operator<<(const Clase& clase) const{
    return;
}
/*
- llamo muchas veces a estudiante en los diferentes archivos? 
o como inclui clase.h (que incluye a su vez estudiante.h) no tengo que 
incluirla nuevamente ------------------ usar pragma once
- problemas al sobrecargar <<
- relacion entre las clases? tipo friends?
- creacion de las materias de la clase por consola?
- fatal error de la terminal :)
*/