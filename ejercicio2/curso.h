#ifndef CURSO_H
#define CURSO_H

#include "estudiante.h"
#include <vector>
#include <memory>

using namespace std;

class Curso {
private:
    vector<shared_ptr<Estudiante>> estudiantes;
    const int capacidad = 20;

public:
    Curso() = default;

    // Constructor de copia (copia profunda)
    Curso(const Curso& otro);

    void inscribirEstudiante(shared_ptr<Estudiante> est);
    void desinscribirEstudiante(int legajo);
    bool estaInscripto(int legajo) const;
    bool cursoCompleto() const;
    void imprimirEstudiantes() const;
};

#endif // CURSO_H