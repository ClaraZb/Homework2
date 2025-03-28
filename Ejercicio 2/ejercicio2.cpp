#include "Clase.h"
#include "Estudiante.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string nombre1 = "ClaraZavaroni";
    vector<pair<string, float>> notas1 = {{"Fisica", 7}, {"Paradigmas",9}};
    Estudiante alumno1(nombre1, 364554, notas1);

    string nombre2 = "JuanaBertone";
    vector<pair<string, float>> notas2 = {{"Fisica", 9}, {"Paradigmas",6}};
    Estudiante alumno2(nombre2, 376845, notas2);

    vector<Estudiante*> alumnos = {&alumno1};
    Clase teoricaParadigmas(alumnos);

    teoricaParadigmas.inscribir(&alumno2);
    bool res = teoricaParadigmas.esta_inscripto(&alumno2);
    if (res == 1){
        cout << "El alumno " + alumno2.get_nombre() + " esta inscripto" << endl;
    }
    else cout << "El alumno " + alumno2.get_nombre() + " no esta inscripto" << endl;

    teoricaParadigmas.desinscribir(&alumno2);
    res = teoricaParadigmas.esta_inscripto(&alumno2);
    if (res == 1){
        cout << "El alumno " + alumno2.get_nombre() + " esta inscripto" << endl;
    }
    else cout << "El alumno " + alumno2.get_nombre() + " no esta inscripto""No esta inscripto" << endl;

    res = teoricaParadigmas.esta_completa();
    if (res == 1){
        cout << "La clase esta completa" << endl;
    }
    else cout << "La clase no esta completa" << endl;
}