#include <Estudiante.h>

class Clase{
    public:
    Clase(vector<Estudiante*> lista);
    void inscribir(Estudiante* alumno);
    void desinscribir(Estudiante* alumno);
    bool esta_inscripto(Estudiante* alumno);
    bool esta_completa();


    private:
    vector<Estudiante*> alumnos;
};