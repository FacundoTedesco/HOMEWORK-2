#include "curso.h"
#include <algorithm>
#include <iostream>

using namespace std;

void Curso::inscribirEstudiante(shared_ptr<Estudiante> est) {
    if (estudiantes.size() < capacidad) {
        estudiantes.push_back(est);
        cout << "Estudiante inscripto: " << *est << endl;
    } else {
        cout << "El curso está completo." << endl;
    }
}

void Curso::desinscribirEstudiante(int legajo) {
    auto it = remove_if(estudiantes.begin(), estudiantes.end(),
        [legajo](const shared_ptr<Estudiante>& est) {
            return est->getLegajo() == legajo;
        });

    if (it != estudiantes.end()) {
        estudiantes.erase(it, estudiantes.end());
        cout << "Estudiante con legajo " << legajo << " desinscripto." << endl;
    } else {
        cout << "Estudiante no encontrado." << endl;
    }
}

bool Curso::estaInscripto(int legajo) const {
    return any_of(estudiantes.begin(), estudiantes.end(),
        [legajo](const shared_ptr<Estudiante>& est) {
            return est->getLegajo() == legajo;
        });
}

bool Curso::cursoCompleto() const {
    return estudiantes.size() >= capacidad;
}

void Curso::imprimirEstudiantes() const {
    vector<shared_ptr<Estudiante>> copiaEstudiantes = estudiantes;

    sort(copiaEstudiantes.begin(), copiaEstudiantes.end(),
        [](const shared_ptr<Estudiante>& a, const shared_ptr<Estudiante>& b) {
            return a->getNombreCompleto() < b->getNombreCompleto();
        });

    for (const auto& est : copiaEstudiantes) {
        cout << *est << endl;
    }
}

// Constructor de copia (realiza copia profunda de los estudiantes)
Curso::Curso(const Curso& otro) {
    for (const auto& est : otro.estudiantes) {
        estudiantes.push_back(make_shared<Estudiante>(*est));
    }
}