#include "numero.h"
#include <sstream>

// Implementación de Entero
Entero::Entero(int v) : valor(v) {}

Numero* Entero::suma(const Numero& otro) const {
    const Entero* otroEntero = dynamic_cast<const Entero*>(&otro);
    if (otroEntero)
        return new Entero(valor + otroEntero->valor);
    return nullptr;
}

Numero* Entero::resta(const Numero& otro) const {
    const Entero* otroEntero = dynamic_cast<const Entero*>(&otro);
    if (otroEntero)
        return new Entero(valor - otroEntero->valor);
    return nullptr;
}

Numero* Entero::multiplicacion(const Numero& otro) const {
    const Entero* otroEntero = dynamic_cast<const Entero*>(&otro);
    if (otroEntero)
        return new Entero(valor * otroEntero->valor);
    return nullptr;
}

std::string Entero::toString() const {
    return std::to_string(valor);
}

// Implementación de Real
Real::Real(double v) : valor(v) {}

Numero* Real::suma(const Numero& otro) const {
    const Real* otroReal = dynamic_cast<const Real*>(&otro);
    if (otroReal)
        return new Real(valor + otroReal->valor);
    return nullptr;
}

Numero* Real::resta(const Numero& otro) const {
    const Real* otroReal = dynamic_cast<const Real*>(&otro);
    if (otroReal)
        return new Real(valor - otroReal->valor);
    return nullptr;
}

Numero* Real::multiplicacion(const Numero& otro) const {
    const Real* otroReal = dynamic_cast<const Real*>(&otro);
    if (otroReal)
        return new Real(valor * otroReal->valor);
    return nullptr;
}

std::string Real::toString() const {
    return std::to_string(valor);
}

// Implementación de Complejo
Complejo::Complejo(double r, double i) : real(r), imaginario(i) {}

Numero* Complejo::suma(const Numero& otro) const {
    const Complejo* otroComplejo = dynamic_cast<const Complejo*>(&otro);
    if (otroComplejo)
        return new Complejo(real + otroComplejo->real, imaginario + otroComplejo->imaginario);
    return nullptr;
}

Numero* Complejo::resta(const Numero& otro) const {
    const Complejo* otroComplejo = dynamic_cast<const Complejo*>(&otro);
    if (otroComplejo)
        return new Complejo(real - otroComplejo->real, imaginario - otroComplejo->imaginario);
    return nullptr;
}

Numero* Complejo::multiplicacion(const Numero& otro) const {
    const Complejo* otroComplejo = dynamic_cast<const Complejo*>(&otro);
    if (otroComplejo) {
        double nuevoReal = (real * otroComplejo->real) - (imaginario * otroComplejo->imaginario);
        double nuevoImag = (real * otroComplejo->imaginario) + (imaginario * otroComplejo->real);
        return new Complejo(nuevoReal, nuevoImag);
    }
    return nullptr;
}

std::string Complejo::toString() const {
    return std::to_string(real) + " + " + std::to_string(imaginario) + "i";
}