#include "banco.h"

using namespace std;

Banco::Banco(string titular, double saldo) : titularcuenta(titular), balance(saldo) {}

void Banco::depositar(double cantidad) {
    if (cantidad > 0) {
        balance += cantidad;
        cout << "Se depositaron $" << cantidad << " en la cuenta de " << titularcuenta << ".\n";
    }
}

double Banco::getBalance() const {
    return balance;
}

void Banco::descontar(double cantidad) {
    balance -= cantidad;
}

CuentaAhorro::CuentaAhorro(string titular, double saldo) : Banco(titular, saldo), mostrada(0) {}

void CuentaAhorro::Mostrardatos() const {
    cout << "Caja de Ahorro - Titular: " << titularcuenta << ", Balance: $" << getBalance() << "\n";
    if (++const_cast<CuentaAhorro*>(this)->mostrada > 2) {
        const_cast<CuentaAhorro*>(this)->descontar(20);
        cout << "Se han descontado $20 por consulta frecuente.\n";
    }
}

void CuentaAhorro::retirar(double cantidad) {
    if (cantidad > getBalance()) {
        cout << "Fondos insuficientes en la Caja de Ahorro.\n";
    } else {
        descontar(cantidad);
        cout << "Se retiraron $" << cantidad << " de la Caja de Ahorro de " << titularcuenta << ".\n";
    }
}

CuentaCorriente::CuentaCorriente(string titular, double saldo, CuentaAhorro* caja)
    : Banco(titular, saldo), caja(caja) {}

void CuentaCorriente::Mostrardatos() const {
    cout << "Cuenta Corriente - Titular: " << titularcuenta << ", Balance: $" << getBalance() << "\n";
    caja->Mostrardatos();
}

void CuentaCorriente::retirar(double cantidad) {
    if (cantidad <= getBalance()) {
        descontar(cantidad);
        cout << "Se retiraron $" << cantidad << " de la Cuenta Corriente de " << titularcuenta << ".\n";
    } else if (caja->getBalance() >= cantidad) {
        caja->retirar(cantidad);
        cout << "Se usaron fondos de la Caja de Ahorro para cubrir el retiro de la Cuenta Corriente.\n";
    } else {
        cout << "No hay fondos suficientes en ninguna cuenta.\n";
    }
}