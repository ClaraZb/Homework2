#include "Clase.h"
#include "Estudiante.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
En primer lugar implemente la clase Estudiante. En estudiante.h declare los metodos
y atributos que necesitaria y los implemente en estudiante.cpp. 
Luego declare la clase Clase (curso). Esta clase tiene un atributo que es una lista
que contiene objetos Estudiante. La relacion entre estas clases es entonces de "has-a"
(agregacion), en la que Clase actua como un "todo" y los objetos Estudiante como sus "partes". 
Sin embargo, no tienen una dependencia total, pueden existir estudiantes aunque no haya
una Clase en la que esten. 

En el main testee todas las funciones necesarias, y para hacer mas claro el codigo
modularice un par de partes.

Explicacion de como copie la clase: (o sino ver este mismo comentario en Clase.cpp)
Decido hacer un shallow copy (para eso antes sobrecargo el operador =). Este solo funciona 
si no se tiene memoria alocada dinámicamente dentro del objeto, lo que es el caso de esta clase. 
Ademas, como sabemos que un estudiante puede estar en muchos cursos a la vez, no conviene 
duplicarlos, por si se modifican y quedan diferencias entre ellos. De esta manera, tanto la copia 
como el original comparten los punteros a los Estudiantes, entonces si hay una modificacion en el 
Estudiante, en ambos la informacion va a estar actualizada.
Ademas con shallpw copy es mas simple jsjjs.
*/

vector<pair<string, float>> crearNotas(string nombre){ 
    //Agrego los cursos a los que esta inscripto el estudiante con sus notas
    vector<pair<string, float>> notas = {};
    string materia = " ";
    float nota = 0;
    cout << "A que materias esta inscripto " << nombre << "? " << endl;
    cout << "Agregar materias una a una. Luego la nota. Cuando hayas terminado escribir exit" << endl;
    while (materia != "exit"){
        cout << "Agregar materia: ";
        cin >> materia;
        if (materia == "exit") break;
        cout << "Agregar nota: ";
        cin >> nota;
        notas.push_back(make_pair(materia, nota));
    }
    return notas;
}

void imprimirInscripcion(Estudiante& alumno, bool estaInscripto) {
    //Imprimo en pantalla si el alumno esta inscripto
    if (estaInscripto) {
        cout << "El alumno " + alumno.get_nombre() + " está inscrito" << endl;
    } 
    else {
        cout << "El alumno " + alumno.get_nombre() + " no está inscrito" << endl;
    }
}

void testeoPromedio(Estudiante& alumno){
    //Imprimo en pantalla el promedio del alumno
    cout << "El estudiante " << alumno.get_nombre()
    << "tiene un promedio de " << alumno.get_promedio()
    << endl;
}

int main(){
    //Creo los estudiantes
    string nombre1 = "Clara Zavaroni";
    vector<pair<string, float>> notas1 = crearNotas(nombre1);
    Estudiante alumno1(nombre1, 364554, notas1);
    cout << endl;

    string nombre2 = "Juana Bertone";
    vector<pair<string, float>> notas2 = crearNotas(nombre2);
    Estudiante alumno2(nombre2, 376845, notas2);
    cout << endl;

    string nombre3 = "Bianca Paz";
    vector<pair<string, float>> notas3 = crearNotas(nombre3);
    Estudiante alumno3(nombre3, 306845, notas3);
    cout << endl;

    //Testeo promedios
    testeoPromedio(alumno1);
    testeoPromedio(alumno2);
    testeoPromedio(alumno3);

    //Creo un objeto Clase y asigno alumno1 y alumno2 a ese curso
    vector<Estudiante*> alumnos = {&alumno1, &alumno3};
    Clase teoricaParadigmas(alumnos);

    //Testeo funciones inscribir y desinscribir
    cout << endl <<"Testeo las funciones inscribir y desinscribir:" << endl;
    cout << "[Inscribo a un alumno]" << endl;
    teoricaParadigmas.inscribir(&alumno2);
    bool res = teoricaParadigmas.esta_inscripto(&alumno2);
    imprimirInscripcion(alumno2, res);

    cout << "[Desinscribo a un alumno]" << endl;
    teoricaParadigmas.desinscribir(&alumno2);
    res = teoricaParadigmas.esta_inscripto(&alumno2);
    imprimirInscripcion(alumno2, res);

    //Testeo si la clase esta completa
    cout << "Testeo si la clase esta completa:" << endl;
    res = teoricaParadigmas.esta_completa();
    if (res == 1){
        cout << "La clase esta completa" << endl << endl;
    }
    else cout << "La clase no esta completa" << endl << endl;

    //Testeo imprimir_clase
    cout << "Imprimo la clase: " << endl;
    teoricaParadigmas.imprimir_clase();

    //Testeo la implementacion de la copia con shallowcopy
    cout << "\nTesteo la implementacion de la copia: " << endl;
    Clase copiaTeoricaParadigmas({});
    copiaTeoricaParadigmas = teoricaParadigmas; //utilizo la sobrecarga del operador =
    cout << "Copia Teorica Paradigmas: " << endl;
    copiaTeoricaParadigmas.imprimir_clase();

    cout << "\n[Desincribo un alumno de la original]" << endl << endl;
    teoricaParadigmas.desinscribir(&alumno1);
    cout << "Teorica despues de desinscribir: " << endl;
    teoricaParadigmas.imprimir_clase();
    cout << "Copa de teorica despues de desinscribir en la original" << endl;
    copiaTeoricaParadigmas.imprimir_clase();
    cout << "No se modifico :))))" << endl;

}