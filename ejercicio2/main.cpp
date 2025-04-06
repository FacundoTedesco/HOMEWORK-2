#include <iostream>
#include <memory>
#include "curso.h"

using namespace std;

void menu() {
    Curso curso;
    int opcion;

    do {
        cout << "\n====== MENU ======\n";
        cout << "1. Inscribir estudiante\n";
        cout << "2. Desinscribir estudiante\n";
        cout << "3. Verificar inscripción\n";
        cout << "4. Verificar si el curso está completo\n";
        cout << "5. Imprimir lista de estudiantes\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                int legajo;
                int numCursos;
                vector<pair<string, float>> notas;

                cout << "Ingrese nombre completo: ";
                cin >> ws; // Limpia espacios pendientes
                getline(cin, nombre);

                cout << "Ingrese legajo: ";
                cin >> legajo;

                cout << "Ingrese el número de cursos: ";
                cin >> numCursos;

                for (int i = 0; i < numCursos; ++i) {
                    string cursoNombre;
                    float nota;
                    cout << "Ingrese nombre del curso y debajo la nota: ";
                    cin >> ws;
                    getline(cin, cursoNombre);
                    cin >> nota;
                    notas.emplace_back(cursoNombre, nota);
                }

                curso.inscribirEstudiante(make_shared<Estudiante>(nombre, legajo, notas));
                break;
            }

            case 2: {
                int legajo;
                cout << "Ingrese legajo a desinscribir: ";
                cin >> legajo;
                curso.desinscribirEstudiante(legajo);
                break;
            }

            case 3: {
                int legajo;
                cout << "Ingrese legajo a verificar: ";
                cin >> legajo;
                cout << (curso.estaInscripto(legajo) ? "Estudiante está inscripto." : "Estudiante no está inscripto.") << endl;
                break;
            }

            case 4: {
                cout << (curso.cursoCompleto() ? "El curso está completo." : "El curso no está completo.") << endl;
                break;
            }

            case 5: {
                curso.imprimirEstudiantes();
                break;
            }

            case 0:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }

    } while (opcion != 0);
}

int main() {
    menu();
    return 0;
}

// entre curso y estudiante la relacion que hay es de agregacion, ya que el curso tiene estudiantes y no al reves
