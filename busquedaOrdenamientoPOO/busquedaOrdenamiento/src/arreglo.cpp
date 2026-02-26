/**
 * @file arreglo.cpp
 * @brief Implementacion de los metodos de la clase Arreglo.
 */

#include "Arreglo.h"
#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime>   // time
using namespace std;

Arreglo::Arreglo() 
{
    n = 10;
    int inicial[10] = { 33, 5, 90, 12, 41, 8, 77, 20, 50, 62 };
    for (int i = 0; i < n; i++)
        arreglo[i] = inicial[i];
    srand(static_cast<unsigned int>(time(0))); // semilla aleatoria
}

// ==================== VISUALIZACION ====================
/**
 * @brief Imprime en la consola el menu principal interactivo del programa.
 */
void Arreglo::mostrarMenu() 
{
    cout << "\n=== MENU ===" << endl;
    cout << "1. Busqueda Secuencial\n";
    cout << "2. Busqueda Binaria (ordena automaticamente)" << endl;
    cout << "3. Ordenar Arreglo" << endl;
    cout << "4. Generar aleatorios con repeticion" << endl;
    cout << "5. Generar aleatorios sin repeticion" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione opcion: ";
}

/**
 * @brief Imprime el contenido actual del arreglo en la consola.
 */
void Arreglo::mostrarArreglo() {
    if (n > 100) {
        cout << "\n[Arreglo de " << n << " elementos. Es muy grande para imprimirlo en pantalla]" << endl;
    }
    else {
        cout << "\nArreglo: ";
        for (int i = 0; i < n; i++)
            cout << arreglo[i] << " ";
        cout << endl;
    }
}

/**
 * @brief Solicita al usuario ingresar un valor numerico por teclado.
 * @return int El valor ingresado por el usuario.
 */
int Arreglo::pedirValor() 
{
    int valor;
    cout << "Ingrese valor: ";
    cin >> valor;
    return valor;
}

/**
 * @brief Imprime en consola el sub-menu con los metodos de ordenamiento disponibles.
 * @return int La opcion (1-5) seleccionada por el usuario.
 */
int Arreglo::mostrarMenuOrdenamiento() 
{
    int opcion;
    cout << "\n=== METODOS DE ORDENAMIENTO ===" << endl;
    cout << "1. Burbuja\n2. Seleccion\n3. Insercion\n4. QuickSort\n5. MergeSort\n";
    cout << "Seleccione metodo: ";
    cin >> opcion;
    return opcion;
}

int Arreglo::getN() { return n; }

// ==================== BUSQUEDAS ====================
/**
 * @brief Realiza una busqueda secuencial iterando desde el inicio hasta el fin.
 * @param valor El numero entero que se desea encontrar.
 * @return int El indice donde se encontro el valor, o -1 si no existe.
 */
int Arreglo::busquedaSecuencial(int valor) 
 {
    for (int i = 0; i < n; i++)
        if (arreglo[i] == valor) return i;
    return -1;
}

/**
 * @brief Realiza una busqueda binaria (requiere que el arreglo este ordenado).
 * @param valor El numero entero que se desea encontrar.
 * @return int El indice donde se encontro el valor, o -1 si no existe.
 */
int Arreglo::busquedaBinaria(int valor) {
    int izq = 0, der = n - 1;
    while (izq <= der) {
        int medio = (izq + der) / 2;
        if (arreglo[medio] == valor) return medio;
        else if (arreglo[medio] < valor) izq = medio + 1;
        else der = medio - 1;
    }
    return -1;
}

// ==================== ORDENAMIENTOS ====================
/**
 * @brief Ordena el arreglo interno utilizando el metodo de la Burbuja.
 */
void Arreglo::ordenarBurbuja() 
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (arreglo[j] > arreglo[j + 1])
                swap(arreglo[j], arreglo[j + 1]);
}

/**
 * @brief Ordena el arreglo interno utilizando el algoritmo de Seleccion.
 */
void Arreglo::ordenarSeleccion() 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arreglo[j] < arreglo[min]) min = j;
        swap(arreglo[i], arreglo[min]);
    }
}

/**
 * @brief Ordena el arreglo interno utilizando el algoritmo de Insercion.
 */
void Arreglo::ordenarInsercion() {
    for (int i = 1; i < n; i++) {
        int clave = arreglo[i];
        int j = i - 1;
        while (j >= 0 && arreglo[j] > clave) {
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = clave;
    }
}

/**
 * @brief Ordena el arreglo interno utilizando el algoritmo recursivo QuickSort.
 * @param izquierda Indice inicial del subarreglo.
 * @param derecha Indice final del subarreglo.
 * @param comparaciones Referencia al contador de comparaciones efectuadas.
 * @param intercambios Referencia al contador de intercambios realizados.
 */
void Arreglo::quickSort(int izquierda, int derecha, int& comparaciones, int& intercambios) 
{
    int i = izquierda, j = derecha;
    int pivote = arreglo[(izquierda + derecha) / 2];
    while (i <= j) 
    {
        while (arreglo[i] < pivote) 
        { 
            i++; comparaciones++; 
        }
        while (arreglo[j] > pivote) 
        {
            j--; comparaciones++; 
        }
        if (i <= j) 
        { 
            swap(arreglo[i], arreglo[j]); intercambios++; i++; j--; 
        }
    }
    if (izquierda < j) quickSort(izquierda, j, comparaciones, intercambios);
    if (i < derecha) quickSort(i, derecha, comparaciones, intercambios);
}

/**
 * @brief Metodo privado auxiliar para MergeSort que mezcla dos subarreglos ordenados.
 * @param izquierda Indice inicial del primer subarreglo.
 * @param medio Indice central que divide los subarreglos.
 * @param derecha Indice final del segundo subarreglo.
 * @param comparaciones Referencia al contador de comparaciones efectuadas.
 */
void Arreglo::merge(int izquierda, int medio, int derecha, int& comparaciones) 
{
    int temp[100000]; // suficiente para MAX
    int i = izquierda, j = medio + 1, k = 0;
    while (i <= medio && j <= derecha) 
    {
        comparaciones++;
        if (arreglo[i] <= arreglo[j]) temp[k++] = arreglo[i++];
        else temp[k++] = arreglo[j++];
    }
    while (i <= medio) temp[k++] = arreglo[i++];
    while (j <= derecha) temp[k++] = arreglo[j++];
    for (i = izquierda, k = 0; i <= derecha; i++, k++) arreglo[i] = temp[k];
}

/**
 * @brief Ordena el arreglo interno utilizando el algoritmo recursivo MergeSort.
 * @param izquierda Indice inicial del subarreglo.
 * @param derecha Indice final del subarreglo.
 * @param comparaciones Referencia al contador de comparaciones efectuadas durante la mezcla.
 */
void Arreglo::mergeSort(int izquierda, int derecha, int& comparaciones) 
{
    if (izquierda < derecha) 
    {
        int medio = (izquierda + derecha) / 2;
        mergeSort(izquierda, medio, comparaciones);
        mergeSort(medio + 1, derecha, comparaciones);
        merge(izquierda, medio, derecha, comparaciones);
    }
}

// ==================== GENERACION ALEATORIA ====================
/**
 * @brief Genera numeros aleatorios y los guarda en el arreglo permitiendo duplicados.
 * @param tamaño El nuevo tamaño logico del arreglo (no debe exceder MAX).
 * @param maxValor El valor mas grande que puede ser generado aleatoriamente.
 */
void Arreglo::generarAleatoriosConRepeticion(int tamaño, int maxValor) 
{
    if (tamaño > MAX) tamaño = MAX;
    n = tamaño;
    for (int i = 0; i < n; i++) 
    {
        arreglo[i] = rand() % maxValor + 1;
        cout << "Pos " << i << " = " << arreglo[i] << endl;
    }
}

/**
 * @brief Genera numeros aleatorios y los guarda en el arreglo asegurando que sean unicos.
 * @param tamaño El nuevo tamaño logico del arreglo (no debe exceder MAX).
 * @param maxValor El valor mas grande que puede ser generado (debe ser mayor o igual a tamaño).
 */
void Arreglo::generarAleatoriosSinRepeticion(int tamaño, int maxValor) 
{
    if (tamaño > MAX) tamaño = MAX;
    n = tamaño;
    for (int i = 0; i < n; i++) 
    {
        int num;
        bool repetido;
        do 
        {
            num = rand() % maxValor + 1;
            repetido = false;
            for (int j = 0; j < i; j++)
                if (arreglo[j] == num) { repetido = true; break; }
        } while (repetido);
        arreglo[i] = num;
        cout << "Pos " << i << " = " << arreglo[i] << endl;
    }
}