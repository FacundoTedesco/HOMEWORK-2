#include "ejercicio1.h"
#include <iostream>
#include <stdexcept>

void mostrarMenu() {
    std::cout << "1. Crear un objeto Tiempo\n";
    std::cout << "2. Modificar la hora\n";
    std::cout << "3. Modificar los minutos\n";
    std::cout << "4. Modificar los segundos\n";
    std::cout << "5. Modificar el periodo (a.m./p.m.)\n";
    std::cout << "6. Mostrar el tiempo completo\n";
    std::cout << "7. Mostrar el tiempo en formato 24 horas\n";
    std::cout << "8. Salir\n";
}

int main() {
    Tiempo tiempo;
    int opcion = 0;

    while (opcion != 8) {
        mostrarMenu();
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        try {
            switch (opcion) {
                case 1: {
                    int h, m, s;
                    bool pm;
                    std::cout << "Ingrese hora (1-12): ";
                    std::cin >> h;
                    std::cout << "Ingrese minutos (0-59): ";
                    std::cin >> m;
                    std::cout << "Ingrese segundos (0-59): ";
                    std::cin >> s;
                    std::cout << "Es p.m.? (1: Sí, 0: No): ";
                    std::cin >> pm;
                    tiempo = Tiempo(h, m, s, pm);
                    break;
                }
                case 2: {
                    int h;
                    std::cout << "Ingrese hora (1-12): ";
                    std::cin >> h;
                    tiempo.setHora(h);
                    break;
                }
                case 3: {
                    int m;
                    std::cout << "Ingrese minutos (0-59): ";
                    std::cin >> m;
                    tiempo.setMinutos(m);
                    break;
                }
                case 4: {
                    int s;
                    std::cout << "Ingrese segundos (0-59): ";
                    std::cin >> s;
                    tiempo.setSegundos(s);
                    break;
                }
                case 5: {
                    bool pm;
                    std::cout << "Es p.m.? (1: Sí, 0: No): ";
                    std::cin >> pm;
                    tiempo.setPeriodo(pm);
                    break;
                }
                case 6:
                    std::cout << "Hora completa: " << tiempo.getTiempoCompleto() << "\n";
                    break;
                case 7:
                    std::cout << "Hora en formato 24h: " << tiempo.getHora24() << "\n";
                    break;
                case 8:
                    std::cout << "Saliendo del programa...\n";
                    break;
                default:
                    std::cout << "Opción inválida. Intente de nuevo.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}