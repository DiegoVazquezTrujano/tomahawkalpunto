/**
 * @file aplicaciones.cpp
 * @brief Implementacion de la logica del menu interactivo.
 */
#include "aplicaciones.h"
#include <iostream>
#include "sort.h"
#include "search.h"
#include "view.h"
#include "randomGen.h"

using namespace std;

void ejecutarApp() {
    int arreglo[100000];  // Soporte para arreglos grandes (pruebas de 10,000+)
    int n = 10;
    int opcion, metodo;
    int posicion, valor;
    int comparaciones, intercambios;
    int N, M;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1: // Búsqueda secuencial
        {
            mostrarArreglo(arreglo, n);
            valor = pedirValor();
            double tiempo = medirTiempo([&]() { busquedaSecuencial(arreglo, n, valor); });
            posicion = busquedaSecuencial(arreglo, n, valor);
            if (posicion != -1)
                cout << "Valor encontrado en posicion: " << posicion << endl;
            else
                cout << "Valor no encontrado.\n";
            cout << "Tiempo de busquedaSecuencial: " << tiempo << " ms\n";
            break;
        }

        case 2: // Búsqueda binaria
        {
            cout << "\nOrdenando arreglo con Burbuja...\n";
            double tiempoOrden = medirTiempo([&]() { ordenarBurbuja(arreglo, n); });
            mostrarArreglo(arreglo, n);
            cout << "Tiempo de ordenarBurbuja: " << tiempoOrden << " ms\n";

            valor = pedirValor();
            double tiempoBusqueda = medirTiempo([&]() { busquedaBinaria(arreglo, n, valor); });
            posicion = busquedaBinaria(arreglo, n, valor);
            if (posicion != -1)
                cout << "Valor encontrado en posicion: " << posicion << endl;
            else
                cout << "Valor no encontrado.\n";
            cout << "Tiempo de busquedaBinaria: " << tiempoBusqueda << " ms\n";
            break;
        }

        case 3: // Menu de nuestro Ordenamiento 
        {
            metodo = mostrarMenuOrdenamiento();
            comparaciones = intercambios = 0;

            double tiempo = 0;
            if (metodo == 1)
                tiempo = medirTiempo([&]() { ordenarBurbuja(arreglo, n); });
            else if (metodo == 2)
                tiempo = medirTiempo([&]() { ordenarSeleccion(arreglo, n); });
            else if (metodo == 3)
                tiempo = medirTiempo([&]() { ordenarInsercion(arreglo, n); });
            else if (metodo == 4)
            {
                tiempo = medirTiempo([&]() { quickSort(arreglo, 0, n - 1, comparaciones, intercambios); });
                cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
            }
            else if (metodo == 5)
            {
                tiempo = medirTiempo([&]() { mergeSort(arreglo, 0, n - 1, comparaciones); });
                cout << "Comparaciones: " << comparaciones << endl;
            }
            else
                cout << "Metodo invalido.\n";

            cout << "\nArreglo ordenado:\n";
            mostrarArreglo(arreglo, n);
            cout << "Tiempo de ordenamiento: " << tiempo << " ms\n";
            break;
        }

        case 4: // Aleatorios con repetición
        {
            cout << "Ingrese N (tamaño base): ";
            cin >> N;
            cout << "Seleccione tamaño: 1=N, 2=N*N, 3=N*M: ";
            int tipo;
            cin >> tipo;
            if (tipo == 1) n = N;
            else if (tipo == 2) n = N * N;
            else if (tipo == 3)
            {
                cout << "Ingrese M: ";
                cin >> M;
                n = N * M;
            }

            double tiempo = medirTiempo([&]() { generarAleatoriosConRepeticion(arreglo, n, n); });
            cout << "Tiempo de generacion (con repeticion): " << tiempo << " ms\n";
            break;
        }

        case 5: // Aleatorios sin repetición
        {
            cout << "Ingrese N (tamaño base): ";
            cin >> N;
            cout << "Seleccione tamaño: 1=N, 2=N*N, 3=N*M: ";
            int tipo;
            cin >> tipo;
            if (tipo == 1) n = N;
            else if (tipo == 2) n = N * N;
            else if (tipo == 3)
            {
                cout << "Ingrese M: ";
                cin >> M;
                n = N * M;
            }

            double tiempo = medirTiempo([&]() { generarAleatoriosSinRepeticion(arreglo, n, n); });
            cout << "Tiempo de generacion (sin repeticion): " << tiempo << " ms\n";
            break;
        }

        case 6:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 6);
}