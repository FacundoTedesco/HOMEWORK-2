#ifndef TIEMPO_H
#define TIEMPO_H

#include <string>

class Tiempo {
private:
    int hora;         // De 1 a 12
    int minutos;      // De 0 a 59
    int segundos;     // De 0 a 59
    bool es_pm;       // true si es p.m., false si es a.m.

    bool esHoraValida(int hora) const;
    bool esMinutoSegundoValido(int valor) const;

public:
    Tiempo();                                    // Constructor por defecto
    Tiempo(int h);                               // Constructor con hora
    Tiempo(int h, int m);                        // Constructor con hora y minutos
    Tiempo(int h, int m, int s);                 // Constructor con hora, minutos y segundos
    Tiempo(int h, int m, int s, bool pm);        // Constructor completo

    // Setters
    void setHora(int h);
    void setMinutos(int m);
    void setSegundos(int s);
    void setPeriodo(bool pm);

    // Getters
    int getHora() const;
    int getMinutos() const;
    int getSegundos() const;
    bool getPeriodo() const;
    std::string getTiempoCompleto() const;

    // Método para mostrar hora en formato 24 horas
    std::string getHora24() const;
};

#endif
