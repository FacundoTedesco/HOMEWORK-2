#ifndef NUMERO_H
#define NUMERO_H

#include <string>

class Numero {
public:
    virtual Numero* suma(const Numero& otro) const = 0;
    virtual Numero* resta(const Numero& otro) const = 0;
    virtual Numero* multiplicacion(const Numero& otro) const = 0;
    virtual std::string toString() const = 0;
    virtual ~Numero() {}
};

class Entero : public Numero {
private:
    int valor;
public:
    Entero(int v);
    Numero* suma(const Numero& otro) const override;
    Numero* resta(const Numero& otro) const override;
    Numero* multiplicacion(const Numero& otro) const override;
    std::string toString() const override;
};

class Real : public Numero {
private:
    double valor;
public:
    Real(double v);
    Numero* suma(const Numero& otro) const override;
    Numero* resta(const Numero& otro) const override;
    Numero* multiplicacion(const Numero& otro) const override;
    std::string toString() const override;
};

class Complejo : public Numero {
private:
    double real, imaginario;
public:
    Complejo(double r, double i);
    Numero* suma(const Numero& otro) const override;
    Numero* resta(const Numero& otro) const override;
    Numero* multiplicacion(const Numero& otro) const override;
    std::string toString() const override;
};

#endif 