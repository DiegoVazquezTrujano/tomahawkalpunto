/**
 * @file search.cpp
 * @brief Implementacion de los metodos de busqueda en arreglos.
 */

#include "search.h"

 /**
  * @brief Realiza una busqueda secuencial (lineal) dentro del arreglo.
  * * Recorre el arreglo elemento por elemento desde el principio hasta el final.
  * Tiene una complejidad de tiempo de $O(n)$ en el peor de los casos.
  * * @param arreglo El arreglo donde se realizara la busqueda.
  * @param n El tamano actual del arreglo.
  * @param valor El numero entero que se desea encontrar.
  * @return int La posicion (indice) del valor si se encuentra, o -1 si no existe en el arreglo.
  */

int busquedaSecuencial(int arreglo[], int n, int valor)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (arreglo[i] == valor)
        {
            return i;  // devuelve la posición
        }
    }

    return -1; // valor no encontrado
}

/**
 * @brief Realiza una busqueda binaria dentro del arreglo.
 * * Divide repetidamente el rango de busqueda a la mitad.
 * IMPORTANTE: El arreglo debe estar ordenado previamente para que este algoritmo funcione.
 * Tiene una complejidad de tiempo de $O(\log n)$.
 * * @param arreglo El arreglo ordenado donde se realizara la busqueda.
 * @param n El tamano actual del arreglo.
 * @param valor El numero entero que se desea encontrar.
 * @return int La posicion (indice) del valor si se encuentra, o -1 si no existe en el arreglo.
 */

int busquedaBinaria(int arreglo[], int n, int valor)
{
    int izquierda = 0;
    int derecha = n - 1;
    int medio;

    while (izquierda <= derecha)
    {
        medio = (izquierda + derecha) / 2;

        if (arreglo[medio] == valor)
        {
            return medio;
        }
        else if (arreglo[medio] < valor)
        {
            izquierda = medio + 1;
        }
        else
        {
            derecha = medio - 1;
        }
    }

    return -1;
}