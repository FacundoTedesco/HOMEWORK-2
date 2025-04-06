#include <iostream>
#include "numero.h"

int main() {
    Entero e1(5), e2(3);
    Real r1(2.5), r2(1.5);
    Complejo c1(1, 2), c2(3, 4);

    Numero* resultado;

    // Operaciones con Enteros
    resultado = e1.suma(e2);
    if (resultado) std::cout << "Entero suma: " << resultado->toString() << std::endl;
    delete resultado;

    resultado = e1.resta(e2);
    if (resultado) std::cout << "Entero resta: " << resultado->toString() << std::endl;
    delete resultado;

    resultado = e1.multiplicacion(e2);
    if (resultado) std::cout << "Entero multiplicación: " << resultado->toString() << std::endl;
    delete resultado;

    // Operaciones con Reales
    resultado = r1.suma(r2);
    if (resultado) std::cout << "Real suma: " << resultado->toString() << std::endl;
    delete resultado;

    resultado = r1.resta(r2);
    if (resultado) std::cout << "Real resta: " << resultado->toString() << std::endl;
    delete resultado;

    resultado = r1.multiplicacion(r2);
    if (resultado) std::cout << "Real multiplicación: " << resultado->toString() << std::endl;
    delete resultado;

    // Operaciones con Complejos
    resultado = c1.suma(c2);
    if (resultado) std::cout << "Complejo suma: " << resultado->toString() << std::endl;
    delete resultado;

    resultado = c1.resta(c2);
    if (resultado) std::cout << "Complejo resta: " << resultado->toString() << std::endl;
    delete resultado;

    resultado = c1.multiplicacion(c2);
    if (resultado) std::cout << "Complejo multiplicación: " << resultado->toString() << std::endl;
    delete resultado;

    return 0;
}