#include <Clase.h>
#include <Estudiante.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string nombre = "ClaraZavaroni";
    vector<pair<string, float>> notas = {{"Fisica", 7}, {"Paradigmas",9}};
    Estudiante alumno1(nombre, 364554, notas);

    string nombre = "JuanaBertone";
    vector<pair<string, float>> notas = {{"Fisica", 9}, {"Paradigmas",6}};
    Estudiante alumno2(nombre, 376845, notas);

    vector<Estudiante*> alumnos = {&alumno1};
    Clase teoricaParadigmas(alumnos);

    teoricaParadigmas.inscribir(&alumno2);
    bool res = teoricaParadigmas.esta_inscripto(&alumno2);
    if (res == 1){
        cout << "Esta inscripo" << endl;
    }
    else cout << "No esta inscripto" << endl;

    teoricaParadigmas.desinscribir(&alumno2);
    res = teoricaParadigmas.esta_inscripto(&alumno2);
    if (res == 1){
        cout << "Esta inscripo" << endl;
    }
    else cout << "No esta inscripto" << endl;

    teoricaParadigmas.esta_completa();
}