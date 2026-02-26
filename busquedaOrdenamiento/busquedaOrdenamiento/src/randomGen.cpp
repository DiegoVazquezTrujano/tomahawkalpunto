/**
 * @file randomGen.cpp
 * @brief Implementacion de la generacion de numeros aleatorios con y sin repeticion.
 */

#include "randomGen.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * @brief Genera un arreglo de numeros aleatorios donde los valores pueden repetirse.
 * * Asigna valores al azar utilizando el tamaño solicitado como base para el limite
 * de los numeros generados. Muestra por consola el proceso de asignacion.
 * * @param arreglo Puntero al arreglo donde se guardaran los numeros generados.
 * @param n Referencia a la variable que almacena el tamaño actual del arreglo (se actualiza a tam).
 * @param tam El numero de elementos que se desean generar.
 */

void generarAleatoriosConRepeticion(int arreglo[], int& n, int tam)
{
    n = tam;
    srand(time(NULL));
    cout << "\nGenerando numeros aleatorios CON repeticion:" << endl;
    for (int i = 0; i < n; i++)
    {
        arreglo[i] = rand() % (n * 10);
        cout << "arreglo[" << i << "] = " << arreglo[i] << endl;
    }
}

/**
 * @brief Genera un arreglo de numeros aleatorios asegurando que ningun valor se repita.
 * * Utiliza un arreglo auxiliar (pool de numeros) para extraer valores aleatorios
 * y evitar colisiones. Muestra por consola el proceso de asignacion.
 * * @param arreglo Puntero al arreglo donde se guardaran los numeros unicos.
 * @param n Referencia a la variable que almacena el tamaño actual del arreglo (se actualiza a tam).
 * @param tam El numero de elementos que se desean generar.
 * @param M Valor maximo opcional para el rango de numeros a generar (por defecto es 0).
 */

void generarAleatoriosSinRepeticion(int arreglo[], int& n, int tam, int M)
{
    n = tam;
    srand(time(NULL));
    int max_val = (M > 0) ? M : n * 10;
    int* aux = new int[max_val];
    for (int i = 0; i < max_val; i++) 
        aux[i] = i;

    cout << "\nGenerando numeros aleatorios SIN repeticion:" << endl;
    for (int i = 0; i < n; i++)
    {
        int idx = rand() % (max_val - i);
        arreglo[i] = aux[idx];
        cout << "arreglo[" << i << "] = " << arreglo[i] << endl;
        aux[idx] = aux[max_val - i - 1];
    }
    delete[] aux;
}