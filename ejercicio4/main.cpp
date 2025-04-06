#include "banco.h"

using namespace std;

int main() {
    CuentaAhorro ahorro("Juan Perez", 500);
    CuentaCorriente corriente("Juan Perez", 300, &ahorro);

    ahorro.depositar(200);
    corriente.depositar(150);

    ahorro.retirar(100);
    corriente.retirar(400); // Debería usar fondos de la caja de ahorro

    ahorro.retirar(700); // No debe permitirlo

    ahorro.Mostrardatos();
    ahorro.Mostrardatos();
    ahorro.Mostrardatos(); // Se descuenta $20

    return 0;
}