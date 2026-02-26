/**
 * @file sort.cpp
 * @brief Implementacion de algoritmos de ordenamiento (Burbuja, Seleccion, Insercion, QuickSort y MergeSort).
 */

#include "sort.h"
#include <iostream>
using namespace std;

/**
 * @brief Ordena un arreglo utilizando el metodo de la Burbuja (Bubble Sort).
 * * Compara elementos adyacentes y los intercambia si estan en el orden incorrecto.
 * Tiene una complejidad de tiempo de $O(n^2)$. Muestra por consola los intercambios realizados.
 * * @param arreglo Puntero al arreglo que se desea ordenar.
 * @param n El numero total de elementos en el arreglo.
 */

void ordenarBurbuja(int arreglo[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            cout << "Comparando " << arreglo[j] << " y " << arreglo[j + 1] << endl;
            if (arreglo[j] > arreglo[j + 1])
            {
                temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
                cout << "Intercambiando: " << arreglo[j] << " con " << arreglo[j + 1] << endl;
            }
        }
    }
}

/**
 * @brief Ordena un arreglo utilizando el algoritmo de Seleccion (Selection Sort).
 * * Busca el elemento mas pequeño del arreglo no ordenado y lo intercambia con el
 * primer elemento no ordenado. Tiene una complejidad de tiempo de $O(n^2)$.
 * * @param arreglo Puntero al arreglo que se desea ordenar.
 * @param n El numero total de elementos en el arreglo.
 */

void ordenarSeleccion(int arreglo[], int n)
{
    int temp, min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            cout << "Comparando " << arreglo[j] << " y " << arreglo[min] << endl;
            if (arreglo[j] < arreglo[min])
            {
                min = j;
            }
        }
        temp = arreglo[i];
        arreglo[i] = arreglo[min];
        arreglo[min] = temp;
        cout << "Poniendo " << arreglo[i] << " en la posición " << i << endl;
    }
}

/**
 * @brief Ordena un arreglo utilizando el algoritmo de Insercion (Insertion Sort).
 * * Construye un subarreglo ordenado insertando un elemento a la vez en su posicion correcta.
 * Tiene una complejidad de tiempo de $O(n^2)$ en el peor caso.
 * * @param arreglo Puntero al arreglo que se desea ordenar.
 * @param n El numero total de elementos en el arreglo.
 */

void ordenarInsercion(int arreglo[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int clave = arreglo[i];
        int j = i - 1;
        cout << "Insertando " << clave << endl;
        while (j >= 0 && arreglo[j] > clave)
        {
            cout << "Moviendo " << arreglo[j] << " a la posición " << j + 1 << endl;
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = clave;
        cout << "Colocando " << clave << " en la posición " << j + 1 << endl;
    }
}

/**
 * @brief Ordena un arreglo utilizando el algoritmo recursivo QuickSort.
 * * Divide el arreglo basandose en un pivote y ordena las dos mitades independientemente.
 * Es un algoritmo muy eficiente con una complejidad promedio de $O(n \log n)$.
 * * @param arreglo Puntero al arreglo que se desea ordenar.
 * @param izquierda Indice inicial del subarreglo a ordenar.
 * @param derecha Indice final del subarreglo a ordenar.
 * @param comparaciones Referencia a un contador para registrar cuantas comparaciones se hacen.
 * @param intercambios Referencia a un contador para registrar cuantos intercambios se realizan.
 */
void quickSort(int arreglo[], int izquierda, int derecha, int& comparaciones, int& intercambios)
{
    int i = izquierda, j = derecha;
    int pivote = arreglo[(izquierda + derecha) / 2];
    cout << "QuickSort pivot: " << pivote << " de posición " << (izquierda + derecha) / 2 << endl;

    int temp;
    while (i <= j)
    {
        while (arreglo[i] < pivote) { i++; comparaciones++; }
        while (arreglo[j] > pivote) { j--; comparaciones++; }
        if (i <= j)
        {
            temp = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temp;
            intercambios++;
            cout << "Intercambiando " << arreglo[i] << " y " << arreglo[j] << endl;
            i++; j--;
        }
    }
    if (izquierda < j) quickSort(arreglo, izquierda, j, comparaciones, intercambios);
    if (i < derecha) quickSort(arreglo, i, derecha, comparaciones, intercambios);
}

/**
 * @brief Funcion auxiliar para el algoritmo MergeSort que mezcla dos subarreglos ordenados.
 * * @param arreglo El arreglo original que contiene los subarreglos.
 * @param izquierda Indice inicial del primer subarreglo.
 * @param medio Indice final del primer subarreglo (punto de division).
 * @param derecha Indice final del segundo subarreglo.
 * @param comparaciones Referencia a un contador de comparaciones.
 */
void merge(int arreglo[], int izquierda, int medio, int derecha, int& comparaciones)
{
    int i = izquierda, j = medio + 1, k = 0;
    int temp[100];

    while (i <= medio && j <= derecha)
    {
        comparaciones++;
        if (arreglo[i] <= arreglo[j])
        {
            temp[k++] = arreglo[i++];
        }
        else
        {
            temp[k++] = arreglo[j++];
        }
    }
    while (i <= medio) temp[k++] = arreglo[i++];
    while (j <= derecha) temp[k++] = arreglo[j++];

    for (i = izquierda, k = 0; i <= derecha; i++, k++)
        arreglo[i] = temp[k];
}
//bye
/**
 * @brief Ordena un arreglo utilizando el algoritmo recursivo MergeSort.
 * * Divide el arreglo en mitades repetidamente hasta que tienen tamaño 1,
 * y luego las mezcla en orden usando la funcion merge(). Complejidad: $O(n \log n)$.
 * * @param arreglo Puntero al arreglo que se desea ordenar.
 * @param izquierda Indice inicial del subarreglo.
 * @param derecha Indice final del subarreglo.
 * @param comparaciones Referencia a un contador de comparaciones realizadas durante la mezcla.
 */
void mergeSort(int arreglo[], int izquierda, int derecha, int& comparaciones)
{
    if (izquierda < derecha)
    {
        int medio = (izquierda + derecha) / 2;
        mergeSort(arreglo, izquierda, medio, comparaciones);
        mergeSort(arreglo, medio + 1, derecha, comparaciones);
        merge(arreglo, izquierda, medio, derecha, comparaciones);
    }
}