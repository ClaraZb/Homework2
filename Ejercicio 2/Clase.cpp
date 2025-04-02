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
    return; 
}
void Clase::imprimir_clase(){
    ordenar_clase(alumnos);
    cout << *this; //creo que quiero imprimir la clase?
}

ostream& operator<<(ostream& os, const Clase& clase){
    string temp;
    for (int i = 0; i < clase.alumnos.size(); i++){
        os << clase.alumnos[i] -> get_nombre() << endl;
    }
    return os;
}

//Sobrecargo el operador = para poder copiar 
Clase& Clase::operator=(const Clase& otraClase){
    alumnos = otraClase.alumnos;
    return *this;
}

/*Decido hacer un shallow copy. Este solo funciona si no se tiene 
memoria alocada dinámicamente dentro del objeto, lo que es el caso
de esta clase. Ademas, como sabemos que un estudiante puede estar en 
muchos cursos a la vez, no conviene duplicarlos, por si se modifican
y quedan diferencias entre ellos. Ademas es mas simple jsjjs*/
