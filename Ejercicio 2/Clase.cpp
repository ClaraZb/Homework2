#include <Clase.h>
#include <vector>
#include <Estudiante.h>
using namespace std;

Clase::Clase(vector<Estudiante*> lista){
    alumnos = lista;
}

void Clase::inscribir(Estudiante* alumno){
    alumnos.push_back(alumno);
    return;
}

void Clase::desinscribir(Estudiante* alumno){
    //buscar al alumno en cuestion
    // para eso tenes q comparar objetos: definir == ?
}

bool Clase::esta_inscripto(Estudiante* alumno){
    //tb tenes que comparar
    //comparar por legajo
}

bool Clase::esta_completa(){
    return alumnos.size() == 20;
}

//llamo muchas veces a estudiante en los diferentes archivos? 
//o como inclui clase.h (que incluye a su vez estudiante.h) no tengo que 
//incluirla nuevamente