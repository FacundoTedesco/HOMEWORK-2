#include "tiempo.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>

Tiempo::Tiempo() : hora(0), minutos(0), segundos(0), es_pm(false) {}

Tiempo::Tiempo(int h) : Tiempo() {
    setHora(h);
}

Tiempo::Tiempo(int h, int m) : Tiempo(h) {
    setMinutos(m);
}

Tiempo::Tiempo(int h, int m, int s) : Tiempo(h, m) {
    setSegundos(s);
}

Tiempo::Tiempo(int h, int m, int s, bool pm) : Tiempo(h, m, s) {
    setPeriodo(pm);
}

bool Tiempo::esHoraValida(int h) const {
    return h >= 1 && h <= 12;
}

bool Tiempo::esMinutoSegundoValido(int valor) const {
    return valor >= 0 && valor <= 59;
}

void Tiempo::setHora(int h) {
    if (!esHoraValida(h)) {
        throw std::invalid_argument("La hora debe estar entre 1 y 12.");
    }
    hora = h;
}

void Tiempo::setMinutos(int m) {
    if (!esMinutoSegundoValido(m)) {
        throw std::invalid_argument("Los minutos deben estar entre 0 y 59.");
    }
    minutos = m;
}

void Tiempo::setSegundos(int s) {
    if (!esMinutoSegundoValido(s)) {
        throw std::invalid_argument("Los segundos deben estar entre 0 y 59.");
    }
    segundos = s;
}

void Tiempo::setPeriodo(bool pm) {
    es_pm = pm;
}

int Tiempo::getHora() const {
    return hora;
}

int Tiempo::getMinutos() const {
    return minutos;
}

int Tiempo::getSegundos() const {
    return segundos;
}

bool Tiempo::getPeriodo() const {
    return es_pm;
}

std::string Tiempo::getTiempoCompleto() const {
    std::ostringstream ss;
    ss << std::setw(2) << std::setfill('0') << hora << "h, "
       << std::setw(2) << std::setfill('0') << minutos << "m, "
       << std::setw(2) << std::setfill('0') << segundos << "s "
       << (es_pm ? "p.m." : "a.m.");
    return ss.str();
}

std::string Tiempo::getHora24() const {
    int hora24 = es_pm ? (hora == 12 ? 12 : hora + 12) : (hora == 12 ? 0 : hora);
    std::ostringstream ss;
    ss << std::setw(2) << std::setfill('0') << hora24 << ":"
       << std::setw(2) << std::setfill('0') << minutos << ":"
       << std::setw(2) << std::setfill('0') << segundos;
    return ss.str();
}