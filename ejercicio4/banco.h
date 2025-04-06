#ifndef banco_H
#define banco_H

#include <iostream>
#include <string>

using namespace std;

class Banco {
protected:
    string titularcuenta;
private:
    double balance;
public:
    Banco(string titular, double saldo);
    void depositar(double cantidad);
    virtual void retirar(double cantidad) = 0;
    double getBalance() const;
    void descontar(double cantidad); //creado porque sino en retirar me generaba una recursividad infinita

    // Hacemos Mostrardatos público para que pueda llamarse desde main (probando y funciono :) )
    virtual void Mostrardatos() const = 0;

    friend class CuentaCorriente;
};

class CuentaAhorro : public Banco {
private:
    int mostrada;
public:
    CuentaAhorro(string titular, double saldo);
    void retirar(double cantidad) override;
    void Mostrardatos() const override;
};

class CuentaCorriente : public Banco {
private:
    CuentaAhorro* caja;
public:
    CuentaCorriente(string titular, double saldo, CuentaAhorro* caja);
    void retirar(double cantidad) override;
    void Mostrardatos() const override;
};

#endif



