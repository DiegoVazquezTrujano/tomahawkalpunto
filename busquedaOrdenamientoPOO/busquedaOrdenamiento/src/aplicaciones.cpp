/**
 * @file App.cpp
 * @brief Implementacion de la logica principal de la aplicacion POO.
 */
#include "aplicaciones.h"
#include <iostream>
using namespace std;

void App::ejecutar() {
    int opcion, metodo;
    int valor, posicion;
    int comparaciones = 0, intercambios = 0;

    do {
        miArreglo.mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1: // Busqueda secuencial
            miArreglo.mostrarArreglo();
            valor = miArreglo.pedirValor();
            {
                double tiempo = medirTiempo([&]() {
                    posicion = miArreglo.busquedaSecuencial(valor);
                    });
                if (posicion != -1) cout << "Valor encontrado en posicion: " << posicion << endl;
                else cout << "Valor no encontrado.\n";
                cout << "Tiempo de ejecucion: " << tiempo << " microsegundos.\n";
            }
            break;

        case 2: // Busqueda binaria (ordenar primero)
            cout << "\nOrdenando arreglo...\n";
            {
                double tiempoOrden = medirTiempo([&]() { miArreglo.ordenarBurbuja(); });
                cout << "Tiempo de ordenamiento: " << tiempoOrden << " microsegundos.\n";
            }
            miArreglo.mostrarArreglo();
            valor = miArreglo.pedirValor();
            {
                double tiempoBusq = medirTiempo([&]() { posicion = miArreglo.busquedaBinaria(valor); });
                if (posicion != -1) cout << "Valor encontrado en posicion: " << posicion << endl;
                else cout << "Valor no encontrado.\n";
                cout << "Tiempo de busqueda binaria: " << tiempoBusq << " microsegundos.\n";
            }
            break;

        case 3: // Ordenamiento
            metodo = miArreglo.mostrarMenuOrdenamiento();
            comparaciones = intercambios = 0;
            if (metodo == 1) {
                double t = medirTiempo([&]() { miArreglo.ordenarBurbuja(); });
                cout << "Tiempo de Burbuja: " << t << " microsegundos.\n";
            }
            else if (metodo == 2) {
                double t = medirTiempo([&]() { miArreglo.ordenarSeleccion(); });
                cout << "Tiempo de Seleccion: " << t << " microsegundos.\n";
            }
            else if (metodo == 3) {
                double t = medirTiempo([&]() { miArreglo.ordenarInsercion(); });
                cout << "Tiempo de Insercion: " << t << " microsegundos.\n";
            }
            else if (metodo == 4) {
                double t = medirTiempo([&]() { miArreglo.quickSort(0, miArreglo.getN() - 1, comparaciones, intercambios); });
                cout << "Tiempo QuickSort: " << t << " microsegundos.\n";
                cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
            }
            else if (metodo == 5) {
                double t = medirTiempo([&]() { miArreglo.mergeSort(0, miArreglo.getN() - 1, comparaciones); });
                cout << "Tiempo MergeSort: " << t << " microsegundos.\n";
                cout << "Comparaciones: " << comparaciones << endl;
            }
            else {
                cout << "Metodo invalido.\n";
            }
            cout << "Arreglo ordenado:\n";
            miArreglo.mostrarArreglo();
            break;

        case 4: // Aleatorios con repetición
        {
            int tamaño, maxVal;
            cout << "Ingrese tamaño del arreglo: "; cin >> tamaño;
            cout << "Ingrese valor máximo: "; cin >> maxVal;
            double t = medirTiempo([&]() { miArreglo.generarAleatoriosConRepeticion(tamaño, maxVal); });
            cout << "Tiempo de generacion: " << t << " microsegundos.\n";
        }
        break;

        case 5: // Aleatorios sin repetición
        {
            int tamaño, maxVal;
            cout << "Ingrese tamaño del arreglo: "; cin >> tamaño;
            cout << "Ingrese valor máximo: "; cin >> maxVal;
            double t = medirTiempo([&]() { miArreglo.generarAleatoriosSinRepeticion(tamaño, maxVal); });
            cout << "Tiempo de generacion: " << t << " microsegundos.\n";
        }
        break;

        case 6:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 6);
}