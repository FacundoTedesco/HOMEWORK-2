#include "estudiante.h"

Estudiante::Estudiante(const string& nombre, int leg, const vector<pair<string, float>>& notas)
    : nombreCompleto(nombre), legajo(leg), cursos(notas) {}

string Estudiante::getNombreCompleto() const {
    return nombreCompleto;
}

int Estudiante::getLegajo() const {
    return legajo;
}

float Estudiante::getPromedio() const {
    float suma = 0;
    for (const auto& curso : cursos) {
        suma += curso.second;
    }
    return cursos.empty() ? 0.0f : suma / cursos.size();
}

// Definición del operador << como función amiga
ostream& operator<<(ostream& os, const Estudiante& est) {
    os << "Nombre: " << est.nombreCompleto
       << ", Legajo: " << est.legajo
       << ", Promedio: " << est.getPromedio();
    return os;
}