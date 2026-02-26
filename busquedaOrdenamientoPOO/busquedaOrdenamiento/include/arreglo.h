/**
 * @file arreglo.h
 * @brief Definicion de la clase Arreglo y sus metodos para busqueda y ordenamiento.
 */
#pragma once
#ifndef ARREGLO_H
#define ARREGLO_H


/**
 * @class Arreglo
 * @brief Clase que encapsula un arreglo estatico de enteros y proporciona metodos para su manipulacion.
 * * Esta clase implementa diversos algoritmos de busqueda (secuencial y binaria),
 * algoritmos de ordenamiento (Burbuja, Seleccion, Insercion, QuickSort y MergeSort),
 * y metodos para rellenar el arreglo con numeros aleatorios.
 */
class Arreglo {
private:
    static const int MAX = 100000; /**< Tamaño maximo permitido para el arreglo estatico. */
    int arreglo[MAX];              /**< Arreglo interno que almacena los datos. */
    int n;                         /**< Tamaño lógico actual (elementos en uso). */

public:
    /**
     * @brief Constructor por defecto. Inicializa el arreglo con un tamaño logico de 10
     * y con datos predeterminados. Tambien inicializa la semilla de numeros aleatorios.
     */
    Arreglo(); // constructor

    // Métodos de visualización
    void mostrarMenu();
    void mostrarArreglo();
    int pedirValor();
    int mostrarMenuOrdenamiento();

    /**
     * @brief Obtiene el tamaño logico actual del arreglo.
     * @return int El numero de elementos actualmente en uso.
     */
    // Obtener tamaño actual
    int getN();

    // Búsquedas
    int busquedaSecuencial(int valor);
    int busquedaBinaria(int valor);

    // Ordenamientos
    void ordenarBurbuja();
    void ordenarSeleccion();
    void ordenarInsercion();
    void quickSort(int izquierda, int derecha, int& comparaciones, int& intercambios);
    void mergeSort(int izquierda, int derecha, int& comparaciones);

    // Generación aleatoria
    void generarAleatoriosConRepeticion(int tamaño, int maxValor);
    void generarAleatoriosSinRepeticion(int tamaño, int maxValor);

private:
    void merge(int izquierda, int medio, int derecha, int& comparaciones);
};

#endif