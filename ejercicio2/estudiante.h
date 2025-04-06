#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Estudiante {
private:
    string nombreCompleto;
    int legajo;
    vector<pair<string, float>> cursos; // Nombre del curso y nota

public:
    Estudiante(const string& nombre, int leg, const vector<pair<string, float>>& notas);

    string getNombreCompleto() const;
    int getLegajo() const;
    float getPromedio() const;

    // Se declara como friend para permitir el acceso a atributos privados
    friend ostream& operator<<(ostream& os, const Estudiante& est);
};

#endif // ESTUDIANTE_H